#!/usr/bin/python -B

from string import Template, upper, replace

from ApiCodeGen   import *
from ApiUtil      import outputCode
from ApiUtil      import typeIsVoid
from ApiRegal     import logFunction

from RegalContextInfo import cond

from RegalDispatchShared import apiDispatchFuncInitCode
from RegalDispatchShared import apiDispatchGlobalFuncInitCode

from Emu       import *
from EmuGLX    import formulaeGlobal as formulae

# CodeGen for dispatch table init.

dispatchGLXTemplate = Template('''${AUTOGENERATED}
${LICENSE}

#include "pch.h" /* For MS precompiled header support */

#include "RegalUtil.h"

#if REGAL_SYS_GLX && !REGAL_SYS_X11

REGAL_GLOBAL_BEGIN

#include "RegalLog.h"
#include "RegalPush.h"
#include "RegalToken.h"
#include "RegalHelper.h"
#include "RegalContext.h"
#include "RegalDispatch.h"

using namespace ::REGAL_NAMESPACE_INTERNAL::Logging;
using namespace ::REGAL_NAMESPACE_INTERNAL::Token;

REGAL_GLOBAL_END

REGAL_NAMESPACE_BEGIN

${API_FUNC_DEFINE}

void InitDispatch::GLX(Dispatch::GL &tbl)
{
${API_GL_DISPATCH_INIT}
}

${API_GLOBAL_DISPATCH_INIT}

REGAL_NAMESPACE_END

#endif
''')

def filterGLX(func):
  return func.name.startswith('glX')

def generateDispatchGLX(apis, args):

  # CodeGen for API functions.

  code = ''
  categoryPrev = None

  for api in apis:

    if api.name != 'glx':
      continue

    code += '\n'

    for function in api.functions:

      if getattr(function,'regalOnly',False)==True:
        continue

      name   = function.name
      params = paramsDefaultCode(function.parameters, True)
      callParams = paramsNameCode(function.parameters)
      rType  = typeCode(function.ret.type)
      category  = getattr(function, 'category', None)
      version   = getattr(function, 'version', None)

      if category:
        category = category.replace('_DEPRECATED', '')
      elif version:
        category = version.replace('.', '_')
        category = 'GL_VERSION_' + category

      # Close prev category block.
      if categoryPrev and not (category == categoryPrev):
        code += '\n'

      # Begin new category block.
      if category and not (category == categoryPrev):
        code += '// %s\n\n' % category

      categoryPrev = category

      code += 'static %sREGAL_CALL %s%s(%s) \n{\n' % (rType, 'GLX_', name, params)

      if not function.needsContext:
        code += '    DispatchTableGlobal *_next = dispatcherGlobal.glx.next();\n'

      code += '    RegalAssert(_next);\n'

      match = emuFindEntry(function,formulae,None)
      if match and 'impl' in match:
#       print match
        code += listToString(indent(match['impl'],'    '))

      code += '    '
      if not typeIsVoid(rType):
        code += '%s ret = '%(rType)
      code += '_next->call(&_next->%s)(%s);\n' % ( name, callParams )

      if not typeIsVoid(rType):
        code += '    return ret;\n'
      code += '}\n\n'

    code += '\n'

  # Close pending if block.
  if categoryPrev:
    code += '\n'

  # Output

  substitute = {}
  substitute['LICENSE']         = args.license
  substitute['AUTOGENERATED']   = args.generated
  substitute['COPYRIGHT']       = args.copyright
  substitute['API_FUNC_DEFINE'] = code
  substitute['API_GL_DISPATCH_INIT']     = apiDispatchFuncInitCode( apis, args, 'GLX', [], filterGLX )
  substitute['API_GLOBAL_DISPATCH_INIT'] = apiDispatchGlobalFuncInitCode( apis, args, 'GLX', [], filterGLX )

  outputCode( '%s/RegalDispatchGLX.cpp' % args.srcdir, dispatchGLXTemplate.substitute(substitute))

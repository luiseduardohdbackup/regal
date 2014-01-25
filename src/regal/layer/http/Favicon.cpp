/*
  Copyright (c) 2011 NVIDIA Corporation
  Copyright (c) 2011-2012 Cass Everitt
  Copyright (c) 2012 Scott Nations
  Copyright (c) 2012 Mathias Schott
  Copyright (c) 2012 Nigel Stewart
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification,
  are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

    Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
  OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "pch.h" /* For MS precompiled header support */

#include "RegalUtil.h"

#if REGAL_HTTP

REGAL_NAMESPACE_BEGIN

unsigned char favicon[2238] =
{
0x00,0x00,0x01,0x00,0x01,0x00,0x20,0x20,0x00,0x00,0x01,0x00,0x08,0x00,0xa8,0x08,
0x00,0x00,0x16,0x00,0x00,0x00,0x28,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x40,0x00,
0x00,0x00,0x01,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x24,0x01,
0x24,0x00,0x21,0x00,0x29,0x00,0x25,0x04,0x2d,0x00,0x34,0x00,0x3a,0x00,0x49,0x00,
0x53,0x00,0x47,0x00,0x58,0x00,0x51,0x00,0x59,0x00,0x1b,0x11,0x34,0x00,0x44,0x01,
0x5c,0x00,0x4c,0x02,0x57,0x00,0x39,0x06,0x50,0x00,0x4a,0x00,0x60,0x00,0x55,0x00,
0x5d,0x00,0x5b,0x00,0x61,0x00,0x49,0x04,0x5b,0x00,0x5e,0x00,0x64,0x00,0x5a,0x00,
0x66,0x00,0x60,0x03,0x66,0x00,0x5b,0x00,0x72,0x00,0x16,0x1b,0x31,0x00,0x65,0x01,
0x6f,0x00,0x5d,0x01,0x75,0x00,0x55,0x04,0x6e,0x00,0x59,0x05,0x6d,0x00,0x6d,0x00,
0x7e,0x00,0x67,0x05,0x71,0x00,0x6b,0x00,0x84,0x00,0x71,0x00,0x83,0x00,0x64,0x07,
0x75,0x00,0x1e,0x1e,0x40,0x00,0x60,0x07,0x78,0x00,0x75,0x00,0x8b,0x00,0x78,0x01,
0x8e,0x00,0x7d,0x00,0x97,0x00,0x3d,0x17,0x61,0x00,0x2a,0x21,0x4e,0x00,0x8b,0x00,
0xa6,0x00,0x8a,0x02,0xa1,0x00,0x28,0x24,0x53,0x00,0x17,0x2a,0x45,0x00,0x80,0x06,
0x9b,0x00,0x1a,0x2b,0x4c,0x00,0x95,0x00,0xb5,0x00,0x36,0x22,0x6a,0x00,0x7e,0x0c,
0xa0,0x00,0xa1,0x00,0xbe,0x00,0x12,0x31,0x4a,0x00,0x0b,0x37,0x3c,0x00,0xa3,0x00,
0xc4,0x00,0x1f,0x30,0x51,0x00,0x00,0x39,0x3f,0x00,0xa7,0x00,0xc9,0x00,0x35,0x2a,
0x6d,0x00,0x01,0x3c,0x43,0x00,0xb5,0x00,0xd9,0x00,0x0c,0x3f,0x45,0x00,0x05,0x40,
0x46,0x00,0xbd,0x00,0xe5,0x00,0x00,0x42,0x4a,0x00,0x09,0x43,0x4a,0x00,0x02,0x44,
0x4c,0x00,0x0a,0x44,0x4b,0x00,0x12,0x40,0x56,0x00,0x0c,0x42,0x54,0x00,0x2e,0x37,
0x72,0x00,0x29,0x39,0x6f,0x00,0x05,0x47,0x4f,0x00,0x06,0x49,0x51,0x00,0x10,0x46,
0x58,0x00,0x00,0x4a,0x52,0x00,0x08,0x4a,0x52,0x00,0x0a,0x4e,0x51,0x00,0x0c,0x4d,
0x56,0x00,0x0d,0x4e,0x57,0x00,0x04,0x50,0x54,0x00,0x00,0x50,0x5a,0x00,0x06,0x50,
0x59,0x00,0x06,0x52,0x56,0x00,0x09,0x50,0x60,0x00,0x08,0x52,0x5b,0x00,0x00,0x53,
0x5d,0x00,0x22,0x48,0x77,0x00,0x09,0x54,0x58,0x00,0x00,0x55,0x5a,0x00,0x23,0x49,
0x78,0x00,0x0a,0x54,0x5d,0x00,0x01,0x56,0x5b,0x00,0x03,0x54,0x64,0x00,0x0c,0x56,
0x5b,0x00,0x03,0x58,0x5d,0x00,0x04,0x59,0x5e,0x00,0x05,0x5a,0x5f,0x00,0x00,0x5a,
0x61,0x00,0x06,0x5a,0x60,0x00,0x00,0x5d,0x64,0x00,0x00,0x5e,0x65,0x00,0x0c,0x5e,
0x64,0x00,0x02,0x60,0x67,0x00,0x04,0x61,0x68,0x00,0x00,0x62,0x69,0x00,0x1b,0x5a,
0x7c,0x00,0x05,0x62,0x69,0x00,0x06,0x63,0x6a,0x00,0x08,0x64,0x6b,0x00,0x00,0x66,
0x6e,0x00,0x0b,0x66,0x6d,0x00,0x00,0x67,0x6f,0x00,0x18,0x5f,0x82,0x00,0x1b,0x5f,
0x88,0x00,0x02,0x69,0x71,0x00,0x05,0x6a,0x73,0x00,0x13,0x66,0x7f,0x00,0x06,0x6b,
0x74,0x00,0x00,0x6c,0x76,0x00,0x08,0x6c,0x75,0x00,0x00,0x6d,0x77,0x00,0x09,0x6d,
0x76,0x00,0x00,0x6e,0x78,0x00,0x08,0x6f,0x72,0x00,0x01,0x71,0x7b,0x00,0x11,0x6d,
0x87,0x00,0x02,0x74,0x78,0x00,0x04,0x73,0x7d,0x00,0x00,0x75,0x7a,0x00,0x03,0x75,
0x79,0x00,0x06,0x74,0x7e,0x00,0x05,0x76,0x7a,0x00,0x00,0x75,0x80,0x00,0x07,0x77,
0x7b,0x00,0x00,0x76,0x81,0x00,0x00,0x77,0x82,0x00,0x00,0x79,0x7f,0x00,0x00,0x7b,
0x80,0x00,0x01,0x7c,0x82,0x00,0x03,0x7d,0x83,0x00,0x00,0x7e,0x85,0x00,0x04,0x7e,
0x84,0x00,0x08,0x7c,0x8e,0x00,0x06,0x7f,0x85,0x00,0x00,0x81,0x88,0x00,0x0a,0x81,
0x87,0x00,0x00,0x82,0x89,0x00,0x00,0x83,0x8a,0x00,0x00,0x84,0x8b,0x00,0x12,0x7e,
0x9c,0x00,0x00,0x85,0x8c,0x00,0x04,0x83,0x96,0x00,0x02,0x86,0x8d,0x00,0x03,0x87,
0x8e,0x00,0x00,0x88,0x90,0x00,0x05,0x88,0x90,0x00,0x19,0x80,0xa5,0x00,0x08,0x89,
0x91,0x00,0x00,0x8b,0x8d,0x00,0x00,0x8a,0x92,0x00,0x0a,0x8a,0x92,0x00,0x0c,0x8b,
0x93,0x00,0x00,0x8d,0x95,0x00,0x13,0x87,0xa7,0x00,0x00,0x8e,0x97,0x00,0x00,0x8f,
0x98,0x00,0x02,0x90,0x99,0x00,0x05,0x91,0x9a,0x00,0x00,0x92,0x9c,0x00,0x00,0x94,
0x97,0x00,0x00,0x93,0x9d,0x00,0x00,0x94,0x9e,0x00,0x00,0x96,0x9a,0x00,0x00,0x95,
0x9f,0x00,0x00,0x97,0xa2,0x00,0x00,0x98,0xa3,0x00,0x00,0x9a,0x9e,0x00,0x01,0x99,
0xa4,0x00,0x00,0x9b,0x9f,0x00,0x06,0x97,0xae,0x00,0x05,0x9d,0xa1,0x00,0x06,0x9c,
0xa6,0x00,0x00,0x9e,0xa3,0x00,0x00,0x9f,0xa4,0x00,0x00,0xa0,0xa5,0x00,0x00,0xa1,
0xa7,0x00,0x00,0xa2,0xa8,0x00,0x00,0xa1,0xac,0x00,0x00,0xa3,0xa9,0x00,0x00,0xa2,
0xae,0x00,0x00,0xa4,0xaa,0x00,0x03,0xa6,0xac,0x00,0x06,0xa7,0xad,0x00,0x00,0xa8,
0xaf,0x00,0x00,0xaa,0xb1,0x00,0x00,0xac,0xb3,0x00,0x00,0xad,0xb4,0x00,0x00,0xae,
0xb5,0x00,0x00,0xad,0xbb,0x00,0x00,0xaf,0xb6,0x00,0x02,0xb0,0xb7,0x00,0x05,0xb1,
0xb8,0x00,0x00,0xb2,0xba,0x00,0x00,0xb3,0xbb,0x00,0x00,0xb4,0xbc,0x00,0x00,0xb5,
0xbe,0x00,0x00,0xb8,0xc0,0x00,0x03,0xba,0xc3,0x00,0x01,0xbc,0xbf,0x00,0x00,0xbb,
0xc5,0x00,0x00,0xbc,0xc6,0x00,0x00,0xbd,0xc8,0x00,0x00,0xbf,0xc3,0x00,0x00,0xc0,
0xc4,0x00,0x00,0xbf,0xc9,0x00,0x00,0xc1,0xc5,0x00,0x00,0xc2,0xc6,0x00,0x00,0xc1,
0xcc,0x00,0x00,0xc3,0xcd,0x00,0x00,0xc5,0xca,0x00,0x01,0xc4,0xcf,0x00,0x02,0xc6,
0xcb,0x00,0x00,0xc7,0xcd,0x00,0x00,0xc6,0xd2,0x00,0x08,0xc6,0xd1,0x00,0x00,0xc7,
0xd3,0x00,0x00,0xc8,0xd4,0x00,0x00,0xcb,0xd0,0x00,0x00,0xcd,0xcc,0x00,0x00,0xce,
0xce,0x00,0x00,0xcd,0xd3,0x00,0x00,0xcf,0xd5,0x00,0x00,0xd0,0xd6,0x00,0x04,0xd1,
0xd7,0x00,0x00,0xd2,0xd9,0x00,0x00,0xd3,0xda,0x00,0x00,0xd4,0xdc,0x00,0x00,0xd6,
0xde,0x00,0x00,0xd9,0xe0,0x00,0x00,0xda,0xe2,0x00,0x01,0xdb,0xe3,0x00,0x00,0xdc,
0xe5,0x00,0x00,0xdd,0xe6,0x00,0x00,0xde,0xe7,0x00,0x00,0xdf,0xe8,0x00,0x00,0xe0,
0xe9,0x00,0x00,0xe3,0xe6,0x00,0x00,0xe2,0xec,0x00,0x00,0xe5,0xe8,0x00,0x00,0xe4,
0xed,0x00,0x00,0xe6,0xe9,0x00,0x00,0xe5,0xee,0x00,0x07,0xe7,0xf1,0x00,0x00,0xee,
0xf2,0x00,0x00,0xef,0xf4,0x00,0x00,0xf0,0xf5,0x00,0x00,0xf2,0xf6,0x00,0x00,0xf4,
0xf9,0x00,0x00,0xf5,0xfa,0x00,0x00,0xf7,0xfd,0x00,0x00,0x00,0x00,0x00,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8c,0xff,0xaf,0xbb,0xc4,0xd1,0xd5,0xdd,
0xe8,0xe9,0xf2,0xff,0xc0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0x79,0x92,0xa2,0xaf,0xb8,0xbf,0xc8,0xd1,0xd9,0xdd,0xe9,
0xf2,0xf9,0xfe,0xf3,0xe5,0xd4,0xbd,0xa7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0x58,0x69,0x7a,0x85,0x8c,0x99,0x9c,0xa4,0xaa,0xb0,0xb7,0xbf,0xc4,0xcc,
0xde,0xe9,0xef,0xe9,0xde,0xd0,0xc0,0xb7,0xa6,0x86,0x5d,0xff,0xff,0xff,0xff,0xff,
0xff,0x58,0x60,0x6a,0x76,0x6e,0x74,0x80,0x92,0xa2,0xb6,0xc0,0xc9,0xd5,0xdd,0xe7,
0xe9,0xe9,0xe8,0xde,0xbd,0xb0,0xaa,0xa6,0x9d,0x8f,0x7d,0x5f,0xff,0xff,0xff,0xff,
0x47,0x4f,0x58,0x50,0x69,0x80,0x93,0x9f,0xaf,0xb7,0xbb,0xc4,0xcf,0xde,0xe4,0xeb,
0xf2,0xf9,0xfe,0xf5,0xe8,0xd0,0xb7,0x99,0x81,0x7b,0x75,0x68,0x50,0xff,0xff,0x37,
0x47,0x55,0x61,0x70,0x80,0x86,0x93,0x9f,0xa9,0xb8,0xbb,0xc8,0xcc,0xdb,0xdd,0xe9,
0xf2,0xf9,0xfe,0xf2,0xe5,0xd4,0xc0,0xb7,0xa3,0x8b,0x70,0x5f,0xff,0xff,0xff,0xff,
0x49,0x58,0x60,0x6e,0x7a,0x7f,0x98,0xa2,0xab,0xb7,0xc4,0xc4,0xd4,0xdd,0xe2,0xe9,
0xf2,0xfa,0xfe,0xf3,0xe2,0xd2,0xc7,0xb4,0xa6,0x91,0x7d,0x6a,0x32,0xff,0xff,0xff,
0x47,0x5d,0x62,0x70,0x7d,0x8a,0x93,0x9f,0xaf,0xb0,0xb8,0xc4,0xd1,0xd5,0xe1,0xe9,
0xf2,0xf9,0xfd,0xf2,0xe5,0xd4,0xc0,0xb4,0xa6,0x8f,0x7d,0x6a,0xff,0xff,0xff,0xff,
0x4c,0x55,0x69,0x72,0x80,0x82,0x9b,0x9f,0xaa,0xb7,0xbf,0xc8,0xcc,0xdd,0xe5,0xe9,
0xf2,0xf9,0xfd,0xf5,0xe2,0xd3,0xc5,0xb4,0xa2,0x91,0x7d,0x6a,0x35,0xff,0xff,0xff,
0x58,0x55,0x67,0x70,0x80,0x82,0x93,0xa2,0xaf,0xaf,0xbd,0xc8,0xcc,0xdb,0xe1,0xe8,
0xf2,0xfa,0xfe,0xf2,0xe2,0xd4,0xc0,0xb8,0xa6,0x8f,0x7d,0x6a,0xff,0xff,0xff,0xff,
0x49,0x5d,0x67,0x69,0x7d,0x86,0x98,0x99,0xa2,0xb6,0xbd,0xc4,0xd1,0xdd,0xe5,0xec,
0xf2,0xf9,0xfa,0xf5,0xe2,0xd2,0xc7,0xaf,0xa7,0x8f,0x7d,0x6a,0x3a,0xff,0xff,0xff,
0x4d,0x5d,0x69,0x69,0x79,0x86,0x8f,0x99,0x89,0x51,0x6b,0xc7,0xd0,0xd5,0xe2,0xe8,
0xf1,0x9e,0x97,0xe1,0xe2,0xd4,0xc0,0xb8,0xa4,0x92,0x81,0x6a,0xff,0xff,0xff,0xff,
0x49,0x1d,0x27,0x76,0x7a,0x86,0x8f,0x78,0x1c,0x21,0x1b,0x0a,0xcc,0xde,0xe2,0xe5,
0x05,0x1b,0x1f,0x0c,0xc1,0xd2,0xc5,0xaf,0x81,0x29,0x4e,0x6a,0x3c,0xff,0xff,0x38,
0x26,0x17,0x0e,0x3f,0x77,0x86,0x9b,0x2b,0x25,0x39,0x2a,0x10,0x89,0xde,0xe5,0x90,
0x18,0x33,0x36,0x21,0x51,0xd4,0xc0,0xb8,0x01,0x17,0x09,0x5e,0xff,0xff,0xff,0xff,
0x22,0x2c,0x1e,0x31,0x80,0x8a,0x94,0x40,0x20,0x33,0x24,0x06,0xb6,0xda,0xdd,0xae,
0x1c,0x2a,0x30,0x1a,0x6b,0xd0,0xc1,0x8c,0x03,0x28,0x1c,0x3f,0x42,0xff,0xff,0xff,
0x23,0x17,0x0e,0x3e,0x80,0x88,0x92,0xa4,0x34,0x14,0x09,0x78,0xd1,0xd8,0xe5,0xef,
0x6c,0x0d,0x11,0x40,0xe2,0xd1,0xc5,0xaf,0x00,0x15,0x06,0x4c,0xff,0xff,0xff,0xff,
0x46,0x07,0x13,0x66,0x6e,0x73,0x80,0x7d,0x8f,0x99,0xa4,0xa9,0xb3,0xc1,0xbf,0xc9,
0xd4,0xe0,0xe0,0xe0,0xcb,0xc5,0xbb,0xaa,0x50,0x01,0x2e,0x6e,0x45,0xff,0xff,0x2f,
0x3d,0x4f,0x58,0x66,0x6e,0x80,0x8c,0x9f,0xab,0xbb,0xc0,0xc9,0xd2,0xdb,0xe5,0xec,
0xf7,0xfa,0xf9,0xe9,0xd4,0xbd,0xab,0x95,0x85,0x79,0x63,0x50,0xff,0xff,0xff,0x3b,
0x49,0x5d,0x66,0x74,0x83,0x82,0x9c,0x9f,0xaa,0xb8,0xbf,0xc4,0xcc,0xde,0xe5,0xe9,
0xf2,0xfa,0xfa,0xf2,0xe2,0xd1,0xbf,0xb4,0xa4,0x8b,0x7d,0x6a,0x4b,0xff,0xff,0xff,
0x58,0x5d,0x60,0x70,0x80,0x82,0x98,0x9f,0xaf,0xb8,0xbb,0xc8,0xcc,0xdd,0xe5,0xe8,
0xf2,0xf9,0xfa,0xf1,0xe1,0xd0,0xc0,0xb6,0xa7,0x8b,0x81,0x68,0xff,0xff,0xff,0xff,
0x3d,0x58,0x5f,0x72,0x7d,0x8a,0x79,0xff,0xaa,0xb8,0xbf,0xc8,0xd4,0xde,0xe5,0xe9,
0xf6,0xfc,0xfe,0xef,0xb4,0xff,0xc0,0xb4,0x9f,0x92,0x77,0x61,0xff,0xff,0xff,0xff,
0xff,0x5d,0x66,0x76,0x80,0x79,0xff,0xff,0xff,0xb7,0xbb,0xc8,0xcc,0xdd,0xdd,0xe8,
0xf8,0xfa,0xfa,0xff,0xff,0xff,0xbb,0xb3,0xa3,0x8d,0x79,0x56,0xff,0xff,0xff,0xff,
0xff,0x55,0x66,0x70,0x77,0xff,0xff,0xff,0xff,0xff,0xbf,0xc8,0xd1,0xd5,0xe8,0xec,
0xf2,0xf9,0xd2,0xff,0xff,0xff,0x83,0xb3,0x9f,0x8d,0x71,0xff,0xff,0xff,0xff,0xff,
0xff,0x47,0x67,0x72,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc8,0xd1,0xdd,0xe5,0xe9,
0xf2,0xff,0xff,0xff,0xff,0xff,0xff,0x95,0xa3,0x8b,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0x5f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xcc,0xde,0xe4,0xe9,
0xc0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x98,0x85,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xde,0xdd,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xbd,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xd0,0x05,0xff,0xfe,0x00,0x00,0x3f,0xf0,0x00,0x00,0x07,0xe0,0x00,
0x00,0x03,0xc0,0x00,0x00,0x01,0x80,0x00,0x00,0x03,0xc0,0x00,0x00,0x01,0xc0,0x00,
0x00,0x03,0xc0,0x00,0x00,0x01,0xc0,0x00,0x00,0x03,0xc0,0x00,0x00,0x01,0xc0,0x00,
0x00,0x03,0xc0,0x00,0x00,0x01,0x80,0x00,0x00,0x03,0xc0,0x00,0x00,0x01,0xc0,0x00,
0x00,0x03,0xc0,0x00,0x00,0x01,0x80,0x00,0x00,0x03,0x80,0x00,0x00,0x01,0xc0,0x00,
0x00,0x03,0xc0,0x40,0x01,0x03,0xe0,0xe0,0x07,0x03,0xe1,0xf0,0x07,0x07,0xe3,0xf8,
0x1f,0x8f,0xf7,0xfc,0x1f,0xcf,0xff,0xfe,0x7f,0xff,0xff,0xff,0x7f,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
};

REGAL_NAMESPACE_END

#endif
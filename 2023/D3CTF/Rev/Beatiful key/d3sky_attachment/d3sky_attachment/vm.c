#include <stdio.h> 
#define __int64 long long

#define __int32 int

#define __int16 short

#define __int8  char

unsigned int decrypt(unsigned __int8 *sbox, unsigned __int16 *input, unsigned int len)
{
  unsigned int result; // eax
  int v4; // [esp+4h] [ebp-10h]
  unsigned int i; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]
  unsigned __int8 v7; // [esp+13h] [ebp-1h]
	
  v6 = 0;
  v4 = 0;
  for ( i = 0; i < len; ++i )
  {
    v6 = (v6 + 1) % 256;
    v4 = (v4 + sbox[v6]) % 256;
    v7 = sbox[v6];
    sbox[v6] = sbox[v4];
    sbox[v4] = v7;
    input[i] ^= sbox[(sbox[v4] + sbox[v6]) % 256];
    result = i + 1;
  }
  //return result;
  //printf("win!\n");
}


unsigned char s_box[] = {0xF7, 0x8A, 0xBA, 0xFE, 0x08, 0x46, 0xEE, 0x6D, 0x1C, 0x76, 
  0xDA, 0xC1, 0x64, 0x3D, 0xE9, 0x11, 0x00, 0x5C, 0x24, 0x22, 
  0x82, 0xFF, 0xB1, 0x28, 0xF0, 0x78, 0x21, 0x3A, 0x16, 0x8D, 
  0xD7, 0x9D, 0xE0, 0x03, 0xA8, 0x2B, 0xFD, 0x36, 0x6C, 0x90, 
  0x0B, 0xC7, 0xA0, 0x27, 0x98, 0x10, 0x65, 0xA9, 0x84, 0x66, 
  0x2C, 0x4A, 0xB3, 0x39, 0xE6, 0xEB, 0xE7, 0x47, 0x9C, 0xDC, 
  0xCC, 0xE1, 0xAF, 0xDE, 0xD3, 0x52, 0x7F, 0x5B, 0x87, 0xB8, 
  0x68, 0x88, 0x6B, 0x7E, 0xD2, 0xC4, 0x12, 0xE3, 0xE8, 0x19, 
  0x42, 0xB2, 0x18, 0x7B, 0x43, 0x95, 0xA3, 0xD9, 0x9A, 0x2A, 
  0xEF, 0x30, 0xDD, 0xAC, 0x4B, 0xCF, 0x71, 0x81, 0xBB, 0xF5, 
  0x1F, 0x89, 0xD1, 0x17, 0x80, 0xB9, 0x2F, 0x25, 0x53, 0x06, 
  0x6F, 0xDF, 0x31, 0xAB, 0x1B, 0x4C, 0xFB, 0xB0, 0x34, 0x6E, 
  0xA4, 0xAA, 0x09, 0x13, 0x97, 0x01, 0x79, 0xD0, 0x58, 0x8B, 
  0xAD, 0x48, 0x91, 0x32, 0x20, 0xD6, 0x67, 0x29, 0x4D, 0x14, 
  0x8F, 0x2E, 0x35, 0xE5, 0x5E, 0x23, 0xAE, 0x8E, 0xA5, 0x45, 
  0x61, 0x0F, 0x72, 0x96, 0xC2, 0xBD, 0xEA, 0x44, 0x02, 0xC9, 
  0xD5, 0x07, 0xCB, 0x56, 0xF8, 0x63, 0x70, 0x1A, 0x6A, 0x7A, 
  0xF4, 0x37, 0x26, 0x93, 0xFC, 0xB7, 0x94, 0xA7, 0xBF, 0xFA, 
  0x0A, 0x55, 0x50, 0x0E, 0x1D, 0xCA, 0xCE, 0xEC, 0x05, 0x2D, 
  0x40, 0xC0, 0x41, 0x38, 0xE2, 0xBC, 0xB5, 0x9B, 0x75, 0x9E, 
  0xCD, 0x04, 0x9F, 0xC8, 0xC6, 0x4E, 0xDB, 0x57, 0x3F, 0x83, 
  0xA2, 0x3E, 0x77, 0x8C, 0x3C, 0xD8, 0xF2, 0x49, 0x62, 0x92, 
  0x85, 0x7C, 0x15, 0xF1, 0xBE, 0xF6, 0x0D, 0xC5, 0xC3, 0x54, 
  0x99, 0xE4, 0x5D, 0x69, 0x0C, 0x74, 0xED, 0x60, 0xB4, 0xF3, 
  0x5A, 0x3B, 0xB6, 0xF9, 0xA6, 0xA1, 0x51, 0x59, 0x4F, 0x1E, 
  0x86, 0x73, 0x33, 0x7D, 0x5F, 0xD4}
;

unsigned __int16 opcode[] = {0x15,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xa16,0xa9c,0xa,0x61,0xda,0x6e,0x8e,0x12,0x65,0xea,0x86,0xd,0xa96,0xa45,0x8d,0x43,0x23,0xf5,0xa4,0x80,0x6d,0x64,0x9f,0xcf,0xaf8,0xa4b,0xf0,0x72,0xbd,0xf,0x4e,0xed,0x92,0x6f,0xae,0x60,0xa4e,0xa3e,0xd1,0x9d,0x5,0x18,0xe7,0x13,0x31,0x9,0x8c,0x17,0xa14,0xa29,0xa0,0xe8,0x1a,0x15,0x1b,0x3a,0xed,0x1f,0xc7,0x3,0xa2c,0xac6,0x78,0x91,0x4e,0x9,0x62,0xc7,0x20,0x5e,0x64,0xf2,0x3,0x52,0x49,0x65,0xff,0xf1,0xe4,0x2f,0x64,0x27,0xe6,0xafb,0xd4,0xb6,0xd,0x51,0x3e,0x42,0x29,0x4d,0xa3,0xdd,0x67,0xaec,0xdd,0x20,0xf2,0xd,0x5f,0x11,0x5d,0x97,0x9e,0x2c,0x20,0xaed,0x9e,0x44,0xb2,0x2,0xea,0x20,0x39,0xf8,0x0,0x11,0x79,0xaca,0xae,0x75,0xab,0x32,0x3,0xd2,0xfc,0x88,0x44,0x5f,0xfc,0xadf,0x64,0x1e,0x4,0x7e,0x24,0x45,0xef,0x2a,0x36,0xd1,0x25,0xae6,0xeb,0x47,0xec,0x81,0x69,0xe1,0x46,0x85,0x11,0xe3,0x2b,0xa9e,0x99,0xd0,0x95,0x32,0xed,0x97,0xcb,0x6e,0xb4,0x3c,0x9,0xa1f,0xa1,0x9c,0x83,0x6d,0x70,0x9,0x78,0xfe,0xa2,0x90,0xd5,0xa3f,0xf9,0xe5,0x15,0xb9,0x63,0x23,0xb6,0x24,0xb4,0xdd,0xf1,0xa56,0x7c,0x70,0xf,0x7,0x5a,0x5e,0x99,0x12,0x28,0xc2,0x95,0xaaa,0xaf,0xb7,0xa3,0x32,0x29,0x86,0xd9,0x8c,0x8f,0xfa,0x9d,0xa5c,0x28,0xb4,0x1c,0xc1,0x13,0x2c,0x23,0x72,0x83,0xa4,0x7e,0xa1e,0x3a,0x48,0x4a,0x7c,0xb1,0x11,0x9,0xce,0xfb,0x45,0xba,0xac8,0xf7,0x1e,0xac,0x55,0x48,0x82,0xb5,0x5d,0xa7,0x5f,0x92,0xa64,0x4f,0x9b,0x22,0x54,0xe,0xfc,0x9,0x8,0xa,0x43,0xd8,0xa60,0xb4,0xbb,0x6d,0x36,0x37,0x2e,0x54,0x9d,0x6b,0x79,0xe2,0xae4,0xa5,0x47,0x94,0x62,0xe8,0x2e,0xe0,0xad,0x9e,0xb2,0x20,0xa44,0x64,0x41,0x11,0xa1,0x60,0x9e,0x2f,0x5b,0x6f,0x0,0x39,0xa87,0x77,0xf6,0xe6,0x86,0x6d,0x3f,0xa1,0x3f,0xc5,0x2f,0x92,0xabf,0x4b,0x25,0xb,0x35,0x6e,0x6b,0xa7,0x58,0xe6,0x55,0xec,0xaaa,0xc,0xd6,0x9e,0x53,0x35,0xba,0x7b,0x36,0x95,0xcd,0xdc,0xa52,0x56,0xec,0x59,0xb3,0x5e,0xa7,0x3d,0xc8,0x90,0xd7,0xf9,0xa5d,0x9,0x3c,0x5f,0xb1,0xa8,0xc5,0xe3,0xd8,0x47,0x97,0xcd,0xab3,0x59,0x24,0xf3,0x7e,0x47,0x22,0x16,0xe4,0x1d,0x52,0x12,0xa05,0x24,0xd2,0x86,0xda,0x96,0xe4,0x4e,0x1b,0x37,0x37,0x69,0xabb,0x21,0x4,0xfd,0x88,0x25,0x4c,0x1c,0xf0,0x14,0xae,0x8b,0xa6e,0xde,0x97,0xfe,0xee,0xe3,0x7d,0xc1,0xc2,0x3c,0xa4,0x64,0xa55,0x88,0x4f,0xf0,0x82,0xc8,0x98,0x5e,0xfb,0x58,0x3c,0x5,0xa77,0x19,0x53,0x6a,0xf9,0xa3,0x29,0x11,0xb5,0xba,0xa7,0xf8,0xac4,0xc4,0x52,0xb3,0x3e,0xc2,0xa1,0xd7,0xe0,0x14,0x18,0xf9,0xaab,0x24,0xd4,0x20,0x80,0x3e,0x40,0x9b,0xd3,0xae,0x8b,0xb1,0xa37,0x53,0xf1,0x62,0x38,0x5d,0x20,0x0,0xc2,0xd8,0xe3,0xe4,0xa73,0xd4,0xe2,0x8,0xfd,0xe6,0xfc,0xad,0x4f,0x87,0xa3,0xd4,0xa47,0x24,0xa2,0x31,0x8c,0x4,0x61,0x81,0x1b,0x3f,0x8c,0x10,0xa14,0x99,0xff,0xa9,0xad,0xfc,0x8,0x34,0x3d,0xb0,0x7b,0x20,0xa63,0x2d,0xc8,0xd0,0x29,0x4e,0x2e,0x78,0xe9,0xdf,0xda,0xf8,0xa4a,0xa2b,0xa10,0xda,0x41,0xa95,0x12,0xa1a,0xa98,0xa8,0x24,0xae7,0x66,0x4d,0x7,0xe0,0xac1,0xa66,0xe7,0x48,0xab3,0xe0,0xa7f,0xa6d,0x88,0xe7,0xaea,0x65,0xc7,0xe1,0x19,0x2,0xb9,0x75,0xdf,0x35,0x25,0x3,0x3b,0xd4,0xf6,0x28,0x91,0xe8,0xc4,0x59,0xae6,0xad2,0x64,0xa0,0x2e,0x60,0xb6,0xd4,0x6c,0xee,0xad3,0xab,0xcf,0xbb,0x21,0xafc,0xa0c,0x31,0x0,0xa32,0x51,0xac3,0xa15,0xc6,0x23,0xab2,0xce,0x32,0xa7,0x1b,0xaec,0xa9c,0x2f,0x75,0xacc,0x8b,0xa4f,0xacd,0x5,0xaf,0xab1,0x55,0x80,0xc0,0x9d,0x9c,0x34,0x90,0x92,0xec,0x2,0x32,0x15,0xdf,0x2e,0x9b,0x26,0xb9,0x70,0x1,0xaeb,0xad8,0x6b,0x18,0x89,0x86,0xe5,0x16,0xc2,0xe0,0xa26,0x8d,0x64,0xb,0xfc,0xa05,0xa52,0x1a,0x8c,0xa26,0x17,0xa3d,0xa17,0x3c,0x11,0xaec,0xd4,0x14,0xa2,0x5d,0xaeb,0xa93,0xcc,0xa6,0xa1a,0x73,0xad2,0xaaf,0x77,0x12,0xa36,0x77,0x47,0xcd,0xd5,0xaf,0x36,0xf2,0xce,0xb2,0x23,0x3a,0xb3,0xf3,0x45,0x3,0xf4,0xa7,0xee,0xcf,0xa3c,0xaa7,0x12,0xa9,0x61,0x5f,0xa7,0x90,0x46,0xdb,0xa41,0x34,0xc4,0x34,0x38,0xa52,0xa13,0x16,0xad,0xab7,0x21,0xa0e,0xa24,0x6c,0x18,0xae5,0x92,0x61,0xcf,0xab,0xac0,0xaa3,0x71,0xd9,0xa13,0xdb,0xa3c,0xa8b,0x12,0x19,0xa2a,0x2,0xc3,0x96,0xed,0x6e,0x24,0xfa,0xc4,0x85,0x75,0xfe,0x50,0x7,0xe8,0xa,0xe6,0x41,0x82,0x12,0xa83,0xad9,0x7c,0x5e,0x4e,0x15,0x4f,0x1b,0x5e,0xc3,0xafc,0x30,0xfb,0x76,0x58,0xac3,0xa3a,0x33,0x44,0xa1b,0x9c,0xab9,0xa7c,0x8,0x4b,0xa17,0x70,0x82,0xbc,0xf3,0xa01,0xaef,0xc5,0x62,0xa9f,0x2a,0xa09,0xacd,0x3f,0x86,0xa8b,0xc5,0x87,0x45,0xea,0xde,0x14,0xbd,0xfe,0xf8,0xc6,0xbb,0xd9,0x9e,0x6a,0x83,0x13,0x63,0x6a,0xaf,0xad0,0xac0,0xc9,0xf6,0x2f,0x62,0x88,0xdf,0xe2,0x90,0xac4,0x69,0x95,0x50,0x82,0xa6a,0xab1,0xf1,0x3e,0xa22,0x2a,0xa1f,0xa66,0x7b,0x89,0xab8,0x30,0x4b,0xbb,0x31,0xaf1,0xa8e,0xdc,0xd4,0xab2,0xf3,0xaf0,0xa1d,0x8c,0xca,0xa57,0x87,0xc3,0x9c,0xfb,0x7e,0x53,0xb6,0x33,0xba,0xf2,0xbb,0x9,0x54,0xa1,0x72,0x88,0xa4,0xd3,0x70,0xacc,0xafb,0x4f,0x2e,0x8b,0x31,0x40,0xe,0xb8,0x9a,0xa44,0xac,0xff,0xf1,0xf5,0xa7b,0xa95,0x77,0x57,0xa3d,0x92,0xa0a,0xa6e,0x17,0xe4,0xabd,0x75,0x5d,0x8d,0x23,0xa84,0xa76,0xa1,0xf6,0xa03,0x3d,0xab1,0xa87,0x55,0x37,0xa0f,0x93,0x1a,0x1a,0x2,0xf1,0x18,0x5,0x9a,0x8a,0x13,0x1a,0x87,0x1b,0x45,0x7e,0x23,0x77,0x8b,0x94,0xaf2,0xabe,0xbf,0xd5,0x6c,0x5b,0x19,0x75,0x1c,0xea,0xa7c,0x2,0x75,0xf5,0xcb,0xa25,0xac6,0x5c,0xba,0xa80,0xc6,0xada,0xa40,0x59,0x94,0xa08,0x53,0x98,0xfd,0x96,0xab8,0xada,0x23,0x60,0xa6a,0xcb,0xab2,0xa25,0x3b,0x4f,0xa4d,0xb,0x2a,0xd1,0xe0,0xaf,0x6d,0xb3,0xcb,0x72,0xbe,0x7,0xac,0xae,0xb,0x39,0x26,0x5,0xa,0xb4,0xbd9,0xbec,0x61,0x24,0xe0,0x7b,0x31,0x4b,0x5e,0x22,0xb8a,0xad,0xb,0xc,0x8d,0xa23,0xa22,0xb0,0xf5,0xadd,0x44,0xadd,0xadd,0x6f,0xf3,0xa22,0x9a,0xf5,0xc,0x30,0xade,0xade,0x3,0xf4,0xa21,0x1b,0xa21,0xadf,0xaa,0xc,0xade,0x42,0xf4,0xf2,0x5c,0xef,0x11,0x7e,0xb,0x12,0x93,0xed,0xec,0x75,0xf2,0x11,0x39,0xb,0xc,0xc5,0xbfe,0xbff,0x17,0xf5,0x12,0xa0,0x12,0x12,0xe4,0xf3,0xbff,0xe6,0xf5,0xc,0xff,0xadd,0xadd,0xe7,0xf4,0xa20,0xef,0xa20,0xade,0x7e,0xc,0xadd,0x81,0xf4,0xf2,0xe5,0xa21,0xadf,0xf3,0xb,0xae0,0xf3,0xa1f,0xa1e,0x4f,0xf2,0xadf,0xbb,0xb,0xc,0x9a,0xee,0xef,0x38,0xf5,0x12,0xc,0x12,0x12,0xcb,0xf3,0xef,0xe5,0xf5,0xc,0x32,0xb02,0xb02,0x89,0xf4,0xec,0x88,0xec,0x12,0x86,0xc,0xb02,0x4a,0xf4,0xf2,0xf2,0xa20,0xade,0xc7,0xb,0xadf,0x1c,0xa20,0xa21,0x88,0xf2,0xade,0x2a,0xb,0xc,0xc9,0xa1f,0xa1e,0x7f,0xf5,0xae1,0xbc,0xae1,0xae1,0x75,0xf3,0xa1e,0xe9,0xf5,0xc,0x81,0x11,0x11,0xe2,0xf4,0xec,0xcd,0xec,0x12,0xb3,0xc,0x11,0xba,0xf4,0xf2,0xba,0xbfd,0xb03,0xff,0xb,0x12,0x34,0xed,0xec,0x7a,0xf2,0xb03,0x42,0xb,0xc,0xe3,0xa20,0xa21,0x97,0xf5,0xae0,0xd1,0xae0,0xae0,0xd6,0xf3,0xa21,0xca,0xf5,0xc,0xc,0xae1,0xae1,0xb1,0xf4,0xa1c,0xd,0xa1c,0xae2,0x96,0xc,0xae1,0x20,0xf4,0xf2,0x3c,0xef,0x11,0x3b,0xb,0x12,0x3b,0xed,0xec,0x3e,0xf2,0x11,0x3,0xb,0xc,0xf8,0xbfb,0xbfa,0xe5,0xf5,0x12,0xdc,0x12,0x12,0xc1,0xf3,0xbfa,0x83,0xf5,0xc,0x21,0xae0,0xae0,0xdf,0xf4,0xa1f,0xae,0xa1f,0xae1,0x8e,0xc,0xae0,0x8e,0xf4,0xf2,0xd9,0xa1c,0xae2,0x1e,0xb,0xae3,0x6a,0xa1c,0xa1d,0xe,0xc,0xae2,0xb1,0xf4,0xf2,0x55,0xef,0x11,0xf4,0xb,0x12,0xa3,0xed,0xec,0xa6,0xf2,0x11,0xbb,0xb,0xc,0xd0,0xbfa,0xbfb,0x86,0xf5,0x12,0xff,0x12,0x12,0xf8,0xf3,0xbfb,0x7a,0xf5,0xc,0x6b,0xae1,0xae1,0x73,0xf4,0xa1c,0x1,0xa1c,0xae2,0x3c,0xc,0xae1,0x58,0xf4,0xf2,0x47,0xa1d,0xae3,0x27,0xb,0xae4,0xcb,0xa1b,0xa1a,0xce,0xf2,0xae3,0x1d,0xb,0xc,0x4c,0xee,0xef,0xf5,0xf5,0x12,0xa,0x12,0x12,0xc,0xf3,0xef,0xd2,0xf5,0xc,0xf2,0xb06,0xb06,0xeb,0xf4,0xec,0xe9,0xec,0x12,0x45,0xc,0xb06,0xa2,0xf4,0xf2,0x25,0xa1c,0xae2,0x94,0xb,0xae3,0xd,0xa1c,0xa1d,0xe,0xc,0xae2,0x9,0xf4,0xf2,0x13,0xae4,0xae4,0xe,0xf4,0xa1b,0x9,0xae5,0xae5,0x9,0xf3,0xa1a,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb07,0xb07,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbf9,0xe,0xb,0xc,0x16,0xa1c,0xa1d,0x9,0xb,0xae4,0xe,0xa1b,0xa1a,0xe,0xc,0xae3,0x9,0xf4,0xf2,0x13,0xae5,0xae5,0xe,0xf4,0xa18,0x9,0xae6,0xae6,0x9,0xf3,0xa1b,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb08,0xb08,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbf6,0xe,0xb,0xc,0x16,0xa1b,0xa1a,0x9,0xb,0xae5,0xe,0xa1a,0xa1b,0xe,0xc,0xae4,0x9,0xf4,0xf2,0x13,0xae6,0xae6,0xe,0xf4,0xa19,0x9,0xae7,0xae7,0x9,0xf3,0xa18,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb09,0xb09,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbf7,0xe,0xb,0xc,0x16,0xa1a,0xa1b,0x9,0xb,0xae6,0xe,0xa19,0xa18,0xe,0xc,0xae5,0x9,0xf4,0xf2,0x13,0xae7,0xae7,0xe,0xf4,0xa16,0x9,0xae8,0xae8,0x9,0xf3,0xa19,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb0a,0xb0a,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbf4,0xe,0xb,0xc,0x16,0xa19,0xa18,0x9,0xb,0xae7,0xe,0xa18,0xa19,0xe,0xc,0xae6,0x9,0xf4,0xf2,0x13,0xae8,0xae8,0xe,0xf4,0xa17,0x9,0xae9,0xae9,0x9,0xf3,0xa16,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb0b,0xb0b,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbf5,0xe,0xb,0xc,0x16,0xa18,0xa19,0x9,0xb,0xae8,0xe,0xa17,0xa16,0xe,0xc,0xae7,0x9,0xf4,0xf2,0x13,0xae9,0xae9,0xe,0xf4,0xa14,0x9,0xaea,0xaea,0x9,0xf3,0xa17,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb0c,0xb0c,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbf2,0xe,0xb,0xc,0x16,0xa17,0xa16,0x9,0xb,0xae9,0xe,0xa16,0xa17,0xe,0xc,0xae8,0x9,0xf4,0xf2,0x13,0xaea,0xaea,0xe,0xf4,0xa15,0x9,0xaeb,0xaeb,0x9,0xf3,0xa14,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb0d,0xb0d,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbf3,0xe,0xb,0xc,0x16,0xa16,0xa17,0x9,0xb,0xaea,0xe,0xa15,0xa14,0xe,0xc,0xae9,0x9,0xf4,0xf2,0x13,0xaeb,0xaeb,0xe,0xf4,0xa12,0x9,0xaec,0xaec,0x9,0xf3,0xa15,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb0e,0xb0e,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbf0,0xe,0xb,0xc,0x16,0xa15,0xa14,0x9,0xb,0xaeb,0xe,0xa14,0xa15,0xe,0xc,0xaea,0x9,0xf4,0xf2,0x13,0xaec,0xaec,0xe,0xf4,0xa13,0x9,0xaed,0xaed,0x9,0xf3,0xa12,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb0f,0xb0f,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbf1,0xe,0xb,0xc,0x16,0xa14,0xa15,0x9,0xb,0xaec,0xe,0xa13,0xa12,0xe,0xc,0xaeb,0x9,0xf4,0xf2,0x13,0xaed,0xaed,0xe,0xf4,0xa10,0x9,0xaee,0xaee,0x9,0xf3,0xa13,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb10,0xb10,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbee,0xe,0xb,0xc,0x16,0xa13,0xa12,0x9,0xb,0xaed,0xe,0xa12,0xa13,0xe,0xc,0xaec,0x9,0xf4,0xf2,0x13,0xaee,0xaee,0xe,0xf4,0xa11,0x9,0xaef,0xaef,0x9,0xf3,0xa10,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb11,0xb11,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbef,0xe,0xb,0xc,0x16,0xa12,0xa13,0x9,0xb,0xaee,0xe,0xa11,0xa10,0xe,0xc,0xaed,0x9,0xf4,0xf2,0x13,0xaef,0xaef,0xe,0xf4,0xa0e,0x9,0xaf0,0xaf0,0x9,0xf3,0xa11,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb12,0xb12,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbec,0xe,0xb,0xc,0x16,0xa11,0xa10,0x9,0xb,0xaef,0xe,0xa10,0xa11,0xe,0xc,0xaee,0x9,0xf4,0xf2,0x13,0xaf0,0xaf0,0xe,0xf4,0xa0f,0x9,0xaf1,0xaf1,0x9,0xf3,0xa0e,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb13,0xb13,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbed,0xe,0xb,0xc,0x16,0xa10,0xa11,0x9,0xb,0xaf0,0xe,0xa0f,0xa0e,0xe,0xc,0xaef,0x9,0xf4,0xf2,0x13,0xaf1,0xaf1,0xe,0xf4,0xa0c,0x9,0xaf2,0xaf2,0x9,0xf3,0xa0f,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb14,0xb14,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbea,0xe,0xb,0xc,0x16,0xa0f,0xa0e,0x9,0xb,0xaf1,0xe,0xa0e,0xa0f,0xe,0xc,0xaf0,0x9,0xf4,0xf2,0x13,0xaf2,0xaf2,0xe,0xf4,0xa0d,0x9,0xaf3,0xaf3,0x9,0xf3,0xa0c,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb15,0xb15,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbeb,0xe,0xb,0xc,0x16,0xa0e,0xa0f,0x9,0xb,0xaf2,0xe,0xa0d,0xa0c,0xe,0xc,0xaf1,0x9,0xf4,0xf2,0x13,0xaf3,0xaf3,0xe,0xf4,0xa0a,0x9,0xaf4,0xaf4,0x9,0xf3,0xa0d,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb16,0xb16,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbe8,0xe,0xb,0xc,0x16,0xa0d,0xa0c,0x9,0xb,0xaf3,0xe,0xa0c,0xa0d,0xe,0xc,0xaf2,0x9,0xf4,0xf2,0x13,0xaf4,0xaf4,0xe,0xf4,0xa0b,0x9,0xaf5,0xaf5,0x9,0xf3,0xa0a,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb17,0xb17,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbe9,0xe,0xb,0xc,0x16,0xa0c,0xa0d,0x9,0xb,0xaf4,0xe,0xa0b,0xa0a,0xe,0xc,0xaf3,0x9,0xf4,0xf2,0x13,0xaf5,0xaf5,0xe,0xf4,0xa08,0x9,0xaf6,0xaf6,0x9,0xf3,0xa0b,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb18,0xb18,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbe6,0xe,0xb,0xc,0x16,0xa0b,0xa0a,0x9,0xb,0xaf5,0xe,0xa0a,0xa0b,0xe,0xc,0xaf4,0x9,0xf4,0xf2,0x13,0xaf6,0xaf6,0xe,0xf4,0xa09,0x9,0xaf7,0xaf7,0x9,0xf3,0xa08,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb19,0xb19,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbe7,0xe,0xb,0xc,0x16,0xa0a,0xa0b,0x9,0xb,0xaf6,0xe,0xa09,0xa08,0xe,0xc,0xaf5,0x9,0xf4,0xf2,0x13,0xaf7,0xaf7,0xe,0xf4,0xa06,0x9,0xaf8,0xaf8,0x9,0xf3,0xa09,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb1a,0xb1a,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbe4,0xe,0xb,0xc,0x16,0xa09,0xa08,0x9,0xb,0xaf7,0xe,0xa08,0xa09,0xe,0xc,0xaf6,0x9,0xf4,0xf2,0x13,0xaf8,0xaf8,0xe,0xf4,0xa2a,0x9,0xad4,0xad4,0x9,0xf3,0xa06,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb1b,0xb1b,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbe5,0xe,0xb,0xc,0x16,0xa08,0xa09,0x9,0xb,0xaf8,0xe,0xa07,0xa06,0xe,0xc,0xaf7,0x9,0xf4,0xf2,0x13,0xad4,0xad4,0xe,0xf4,0xa2b,0x9,0xad5,0xad5,0x9,0xf3,0xa2a,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb1c,0xb1c,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbe2,0xe,0xb,0xc,0x16,0xa07,0xa06,0x9,0xb,0xad4,0xe,0xa2b,0xa2a,0xe,0xc,0xaf8,0x9,0xf4,0xf2,0x13,0xad5,0xad5,0xe,0xf4,0xa28,0x9,0xad6,0xad6,0x9,0xf3,0xa2b,0xe,0xb,0xc,0x17,0xee,0xef,0x9,0xb,0x12,0xe,0xed,0xec,0xe,0xc,0x11,0x9,0xf4,0xf2,0x10,0xb1d,0xb1d,0xe,0xf4,0xec,0x9,0x12,0x12,0x9,0xf3,0xbe3,0xe,0xb,0xc,0x16,0xf5,0xf4,0x2,0x0,0x0,0x0,0x0,0x0,0x0,0x49,0x6e,0x70,0x75,0x74,0x3a,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x24,0xb,0x6d,0xf,0x3,0x32,0x42,0x1d,0x2b,0x43,0x78,0x43,0x73,0x30,0x2b,0x4e,0x63,0x48,0x77,0x2e,0x32,0x39,0x1a,0x12,0x71,0x7a,0x42,0x17,0x45,0x72,0x56,0xc,0x5c,0x4a,0x62,0x53,0x33,0x0,}; 
int main(int argc, char *argv[])
{
	int ind = 0;
	 int len; // [esp+0h] [ebp-24h]
  int v5; // [esp+Ch] [ebp-18h]
  unsigned __int16 v6; // [esp+14h] [ebp-10h]
  unsigned __int16 v7; // [esp+18h] [ebp-Ch]
  unsigned __int16 v8; // [esp+1Ch] [ebp-8h]
  unsigned __int16 offset; // [esp+20h] [ebp-4h]
	char *cin="EZToj<6c[LiU3wRepl7H[SnTPpf7[H3elli5zDXU";
  v5 = 0;
  puts("Welcome to D^3CTF~");
  //printf("cin == %s\n",argv[1]);
  //
  while ( opcode[0] != 0xFFFF )
  {
    if ( opcode[2] == 1 )
    {
      opcode[2] = 0;
      printf("%c",opcode[3]);// printf
    }
    if ( opcode[7] == 1 )
    {
      opcode[7] = 0;
      //scanf("%c", &opcode[8]);               // scanf
      opcode[8] = (char )cin[v5];
      //opcode[8] = (char )argv[1][v5];
      //printf("opcode[8] == %c\n",argv[1][v5]);
      
      len = v5++;
      if ( len == 37 && opcode[8] != '~' )
      {
        puts("Wrong! -- len");
        printf("%d",ind);	
        return 0;
      }
    }
    if ( opcode[19] )
    {
      puts("Wrong! -- check");
      printf("ind == %d",ind);
      return 0;
    }
    ind += 1;
    offset = opcode[0];
    decrypt(&s_box, &opcode[offset], 3);
    v7 = opcode[offset];
    v8 = opcode[offset+1];
    v6 = opcode[offset+2];
    //printf("%x\n",v7);
    opcode[0] = offset + 3;
    decrypt(&s_box, &opcode[offset], 3);
    opcode[v6] = ~(opcode[v7] & opcode[v8]);
    if(1){
		printf("opcode[%d] = 0x%x v7 = %d v8=%d opcode[v7] =0x%x ,opcode[v8] =0x%x  \n",v6,opcode[v6],v7,v8,opcode[v7],opcode[v8]);
		;
		}
  }
  puts("Right! Your flag is antd3ctf{your input}");
  return 0;
}

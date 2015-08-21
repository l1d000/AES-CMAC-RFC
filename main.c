/****************************************************************/
/* AES-CMAC with AES-128 bit                                    */
/* CMAC     Algorithm described in SP800-38B                    */
/* Author: Junhyuk Song (junhyuk.song@samsung.com)              */
/*         Jicheol Lee  (jicheol.lee@samsung.com)               */
/****************************************************************/

#include <stdio.h>
#include <string.h>

#include "cmac.h"

int main() {
	//unsigned char L[BLOCK_SIZE], K1[BLOCK_SIZE], K2[BLOCK_SIZE];
	unsigned char T[BLOCK_SIZE];
	const unsigned char T64[BLOCK_SIZE] = { 0x51, 0xf0, 0xbe, 0xbf, 0x7e, 0x3b, 0x9d,
			0x92, 0xfc, 0x49, 0x74, 0x17, 0x79, 0x36, 0x3c, 0xfe };
	const unsigned char M[64] = { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96,
			0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a, 0xae, 0x2d, 0x8a,
			0x57, 0x1e, 0x03, 0xac, 0x9c, 0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf,
			0x8e, 0x51, 0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11, 0xe5,
			0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef, 0xf6, 0x9f, 0x24, 0x45,
			0xdf, 0x4f, 0x9b, 0x17, 0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37,
			0x10 };
	const unsigned char key[BLOCK_SIZE] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2,
			0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };

	const unsigned char key2[BLOCK_SIZE] = "password\0\0\0\0\0\0\0\0";
	const unsigned char M2[] = "1234567890;09876543";


	printf("--------------------------------------------------\n");
	printf("K              ");
	print128(key);
	printf("\n");

	/*
	 printf("\nSubkey Generation\n"); //TODO: restore
	 //AES_128(key, const_Zero, L);
	 printf("AES_128(key,0) ");
	 print128(L);
	 printf("\n");
	 generate_subkey(key, K1, K2);
	 printf("K1             ");
	 print128(K1);
	 printf("\n");
	 printf("K2             ");
	 print128(K2);
	 printf("\n");
	 */

	printf("\nExample 1: len = 0\n");
	printf("M              ");
	printf("<empty string>\n");

	AES_CMAC(key, M, 0, T);
	printf("AES_CMAC       ");
	print128(T);
	printf("\n");

	printf("\nExample 2: len = 16\n");
	printf("M              ");
	print_hex("                ", M, 16);
	AES_CMAC(key, M, 16, T);
	printf("AES_CMAC       ");
	print128(T);
	printf("\n");
	printf("\nExample 3: len = 40\n");
	printf("M              ");
	print_hex("               ", M, 40);
	AES_CMAC(key, M, 40, T);
	printf("AES_CMAC       ");
	print128(T);
	printf("\n");

	printf("\nExample 4: len = 64\n");
	printf("M              ");
	print_hex("               ", M, 64);
	AES_CMAC(key, M, 64, T);
	printf("AES_CMAC       ");
	print128(T);
	printf("\n");

	printf("AES_CMAC_CHECK: %d\n", AES_CMAC_CHECK(key, M, 64, T64));
	AES_CMAC(key2, M2, sizeof(M2) - 1, T);
	printf("M2sz:%d\n", (int)sizeof(M2) - 1);
	printf("AES_CMAC       ");
	print128(T);
	printf("\n");
	printf("--------------------------------------------------\n");

	return 0;
}

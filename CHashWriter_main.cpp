#include <stdio.h>
#include <string.h>
#include "CHashWriter.hpp"

int main()
{
	unsigned char ibuf[] = "hello world";

	unsigned char digest1[SHA256_DIGEST_LENGTH] = {0};
	unsigned char digest2[SHA256_DIGEST_LENGTH] = {0};

	unsigned char digest_tmp[SHA256_DIGEST_LENGTH] = {0};
	unsigned char digest3[SHA256_DIGEST_LENGTH] = {0};

	/*
	 * Calc sha256 twice by SHA256_Final() and then SHA256()
	 */
	CHashWriter chw1(0, 0);

	chw1.write(ibuf, strlen((const char *)ibuf));
	chw1.GetHash(digest1);

	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
		printf("%02x", digest1[i]);
	printf("\n");

	/*
	 * Calc sha256 twice by SHA256_Final() and then SHA256_Final()
	 */
	CHashWriter chw2(0, 0);

	chw2.write(ibuf, strlen((const char *)ibuf));
	chw2.GetHash_other(digest2);

	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
		printf("%02x", digest2[i]);
	printf("\n");

	/*
	 * Calc sha256 twice by SHA256() and then SHA256()
	 */
	SHA256(ibuf, strlen((const char *)ibuf), digest_tmp);
	SHA256(digest_tmp, SHA256_DIGEST_LENGTH, digest3);

	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
		printf("%02x", digest3[i]);
	printf("\n");

	return 0;
}


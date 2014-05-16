#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
	unsigned char digest1[SHA256_DIGEST_LENGTH];
	unsigned char digest2[SHA256_DIGEST_LENGTH];
	unsigned char ibuf[] = "hello world";
	int i;

	/*
	 * Calc SHA256 first time.
	 */
	if (!SHA256(ibuf, strlen(ibuf), digest1)) {
		printf("%s: SHA256 failed\n", __func__);
		return 1;
	}

	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
		printf("%02x", digest1[i]);
	printf("\n");

	/*
	 * Calc SHA256 second time.
	 */
	SHA256(digest1, SHA256_DIGEST_LENGTH, digest2);

	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
		printf("%02x", digest2[i]);
	printf("\n");

	/*
	 * Note: 'strlen(digest)' = 33, hence, don't use it.
	 */
	printf("SHA256_DIGEST_LENGTH = %d\n", SHA256_DIGEST_LENGTH);
	printf("strlen(digest1) = %lu\n", strlen(digest1));
	printf("strlen(digest2) = %lu\n", strlen(digest2));

	return 0;
}


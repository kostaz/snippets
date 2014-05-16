#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
	unsigned char digest[SHA256_DIGEST_LENGTH];
	unsigned char ibuf[] = "hello world";
	unsigned char obuf[SHA256_DIGEST_LENGTH * 2 + 1];
	int i;

	if (!SHA256(ibuf, strlen(ibuf), digest)) {
		printf("%s: SHA256 failed\n", __func__);
		return 1;
	}

	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
		sprintf(&obuf[i * 2], "%02x", digest[i]);
	printf("SHA256 digest: 0x%s\n", obuf);

	return 0;
}


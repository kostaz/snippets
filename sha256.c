#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
	unsigned char digest[SHA256_DIGEST_LENGTH];
	unsigned char ibuf[] = "hello world";
	int i;

	if (!SHA256(ibuf, strlen(ibuf), digest)) {
		printf("%s: SHA256 failed\n", __func__);
		return 1;
	}

	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
		printf("%02x", digest[i]);

	return 0;
}


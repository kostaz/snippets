#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
	SHA256_CTX ctx;
	unsigned char digest[SHA256_DIGEST_LENGTH] = {0};
	unsigned char ibuf[] = "hello world";
	int i;

	SHA256_Init(&ctx);
	SHA256_Update(&ctx, ibuf, strlen(ibuf));
	SHA256_Final(digest, &ctx);

	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
		printf("%02x", digest[i]);

	return 0;
}


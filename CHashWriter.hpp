#include <openssl/sha.h>

class CHashWriter
{
private:
	SHA256_CTX ctx;

public:
	int nType;
	int nVersion;

	void Init() {
		SHA256_Init(&ctx);
	}

	CHashWriter(int nTypeIn, int nVersionIn) : nType(nTypeIn), nVersion(nVersionIn) {
		Init();
	}

	CHashWriter& write(const unsigned char *pch, size_t size) {
		SHA256_Update(&ctx, pch, size);
		return *this;
	}

	void GetHash_other(unsigned char *hash) {
		unsigned char hash_tmp[SHA256_DIGEST_LENGTH] = {0};
		SHA256_Final(hash_tmp, &ctx);

		SHA256_CTX ctx_tmp;
		SHA256_Init(&ctx_tmp);
		SHA256_Update(&ctx_tmp, hash_tmp, sizeof(hash_tmp));
		SHA256_Final(hash, &ctx_tmp);
	}

	void GetHash(unsigned char *hash) {
		unsigned char hash_tmp[SHA256_DIGEST_LENGTH] = {0};
		SHA256_Final(hash_tmp, &ctx);
		SHA256(hash_tmp, SHA256_DIGEST_LENGTH, hash);
	}
};


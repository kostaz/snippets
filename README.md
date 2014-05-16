
sha1.c
gcc sha1.c -o sha1 -lcrypto

sha256.c
gcc sha256.c -o sha256 -lcrypto

sha256_ctx.c
gcc sha256_ctx.c -o sha256_ctx -lcrypto

sha256_twice.c
gcc sha256_twice.c -o sha256_twice -lcrypto

Bash
echo "ddd" | openssl sha
echo "ddd" | openssl sha1
echo "ddd" | openssl sha256
echo "ddd" | openssl dgst -sha256
echo "ddd" | openssl dgst -sha384
echo "ddd" | openssl dgst -sha512


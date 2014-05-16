
sha1.c
gcc sha1.c -o sha1 -lcrypto

sha256.c
gcc sha256.c -o sha256 -lcrypto

Bash
echo "ddd" | openssl sha
echo "ddd" | openssl sha1
echo "ddd" | openssl sha256
echo "ddd" | openssl dgst -sha256
echo "ddd" | openssl dgst -sha384
echo "ddd" | openssl dgst -sha512



sha1.c
gcc sha1.c -o sha1 -lcrypto

sha256.c
gcc sha256.c -o sha256 -lcrypto

sha256_ctx.c
gcc sha256_ctx.c -o sha256_ctx -lcrypto

sha256_twice.c
gcc sha256_twice.c -o sha256_twice -lcrypto

CHashWriter.cpp
g++ CHashWriter_main.cpp CHashWriter.cpp -o CHashWriter -lcrypto

uint256.c
g++ uint256/main.cpp -o uint256/uint256

boost_threads
http://antonym.org/2009/05/threading-with-boost---part-i-creating-threads.html
g++ boost_thread/main.cpp -o boost_thread/main -lboost_thread -lboost_system

boost_thread_group
http://www.boost.org/doc/libs/1_55_0/libs/thread/example/thread_group.cpp
g++ boost_thread_group/main.cpp -o boost_thread_group/main -lboost_thread -lboost_system


Bash
echo "ddd" | openssl sha
echo "ddd" | openssl sha1
echo "ddd" | openssl sha256
echo "ddd" | openssl dgst -sha256
echo "ddd" | openssl dgst -sha384
echo "ddd" | openssl dgst -sha512



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

boost/regex.cpp
http://www.boost.org/doc/libs/1_31_0/libs/regex/example/snippets/credit_card_example.cpp
g++ boost/regex.cpp -o boost/regex -lboost_regex

boost/filesystem_tut3.cpp
http://www.boost.org/doc/libs/1_55_0b1/libs/filesystem/doc/tutorial.html
g++ boost/filesystem_tut3.cpp -o boost/filesystem_tut3 -lboost_system -lboost_filesystem

boost/filesystem_tut4.cpp
g++ boost/filesystem_tut4.cpp -o boost/filesystem_tut4 -lboost_system -lboost_filesystem

openssl/bignum.cpp
http://stackoverflow.com/questions/16437475/openssl-bn-ctx-usage
http://etutorials.org/Programming/secure+programming/Chapter+7.+Public+Key+Cryptography/7.4+Manipulating+Big+Numbers/
g++ openssl/bignum.cpp -o openssl/bignum -lcrypto

libdb/main.cpp
http://www.stanford.edu/class/cs276a/projects/docs/berkeleydb/ref/simple_tut/open.html
g++ libdb/main.cpp -o libdb/main -ldb

Bash
echo "ddd" | openssl sha
echo "ddd" | openssl sha1
echo "ddd" | openssl sha256
echo "ddd" | openssl dgst -sha256
echo "ddd" | openssl dgst -sha384
echo "ddd" | openssl dgst -sha512


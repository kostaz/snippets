#include <string.h>
#include <iostream>
#include <string>
#include <openssl/bn.h>

using namespace std;

int main()
{
#if 0
	BIGNUM bn;

	BN_init(&bn);

	BN_zero(&bn);
	cout << "0x" << hex << BN_bn2hex(&bn) << endl;

	BN_one(&bn);
	cout << "0x" << hex << BN_bn2hex(&bn) << endl;
	cout << "BN_bn2hex() = " << BN_bn2hex(&bn) << endl;
	cout << "BN_bn2dec() = " << BN_bn2dec(&bn) << endl;
	cout << endl;

	// string bin = "0";
	// BN_bin2bn((const unsigned char*)bin.c_str(), bin.length(), &bn);
#endif

	//
	// Test hex2bn
	// int BN_hex2bn(BIGNUM **a, const char *str);
	string hex = "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";
	BIGNUM *pbn = BN_new();
	int ret = BN_hex2bn(&pbn, hex.c_str());
	cout << "BN_hex2bn() returend : " << ret << endl;
	cout << "BN_bn2hex() = 0x" << BN_bn2hex(pbn) << endl;
	cout << "BN_bn2dec() =   " << BN_bn2dec(pbn) << endl;

#if 0
	BIGNUM *bn_ret = BN_bin2bn((unsigned char*)"0", 1, &bn);
	cout << "bn_ret = " << bn_ret << endl;

	cout << "BN_bn2hex() = " << BN_bn2hex(bn_ret) << endl;
	cout << "BN_bn2dec() = " << BN_bn2dec(bn_ret) << endl;
#endif

	return 0;
}


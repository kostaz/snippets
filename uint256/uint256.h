#include <assert.h>
#include <stdexcept>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

template<unsigned int BITS>
class base_uint
{
private:
	enum {WIDTH = BITS/32};
	uint32_t pn[WIDTH];

public:
	base_uint() {
		for (int i = 0; i < WIDTH; i++)
			pn[i] = 0;
	}

	base_uint(const base_uint& b) {
		for (int i = 0; i < WIDTH; i++)
			pn[i] = b.pn[i];
	}

	base_uint& operator=(const base_uint& b) {
		for (int i = 0; i < WIDTH; i++)
			pn[i] = b.pn[i];
		return *this;
	}

	base_uint(uint64_t b) {
		pn[0] = (uint32_t)b;
		pn[1] = (uint32_t)(b >> 32);
		for (int i = 2; i < WIDTH; i++)
			pn[i] = 0;
	}

	explicit base_uint(const std::string& str) {
		// SetHex(str);
	}

	explicit base_uint(const std::vector<unsigned char>& vch) {
		if (vch.size() != sizeof(pn))
			throw std::runtime_error();
		memcpy(pn, &vch[0], sizeof(pn));
	}

	bool operator!() const {
		for (int i = 0; i < WIDTH; i++) {
			if (pn[i] != 0)
				return false;
		}
		return true;
	}

	const base_uint operator~() const {
		base_uint ret;
		for (int i = 0; i < WIDTH; i++)
			ret.pn[i] = ~pn[i];
		return ret;
	}

	const base_uint operator-() const {
		base_uint ret;
		for (int i = 0; i < WIDTH; i++)
			ret.pn[i] = ~pn[i];
		ret++;
		return ret;
	}

	base_uint& operator=(uint64_t b) {
		pn[0] = (uint32_t)b;
		pn[1] = (uint32_t)(b >> 32);
		for (int i = 2; i < WIDTH; i++)
			pn[i] = 0;
		return *this;
	}

	base_uint& operator^=(const base_uint& b) {
		for (int i = 0; i < WIDTH; i++)
			pn[i] ^= b.pn[i];
		return *this;
	}

	base_uint& operator&=(const base_uint& b) {
		for (int i = 0; i < WIDTH; i++)
			pn[i] &= b.pn[i];
		return *this;
	}

	base_uint& operator|=(const base_uint& b) {
		for (int i = 0; i < WIDTH; i++)
			pn[i] |= b.pn[i];
		return *this;
	}
};

class uint256 : public base_uint<256>
{
};


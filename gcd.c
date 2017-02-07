#include "gcd.h"

uint64_t euclid_gcd(uint64_t x, uint64_t y)
{
	if (x == 0) {
		return y;
	}
	if (y == 0) {
		return x;
	}
	uint8_t p2;
	for (p2 = 0; ((x | y) & 1) == 0; p2++) {
		x >>= 1;
		y >>= 1;
	}
	while ((x & 1) == 0) {
		x >>= 1;
	}
	do {
		while ((y & 1) == 0) {
			y >>= 1;
		}
		if (x > y) {
			uint64_t z = x;
			x = y;
			y = z;
		}
		y -= x;
	} while (y > 0);
	return x << p2;
}

#include "LcmGcd.h"

long Gcd(long x, long y)
{
	if (x == 0 || y == 0)
		return 0;

	while (x % y != 0)
	{
		// x / y
		long tempY = y;
		y = x % y;
		x = tempY;
	}
	return y;
}

long GcdRecursive(long x, long y)
{
	if (x == 0 || y == 0)
		return 0;
	if (x % y == 0)
		return y;

	return GcdRecursive(y, x % y);
}

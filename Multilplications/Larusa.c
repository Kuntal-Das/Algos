long LarusaMult(long x, long y)
{
	long result = 0;

	if (x > y) {
		y = x + y;
		x = y - x;
		y = y - x;
	}

	while (x > 0)
	{
		if (x % 2 != 0) result += y;

		x = x / 2;
		y = y * 2;
	}

	return result;
}

long LarusaMultRecursive(long x, long y) {
	long result = 0;

	if (x > y) {
		y = x + y;
		x = y - x;
		y = y - x;
	}

	if (x <= 0) {
		return result;
	}

	if (x % 2 != 0) {
		return result + y + LarusaMultRecursive(x / 2, y * 2);
	}
	else {
		return result + LarusaMultRecursive(x / 2, y * 2);
	}
}

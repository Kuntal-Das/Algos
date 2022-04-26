#include<math.h>
#include<string.h>
#include "../Helpers/Helpers.h"

unsigned long long int KaratsubaMult(long long int m,long long int n)
{
    long long a,b,c,d;
	int maxLength = MAX(Length(m), Length(n));
    unsigned long long int result;

	if (maxLength <= 2) return m * n;

	a = m / pow(10, maxLength / 2);
	b = m % (long long)pow(10, maxLength / 2);
	c = n / pow(10, maxLength / 2);
	d = n % (long long)pow(10, maxLength / 2);

	result = KaratsubaMult(b, d)
		+ KaratsubaMult(b, c) * pow(10, maxLength / 2)
		+ KaratsubaMult(a, d) * pow(10, maxLength / 2)
		+ KaratsubaMult(a, c) * pow(10, 2 * (maxLength / 2));

	return result;
}

// char* KaratsubaMultStr(char* m, char* n)
// {
// 	char zero[3] = "00";
// 	if (strcmp(m, zero) == 0 || strcmp(n, zero) == 0)
// 		return "00";

// 	if (strlen(m) > strlen(n))
// 		swap(&m, &n);

// 	int mLen = strlen(m), nLen = strlen(n);

// 	if (nLen <= 2) return ToStr(atof(m) * atof(n));

// 	if (mLen < 4) {
// 		m = AddLeft(m, '0', 4 - mLen);
// 		mLen = 4;
// 	}

// 	if (nLen < 4) {
// 		n = AddLeft(n, '0', 4 - nLen);
// 		nLen = 4;
// 	}


// 	int midLen = nLen / 2;
// 	int fPart = nLen - midLen;

// 	char* a = SubString(m, 0, mLen - fPart);
// 	char* b = SubString(m, mLen - fPart, fPart);
// 	char* c = SubString(n, 0, nLen - fPart);
// 	char* d = SubString(n, nLen - fPart, fPart);

// 	char* ac = KaratsubaMultStr(a, c);
// 	char* adbc = findSum(KaratsubaMultStr(a, d), KaratsubaMultStr(b, c));
// 	char* bd = KaratsubaMultStr(b, d);


// 	char* mult = findSum("0", bd);
// 	mult = findSum(mult, AddRight(adbc, '0', floor(nLen / 2)));
// 	mult = findSum(mult, AddRight(ac, '0', 2 * floor(nLen / 2)));

// 	return mult;
// }

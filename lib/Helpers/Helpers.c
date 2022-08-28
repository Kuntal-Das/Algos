#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include "Helpers.h"

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int Length(long num)
{
	if (num / 10 == 0)
		return 1;
	return 1 + Length(num / 10);
}

void Swap(void *arg1, void *arg2, size_t len)
{
	unsigned char *p = arg1, *q = arg2, temp;
	for (size_t i = 0; i != len; i++)
	{
		temp = p[i];
		p[i] = q[i];
		q[i] = temp;
	}
}

void SwapLongByRef(long *arg1, long *arg2)
{
	long t = *arg1;
	*arg1 = *arg2;
	*arg2 = t;
}
void SwapDoubleByRef(double *arg1, double *arg2)
{
	double t = *arg1;
	*arg1 = *arg2;
	*arg2 = t;
}
void SwapStrByRef(char **arg1, char **arg2)
{
	char *t = *arg1;
	*arg1 = *arg2;
	*arg2 = t;
}

char *ToStr(long num)
{
	int size = (int)log10((double)num);
	char *charArr = (char *)calloc(size + 1, sizeof(char));

	sprintf(charArr, "%ld", num);

	return charArr;
}

char *SubString(char *str, int startIndex, int chNums)
{
	char *subStr = (char *)calloc(chNums + 1, sizeof(char));
	for (int i = 0; i < chNums; i++)
	{
		subStr[i] = (char)str[startIndex++];
	}
	return subStr;
}

char *AddRight(char *str, char ch, int num)
{
	int size = strlen(str) + num;
	char *result = (char *)calloc(size + 1, sizeof(char));

	for (int i = 0; i < size; i++)
	{
		result[i] = (i < size - num) ? str[i] : ch;
	}

	return result;
}

char *AddLeft(char *str, char ch, int num)
{
	int size = strlen(str) + num;
	char *result = (char *)calloc(size + 1, sizeof(char));

	for (int i = 0, j = 0; i < size; i++)
	{
		result[i] = (i < num) ? ch : str[j++];
	}

	return result;
}

// Function for finding sum of larger numbers
char *FindSum(char *str1, char *str2)
{
	int n1, n2, j, carry = 0;
	// Before proceeding further, make sure length
	// of str2 is larger.
	if (strlen(str1) > strlen(str2))
		SwapStrByRef(&str1, &str2);

	// Calculate length of both string
	n1 = strlen(str1);
	n2 = strlen(str2);

	// Reverse both of strings
	str1 = strrev(str1);
	str2 = strrev(str2);

	j = 0;
	carry = 0;
	char *result = (char *)malloc(sizeof(char) * n2 + 1);
	for (int i = 0; i < n1; i++)
	{
		// Do school mathematics, compute sum of
		// current digits and carry
		int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);

		result[j++] = sum % 10 + '0';
		// str.push_back(sum % 10 + '0');

		// Calculate carry for next step
		carry = sum / 10;
	}

	// Add remaining digits of larger number
	for (int i = n1; i < n2; i++)
	{
		int sum = ((str2[i] - '0') + carry);
		result[j++] = sum % 10 + '0';
		// str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	// Add remaining carry
	if (carry)
		result[j++] = carry + '0'; // str.push_back(carry + '0');

	result[j++] = '\0';
	// reverse resultant string
	result = strrev(result);
	// reverse(str.begin(), str.end());

	return result;
}

char *ConcatStr(int n_args, ...)
{
	register int i, j;
	int len1, newlength = 0, oldLength = 0;
	char *str, *result = NULL;
	va_list ap;

	va_start(ap, n_args);
	for (i = 0; i < n_args; i++)
	{
		str = va_arg(ap, char *);

		oldLength = (result == NULL) ? 0 : strlen(result);
		newlength += strlen(str);

		if (result == NULL)
			result = (char *)malloc(newlength * sizeof(char) + 1);
		else
			result = (char *)realloc(result, newlength + 1);

		for (j = oldLength; j < newlength; j++)
		{
			result[j] = str[j - oldLength];
		}
		result[j] = '\0';
	}
	va_end(ap);

	return result;
}

void FreeMem(int n_args, ...)
{
	register int i = 0;
	void *memory;
	va_list ap;

	va_start(ap, n_args);
	for (i = 0; i < n_args; i++)
	{
		memory = va_arg(ap, void *);
		free(memory);
	}

	va_end(ap);
}

int isStrsEqual(char *str1, char *str2)
{
	int i, l1 = strlen(str1), l2 = strlen(str2);

	if (l1 != l2)
		return 0;

	for (i = 0; i < l1; i++)
	{
		if (str1[i] != str2[i])
			return 0;
	}
	return 1;
}

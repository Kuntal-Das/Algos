#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

int Length(long num)
{
	if (num / 10 == 0)
		return 1;
	return 1 + Length(num / 10);
}

void swap(char **str1, char **str2)
{
	char *t = *str1;
	*str1 = *str2;
	*str2 = t;
}

char *ToStr(long num)
{
	int size = (int)(log10(num));
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
char *findSum(char *str1, char *str2)
{
	int n1, n2, j, carry = 0;
	// Before proceeding further, make sure length
	// of str2 is larger.
	if (strlen(str1) > strlen(str2))
		swap(&str1, &str2);

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

#include "palindrome.h"

/**
 * is_palindrome - Checks if an int is a palindrome or not
 * @n: Number given to be checked
 *
 * Return: 1 if @n is a palindrome, otherwise 0
 */

int is_palindrome(unsigned long n)
{
	unsigned int rem = 0, num_rev = 0, num;

	if (n <= 9)
		return (1);

	num = n;
	while (n != 0)
	{
		rem = n % 10;
		num_rev = num_rev * 10 + rem;
		n /= 10;
	}

	if (num_rev == num)
		return (1);
	return (0);
}

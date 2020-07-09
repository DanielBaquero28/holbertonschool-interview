#include "menger.h"

/**
 * menger - Prints a 2D Menger Sponge.
 * @level: Level of @menger
 * Return: Nothing
 */

void menger(int level)
{
	int size_sponge, tmp_i, tmp_j;
	int i, j;
	char c;

	size_sponge = pow(3, level);
	for (i = 0; i < size_sponge; i++)
	{
		for (j = 0; j < size_sponge; j++)
		{
			c = '#';
			tmp_i = i;
			tmp_j = j;
			while (tmp_i > 0)
			{
				if (tmp_i % 3 == 1 && tmp_j % 3 == 1)
				{
					c = ' ';
				}
				tmp_i /= 3;
				tmp_j /= 3;
			}
			printf("%c", c);
		}
		printf("\n");
	}
}

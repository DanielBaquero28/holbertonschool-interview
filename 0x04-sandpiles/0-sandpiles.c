#include "sandpiles.h"

/**
 * sum_grids - Adds two grids
 * @grid1: First grid
 * @grid2: Second grid
 * Return: Nothing
 */
void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}
}
/**
 * print_grid - Prints the result grid
 * @grid: Grid that will be printed
 *
 * Return: Nothing
 */
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * stable_grid - Check if it is a stable grid or else change sandpile value
 * @grid: Grid that will be checked
 *
 * Return: 1 if it's stable, else 0
 */
int stable_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}
/**
 * tuple_grid - Tuples @grid in order to make it stable
 * @grid: Grid that will tuple
 *
 * Return: Nothing
 */
void tuple_grid(int grid[3][3])
{
	int i, j;
	int r_grid[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}};
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{   grid[i][j] -= 4;
				if ((i + 1) >= 0 && (i + 1) < 3)
					r_grid[i + 1][j] += 1;
				if ((j + 1) >= 0 && (j + 1) < 3)
					r_grid[i][j + 1] += 1;
				if ((i - 1) >= 0 && (i - 1) < 3)
					r_grid[i - 1][j] += 1;
				if ((j - 1) >= 0 && (j - 1) < 3)
					r_grid[i][j - 1] += 1;
			}
		}
	}
	sum_grids(grid, r_grid);
}
/**
 * sandpiles_sum - Adds two sandpiles
 * @grid1: First grid
 * @grid2: Second grid
 *
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grids(grid1, grid2);
	while (stable_grid(grid1) == 0)
	{
		print_grid(grid1);
		tuple_grid(grid1);
	}
}

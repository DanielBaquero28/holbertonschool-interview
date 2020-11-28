#!/usr/bin/python3
""" Finds the perimeter of an island made of 1s in a matrix """


def island_perimeter(grid):
    """ Returns the perimeter of the island described in grid """
    rows = len(grid)
    columns = len(grid[0])
    perimeter = 0
    count = 0

    for x in range(rows):
        for y in range(columns):
            if (grid[x][y]):
                count = 0
                if (x > 0 and grid[x - 1][y]):
                    count += 1
                if (y < columns - 1 and grid[x][y + 1]):
                    count += 1
                if (y > 0 and grid[x][y - 1]):
                    count += 1
                if (x < rows - 1 and grid[x + 1][y]):
                    count += 1
                perimeter += (4 - count)

    return (perimeter)

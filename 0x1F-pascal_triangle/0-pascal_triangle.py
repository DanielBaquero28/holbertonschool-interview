#!/usr/bin/python3
""" Function that returns the representation of a Pascal Triangle """


def pascal_triangle(n):
    """
    Returns a list of lists of integers representing
    the Pascal’s triangle of n
    """
    pt = [[] for i in range(0, n)]
    for line in range(0, n):
        for j in range(line + 1):
            if (j < line):
                if (j <= 0):
                    pt[line].append(1)
                else:
                    pt[line].append(pt[line - 1][j - 1] + pt[line - 1][j])
            elif(j == line):
                pt[line].append(1)
    return (pt)

#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    """ Finds the minimum number of operations to get n H """
    op = 0
    paste_char = 2

    if (n <= 1 or type(n) != int):
        return (0)
    while (n != 1):
        if (n % paste_char) == 0:
            n /= paste_char
            op += paste_char
        else:
            paste_char += 1
    return (op)
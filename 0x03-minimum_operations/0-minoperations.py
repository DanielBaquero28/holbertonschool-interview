#!/usr/bin/python3
""" Minimum Operations """

def minOperations(n):
    """ Finds the minimum number of operations to get n H """
    op = 0
    char = 1
    paste_char = 0
    flag = 0

    if (n <= 1):
        return (0)
    while ((char * 2) <= n):
        op += 2
        paste_char = char
        char *= 2
        if (char == n):
            flag = 1
            break
    while (char < n):
        if ((char + paste_char) <= n):
            op += 1
            char += paste_char
            if (char == n):
                flag = 1
                break
        if ((char + paste_char) > n):
            flag = 0
            break
    if (flag == 1):
        return (op)
    return (0)

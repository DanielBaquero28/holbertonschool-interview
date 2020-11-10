#!/usr/bin/python3
""" Determines the fewest number of coins needed to meet a given amount """


def makeChange(coins, total):
    """
    Checks if with @coins we can give change or not, if it can returns the
    fewest amount of coins needed
    """
    if total <= 0:
        return (0)

    count = 0
    tmpTotal = total
    coins.sort(reverse=True)
    for val in coins:
        if (tmpTotal == 0):
            break
        currentVal = val
        while (currentVal <= tmpTotal):
            tmpTotal -= val
            count += 1
    if (tmpTotal == 0):
        return (count)
    else:
        return (-1)

#!/usr/bin/python3
""" Function that returns the maximum amount of rain retained """


def rain(walls):
    """ Finds the amount of rain retained between walls of different heights
"""
    if (len(walls) <= 0):
        return (0)
    rain = 0
    """ The ends of the list are not walls, so we don't traverse them """
    for i in range(1, len(walls) - 1):
        height_left = walls[i]
        """ Finding max height of walls on the left (subsequence) """
        for j in range(i):
            height_left = max(height_left, walls[j])

        height_right = walls[i]
        """ Finding max height of walls on the right (subsequence) """
        for j in range(i + 1, len(walls)):
            height_right = max(height_right, walls[j])

        """
        We add all the rain retained previously with the minimum of the
        heights in order to add only the rain that doesn't overflow
        """
        rain = rain + (min(height_left, height_right) - walls[i])
    return (rain)

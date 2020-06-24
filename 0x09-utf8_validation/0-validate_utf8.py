#!/usr/bin/python3
""" Importing necessary packages """
import codecs


def validUTF8(data):
    """ Checks if data is a valid utf-8 """
    number_bytes = 0

    for element in data:
        mask_pre = 1 << 7
        if (number_bytes == 0):
            while (mask_pre & element):
                number_bytes += 1
                mask_pre = mask_pre >> 1
            if (number_bytes == 0):
                continue
            if (number_bytes == 1 or number_bytes > 4):
                return (False)
        else:
            mask_sig1 = 1 << 7
            mask_sig2 = 1 << 6
            if not ((element & mask_sig1) and not (element & mask_sig2)):
                return (False)
        number_bytes -= 1
    is_valid = number_bytes == 0
    return (is_valid)

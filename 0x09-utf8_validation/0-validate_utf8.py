#!/usr/bin/python3
"""
determine if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Determines if a given data set
    represents a valid UTF-8 encoding

    Conditions:
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Each integer represents 1 byte of data, therefore you only need to
        handle the 8 least significant bits of each integer

    Returns:
        True if data is a valid UTF-8 encoding, else return False
    """

    n_bytes = 0
    for i in data:
        byte = format(i, '#010b')[-8:]

        if n_bytes == 0:
            if byte[0] == '1':
                n_bytes = len(byte.split('0')[0])

            if n_bytes > 4 or n_bytes == 1:
                return False
            elif n_bytes == 0:
                continue
        else:
            if not (byte[0] == '1' and byte[1] == '0'):
                return False
        n_bytes = n_bytes - 1

    if n_bytes != 0:
        return False
    return True

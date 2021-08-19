#!/usr/bin/python3
"""method that calculates the fewest number of
operations needed to result in exactly n H characters in the file"""


def minOperations(n):
    """calculates the fewest number of operations
    needed to result in exactly n H characters in the file"""
    if n <= 1:
        return 0
    operations = 2
    chars = 2
    copy = 1
    while chars < n:
        if n % chars == 0:
            copy = chars
            operations += 1
        chars += copy
        operations += 1
    return operations

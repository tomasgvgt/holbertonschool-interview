#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """Determines if all boxes can be opened"""
    unlocked = [0] * len(boxes)
    unlocked[0] = 1

    for t in range(100):
        for i in range(len(boxes)):
            if unlocked[i] == 1 and len(boxes[i]) != 0:
                for key in boxes[i]:
                    if key < len(boxes):
                        unlocked[key] = 1
        t += 1
    for u in unlocked:
        if u != 1:
            return False
    return True

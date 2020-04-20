#!/usr/bin/python3


def canUnlockAll(boxes):
    """ Method that checks if all locked boxes can be unlocked """

    key = 0
    keys = [0]

    if not boxes:
        return (True)

    for key in keys:
        for key in boxes[key]:
            """ Avoiding duplicate valid keys """
            if key in keys:
                continue
            else:
                """ Ensuring only valid keys are appended """
                if key <= len(boxes) - 1:
                    keys.append(key)
                else:
                    continue

    """ If we collected the exact number of keys to unlock all of the boxes """
    if len(keys) == len(boxes):
        return (True)
    else:
        return (False)

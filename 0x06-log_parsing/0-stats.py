#!/usr/bin/python3
""" Importing neccessary packages """
import sys


if __name__ == '__main__':
    """ Main entrypoint """
    size = 0
    status_stats = {"200": 0, "301": 0, "400": 0, "401": 0,
                    "403": 0, "404": 0, "405": 0, "500": 0}
    num_line = 1

    def print_log(status_dict):
        """ Method that prints the parsed log """
        print("File size: {}".format(size))
        for status, stat in status_dict.items():
            if stat > 0:
                print("{}: {}".format(status, stat))

    try:
        for stdin_line in sys.stdin:
            args = stdin_line.split(" ")
            if len(args) > 5:
                status = args[-2]
                if status in status_stats.keys():
                    """ index = list(status_stats).index(status) """
                    status_stats[status] += 1
                size += int(args[-1])
                if num_line % 10 == 0:
                    print_log(status_stats)
            num_line += 1
    except KeyboardInterrupt:
        print_log(status_stats)
        raise
    print_log(status_stats)

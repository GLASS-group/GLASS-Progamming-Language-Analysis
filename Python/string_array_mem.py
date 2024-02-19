import time

ONE_MILLION = 1000000
ONE_BILLION = 1000000000
NUM_TRIALS = 50
cumulative = 0

x = 0
strings = []
while x < 100000:
    if x == 0:
        strings.append("a")
    else:
       strings.append(strings[x-1] + "a")
    x += 1


input()
    
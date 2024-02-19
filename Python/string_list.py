import time

ONE_BILLION = 1000000000
ONE_MILLION = 1000000
NUM_TRIALS = 50
cumulative = 0


for t in range(NUM_TRIALS):


    startTime = time.time_ns()

    x = 0
    stings = []
    strings = [None] * 100000
    while x < 100000:
        if x == 0:
            strings[x] = "a"
        else:
            strings[x] = strings[x-1] + "a"
        x += 1

    endTime = time.time_ns()
    difference = endTime - startTime
    cumulative += difference
    seconds = difference / ONE_BILLION
    print(f"Time to process: {seconds} seconds")
    time.sleep(0.03)

seconds = cumulative / ONE_BILLION / NUM_TRIALS
print(f"Average time to process: {seconds} seconds")
    
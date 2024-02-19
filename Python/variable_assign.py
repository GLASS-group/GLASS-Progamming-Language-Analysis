import time

ONE_BILLION = 1000000000
NUM_TRIALS = 50
cumulative = 0

for t in range(NUM_TRIALS):
    startTime = time.time_ns()
    x = 0
    while x < ONE_BILLION:
        x += 1
    endTime = time.time_ns()
    difference = endTime - startTime
    cumulative += difference
    seconds = difference / ONE_BILLION
    print(f"Time to process: {seconds} seconds")
    time.sleep(0.0003)

seconds = cumulative / ONE_BILLION / NUM_TRIALS
print(f"Average time to process: {seconds} seconds")
    
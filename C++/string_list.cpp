#include <chrono>
#include <iostream>
#include <windows.h>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
    const int NUM_TRAILS = 50;
    const int ONE_BILLION = 1000000000;
    const int ONE_MILLION = 1000000;
    chrono::high_resolution_clock m_clock;
    double cumulative = 0;

    for (int t = 0; t < NUM_TRAILS; t++) {
        uint64_t startTime = std::chrono::duration_cast<std::chrono::nanoseconds>(m_clock.now().time_since_epoch()).count();
        int x = 0;
        int y = 0;
        string strings[10000];
        while (x < 100000) { 
            if (x == 0 && y == 0) {
                strings[x] = "a";
            } else if (x % 10000 == 0) {
                y += 1;
                x = 0;
                strings[x] = strings[9999] + "a";
            } else {
                strings[x] = strings[x-1] + "a";
            }
            x += 1; 
        }
        uint64_t endTime = std::chrono::duration_cast<std::chrono::nanoseconds>(m_clock.now().time_since_epoch()).count();
        uint64_t difference = endTime - startTime;
        cumulative = cumulative + (double)difference;
        double seconds = difference / (double) ONE_BILLION;

        cout << "Time to process: " << seconds << " seconds" << '\n';
        sleep(0.003);
    }
    double seconds = cumulative / ((double) NUM_TRAILS) / ((double) ONE_BILLION);
    cout << "Total time to process: " << seconds << " seconds" << '\n';
}
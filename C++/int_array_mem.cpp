#include <chrono>
#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    const int ONE_BILLION = 1000000000;
    const int ONE_MILLION = 1000000;
    int x = 0;
    static int ints[ONE_MILLION];
    while (x < ONE_MILLION) {
        ints[x] = x;
        x++;
    }
    string temp;
    cin >> temp;
}
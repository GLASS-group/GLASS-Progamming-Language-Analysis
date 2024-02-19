#include <chrono>
#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    const int ONE_BILLION = 1000000000;
    const int ONE_MILLION = 1000000;
    int x = 0;
    static string strings[100000];
    st
    while (x < 100000) {
        if (x == 0) {
            strings[x] = "a";
        } else {
            strings[x] = strings[x-1] + "a";
        }
        cout << x << '\n';
        x++;
    }
    string temp;
    cin >> temp;
}
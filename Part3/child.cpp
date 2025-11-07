#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
int main() {
    std::cout.setf(std::ios::unitbuf);
    long x = 0;
    unsigned long cycle = 0;
    while (x >= -500) {
        std::cout << "[child ] " << getpid() << " Cycle number: " << cycle;
        if (x % 3 == 0) {
            std::cout << " — " << x << " is a multiple of 3";
        }
        std::cout << "\n";
        x--;
        cycle++;
        usleep(50000);
    }
    return 0; 
}

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <thread>
#include <chrono>

int main() {
    std::cout.setf(std::ios::unitbuf);
    pid_t pid = fork();

    if (pid == 0) {
        char *args[] = { (char*)"./bin/child", nullptr };
        execv(args[0], args);
        _exit(1); 
    }

    unsigned long cycle = 0, x = 0;
    while (true) {
        std::cout << "[parent] " << getpid() << " Cycle number: " << cycle;
        if (x % 3 == 0) {
            std::cout << " — " << x << " is a multiple of 3";
        }
        std::cout << "\n";
        x++;
        cycle++;
        usleep(50000);
    }
}

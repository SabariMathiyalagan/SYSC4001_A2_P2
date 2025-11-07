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

 
    wait(nullptr);
    std::cout << "Child finished (reached < -500). Parent exiting.\n";
    return 0;
}

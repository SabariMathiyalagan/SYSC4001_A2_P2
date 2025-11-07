#include <iostream>
#include <unistd.h>     
#include <sys/types.h>  

int main() {
    pid_t pid = fork();          
    unsigned long counter = 0;   

    if (pid == 0) {
        while (true) {
            counter++;
            std::cout << "[child ] " << getpid() << " counter=" << counter << "\n";
            usleep(200000); 
        }
    } else {
        while (true) {
            counter++;
            std::cout << "[parent] " << getpid() << " counter=" << counter << "\n";
            usleep(200000); 
        }
    }
}

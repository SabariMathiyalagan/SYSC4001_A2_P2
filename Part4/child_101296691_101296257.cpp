#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <thread>
#include <chrono>

struct Shared { int multiple; int counter; };

int main(int argc, char** argv) {
    std::cout.setf(std::ios::unitbuf);
    int shmid = std::stoi(argv[1]);
    Shared* sh = (Shared*)shmat(shmid, nullptr, 0);

  
    while (sh->counter < 100) { }

    while (sh->counter <= 500) {
        sh->counter++;
        if (sh->counter % sh->multiple == 0) {
            std::cout << "[CHILD ] counter=" << sh->counter << " (multiple=" << sh->multiple << ")\n";
        }
        usleep(200000);
    }

    shmdt(sh);
    return 0;
}

#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <thread>
#include <chrono>

struct Shared { int multiple; int counter; };
static sembuf P = {0, -1, 0};
static sembuf V = {0,  1, 0};

int main(int argc, char** argv) {
    std::cout.setf(std::ios::unitbuf);

    int shmid = std::stoi(argv[1]);
    int semid = std::stoi(argv[2]);
    Shared* sh = (Shared*)shmat(shmid, nullptr, 0);

    while (true) {
        semop(semid, &P, 1);
        int c = sh->counter;
        semop(semid, &V, 1);
        if (c > 100) {
            break;
        }
        usleep(100000);
    }

    while (true) {
        semop(semid, &P, 1);
        sh->counter++;
        int c = sh->counter, m = sh->multiple;
        semop(semid, &V, 1);

        if (c % m == 0) {
            std::cout << "[CHILD ] counter=" << c << " (multiple=" << m << ")\n";
        }
        if (c > 500) {
            break;
        }
        usleep(100000);
    }

    shmdt(sh);
    return 0;
}

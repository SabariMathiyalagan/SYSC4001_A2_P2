#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <thread>
#include <chrono>

struct Shared { int multiple; int counter; };

int main() {
    std::cout.setf(std::ios::unitbuf);

    int shmid = shmget(IPC_PRIVATE, sizeof(Shared), IPC_CREAT | 0600);
    Shared* sh = (Shared*)shmat(shmid, nullptr, 0);
    sh->multiple = 3;
    sh->counter = 0;

    pid_t pid = fork();
    if (pid == 0) {
        char *args[] = { (char*)"./bin/child", const_cast<char*>(std::to_string(shmid).c_str()), nullptr };
        execv(args[0], args);
        _exit(1);
    }

    while (sh->counter <= 500) {
        sh->counter++;
        if (sh->counter % sh->multiple == 0) {
            std::cout << "[PARENT] counter=" << sh->counter << " (multiple=" << sh->multiple << ")\n";
        }
        usleep(100000);
    }

    shmdt(sh);
    shmctl(shmid, IPC_RMID, nullptr);
    return 0;
}

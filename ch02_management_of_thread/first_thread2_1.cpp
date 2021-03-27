#include <pthread/pthread.h>
#include <cstdlib>
#include <cstdio>
#include <stdexcept>
#include <thread>
#include <chrono>
using std::this_thread::sleep_for;

/**
 * @brief pthreadではメインスレッドと別スレッドの優劣関係は対等.
 * 別スレッドからでもプロセスを終了するコマンドexit()を呼べる.
 */

void another_func(int i) {
    if (i == 2) {
        std::printf("Hasta la vista, baby.\n");
        // pthread_exit(nullptr);
        std::printf("exit(0) in another thread.\n");
        exit(0);
    }
}

void* thread_func(void* arg) {
    for (int i = 0; i < 3; ++i) {
        std::printf("I'm thread_func: %d\n", i);
        another_func(i);
        sleep_for(std::chrono::milliseconds(1000));
    }
    return nullptr;
}

int main(int, char**)
{
    pthread_t thread;

    if (pthread_create(&thread, nullptr, thread_func, nullptr) != 0) {
        throw std::runtime_error("Error: Failed to create new thread.");
    }

    for (int i = 0; i < 5; ++i) {
        std::printf("I'm main: %d\n", i);
        sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
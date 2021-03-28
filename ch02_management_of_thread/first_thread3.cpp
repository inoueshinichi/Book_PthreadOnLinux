/**
 * @file first_thread3.cpp
 * @author your name (you@domain.com)
 * @brief スレッドIDとスレッド終了待ち
 * @version 0.1
 * @date 2021-03-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <pthread/pthread.h>
#include <cstdlib>
#include <cstdio>
#include <stdexcept>
#include <thread>
#include <chrono>
using std::this_thread::sleep_for;

/**
 * @brief スレッド終了待ちをしないコードは良くない.
 * 他のスレッドの終了を確実に待ってからプロセスを終了するようにする.
 * pthread_join関数
 */

void* thread_func(void* arg) {
    // ユーザーによってスレッドの生存時間が変わる
    int* n = (int*)arg;

    for (int i = 0; i < *n; ++i) {
        std::printf("I'm thread_func: %d\n", i);
        sleep_for(std::chrono::milliseconds(1000));
    }
    return nullptr;
}

int main(int argc, char** argv)
{
    pthread_t thread; // スレッドID
    int n = 1;

    if (argc > 1) {
        n = std::atoi(argv[1]);
    }

    if (pthread_create(&thread, nullptr, thread_func, (void*)&n) != 0) {
        throw std::runtime_error("Error: Failed to create new thread.");
    }

    for (int i = 0; i < 5; ++i) {
        std::printf("I'm main: %d\n", i);
        sleep_for(std::chrono::milliseconds(1000));
    }

    // 行儀の良いスレッドの終了待ち
    if (thread != nullptr) {
        if (pthread_join(thread, nullptr) != 0) { // ここでメインスレッドの処理は待ち状態になる
            throw std::runtime_error("Error: Failed to wait for the thread termination.");
        }
        thread = nullptr;
    }
    
    std::printf("Bye.\n");

    return 0;
}
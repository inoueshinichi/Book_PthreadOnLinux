/**
 * @file cencel_other_thread_good_style.cpp
 * @author your name (you@domain.com)
 * @brief 
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
 * @brief int pthread_cancel(pthread_t thread)
 * この関数を呼び出すと、引数で指定したスレッドに停止要求を出し、
 * この関数自身はすぐに呼び出し元に戻ってくる. 引数で指定されたスレッドは、
 * システムコールを呼び出すなどして、OSに制御が渡り次第、自動的にpthread_exit関数を
 * 実行して、スレッドを停止する.
 */

/**
 * @brief スレッドは消去されても資源の開放はされない
 * 停止したスレッドがmalloc関数などで獲得したメモリはそのままになってしまう...
 * 注意深くプログラムを組まないと簡単にメモリリークになる.
 */

static bool stop_request = false;

void* thread_func(void* arg) {
    char* buf = (char*)std::malloc(256);
    while (!stop_request)
    {
        // do someting
        sleep_for(std::chrono::milliseconds(1000));
    }
    std::free(buf); // このスレッド自身がwhileブロックから抜けてstd::freeするので、メモリリークは発生しない
    return nullptr;
}

// 行儀の良いコード
int main(int,char**)
{
    pthread_t thread;

    if (pthread_create(&thread, nullptr, thread_func, nullptr) != 0) {
        throw std::runtime_error("Error: Failed to create new thread.");
    }

    bool stop_flag = false;
    for (int i = 0; i < 10; ++i)
    {
        sleep_for(std::chrono::milliseconds(500));
    }
    stop_flag = true;

    if (stop_flag) {
        // pthread_cancel(thread);
        stop_request = true;
        if (pthread_join(thread, nullptr) != 0) {
            throw std::runtime_error("Error: Failed to wait for the thread termiantion.");
        }
    }

}
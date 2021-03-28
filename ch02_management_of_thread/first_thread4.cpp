/**
 * @file first_thread4.cpp
 * @author your name (you@domain.com)
 * @brief スレッドの戻り値
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

struct share_data {
    pthread_t th;
    int n;
};

void* thread_func(void* arg) {
    share_data* data_ptr = (share_data*)arg;

    for (int i = 0; i < data_ptr->n; ++i) {
        std::printf("I'm thread_func: %d\n", i);
        sleep_for(std::chrono::milliseconds(1000));
    }

    // スレッドIDによるスレッドの同定
    std::printf("thread: %p\n", (void*)data_ptr->th);
    if (pthread_equal(pthread_self(), data_ptr->th))
    {
        std::printf("Same thread.\n");
    }

    return (void*)&(data_ptr->n);
}



int main(int argc, char** argv)
{
    pthread_t thread;
    share_data data;
    data.n = 1;
    data.th = thread;
    int* ret;

    std::printf("thread: %p\n", (void*)thread);

    if (argc > 1)
        data.n = std::atoi(argv[1]);
    
    if (pthread_create(&thread, nullptr, thread_func, (void*)&data) != 0) {
        throw std::runtime_error("Error: Failed to create new thread.\n");
    }

    for (int i = 0; i < 5; ++i) {
        std::printf("I'm main: %d\n", i);
        sleep_for(std::chrono::milliseconds(1000));
    }

    if (pthread_join(thread, (void**)&ret) != 0) {
        throw std::runtime_error("Error: Failed to wait for the thread termination.\n");
    }

    std::printf("thread_func has been terminated with number %d\n", *ret);
    std::printf("Bye.\n");

    return 0;
}
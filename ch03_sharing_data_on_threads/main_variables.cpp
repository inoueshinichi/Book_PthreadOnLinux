/**
 * @file main_variables.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-01
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

// global scope
int varA;

void* thread_func(void* arg)
{
    int* np = (int*)arg;
    int varB;

    varB = 4 * (*np);
    std::printf("thread_func-%d-1: varA=%d, varB=%d\n", *np, varA, varB);
    varA = 5 * (*np);
    std::printf("thread_func-%d-2: varA=%d, varB=%d\n", *np, varA, varB);
    sleep_for(std::chrono::milliseconds(2000));
    std::printf("thread_func-%d-3: varA=%d, varB=%d\n", *np, varA, varB);
    varB = 6 * (*np);
    std::printf("thread_func-%d-4: varA=%d, varB=%d\n", *np, varA, varB);

    return nullptr;
}

int main(int,char**)
{
    pthread_t thread1, thread2;
    int varB = 2;
    std::printf("main-1: varA=%d, varB=%d\n", varA, varB);

    int arg1 = 1;
    if (pthread_create(&thread1, nullptr, thread_func, (void*)&arg1) != 0) {
        throw std::runtime_error("Error: Failed to create new thread.");
    }
    sleep_for(std::chrono::milliseconds(1000));

    int arg2 = 2;
    varB = 3;
    std::printf("main-2: varA=%d, varB=%d\n", varA, varB);
    if (pthread_create(&thread2, nullptr, thread_func, (void*)&arg2) != 0) {
        throw std::runtime_error("Error: Failed to create new thread.");
    }
        
    if (pthread_join(thread1, nullptr) != 0) {
        throw std::runtime_error("Error: Failed to wait for the thread termiantion.");
    }
    if (pthread_join(thread2, nullptr) != 0) {
        throw std::runtime_error("Error: Failed to wait for the thread termiantion.");
    }
   
    std::printf("main-3: varA=%d, varB=%d\n", varA, varB);

    return 0;
}
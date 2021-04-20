/**
 * @file malloc_variables.cpp
 * @author your name (you@domain.com)
 * @brief 動的に割り当てられたメモリとスレッド
 * @version 0.1
 * @date 2021-04-20
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

#include <vector>

char* varA; // スレッド間で共有する動的メモリ
#define STRINGSIZE 32

void* thread_func(void* arg)
{
    int* pn = (int*)arg;

    // size_t size = std::snprintf(nullptr, 0, "Hello I'm No.%d", *pn);
    // if (size < 0)
    // {
    //     std::printf("[Fatal Error] Fail std::snprintf.\n");
    //     std::abort();
    // }
    // std::vector<char> buffer(size + 1);
    // std::snprintf(buffer.data(), size + 1, "Hello I'm No.%d", *pn);

    std::snprintf(varA, STRINGSIZE, "Hello I'm No.%d", *pn);

    std::printf("thread_func-%d: Sets varA as `%s`\n", *pn, varA);
    sleep_for(std::chrono::milliseconds(2000));
    std::printf("thread_func-%d: After 2.0 secs. varA is `%s`\n", *pn, varA);

    return nullptr;
}


int main(int, char**)
{
    pthread_t thread1, thread2;

    // size_t size = std::snprintf(nullptr, 0, "Good morning");
    // varA = (char*)std::malloc(size + 1); // length + null文字

    varA = (char*)std::malloc(STRINGSIZE);
    std::strcpy(varA, "Good morning");

    std::printf("main-1: varA is `%s`\n", varA);

    // Make thread1
    int arg1 = 1;
    if (pthread_create(&thread1, nullptr, thread_func, (void*)&arg1) != 0) {
        throw std::runtime_error("Error: Failed to create new thread.");
    }

    sleep_for(std::chrono::milliseconds(1000));
    std::printf("main-2: varA is `%s`\n", varA);

    // Make thread2
    int arg2 = 2;
    if (pthread_create(&thread2, nullptr, thread_func, (void*)&arg2) != 0) {
        throw std::runtime_error("Error: Failed to create new thread.");
    }

    // Wait thread1
    if (pthread_join(thread1, nullptr) != 0) {
        throw std::runtime_error("Error: Failed to wait for the thread termiantion.");
    }
    // Wait thread2
    if (pthread_join(thread2, nullptr) != 0) {
        throw std::runtime_error("Error: Failed to wait for the thread termiantion.");
    }

    std::printf("main-3: varA is `%s`\n", varA);

    std::free(varA);

    return 0;
}
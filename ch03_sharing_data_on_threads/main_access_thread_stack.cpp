/**
 * @file main_access_thread_stack.cpp
 * @author your name (you@domain.com)
 * @brief 他のスレッドのスタックへのアクセス
 * @version 0.1
 * @date 2021-04-21
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

char* varA; // スレッド間で共有する動的メモリ
#define STRINGSIZE 32

void* thread_func(void* arg)
{
    int* pn = (int*)arg;

    // 別スレッドがメインスレッドのスタック変数varBにvarAを介してアクセスする
    std::snprintf(varA, STRINGSIZE, "Hello I'm No.%d", *pn);

    std::printf("thread_func-%d: Sets varA as `%s`\n", *pn, varA);
    sleep_for(std::chrono::milliseconds(2000));
    std::printf("thread_func-%d: After 2.0 secs. varA is `%s`\n", *pn, varA);

    return nullptr;
}

int main(int, char**)
{
    pthread_t thread1, thread2;

    // メインスレッドのスタックにメモリを構築
    char varB[STRINGSIZE];
    varA = varB;
    std::strcpy(varA, "Good morning"); // varAを介してvarBに構築

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

    return 0;
}
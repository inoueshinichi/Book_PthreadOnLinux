/**
 * @file first_thread_attr.cpp
 * @author your name (you@domain.com)
 * @brief スレッドの属性の扱い
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
 * @brief スレッド属性については、OSやライブラリのバージョン違いによって正しく機能しないことがある.
 * スレッド属性：メモリの取り扱い, CPUのタスク割当など
 * pthread_attr_init関数, pthread_attr_setdetachstate関数, pthread_attr_setstacksize関数などがある.
 * どうしても必要である積極的な理由がない限り、使用しないこと.
 */

/**
 * @brief このコードで行うこと。
 * 比較的まともに実装されていることが多く、まれに必要になることがある、スタックサイズの指定の例
 * 
 */

const int SIZE = 10000000; // 1000万

void* thread_func(void* arg) {
    double table[SIZE];
    
    for (int i = 0; i < SIZE; ++i) {
        table[i] = i * 3.14;
    }

    return nullptr;
}

int main(int argc, char** argv) 
{
    pthread_attr_t attr;
    pthread_t thread;

    pthread_attr_init(&attr);
    if (pthread_attr_setstacksize(&attr, SIZE * sizeof(double) + 100000) != 0) 
    {
        throw std::runtime_error("Failed to set stack size."); // iMacの環境ではスタックサイズ(80MB)の確保ができずにエラーとなる.
    }

    if (pthread_create(&thread, &attr, thread_func, nullptr) != 0) {
        throw std::runtime_error("Error: Failed to create new thread.\n");
    }

    if (pthread_join(thread, nullptr) != 0) {
        throw std::runtime_error("Error: Failed to wait for the thread termination.");
    }

    return 0;
}
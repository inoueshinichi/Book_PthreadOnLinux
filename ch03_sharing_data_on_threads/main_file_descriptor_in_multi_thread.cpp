/**
 * @file main_file_descriptor_in_multi_thread.cpp
 * @author your name (you@domain.com)
 * @brief マルチスレッドにおけるファイルディスクリプタの扱い
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

#include <unistd.h> // fork, open, close

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void* thread_func(void* arg)
{
    const char* msg = "thread_func writes to standard output\n";
    write(1, msg, strlen(msg));
    close(1);
    open("fdThread.txt", O_WRONLY | O_CREAT | O_TRUNC, 0744); // システムコール：　現在使用されていない最小のファイルディスクリプタに割り当てる
    msg = "thread_func writes to fdThread.txt\n";
    write(1, msg, strlen(msg));
    sleep_for(std::chrono::milliseconds(2000));
    pthread_exit(nullptr);
}


int main(int, char**)
{
    pthread_t thread;

    // Make thread
    if (pthread_create(&thread, nullptr, thread_func, (void*)nullptr) != 0) {
        throw std::runtime_error("Error: Failed to create new thread.");
    }

    sleep_for(std::chrono::milliseconds(1000));


    const char* msg = "main writes to standard output\n";
    write(1, msg, strlen(msg)); // 出力先が標準出力からファイル`fdThread.txt`に書き換わっている

    // Wait thread1
    if (pthread_join(thread, nullptr) != 0) {
        throw std::runtime_error("Error: Failed to wait for the thread termiantion.");
    }

    return 0;
}
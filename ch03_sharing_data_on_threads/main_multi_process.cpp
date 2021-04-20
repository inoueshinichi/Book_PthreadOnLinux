/**
 * @file main_multi_process.cpp
 * @author your name (you@domain.com)
 * @brief マルチプロセスの動作
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

#include <unistd.h> // fork
#include <sys/wait.h>

int varA;

void process_func(int n)
{
    int varB;

    varB = 4 * n;
    std::printf("process_func-%d-1: varA=%d, varB=%d\n", n, varA, varB);
    varA = 5 * n;
    std::printf("process_func-%d-2: varA=%d, varB=%d\n", n, varA, varB);
    sleep_for(std::chrono::milliseconds(2000));
    std::printf("process_func-%d-3: varA=%d, varB=%d\n", n, varA, varB);
    varB = 6 * n;
    std::printf("process_func-%d-4: varA=%d, varB=%d\n", n, varA, varB);

    std::exit(0);
}


int main(int, char**)
{
    pid_t process1, process2;
    int varB;

    varA = 1, varB = 2;
    std::printf("main-1: varA=%d, varB=%d\n", varA, varB);
    if ((process1 = fork()) == 0)
    {
        // this is child process
        process_func(1);
    }
    
    // this is main process
    sleep_for(std::chrono::milliseconds(1000));
    varB = 3;
    std::printf("main-2: varA=%d, varB=%d\n", varA, varB);
    if ((process2 = fork()) == 0)
    {
        // this is child process
        process_func(2);
    }

    // this is main process
    waitpid(process1, nullptr, 0);
    waitpid(process2, nullptr, 0);

    std::printf("main-3: varA=%d, varB=%d\n", varA, varB);

    return 0;
}
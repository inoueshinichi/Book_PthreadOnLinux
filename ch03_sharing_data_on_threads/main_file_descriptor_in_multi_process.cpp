/**
 * @file main_file_descriptor_in_multi_process.cpp
 * @author your name (you@domain.com)
 * @brief マルチプロセスにおけるファイルディスクリプタの扱い
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
#include <sys/wait.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string>

// ファイルディスクリプタ：１は標準出力

void process_func()
{
    const char* msg = "process_func writes to standard output\n";
    write(1, msg, strlen(msg)); // 1: 標準出力に書き込む
    close(1); // 1: 標準出力をクローズ
    open("fdProcess.txt", O_WRONLY | O_CREAT | O_TRUNC, 0744); // システムコール：　現在使用されていない最小のファイルディスクリプタに割り当てる
    msg = "process_func writes to fdProcess.txt\n";
    write(1, msg, strlen(msg));
    sleep_for(std::chrono::milliseconds(2000));
    exit(0);
}


int main(int, char**)
{
    pid_t process;

    if ((process = fork()) == 0)
    {
        // this is child process
        process_func();
    }

    // this is main process
    sleep_for(std::chrono::milliseconds(1000));

    const char* msg = "main writes to standard output\n";
    write(1, msg, strlen(msg));

    waitpid(process, nullptr, 0);

    return 0;
}
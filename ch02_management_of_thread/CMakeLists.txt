
find_package(Threads REQUIRED)

# 1
add_executable(FirstThread
    first_thread.cpp
)

target_link_libraries(FirstThread
    PRIVATE Threads::Threads
)

# 2
add_executable(FirstThread2
    first_thread2.cpp
)

target_link_libraries(FirstThread2
    PRIVATE Threads::Threads
)

# 2-1
add_executable(FirstThread2_1
    first_thread2_1.cpp
)

target_link_libraries(FirstThread2_1
    PRIVATE Threads::Threads
)
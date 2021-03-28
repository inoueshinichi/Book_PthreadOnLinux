
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

# 3
add_executable(FirstThread3
    first_thread3.cpp
)

target_link_libraries(FirstThread3
    PRIVATE Threads::Threads
)

# 4
add_executable(FirstThread4
    first_thread4.cpp
)

target_link_libraries(FirstThread4
    PRIVATE Threads::Threads
)

# attr
add_executable(FirstThreadAttr
    first_thread_attr.cpp
)

target_link_libraries(FirstThreadAttr
    PRIVATE Threads::Threads
)

# cancel other thread bad style
add_executable(CancelOtherThreadBadStyle
    cancel_other_thread_bad_style.cpp
)

target_link_libraries(CancelOtherThreadBadStyle
    PRIVATE Threads::Threads
)


# cancel other thread good style
add_executable(CancelOtherThreadGoodStyle
    cancel_other_thread_good_style.cpp
)

target_link_libraries(CancelOtherThreadGoodStyle
    PRIVATE Threads::Threads
)
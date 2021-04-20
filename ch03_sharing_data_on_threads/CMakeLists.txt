
find_package(Threads REQUIRED)

# variables
add_executable(Variables
    main_variables.cpp
)
target_link_libraries(Variables
    PRIVATE Threads::Threads
)


# malloc variables
add_executable(MallocVariables
    main_malloc_variables.cpp
)
target_link_libraries(MallocVariables
    PRIVATE Threads::Threads
)

# access thread stack
add_executable(AccessThreadStack
    main_access_thread_stack.cpp
)
target_link_libraries(AccessThreadStack
    PRIVATE Threads::Threads
)


# multi process
add_executable(MultiProcess
    main_multi_process.cpp
)

# file descriptor in multi process
add_executable(FileDescriptorInMultiProcess
    main_file_descriptor_in_multi_process.cpp
)

# file descriptor in multi thread
add_executable(FileDescriptorInMultiThread
    main_file_descriptor_in_multi_thread.cpp
)
target_link_libraries(FileDescriptorInMultiThread
    PRIVATE Threads::Threads
)

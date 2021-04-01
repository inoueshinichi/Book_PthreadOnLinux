
find_package(Threads REQUIRED)

# variables
add_executable(Variables
    main_variables.cpp
)

target_link_libraries(Variables
    PRIVATE Threads::Threads
)

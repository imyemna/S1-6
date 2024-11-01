cmake_minimum_required(VERSION 3.29)
project(programation_c_s1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(s1-p)

add_executable(programation_c_s1
    s1-p/base16.c
    s1-p/count.c
    s1-p/one.c
    s1-p/Untitled-1.c
    area.c
    calc.c
    devide.c
    for.c
    hello.c
    main.c
    sum.c
    Untitled-1.c)

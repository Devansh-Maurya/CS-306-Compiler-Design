cmake_minimum_required(VERSION 3.12)
project(Dining_Philosopher_s_Problem_ C)

set(CMAKE_C_STANDARD 99)

add_executable(Dining_Philosopher_s_Problem_ semaphore.c monitor.c diningPhilosopher.c monitor.h)
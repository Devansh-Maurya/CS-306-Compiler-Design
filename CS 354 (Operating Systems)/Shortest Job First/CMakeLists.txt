cmake_minimum_required(VERSION 3.12)
project(Shortest_Job_First C)

set(CMAKE_C_STANDARD 99)

add_executable(Shortest_Job_First non_preemptive_sjf.c preemptive_sjf.c)
# Implementation of Scheduling Algorithms
Implemented three different CPU scheduling algorithms: round robin, shortest job first, and shortest remaining time first. 

## Description: 
This program simulates the performance of CPU scheduling algorithms. The program reads a text file with the following three columns (comma separated): the first column contains the job Id, the second column indicates the CPU burst, and column three is the arrival time of the corresponding job. For each job it will compute the turnaround time for all jobs, overall throughput of the system, and waiting time for all jobs. It also prints the order in which the processes were allowed to execute on the CPU. I used the following data structures: array, linked list, and min queue. 

## Why this project exists: 
This program was practice using c++ and also an exercise to better understand CPU scheduling algorithms.  

## How to run it: 

PLEASE NOTE: I used c++ 11 to test and compile my code. 

First, compile all files. For example:

`>> g++ -std=c++11 SJF.cpp SJF.h ProcessRR.h ProcessRR.cpp Driver.cpp RR.cpp RR.h Process.h Process.cpp SRTF.cpp SRTF.h`

Second, run the executable. For example:

`>> ./a.out`

Once it is executed it will prompt user to input a name of a file. If file is not found 
in working directory it will print "file not found", but if the file is present it
will print the result in the console. 

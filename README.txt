Joel Aguiar
HW5

This file is to provide some instruction on how to use my files for HW5. These files include:
Process.h
Process.cpp
ProcessRR.h
ProcessRR.cpp
SJF.h
SJF.cpp
RR.h
RR.cpp
SRTF.cpp
SRTF.h
Driver.cpp
README.txt

To use the code:

PLEASE NOTE: I used c++ 11 to test and compile my code. 

first, compile the three relevant files. For example:

>> g++ -std=c++11 SJF.cpp SJF.h ProcessRR.h ProcessRR.cpp Driver.cpp RR.cpp RR.h Process.h Process.cpp SRTF.cpp SRTF.h

second, run the executable. For example:

>> ./a.out

Once it is executed it will prompt user to input a name of a file. If file is not found 
in working directory it will print "file not found", but if the file is present it
will print the result in the console. 

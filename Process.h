/*
 * Process.h
 * This is the header file for Process class. This class
 * represents a proceess. 
 *  
 */
#include <iostream>
#include <string>
using namespace std;
#ifndef PROCESS_H_
#define PROCESS_H_

class Process{
private:
public:
	int terminationTime;
	int arrivalTime; 
	int jobID;
	int CPUburst;
	int tempCPUburst; 
	//constructor that takes in three param
	//jobID, CPUburst,and arrivaltime
	Process(int, int, int);
	//prints the jobId of a process
	void printValues();
	//returns arrival time of process
	int getArrivalTime(); 
	//is used to compare priority of processes 
	bool operator<(const Process &p1) const;
};



#endif /* PROCESS_H_ */

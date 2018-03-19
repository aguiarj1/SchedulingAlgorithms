/*
 * Process.cpp
 * This is the Process cpp file that implements 
 * all the methods for the Process class. 
 */
#include "Process.h"
#include <iostream>
#include <string>
using namespace std;

//constructor that takes in three param
//jobID, CPUburst,and arrivaltime
Process::Process(int j, int c, int a){
	jobID = j;
	CPUburst = c;
	arrivalTime = a;
	tempCPUburst = c; 
}

//prints the jobId of a process
void Process::printValues(){
	cout << jobID << ", ";
}

//returns arrival time of process
int Process::getArrivalTime(){
	return arrivalTime; 
}

//is used to compare priority of processes 
bool Process::operator<(const Process &p1) const{
	if(p1.CPUburst < CPUburst){
		return true; 
	} else if (p1.CPUburst == CPUburst){
		return (p1.jobID < jobID); 
	} else {
		return false; 
	}
}





/*
 * RR.h
 * This is the header file for the implementation of the
 * Round Robin scheduling algorithm. 
 */

#ifndef RR_H_
#define RR_H_
#include <string>
#include <list> 
#include "ProcessRR.h"
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

class RR {
private:
	int lastArrival;
	int CPUtimer; 
public :
	int newArrival; 
	int sumTurnaroundTime;
	int sumWaitingTime; 
	int countOfProcesses; 
	int countTotalTime; 
	//Constructor
	RR();
	//gets the data from the file and puts them into 
	//a list of Process objects
	void getFileData(string);
	//goes through text and gets the data from the file
	//to make a Process object 
	ProcessRR makeProcess(string s);
	//puts all the processes in an array and then 
	//uses a minqueue to process them. 
	void putProcessInArray(list<ProcessRR> p);
	//calculates and returns the turnaroundtime
	double getAverageTurnaroundtime(); 
	//calculates and returns the averagewait time
	double getAverageWaitingTime(); 
	//calculates and returns the throughput
	double getThroughput();
};



#endif /* RR_H_ */

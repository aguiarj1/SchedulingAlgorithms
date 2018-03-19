/*
 * SJF.h
 * This is the header file for the SJF class. 
 * SJF stands for Shortest Job First. 
 */

#ifndef SJF_H_
#define SJF_H_
#include <string>
#include <list> 
#include "Process.h"
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

class SJF {
private:
	int lastArrival;
	int CPUtimer; 
public :
	int sumTurnaroundTime;
	int sumWaitingTime; 
	int countOfProcesses; 
	int countTotalTime; 
	//Constructor 
	SJF();
	//gets the data from the file and puts them into 
	//a list of Process objects
	void getFileData(string);
	//goes through text and gets the data from the file
	//to make a Process object 
	Process makeProcess(string s);
	//puts all the processes in an array and then 
	//uses a minqueue to process them. 
	void putProcessInArray(list<Process> p);
	//calculates and returns the turnaroundtime
	double getAverageTurnaroundtime(); 
	//calculates and returns the averagewait time
	double getAverageWaitingTime(); 
	//calculates and returns the throughput
	double getThroughput();
};



#endif /* SJF_H_ */

/*
 * SRTF.h
 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
 */

#ifndef SRTF_H_
#define SRTF_H_
#include <string>
#include <list> 
#include "Process.h"
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

class SRTF {
private:
	int lastArrival;
	int CPUtimer; 
public :
	int sumTurnaroundTime;
	int sumWaitingTime; 
	int countOfProcesses; 
	int countTotalTime; 
	//Constructor 
	SRTF();
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



#endif /* SRTF_H_ */

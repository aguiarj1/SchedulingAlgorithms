/*
 * RR.h
 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
 */

#ifndef RR_H_
#define RR_H_
#include <string>
#include <list> 
#include "Process.h"
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
	RR();
	void getFileData(string);
	Process makeProcess(string s);
	void putProcessInArray(list<Process> p);
	double getAverageTurnaroundtime(); 
	double getAverageWaitingTime(); 
	double getThroughput();
};



#endif /* RR_H_ */

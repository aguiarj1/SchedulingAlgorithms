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
	SRTF();
	void getFileData(string);
	Process makeProcess(string s);
	void putProcessInArray(list<Process> p);
	double getAverageTurnaroundtime(); 
	double getAverageWaitingTime(); 
	double getThroughput();
};



#endif /* SRTF_H_ */

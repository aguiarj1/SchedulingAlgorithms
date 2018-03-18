/*
 * SJF.h
 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
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
	int sumThroughput;
	int sumWaitingTime; 
	int countOfProcesses; 
	SJF();
	void getFileData(string);
	Process makeProcess(string s);
	void putProcessInArray(list<Process> p);
	double getAverageTurnaroundtime(); 
};



#endif /* SJF_H_ */

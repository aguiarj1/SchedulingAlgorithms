/*
 * Process.h
 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
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
	int ArrivalTime;
	Process(int, int, int);
	//bool operator>(const Process &p1, const Process &p2);
	void printValues();
	int getArrivalTime(); 
	bool operator<(const Process &p1) const;
};



#endif /* PROCESS_H_ */

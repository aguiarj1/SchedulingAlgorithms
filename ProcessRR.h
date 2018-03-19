/*
 * Process.h
 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
 */
#include <iostream>
#include <string>
using namespace std;
#ifndef PROCESSRR_H_
#define PROCESSRR_H_

class ProcessRR{
private:



public:
	int priority; //at first same as jobID but then -1
	int terminationTime;
	int arrivalTime; 
	int tempArrivalTime; 
	int jobID;
	int CPUburst;
	int ArrivalTime;
	ProcessRR(int, int, int);
	//bool operator>(const Process &p1, const Process &p2);
	void printValues();
	int getArrivalTime(); 
	bool operator<(const ProcessRR &p1) const;
};



#endif /* PROCESSRR_H_ */

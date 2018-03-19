/*
 * ProcessRR.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
 */
#include "ProcessRR.h"
#include <iostream>
#include <string>
using namespace std;

ProcessRR::ProcessRR(int j, int c, int a){
	jobID = j;
	CPUburst = c;
	tempCPUburst = c; 
	arrivalTime = a;
	priority  = jobID; 
	tempArrivalTime = a; 
}

void ProcessRR::printValues(){
	cout << jobID << ", ";
}

int ProcessRR::getArrivalTime(){
	return arrivalTime; 
}

bool ProcessRR::operator<(const ProcessRR &p1) const{
	if(p1.tempArrivalTime < tempArrivalTime){
		return true; 
	} else if (p1.tempArrivalTime == tempArrivalTime){
		return (p1.priority < priority); 
	} else {
		return false; 
	}
}





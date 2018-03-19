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
	ArrivalTime = a;
	priority  = jobID; 
	tempArrivalTime = a; 
}

void ProcessRR::printValues(){
	cout << "jobID = " << jobID << " ";
	cout << "CPUBurst= " << CPUburst << " ";
	cout << "ArrivalTime= " << ArrivalTime << endl;
}

int ProcessRR::getArrivalTime(){
	return ArrivalTime; 
}

bool ProcessRR::operator<(const ProcessRR &p1) const{
	if(p1.ArrivalTime < ArrivalTime){
		return true; 
	} else if (p1.ArrivalTime == ArrivalTime){
		return (p1.priority < priority); 
	} else {
		return false; 
	}
}





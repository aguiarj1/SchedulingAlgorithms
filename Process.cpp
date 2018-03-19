/*
 * Process.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
 */
#include "Process.h"
#include <iostream>
#include <string>
using namespace std;

Process::Process(int j, int c, int a){
	jobID = j;
	CPUburst = c;
	arrivalTime = a;
}

void Process::printValues(){
	cout << "jobID = " << jobID << " ";
	cout << "CPUBurst= " << CPUburst << " ";
	cout << "ArrivalTime= " << arrivalTime << endl;
}

int Process::getArrivalTime(){
	return arrivalTime; 
}

bool Process::operator<(const Process &p1) const{
	if(p1.CPUburst < CPUburst){
		return true; 
	} else if (p1.CPUburst == CPUburst){
		return (p1.jobID < jobID); 
	} else {
		return false; 
	}
}





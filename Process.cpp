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
	ArrivalTime = a;
}

void Process::printValues(){
	cout << "jobID = " << jobID << endl;
	cout << "CPUBurst= " << CPUburst << endl;
	cout << "ArrivalTime= " << ArrivalTime << endl;
}

int Process::getArrivalTime(){
	return ArrivalTime; 
}

bool Process::operator>(const Process &p1){
	return true; //FIXME This is for min queue
}

bool Process::operator<(const Process &p1){
	return false; //FIXME This is for min queue
}

bool Process::operator>=(const Process &p1){
	return true; //FIXME This is for min queue
}

bool Process::operator<=(const Process &p1){
	return false; //FIXME This is for min queue
}

bool Process::operator==(const Process &p1){
	return false; //FIXME This is for min queue
}

bool Process::operator!=(const Process &p1){
	return true; //FIXME This is for min queue
}

bool Process::compare(const Process &p1){
	return false; 
}

bool Process::comp(const Process &p1){
	return false; 
}





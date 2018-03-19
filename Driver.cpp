/*
 * Driver.cpp

 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
 */
#include "SJF.h"
#include "SRTF.h"
#include <iostream>
#include "ProcessRR.h"
#include "Process.h"
#include <string>
#include "RR.h"
using namespace std;

int main(){

	// SJF sjf;
	// sjf.getFileData("jobs.txt"); //change it so constructor takes in the name of file
	// cout << "Shortest Job First (SJF)" << endl; 
	// cout << "Average Turnaround Time= " << sjf.getAverageTurnaroundtime() << endl; 
	// cout << "Average Waiting Time= " << sjf.getAverageWaitingTime() << endl; 
	// cout << "Average Throughput= " << sjf.getThroughput() << endl;
	
	
	// RR rr;
	// rr.getFileData("jobs.txt"); //change it so constructor takes in the name of file
	// cout << "Round Robin (RR)" << endl; 
	// cout << "Average Turnaround Time= " << rr.getAverageTurnaroundtime() << endl; 
	// cout << "Average Waiting Time= " << rr.getAverageWaitingTime() << endl; 
	// cout << "Average Throughput= " << rr.getThroughput() << endl;
	
	SRTF srtf;
	srtf.getFileData("jobs.txt"); //change it so constructor takes in the name of file
	cout << "Shortest Job First (SRTF)" << endl; 
	cout << "Average Turnaround Time= " << srtf.getAverageTurnaroundtime() << endl; 
	cout << "Average Waiting Time= " << srtf.getAverageWaitingTime() << endl; 
	cout << "Average Throughput= " << srtf.getThroughput() << endl;
 
}



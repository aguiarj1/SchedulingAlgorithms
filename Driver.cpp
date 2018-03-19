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
	
	
	cout << "Please input name of file with data: "; 
	string fileName;
	getline (cin, fileName);
	cout << "\nYou are the scheduling algorithms for the file " << fileName << "."<<endl; 
	cout << "\nShortest Job First (SJF)" << endl;
	
	SJF sjf;
	sjf.getFileData("fileName"); 
	cout << "\nAverage Waiting Time= " << sjf.getAverageWaitingTime() << endl;
	cout << "Average Throughput= " << sjf.getThroughput() << endl;
	cout << "Average Turnaround Time= " << sjf.getAverageTurnaroundtime() << endl; 
	cout << "\n"; 
	
	cout << "Round Robin (RR)" << endl;
	RR rr;
	cout << "Order: "; 
	rr.getFileData("fileName"); 
	cout << "\nAverage Waiting Time= " << rr.getAverageWaitingTime() << endl; 
	cout << "Average Throughput= " << rr.getThroughput() << endl;
	cout << "Average Turnaround Time= " << rr.getAverageTurnaroundtime() << endl; 
	cout << "\n"; 	
	
	cout << "Shortest Remaining Time (SRTF)" << endl; 
	SRTF srtf;
	srtf.getFileData("fileName");
	cout << "\nAverage Waiting Time= " << srtf.getAverageWaitingTime() << endl;
	cout << "Average Throughput= " << srtf.getThroughput() << endl;
	cout << "Average Turnaround Time= " << srtf.getAverageTurnaroundtime() << endl; 
	cout << "\n"; 
	
 
}



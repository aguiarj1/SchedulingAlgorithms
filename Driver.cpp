/*
 * Driver.cpp

 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
 */
#include "SJF.h"
#include <iostream>
#include "Process.h"
#include <string>
using namespace std;

int main(){

	SJF sjf;
	sjf.getFileData("jobs.txt"); //change it so constructor takes in the name of file
	cout << "Shortest Job First (SJF)" << endl; 
	cout << "Average Turnaround Time= " << sjf.getAverageTurnaroundtime() << endl; 
	cout << "Average Waiting Time= " << sjf.getAverageWaitingTime() << endl; 
	cout << "Average Waiting Time= " << sjf.getThroughput() << endl;
	
 
}



/*
 * SRTF.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
 */
#include "SRTF.h"
#include <string>
#include <iostream>
#include "Process.h"
#include <fstream>
#include <list> 
#include <iterator>
#include <typeinfo>
#include <queue>
using namespace std;


//Constructor
SRTF::SRTF(){
	lastArrival = -1;
	CPUtimer = -1; //CPU time hasn't started
	sumTurnaroundTime = 0;
	sumWaitingTime = 0;
	countOfProcesses = 0; //FIXME 
	countTotalTime = 0; 

}

void SRTF::getFileData(string fileName){
	cout << fileName << endl; //FIXME
	//print out all values from file
	ifstream afile;
	string line;
	afile.open(fileName); //fixme
	list<Process> alist;    
	//make each line a process
	while(afile >> line){
		//cout << line << endl;
		countOfProcesses++; 
		alist.push_back(makeProcess(line));
	}
	cout << lastArrival << endl;
	//do an array of size lastArrival and fill it with the processes 
	putProcessInArray(alist); 
	list<Process>::iterator itr; 

}

void SRTF::putProcessInArray(list<Process> alist){
	//make array of lists 
	list<Process> allProcesses[lastArrival+1];
	//fill array with empty list
	for(int i = 0; i<lastArrival+1; i++){
		list<Process> temp;
		allProcesses[i]=  temp; 
	}

	list<Process>::iterator itr; 
	for(itr = alist.begin(); itr != alist.end(); ++itr){
		allProcesses[itr->getArrivalTime()].push_back(*itr); 
	}
	
	//initialize a min heap and put all the processes that start at 0
	//start timer will have to be in a while loop FIXME 
	int beg = 0; 
	CPUtimer++;
	cout << "on top CPUtimer= "<< CPUtimer << endl; 
	priority_queue<Process> q; 
	while(CPUtimer <= lastArrival){
		for(int i = beg; i<=CPUtimer; i++){
			if (allProcesses[i].empty()){
		 		//do nothing
			} else {
		 		//add it to the queue 
		 		list<Process>::iterator itr2; 
		 		for(itr2 = allProcesses[i].begin(); itr2 != allProcesses[i].end(); ++itr2){
			 			q.push(*itr2); 
		 		}
			}
		}
		//cout << "PRINT RESULT: "<< endl; 
		Process tempP = q.top();
		tempP.CPUburst = tempP.CPUburst -1;
		
		beg =CPUtimer +1;  //= CPUtimer;
		tempP.terminationTime = CPUtimer + tempP.CPUburst; 
		//cout << "TerminationTime = " << CPUtimer + tempP.CPUburst << endl;
		countTotalTime++; 
		//cout << "Turnaround Time = " << tempP.terminationTime - tempP.ArrivalTime << endl; 
		//cout << "Waiting Time = " << (tempP.terminationTime - tempP.ArrivalTime) - tempP.CPUburst << endl; 
		sumWaitingTime = sumWaitingTime + ((tempP.terminationTime - tempP.arrivalTime) - tempP.CPUburst); 
		
		CPUtimer = CPUtimer + 1;
		//pop, if greater than zero add back in, if 0 don't add
		if(tempP.CPUburst == 0){
			//cout << "sum turnaround time = " << sumTurnaroundTime << endl;
			//countTotalTime = CPUtimer; 
			tempP.printValues();
			cout << "CPUtimer= " << CPUtimer << endl; 
			cout << "tempP.arrivalTime= " << tempP.arrivalTime << endl; 
			int turnAroundTime = CPUtimer - tempP.arrivalTime; 
			sumTurnaroundTime = sumTurnaroundTime + turnAroundTime; 
			q.pop(); 
		} else {
			q.pop(); 
			q.push(tempP); 
		}
		
		//cout << "\n";
		 
	}
	
	//pop remaining 
	//cout << "PRINT RESULT: "<< endl; 
	while(!q.empty()){
		Process tempP = q.top();
		tempP.CPUburst = tempP.CPUburst -1;
		tempP.terminationTime = CPUtimer + tempP.CPUburst; //FIXME
		//cout << "TerminationTime = " << CPUtimer + tempP.CPUburst << endl; //FIXME
		countTotalTime++; 
		CPUtimer = CPUtimer + 1;
		//cout << "Turnaround Time = " << tempP.terminationTime - tempP.ArrivalTime << endl; 
		//cout << "Waiting Time = " << (tempP.terminationTime - tempP.ArrivalTime) - tempP.CPUburst << endl; 
		sumWaitingTime = sumWaitingTime + ((tempP.terminationTime - tempP.arrivalTime) - tempP.CPUburst); 

		//pop, if greater than zero add back in, if 0 don't add
		if(tempP.CPUburst == 0){
			//cout << "sum turnaround time = " << sumTurnaroundTime << endl;
			//countTotalTime = CPUtimer; 
			cout << "CPUtimer= " << CPUtimer << endl; 
			cout << "tempP.arrivalTime= " << tempP.arrivalTime << endl; 
			int turnAroundTime = CPUtimer - tempP.arrivalTime; 
			sumTurnaroundTime = sumTurnaroundTime + turnAroundTime; 
			tempP.printValues(); 
			q.pop(); 
		} else {
			q.pop(); 
			q.push(tempP); 
		}
		//cout << "\n"; 
	}	

	return;
}

//maybe this should be private... helper function
Process SRTF::makeProcess(string line){
	int commas = 0;
	string v1 = "";
	string v2 = "";
	string v3 = "";
	for(int i=0; i<line.size();i++){
		if(line[i] == ','){
			commas++;
		} else {
			if(commas == 0){
				v1 = v1 + line.at(i);
			} else if(commas == 1){
				v2 = v2 + line.at(i);
			} else {
				v3 = v3 + line.at(i);
			}
			//cout << line.at(i) << endl;
		}

	}
	Process p(stoi(v1), stoi(v2), stoi(v3));
	//find out last arrival time;
	if(stoi(v3) > lastArrival){
		lastArrival = stoi(v3);
	}
//	p.printValues();
	return p;
}

double SRTF::getAverageTurnaroundtime(){
	cout << "sumTurnaroundTime= " << sumTurnaroundTime << endl; 
	cout << "countOfProcesses= " << countOfProcesses << endl; 
	double ans = (double(sumTurnaroundTime) / double(countOfProcesses));
	//FIXME set precision higher
	return ans; 
}

double SRTF::getAverageWaitingTime(){
	double ans = (double(sumWaitingTime) / double(countOfProcesses));
	//FIXME set precision higher
	return ans; 
}

double SRTF::getThroughput(){
	double ans = (double(countOfProcesses) / double(countTotalTime)); 
	return ans; 
}


/*
 * SJF.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
 */
#include "SJF.h"
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
SJF::SJF(){
	lastArrival = -1;
	CPUtimer = -1; //CPU time hasn't started
	sumTurnaroundTime = 0;
	sumWaitingTime = 0;
	countOfProcesses = 0; //FIXME 
	countTotalTime = 0; 

}

void SJF::getFileData(string fileName){
	//print out all values from file
	ifstream afile;
	string line;
	afile.open(fileName); //fixme
	list<Process> alist;    
	//make each line a process
	while(afile >> line){
		countOfProcesses++; 
		alist.push_back(makeProcess(line));
	}
	//do an array of size lastArrival and fill it with the processes 
	putProcessInArray(alist); 
	list<Process>::iterator itr; 
}

void SJF::putProcessInArray(list<Process> alist){
	//make array of lists 
	list<Process> allProcesses[lastArrival+1];
	//fill array with empty list
	for(int i = 0; i<lastArrival+1; i++){
		list<Process> temp;
		allProcesses[i]=  temp; 
	}

	//put these processes in an array based on arrival time
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
			 			//cout << itr2->getArrivalTime();  
			// 	 		// cout << ", ";
		 		}
			}
		}
		cout << "PRINT RESULT: "<< endl; 
		Process tempP = q.top();
		tempP.printValues();
		//cout << "before beg = " << beg << endl; 
		beg =CPUtimer +1;  //= CPUtimer;
		//cout << "after beg = " << beg << endl; 
		//cout << "before CPUTimer = " << CPUtimer << endl; 
		tempP.terminationTime = CPUtimer + tempP.CPUburst; 
		cout << "TerminationTime = " << CPUtimer + tempP.CPUburst << endl;
		countTotalTime = CPUtimer + tempP.CPUburst; 
		cout << "Turnaround Time = " << tempP.terminationTime - tempP.ArrivalTime << endl; 
		sumTurnaroundTime = sumTurnaroundTime + tempP.terminationTime - tempP.ArrivalTime; 
		cout << "Waiting Time = " << (tempP.terminationTime - tempP.ArrivalTime) - tempP.CPUburst << endl; 
		sumWaitingTime = sumWaitingTime + ((tempP.terminationTime - tempP.ArrivalTime) - tempP.CPUburst); 
		
		CPUtimer = CPUtimer + tempP.CPUburst;
		 
		//cout << "CPUtimer = " << CPUtimer << endl; 
		q.pop(); 
		cout << "\n";
		 
	}
	//add anything else that is missing
	for(int i = beg; i<=lastArrival; i++){
		//cout << "outer for loop"<< endl; 
		if (allProcesses[i].empty()){
	 		//do nothing
		} else {
	 		//add it to the queue 
	 		//cout << "inside else"<< endl; 
	 		list<Process>::iterator itr2; 
	 		for(itr2 = allProcesses[i].begin(); itr2 != allProcesses[i].end(); ++itr2){
	 				//cout << "inside for" << endl; 
		 			q.push(*itr2); 
		 			//cout << itr2->getArrivalTime();  
		// 	 		// cout << ", ";
	 		}
		}
	}
	//pop remaining 
	cout << "PRINT RESULT: "<< endl; 
	while(!q.empty()){
		Process tempP = q.top();
		tempP.printValues(); 
		tempP.terminationTime = CPUtimer + tempP.CPUburst; //FIXME
		cout << "TerminationTime = " << CPUtimer + tempP.CPUburst << endl; //FIXME
		countTotalTime = CPUtimer + tempP.CPUburst; 
		sumTurnaroundTime = sumTurnaroundTime + tempP.terminationTime - tempP.ArrivalTime;
		CPUtimer = CPUtimer + tempP.CPUburst;
		cout << "Turnaround Time = " << tempP.terminationTime - tempP.ArrivalTime << endl; 
		cout << "Waiting Time = " << (tempP.terminationTime - tempP.ArrivalTime) - tempP.CPUburst << endl; 
		sumWaitingTime = sumWaitingTime + ((tempP.terminationTime - tempP.ArrivalTime) - tempP.CPUburst); 

		q.pop(); 
		cout << "\n"; 
	}	
	
	// cout << "is q empty?= " << q.empty() << endl; 
	// int counter = 0; 
	// while(!q.empty()){
	// 	cout << counter << endl; 
	// 	Process tempP = q.top();
	// 	tempP.printValues(); 
	// 	q.pop(); 
	// 	cout << "\n"; 
	// 	counter++; 
	// }

	return;
}

//maybe this should be private... helper function
Process SJF::makeProcess(string line){
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

double SJF::getAverageTurnaroundtime(){
	double ans = (double(sumTurnaroundTime) / double(countOfProcesses));
	//FIXME set precision higher
	return ans; 
}

double SJF::getAverageWaitingTime(){
	double ans = (double(sumWaitingTime) / double(countOfProcesses));
	//FIXME set precision higher
	return ans; 
}

double SJF::getThroughput(){
	double ans = (double(countOfProcesses) / double(countTotalTime)); 
	return ans; 
}


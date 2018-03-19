/*
 * SJF.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
 */
#include "RR.h"
#include <string>
#include <iostream>
#include "ProcessRR.h"
#include <fstream>
#include <list> 
#include <iterator>
#include <typeinfo>
#include <queue>
using namespace std;


//Constructor
RR::RR(){
	lastArrival = -1;
	CPUtimer = -1; //CPU time hasn't started
	sumTurnaroundTime = 0;
	sumWaitingTime = 0;
	countOfProcesses = 0; //FIXME 
	countTotalTime = 0; 
	newArrival = -1; 

}

void RR::getFileData(string fileName){
	cout << fileName << endl; //FIXME
	//print out all values from file
	ifstream afile;
	string line;
	afile.open(fileName); //fixme
	list<ProcessRR> alist;    
	//make each line a process
	while(afile >> line){
		//cout << line << endl;
		countOfProcesses++; 
		alist.push_back(makeProcess(line));
	}
	newArrival = countOfProcesses; 
	cout << lastArrival << endl;
	//do an array of size lastArrival and fill it with the processes 
	putProcessInArray(alist); 
	list<ProcessRR>::iterator itr; 
	
	//make a min heap
	//set up logic of putting in min heap if the time is equal or less

}

void RR::putProcessInArray(list<ProcessRR> alist){
	//make array of lists 
	list<ProcessRR> allProcesses[lastArrival+1];
	//fill array with empty list
	for(int i = 0; i<lastArrival+1; i++){
		list<ProcessRR> temp;
		allProcesses[i]=  temp; 
	}

	//put these processes in an array based on arrival time
	list<ProcessRR>::iterator itr; 
	for(itr = alist.begin(); itr != alist.end(); ++itr){
		allProcesses[itr->getArrivalTime()].push_back(*itr); 
	}
	
	
	//initialize a min heap and put all the processes that start at 0
	int beg = 0; 
	CPUtimer++;
	cout << "on top CPUtimer= "<< CPUtimer << endl; 
	priority_queue<ProcessRR> q; 
	while(CPUtimer <= lastArrival){
		for(int i = beg; i<=CPUtimer; i++){
			if (allProcesses[i].empty()){
		 		//do nothing
			} else {
		 		//add it to the queue 
		 		list<ProcessRR>::iterator itr2; 
		 		for(itr2 = allProcesses[i].begin(); itr2 != allProcesses[i].end(); ++itr2){
			 			q.push(*itr2); 
		 		}
			}
		}
		cout << "PRINT RESULT: "<< endl; 
		ProcessRR tempP = q.top();
		tempP.printValues();
		beg =CPUtimer +1;  
		CPUtimer = CPUtimer + 1; 
		//subtract one unit of time from top 
		tempP.CPUburst = tempP.CPUburst -1;  
		//pop, if greater than zero add back in, if 0 don't add
		if(tempP.CPUburst == 0){
			cout << "CPU timer / Termination time = " << CPUtimer << endl;
			cout << "Arrival time=  " << tempP.arrivalTime << endl;  
			sumTurnaroundTime = sumTurnaroundTime + (CPUtimer - tempP.arrivalTime);
			cout << "sum turnaround time = " << sumTurnaroundTime << endl;
			countTotalTime = CPUtimer; 
			q.pop(); 
		} else {
			q.pop(); 
			newArrival= CPUtimer; 
			tempP.priority = -1; //appear first
			cout<< "new Arrival: " << newArrival << endl; 
			tempP.ArrivalTime = newArrival; 
			q.push(tempP); 
		}
		
		cout << "\n";
		 
	}
	
	//pop remaining 
	cout << "PRINT RESULT: "<< endl; 
	while(!q.empty()){
		ProcessRR tempP = q.top();
		tempP.printValues(); 
		CPUtimer = CPUtimer + 1; 
		//subtract one unit of time from top 
		tempP.CPUburst = tempP.CPUburst -1;  
		//pop, if greater than zero add back in, if 0 don't add
		if(tempP.CPUburst == 0){
			sumTurnaroundTime = sumTurnaroundTime + (CPUtimer - tempP.arrivalTime);
			countTotalTime = CPUtimer;
			q.pop(); 
		} else {
			q.pop(); 
			newArrival= CPUtimer; 
			tempP.priority = -1; 
			tempP.ArrivalTime = newArrival; 
			q.push(tempP); 
		}
		cout << "\n"; 
	}	
	return;
}

//maybe this should be private... helper function
ProcessRR RR::makeProcess(string line){
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
	ProcessRR p(stoi(v1), stoi(v2), stoi(v3));
	//find out last arrival time;
	if(stoi(v3) > lastArrival){
		lastArrival = stoi(v3);
	}
//	p.printValues();
	return p;
}

double RR::getAverageTurnaroundtime(){
	cout << "sum turnaround time: " << sumTurnaroundTime << endl; 
	double ans = (double(sumTurnaroundTime) / double(countOfProcesses));
	//FIXME set precision higher
	return ans; 
}

double RR::getAverageWaitingTime(){
	double ans = (double(sumWaitingTime) / double(countOfProcesses));
	//FIXME set precision higher
	return ans; 
}

double RR::getThroughput(){
	double ans = (double(countOfProcesses) / double(countTotalTime)); 
	return ans; 
}


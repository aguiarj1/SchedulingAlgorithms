/*
 * RR.cpp
 * This is the implementation of the 
 * Round Robin scheduling algorithm. 
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
//gets the data from the file and puts them into 
//a list of Process objects
void RR::getFileData(string fileName){
	//print out all values from file
	ifstream afile;
	string line;
	afile.open(fileName); //fixme
	list<ProcessRR> alist;    
	//make each line a process
	while(afile >> line){
		countOfProcesses++; 
		alist.push_back(makeProcess(line));
	}
	newArrival = countOfProcesses; 
	//do an array of size lastArrival and fill it with the processes 
	putProcessInArray(alist); 
	list<ProcessRR>::iterator itr; 
	
	//make a min heap
	//set up logic of putting in min heap if the time is equal or less

}
//puts all the processes in an array and then 
//uses a minqueue to process them. 
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
		ProcessRR tempP = q.top();
		tempP.printValues();
		beg =CPUtimer +1;  
		CPUtimer = CPUtimer + 1; 
		//subtract one unit of time from top 
		tempP.CPUburst = tempP.CPUburst -1;  
		//pop, if greater than zero add back in, if 0 don't add
		if(tempP.CPUburst == 0){
			sumTurnaroundTime = sumTurnaroundTime + (CPUtimer - tempP.arrivalTime);
			countTotalTime = CPUtimer; 
			int turnaroundtime = CPUtimer - tempP.arrivalTime; 
			int waitingtime = turnaroundtime - tempP.tempCPUburst; 
			sumWaitingTime = sumWaitingTime + waitingtime; 
			q.pop(); 
		} else {
			q.pop(); 
			newArrival= CPUtimer; 
			tempP.priority = -1; //appear first
			tempP.tempArrivalTime = newArrival; 
			q.push(tempP); 
		}
	}
	
	//pop remaining 
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
			int turnaroundtime = CPUtimer - tempP.arrivalTime; 
			int waitingtime = turnaroundtime - tempP.tempCPUburst; 
			sumWaitingTime = sumWaitingTime + waitingtime; 
			q.pop(); 
		} else {
			q.pop(); 
			newArrival= CPUtimer; 
			tempP.priority = -1; 
			tempP.tempArrivalTime = newArrival; 
			q.push(tempP); 
		}
	}	
	return;
}

//goes through text and gets the data from the file
//to make a Process object 
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
//calculates and returns the turnaroundtime
double RR::getAverageTurnaroundtime(){
	double ans = (double(sumTurnaroundTime) / double(countOfProcesses));
	//FIXME set precision higher
	return ans; 
}
//calculates and returns the averagewait time
double RR::getAverageWaitingTime(){
	double ans = (double(sumWaitingTime) / double(countOfProcesses));
	//FIXME set precision higher
	return ans; 
}
//calculates and returns the throughput
double RR::getThroughput(){
	double ans = (double(countOfProcesses) / double(countTotalTime)); 
	return ans; 
}


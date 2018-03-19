/*
 * SJF.cpp
 * This is the Shortest Job First Scheduling 
 * algorithm. 
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
	countOfProcesses = 0; 
	countTotalTime = 0; 

}

//gets the data from the file and puts them into 
//a list of Process objects
void SJF::getFileData(string fileName){
	//print out all values from file
	ifstream afile;
	string line;
	afile.open(fileName); 
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

//puts all the processes in an array and then 
//uses a minqueue to process them. 
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
		Process tempP = q.top();
		tempP.printValues();
		beg =CPUtimer +1; 
		tempP.terminationTime = CPUtimer + tempP.CPUburst; 
		countTotalTime = CPUtimer + tempP.CPUburst; 
		
		sumTurnaroundTime = sumTurnaroundTime + tempP.terminationTime - tempP.arrivalTime; 
		
		sumWaitingTime = sumWaitingTime + ((tempP.terminationTime - tempP.arrivalTime) - tempP.CPUburst); 
		
		CPUtimer = CPUtimer + tempP.CPUburst;
		q.pop(); 
		 
	}
	//add anything else that is missing
	for(int i = beg; i<=lastArrival; i++){
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
	//pop remaining 
	while(!q.empty()){
		Process tempP = q.top();
		tempP.printValues(); 
		tempP.terminationTime = CPUtimer + tempP.CPUburst; 
		countTotalTime = CPUtimer + tempP.CPUburst; 
		sumTurnaroundTime = sumTurnaroundTime + tempP.terminationTime - tempP.arrivalTime;
		CPUtimer = CPUtimer + tempP.CPUburst;
		sumWaitingTime = sumWaitingTime + ((tempP.terminationTime - tempP.arrivalTime) - tempP.CPUburst); 
		q.pop(); 
	}	
	return;
}

//goes through text and gets the data from the file
//to make a Process object 
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
//calculates and returns the turnaroundtime
double SJF::getAverageTurnaroundtime(){
	double ans = (double(sumTurnaroundTime) / double(countOfProcesses));
	//FIXME set precision higher
	return ans; 
}
//calculates and returns the averagewait time
double SJF::getAverageWaitingTime(){
	double ans = (double(sumWaitingTime) / double(countOfProcesses));
	//FIXME set precision higher
	return ans; 
}
//calculates and returns the throughput
double SJF::getThroughput(){
	double ans = (double(countOfProcesses) / double(countTotalTime)); 
	return ans; 
}


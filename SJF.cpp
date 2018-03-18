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

}

void SJF::getFileData(string fileName){
	cout << fileName << endl; //FIXME
	//print out all values from file
	ifstream afile;
	string line;
	afile.open(fileName); //fixme
	list<Process> alist;    
	//make each line a process
	while(afile >> line){
		//cout << line << endl;
		alist.push_back(makeProcess(line));
	}
	cout << lastArrival << endl;
	//do an array of size lastArrival and fill it with the processes 
	putProcessInArray(alist); 
	list<Process>::iterator itr; 
	
	// for(itr = alist.begin(); itr != alist.end(); ++itr){
	//  	itr->printValues(); 
	//  	cout << "\n"; 
	// }
	//make a min heap
	//set up logic of putting in min heap if the time is equal or less

}

void SJF::putProcessInArray(list<Process> alist){
	//make array of lists 
	list<Process> allProcesses[lastArrival+1];
	//fill array with empty list
	for(int i = 0; i<lastArrival+1; i++){
		list<Process> temp;
		allProcesses[i]=  temp; 
	}
	// for(int i = 0; i<lastArrival+1; i++){
	// 	if (allProcesses[i].empty()){
	// 		cout << "empty" << endl;
	// 	}
	// }
	//put these processes in an array based on arrival time
	// list<Process>::iterator itr; 
	// for(itr = alist.begin(); itr != alist.end(); ++itr){
	// 	allProcesses[itr->getArrivalTime()].push_back(*itr); 
		
	// 	cout << itr->getArrivalTime();  
 //		cout << "\n"; 
	// }
	
	// for(int i = 0; i<lastArrival+1; i++){
	// 	if (allProcesses[i].empty()){
	// 		cout << "empty" << endl;
	// 	}
	// 	else {
	// 		cout << "not empty" << endl; 
	// 		list<Process>::iterator itr2; 
	// 		for(itr2 = allProcesses[i].begin(); itr2 != allProcesses[i].end(); ++itr2){
	// 			cout << itr2->getArrivalTime();  
	// 	 		cout << ", "; 
	// 		}
	// 	}
	// 	cout << " " << endl; 
	// }
	
	//initialize a min heap and put all the processes that start at 0
	//start timer will have to be in a while loop FIXME 
	int beg = 0; 
	CPUtimer++; 
	priority_queue<Process> q; 
	while(CPUtimer > lastArrival){
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
		//beg = CPUtimer; 
		CPUtimer++; 		
	}
	cout << "is q empty?= " << q.empty() << endl; 
	while(!q.empty()){
		Process tempP = q.top();
		tempP.printValues(); 
		q.pop(); 
	}

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


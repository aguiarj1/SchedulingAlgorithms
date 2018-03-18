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
using namespace std;


//Constructor
SJF::SJF(){
	lastArrival = -1;

}

void SJF::getFileData(string fileName){
	cout << fileName << endl; //FIXME
	//print out all values from file
	ifstream afile;
	string line;
	afile.open(fileName); //fixme
	//make each line a process
	while(afile >> line){
		cout << line << endl;
		putProcessInArray(makeProcess(line));
	}
	cout << lastArrival << endl;

	//put these processes in an array based on arrival time
		//create array
	//make a min heap
	//set up logic of putting in min heap if the time is equal or less

}

void SJF::putProcessInArray(Process p){
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
			cout << line.at(i) << endl;
		}

	}
	Process p(stoi(v1), stoi(v2), stoi(v3));
	//find out last arrival time;
	if(stoi(v3) > lastArrival){
		lastArrival = stoi(v3);
	}
	p.printValues();
	return p;
}


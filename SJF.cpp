/*
 * SJF.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
 */
#include "SJF.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


//Constructor
SJF::SJF(){


}

void SJF::getFileData(string s){
	cout << s << endl; //FIXME
	//print out all values from file
	ifstream afile;
	string line;
	afile.open("jobs.txt");
	while(afile >> line){
		cout << line << endl;
	}


}


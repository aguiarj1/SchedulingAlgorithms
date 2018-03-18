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
	Process p(6,5,10);
	Process p1(7,8,15);
	//cout << (p1<p);
	priority_queue<Process> q;
	if(q.empty()){
		cout << "YESempty"<< endl;
	}
	q.push(p);
	q.push(p1);
		if(!q.empty()){
		cout << "NOT empty"<< endl;
	}
	Process temp= q.top();
	temp.printValues(); 
 
}



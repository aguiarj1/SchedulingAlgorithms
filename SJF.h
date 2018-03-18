/*
 * SJF.h
 *
 *  Created on: Mar 17, 2018
 *      Author: jagui
 */

#ifndef SJF_H_
#define SJF_H_
#include <string>
#include "Process.h"
#include <iostream>
using namespace std;

class SJF {
private:
	int lastArrival;
public :
	SJF();
	void getFileData(string);
	Process makeProcess(string s);
	void putProcessInArray(Process p);
};



#endif /* SJF_H_ */

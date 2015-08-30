/*
 * taskQueue.cpp
 *
 *  Created on: 2015Äê8ÔÂ30ÈÕ
 *      Author: Administrator
 */

#include "task.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

task::task() {
	// TODO Auto-generated constructor stub

}

task::~task() {
	// TODO Auto-generated destructor stub
}

void task::run()
{
	cout << "threadid:" << getpid() << endl;
	cout << "hello" << endl;
	sleep(1);
}

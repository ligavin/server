/*
 * worker.h
 *
 *  Created on: 2015Äê8ÔÂ29ÈÕ
 *      Author: gavinlli
 */

#ifndef WORKER_H_
#define WORKER_H_

#include "iostream"

using namespace std;


class worker {
public:
	worker();
	virtual ~worker();
	virtual void run() = 0;
};


#endif /* WORKER_H_ */

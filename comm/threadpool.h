/*
 * threadpool.h
 *
 *  Created on: 2015Äê8ÔÂ29ÈÕ
 *      Author: gavinlli
 */


#include "worker.h"
#include <vector>

#ifndef THREADPOOL_H_
#define THREADPOOL_H_

class threadpool {
public:
	threadpool(int num);
	virtual ~threadpool();

private:
	int numOfThread;
	std::vector<worker*> workers;
};

#endif /* THREADPOOL_H_ */

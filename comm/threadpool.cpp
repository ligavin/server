/*
 * threadpool.cpp
 *
 *  Created on: 2015Äê8ÔÂ29ÈÕ
 *      Author: gavinlli
 */

#include "threadpool.h"

threadpool::threadpool(int num):numOfThread(num)
{
	// TODO Auto-generated constructor stub

	for (int i = 0 ; i < numOfThread; ++i)
	{
		workers.push_back(new worker());
		workers[i]->run();
	}
}

threadpool::~threadpool() {
	// TODO Auto-generated destructor stub

	for (int i = 0; i < workers.size(); ++i)
		delete workers[i];
}

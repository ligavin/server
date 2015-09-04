/*
 * taskQueue.h
 *
 *  Created on: 2015年8月30日
 *      Author: gavinlli
 */

#ifndef TASKQUEUE_H_
#define TASKQUEUE_H_

class task
{
public:
	task();
	virtual ~task();
	virtual void run();
};

#endif /* TASKQUEUE_H_ */

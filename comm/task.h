/*
 * taskQueue.h
 *
 *  Created on: 2015��8��30��
 *      Author: Administrator
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

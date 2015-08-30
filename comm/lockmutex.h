/*
 * lockmutex.h
 *
 *  Created on: 2015��8��30��
 *      Author: Administrator
 */

#ifndef LOCKMUTEX_H_
#define LOCKMUTEX_H_

#include <pthread.h>

class lock_mutex
{
public:
	lock_mutex();
	virtual ~lock_mutex();
	void lock();
	void unlock();

private:
	pthread_mutex_t mutex;
};

#endif /* LOCKMUTEX_H_ */

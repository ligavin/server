/*
 * lockmutex.cpp
 *
 *  Created on: 2015Äê8ÔÂ30ÈÕ
 *      Author: Administrator
 */

#include "lockmutex.h"

lock_mutex::lock_mutex() {
	// TODO Auto-generated constructor stub
	pthread_mutex_init(&mutex, NULL);
}

lock_mutex::~lock_mutex() {
	// TODO Auto-generated destructor stub

	pthread_mutex_destroy(&mutex);
}

void lock_mutex::lock()
{
	pthread_mutex_lock(&mutex);
}

void lock_mutex::unlock()
{
	pthread_mutex_unlock(&mutex);
}

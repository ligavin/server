/*
 * threadpool.h
 *
 *  Created on: 2015Äê8ÔÂ29ÈÕ
 *      Author: gavinlli
 */
#ifndef THREADPOOL_H_
#define THREADPOOL_H_


#include "task.h"
#include "lock.h"
#include "lockmutex.h"
#include "lockcond.h"
#include <vector>
#include <queue>
#include "pthread.h"

class thread_pool {
public:
	thread_pool(int num, int queSize);
	virtual ~thread_pool();
	bool push(task *t);
	bool pop(task **t);
	static void *work(void *p);
	void stop_run();
	unsigned get_queue_size();

private:
	int maxQueSize;
	int numOfThread;
	std::queue<task*> reqQue;
	lock_mutex m_locker;
	lock_cond m_cond;
	bool stop;
	std::vector<pthread_t> pt;
};

class thread_data
{
public:
	thread_pool *m_tp;
	pthread_t m_tid;

	thread_data(thread_pool *tp, pthread_t tid):m_tp(tp),m_tid(tid)
	{}
	virtual ~thread_data(){}
};


#endif /* THREADPOOL_H_ */

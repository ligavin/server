/*
 * threadpool.cpp
 *
 *  Created on: 2015Äê8ÔÂ29ÈÕ
 *      Author: gavinlli
 */

#include "threadpool.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

thread_pool::thread_pool(int num, int queSize):numOfThread(num), maxQueSize(queSize)
{
	// TODO Auto-generated constructor stub
	stop = false;

	for(int i = 0; i < numOfThread; ++i)
	{
		pthread_t tid;

		int ret = pthread_create(&tid, NULL, (thread_pool::work), this);
		if (ret != 0)
			continue;

		pthread_detach(tid);

		pt.push_back(tid);
	}
}

thread_pool::~thread_pool() {
	// TODO Auto-generated destructor stub
	stop_run();
}


bool thread_pool::push(task *t)
{
	if (NULL == t)
		return false;

	m_locker.lock();
	if (reqQue.size() >= maxQueSize)
	{
		m_locker.unlock();
		return false;
	}
	reqQue.push(t);
	m_cond.post_msg();
	m_locker.unlock();
	return true;
}
bool thread_pool::pop(task **t)
{
	if (NULL == t )
	{
		return false;
	}

	m_locker.lock();

	if (reqQue.empty())
	{
		m_cond.wait_with_time((m_locker.get_mutex()));

		if (reqQue.empty())
		{
			m_locker.unlock();
			return false;
		}
	}

	*t = reqQue.front();
	reqQue.pop();

	m_locker.unlock();
	return true;
}

void *thread_pool::work(void *p)
{
	thread_pool *p_tp = (thread_pool*)p;
	while(!p_tp->stop)
	{
		task *t;

		if (!p_tp->pop(&t))
		{
			continue;
		}

		t->run();
		delete t;
	}
}

void thread_pool::stop_run()
{
	stop = true;

	while(!reqQue.empty())
	{
		task *task = reqQue.front();
		reqQue.pop();

		if (NULL != task)
			delete task;
	}
}

unsigned thread_pool::get_queue_size()
{
	return reqQue.size();
}



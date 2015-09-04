/*
 * threadpool.cpp
 *
 *  Created on: 2015年8月29日
 *      Author: gavinlli
 */

#include "threadpool.h"
#include <iostream>
#include <stdlib.h>
#include "timer.h"
#include <stdio.h>

using namespace std;

thread_pool::thread_pool(int num, int queSize):numOfThread(num), maxQueSize(queSize)
{
	// TODO Auto-generated constructor stub
	stop = false;

	for(int i = 0; i < numOfThread; ++i)
	{
		pthread_t tid;
		thread_data *td = new thread_data(this, tid);

		int ret = pthread_create(&tid, NULL, (thread_pool::work), td);
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

	lock<lock_mutex> locker(m_locker);

	if (reqQue.size() >= maxQueSize)
	{
		return false;
	}

	reqQue.push(t);
	m_cond.post_msg();
	return true;
}
bool thread_pool::pop(task **t)
{
	if (NULL == t )
	{
		return false;
	}

	lock<lock_mutex> locker(m_locker);

	if (reqQue.empty())
	{
		m_cond.wait_with_time((m_locker.get_mutex()),0,1000000);

		if (reqQue.empty())
		{
			return false;
		}
	}

	*t = reqQue.front();
	reqQue.pop();

	return true;
}

void *thread_pool::work(void *p)
{
	thread_data *td = (thread_data*)p;
	thread_pool *p_tp = td->m_tp;
	while(!p_tp->stop)
	{
		timer tm;
		task *t;

	//	cout << "tid:" << td->m_tid << endl;
		if (!p_tp->pop(&t))
		{
			continue;
		}

		t->run();

		delete t;
	}
	delete td;
}

void thread_pool::stop_run()
{
	stop = true;
	lock<lock_mutex> locker(m_locker);

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
	lock<lock_mutex> locker(m_locker);
	return reqQue.size();
}




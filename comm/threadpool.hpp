/*
 * threadpool.h
 *
 *  Created on: 2015年8月29日
 *      Author: gavinlli
 */
#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include "bufferqueue.hpp"
#include <vector>
#include <queue>
#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include "timer.h"
#include <stdio.h>

using namespace std;

template<class Ttask>
class thread_pool
{
public:
	thread_pool(int num, int queSize);
	virtual ~thread_pool();
	bool push(const Ttask &t);
	bool pop(Ttask &t);
	static void *work(void *p);
	void stop_run();
	unsigned get_queue_size();

private:
	int m_numOfTtaskhread;
	bool m_stop;
	buffer_queue<Ttask> m_que;
};

template<class Ttask>
class thread_data
{
public:
	thread_pool<Ttask> *m_tp;
	pthread_t m_tid;

	thread_data(thread_pool<Ttask> *tp, pthread_t tid):m_tp(tp),m_tid(tid)
	{}
	virtual ~thread_data(){}
};

template<class Ttask>
thread_pool<Ttask>::thread_pool(int num, int queSize):m_numOfTtaskhread(num), m_que(queSize)
{
	// TtaskODO Auto-generated constructor stub
	m_stop = false;

	for(int i = 0; i < m_numOfTtaskhread; ++i)
	{
		pthread_t tid;
		thread_data<Ttask> *td = new thread_data<Ttask>(this, tid);

		int ret = pthread_create(&tid, NULL, (thread_pool::work), td);

		if (ret != 0)
			continue;

		pthread_detach(tid);

	}
}

template<class Ttask>
thread_pool<Ttask>::~thread_pool() {
	// TtaskODO Auto-generated destructor stub
	stop_run();
}

template<class Ttask>
bool thread_pool<Ttask>::push(const Ttask &t)
{
	return m_que.push(t);
}

template<class Ttask>
bool thread_pool<Ttask>::pop(Ttask &t)
{
	return m_que.pop(t);
}

template<class Ttask>
void *thread_pool<Ttask>::work(void *p)
{
	thread_data<Ttask> *td = (thread_data<Ttask>*)p;
	thread_pool<Ttask> *p_tp = td->m_tp;
	while(!p_tp->m_stop)
	{
		Ttask t;

		cout << "tid:" << td->m_tid << endl;
		if (!p_tp->pop(t))
		{
			continue;
		}

		t.run();
	}
	delete td;
}

template<class Ttask>
void thread_pool<Ttask>::stop_run()
{
	m_stop = true;
}


#endif /* THREADPOOL_H_ */

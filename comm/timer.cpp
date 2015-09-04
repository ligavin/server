/*
 * timer.cpp
 *
 *  Created on: 2015年9月3日
 *      Author: gavinlli
 */

#include "timer.h"
#include <stdio.h>


timer::timer() {
	// TODO Auto-generated constructor stub
	start();
}

timer::~timer() {
	// TODO Auto-generated destructor stub
}

void timer::start()
{
	gettimeofday( &m_start, NULL);
}
double timer::get_time()
{
	struct timeval end;
	gettimeofday( &end, NULL);
	double timeuse = (end.tv_sec - m_start.tv_sec ) + 1.0*(end.tv_usec - m_start.tv_usec)/1000000;
	return timeuse;
}

/*
 * toools.h
 *
 *  Created on: 2015Äê8ÔÂ29ÈÕ
 *      Author: gavinlli
 */

#include <sstream>


template<typename T> std::string tostr(const T& t)
{
	std::ostringstream s;
	s << t;
	return s.str();
}

template<typename T> T strto(const std::string& s)
{
	std::istringstream is(s);
	T t;
	is >> t;
	return t;
}

void Daemon();

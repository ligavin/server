/*
 * main.cpp
 *
 *  Created on: 2015年8月29日
 *      Author: gavinlli
 */


#include <iostream>
#include "comm/tools.h"
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <getopt.h>
#include "comm/threadpool.hpp"
#include <stdlib.h>
#include "task.h"

using namespace std;

void showUsage()
{
	cout << "usage: --ip 127.0.0.1 --port 8080 -h help" << endl;
}

const char *short_opts = "hi:p:";
const struct option long_opts[] = {
	{"help", no_argument, NULL, 'h'},
	{"ip", required_argument, NULL, 'i'},
	{"port", required_argument, NULL, 'p'},
	{0, 0, 0, 0}
};



int main(int argc, char** argv)
{
	//Daemon();

	/*int opt = 0;
	char ip[20] = "\0";
	int port = 0;

	while((opt = getopt_long(argc, argv, short_opts, long_opts, NULL)) != -1)
	{
		switch(opt)
		{
		case 'i':
			snprintf(ip, sizeof(ip), "%s", optarg);
			break;
		case 'p':
			port = strto<int>(optarg);
			break;
		case 'h':
		default:
			showUsage();
			return -1;
		}
	}

	if (argc < 3)
	{
		showUsage();
		return -1;
	}

	cout << ip << ":" << port << endl;*/

	thread_pool<task> tp = thread_pool<task>(2, 1000000);

	sleep(15);
	cout << "begin to push task" << endl;
	/*for (int i = 0; i < 100000000; ++i)
	{
		task pt;
		cout << "i:" << i << endl;

		tp.push(pt);

//		if (i % 100000 == 0)
//			cout << i << endl;
	}*/

	cout << "push task over" << endl;

	sleep(200);

	return 0;
}


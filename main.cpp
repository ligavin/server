/*
 * main.cpp
 *
 *  Created on: 2015年8月29日
 *      Author: gavinlli
 */


#include <iostream>
#include "comm/transfer_server.h"
#include "comm/tools.h"
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <getopt.h>
#include "comm/threadpool.h"
#include <stdlib.h>

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

	thread_pool tp = thread_pool(2, 1000);

	for (int i = 0; i < 1000; ++i)
	{
		task *pt = new task;
		cout << "i:" << i << endl;

		tp.push(pt);
	}

	sleep(200);

	return 0;
}


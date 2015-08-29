/*
 * main.cpp
 *
 *  Created on: 2015Äê8ÔÂ29ÈÕ
 *      Author: gavinlli
 */


#include <iostream>
#include "comm/transfer_server.h"
#include "comm/tools.h"
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <getopt.h>

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
	Daemon();

	int opt = 0;
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

	cout << ip << ":" << port << endl;

	return 0;
}


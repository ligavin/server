/*
 * tools.cpp
 *
 *  Created on: 2015年8月29日
 *      Author: gavinlli
 */

#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>

void Daemon()
{
	pid_t pid;

	if ((pid = fork()) != 0) { exit(0); }

	setsid();
	signal(SIGINT, SIG_IGN);
	signal(SIGHUP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGCHLD, SIG_IGN);
	signal(SIGTERM, SIG_IGN);

	// ignore_pipe();
	struct sigaction sig;
	sig.sa_handler = SIG_IGN;
	sig.sa_flags = 0;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGPIPE, &sig, NULL);

	if ((pid = fork()) != 0) 	{ exit(0);	}

	//chdir("/");

	umask(0);

	for (int i = 3; i < 64; i++)
		close(i);
}

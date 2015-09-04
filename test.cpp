#include<iostream>
#include<pthread.h>
#include <stdio.h>

using namespace std;

void *work(void *p)
{
	while(1)
	{
		cout << "1111:" << *(int*)p << endl;
		sleep(1);
	}
	delete (int*)p;
	return NULL;
}

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		pthread_t tid;
		int *p = new int(i);

		int ret = pthread_create(&tid, NULL, work, (void*)p);

		cout << "1tid:" << tid << ",i:" << i << endl;
		sleep(1);
		if (ret != 0)
			continue;

		pthread_detach(tid);
	}
	return 0;
}
#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <ctime>
#define CH 2
#define BARBERS 1
using namespace std;
//设置三个mutex，分别是互斥量，理发师，客户
HANDLE hMutex, hBarbers, hCustomers;
int customer_id, waits;
//下面是理发师和客户的线程函数
DWORD WINAPI barber_thread(void *param);
DWORD WINAPI customer_thread(void *param);

DWORD WINAPI barber_thread(void *param)
{
	int my_id = *(int *)param;
	while(1)
	{
		//infinite是等待时间，如果是无穷，就是先进入等待区，一定要进入cr才会返回。
		//下面就是对客户信号量hCustomers的操作
		WaitForSingleObject(hCustomers, INFINITE);
		//对全局互斥量hMutex的操作
		WaitForSingleObject(hMutex, INFINITE);
		//等待的人减一
		waits--;
		//就是第二个参数是release要加的值。
		//up操作，对于barber信号量
		ReleaseSemaphore(hBarbers, 1, NULL);
		//在这里加上唤醒客户的进程，让准备好的客户来剪头，这样会更有秩序一点
		ResumeThread(hCustomers);// call a customer to haircut
		//up操作，对全局互斥量
		ReleaseMutex(hMutex);
		//对理发师线程来说的理发过程
		printf("%dth barber starts to haircut\n", my_id);//第N个理发师开始去理发
		Sleep(7000);
		printf("%dth barber finish haircut and charges\n", my_id);//第N个理发师完成理发并收费
	}
	return 0;
}
DWORD WINAPI customer_thread(void *param)
{
	int my_id;
	my_id = ++customer_id;
	printf("-------%dth customer come\n", my_id);//第N个顾客进店
	//down操作，对全局互斥量，进入CR
	WaitForSingleObject(hMutex, INFINITE);
	//判断还有没有多余的椅子
	if(waits<CH)
	{
	//等待的人数加1
		waits++;
		printf("%dth customer sits. Now totally %d customers waiting\n", my_id, waits);//第N个顾客坐椅子上,现在有waits个顾客等待
		//up,对客户信号量
		ReleaseSemaphore(hCustomers, 1, NULL);
		//准备好的客户呼唤理发师来理发
		ResumeThread(hBarbers);
		//call a barber to haircut此时customer还没离开临界区，barber即使resume也没获得控制
		ReleaseMutex(hMutex);

		printf("%dth customer is waiting\n", my_id);//第N个顾客等待理发
		//down操作，对于理发师信号量
		WaitForSingleObject(hBarbers, INFINITE);
		printf("%dth customer get ready for haircut\n", my_id);//第N个顾客开始理发
		Sleep(7000);
		printf("%dth customer have been haircut and pay\n", my_id);//第N个顾客理发完毕并付钱
		Sleep(10);
		printf("%dth customer leave\n", my_id);//第N个顾客离开
	}
	else
	{
		printf("Now totally %d customers waiting.No seat. %dth customer leaves. \n",  waits, my_id);//现在等待的顾客有N个 没有空椅子坐 第N个顾客离开
		ReleaseMutex(hMutex);
	}
	return 0;
}
int main ()
{
	//第一个变量都是权限，有点线程里面的创建一个新的线程,A pointer to a SECURITY_ATTRIBUTES structure.
	//If this parameter is NULL, the handle cannot be inherited by child processes.
	//定义信号量和互斥量
	hMutex = CreateMutex(NULL, FALSE, "mutex");
	hBarbers = CreateSemaphore(NULL, 0, BARBERS, "barbers"); // barbers currently available
	hCustomers = CreateSemaphore(NULL, 0, CH, "customer"); //customers waiting

	HANDLE h;
	int *temp = new int [BARBERS];
	//对于理发师，每个理发师都是一个单独的线程。
	for(int i=0; i<BARBERS; ++i)
	{
		temp[i] = i+1; // barber's id
		h = CreateThread(NULL, 0, barber_thread, (void *)(&temp[i]), 0, NULL);
	}
	srand(time(NULL));
	//随机产生客户，每个客户也都是一个线程。
	while(1)
	{
		if(rand()%4==0)
			h = CreateThread(NULL, 0, customer_thread, NULL, 0, NULL);
		if(rand()%3==0)
			h = CreateThread(NULL, 0, customer_thread, NULL, 0, NULL);
		if(rand()%2==0)
			h = CreateThread(NULL, 0, customer_thread, NULL, 0, NULL);
		Sleep(1000);
	}
	delete temp;
	//关掉信号量
	CloseHandle(hMutex);
	CloseHandle(hBarbers);
	CloseHandle(hCustomers);
	CloseHandle(h);
	return 0;
}

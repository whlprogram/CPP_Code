#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <ctime>
#define CH 2
#define BARBERS 1
using namespace std;
//��������mutex���ֱ��ǻ���������ʦ���ͻ�
HANDLE hMutex, hBarbers, hCustomers;
int customer_id, waits;
//��������ʦ�Ϳͻ����̺߳���
DWORD WINAPI barber_thread(void *param);
DWORD WINAPI customer_thread(void *param);

DWORD WINAPI barber_thread(void *param)
{
	int my_id = *(int *)param;
	while(1)
	{
		//infinite�ǵȴ�ʱ�䣬�������������Ƚ���ȴ�����һ��Ҫ����cr�Ż᷵�ء�
		//������ǶԿͻ��ź���hCustomers�Ĳ���
		WaitForSingleObject(hCustomers, INFINITE);
		//��ȫ�ֻ�����hMutex�Ĳ���
		WaitForSingleObject(hMutex, INFINITE);
		//�ȴ����˼�һ
		waits--;
		//���ǵڶ���������releaseҪ�ӵ�ֵ��
		//up����������barber�ź���
		ReleaseSemaphore(hBarbers, 1, NULL);
		//��������ϻ��ѿͻ��Ľ��̣���׼���õĿͻ�����ͷ���������������һ��
		ResumeThread(hCustomers);// call a customer to haircut
		//up��������ȫ�ֻ�����
		ReleaseMutex(hMutex);
		//����ʦ�߳���˵��������
		printf("%dth barber starts to haircut\n", my_id);//��N����ʦ��ʼȥ��
		Sleep(7000);
		printf("%dth barber finish haircut and charges\n", my_id);//��N����ʦ��������շ�
	}
	return 0;
}
DWORD WINAPI customer_thread(void *param)
{
	int my_id;
	my_id = ++customer_id;
	printf("-------%dth customer come\n", my_id);//��N���˿ͽ���
	//down��������ȫ�ֻ�����������CR
	WaitForSingleObject(hMutex, INFINITE);
	//�жϻ���û�ж��������
	if(waits<CH)
	{
	//�ȴ���������1
		waits++;
		printf("%dth customer sits. Now totally %d customers waiting\n", my_id, waits);//��N���˿���������,������waits���˿͵ȴ�
		//up,�Կͻ��ź���
		ReleaseSemaphore(hCustomers, 1, NULL);
		//׼���õĿͻ�������ʦ����
		ResumeThread(hBarbers);
		//call a barber to haircut��ʱcustomer��û�뿪�ٽ�����barber��ʹresumeҲû��ÿ���
		ReleaseMutex(hMutex);

		printf("%dth customer is waiting\n", my_id);//��N���˿͵ȴ���
		//down������������ʦ�ź���
		WaitForSingleObject(hBarbers, INFINITE);
		printf("%dth customer get ready for haircut\n", my_id);//��N���˿Ϳ�ʼ��
		Sleep(7000);
		printf("%dth customer have been haircut and pay\n", my_id);//��N���˿�����ϲ���Ǯ
		Sleep(10);
		printf("%dth customer leave\n", my_id);//��N���˿��뿪
	}
	else
	{
		printf("Now totally %d customers waiting.No seat. %dth customer leaves. \n",  waits, my_id);//���ڵȴ��Ĺ˿���N�� û�п������� ��N���˿��뿪
		ReleaseMutex(hMutex);
	}
	return 0;
}
int main ()
{
	//��һ����������Ȩ�ޣ��е��߳�����Ĵ���һ���µ��߳�,A pointer to a SECURITY_ATTRIBUTES structure.
	//If this parameter is NULL, the handle cannot be inherited by child processes.
	//�����ź����ͻ�����
	hMutex = CreateMutex(NULL, FALSE, "mutex");
	hBarbers = CreateSemaphore(NULL, 0, BARBERS, "barbers"); // barbers currently available
	hCustomers = CreateSemaphore(NULL, 0, CH, "customer"); //customers waiting

	HANDLE h;
	int *temp = new int [BARBERS];
	//������ʦ��ÿ����ʦ����һ���������̡߳�
	for(int i=0; i<BARBERS; ++i)
	{
		temp[i] = i+1; // barber's id
		h = CreateThread(NULL, 0, barber_thread, (void *)(&temp[i]), 0, NULL);
	}
	srand(time(NULL));
	//��������ͻ���ÿ���ͻ�Ҳ����һ���̡߳�
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
	//�ص��ź���
	CloseHandle(hMutex);
	CloseHandle(hBarbers);
	CloseHandle(hCustomers);
	CloseHandle(h);
	return 0;
}

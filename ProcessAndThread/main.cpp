#include <iostream>

using namespace std;
//���̺��߳�
//������Ŀ���Ǹ����̣�getmax(), main() ����һ����С���߳�
//һ������(�߳�)���﷨������Ŀ�Ͳ���ִ��
int getmax(int x, int y);   // ����getmax����

int main()
{
	int  a, b, Max;
	cin >> a >> b;
	Max = getmax(a, b);
	cout<<"Max=" << Max <<endl;
	return 0;
}
int getmax(int x, int y)
{
	int z = x>y?x:y;
	return z;
}

// 1-2.cpp: ����Ŀ�ļ���

#include  <iostream>
using namespace std;

int  getmax(int x, int y);   // ����max����

int  main(  )
{
	//int getmax(int x,int y);
	int  a, b, m ;				// ��������
	cin >> a>>b ;			// ������� a��b��ֵ
	m = getmax(a, b) ;		// ���ú���max�����õ���ֵ����m
	cout<<"max=" << m << '\n' ;		//   ���m
	return 0;

}
int  getmax(int x, int y)   // ����max����
{
	int z;               // ��������
	if (x>y) z = x;
	else  z = y;
	return (z);
}

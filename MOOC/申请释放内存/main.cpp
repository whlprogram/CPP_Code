#include <string.h>
#include <iostream>
using namespace std;
int main(void)
{
    //�ڶ�������100��char���͵��ڴ�
    char *str = new char[100];
    //����Hello C++�ַ���������Ķ��е��ڴ���
	strcpy(str, "Hello imooc");
    //��ӡ�ַ���
    cout << str << endl;
    //�ͷ��ڴ�
	delete []str;
    str = NULL;
	return 0;
}

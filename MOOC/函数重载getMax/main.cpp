#include <iostream>
using namespace std;

int getMax(int a, int b)
{
    return a > b ? a : b;
}

/**
  * �������ܣ����������е����ֵ
  * arr����������
  * count�����鳤��
  * �ú����Ƕ����溯��������
  */
int getMax(int *arr, int count)
{
    //����һ����������ȡ����ĵ�һ��Ԫ��
    int a = arr[0];
	for(int i = 1; i < count; i++)
	{
        //�Ƚϱ�������һ��Ԫ�صĴ�С
		if(a < arr[i])
		{
            //��������е�Ԫ�ر�maxNum�����ȡ�����е�ֵ
			a = arr[i];
		}
	}
	return a;
}

int main(void)
{
    //����int���鲢��ʼ��
	int numArr[3] = {3, 8, 6};

    //�Զ�����int getMax(int a, int b)
	cout << getMax(6, 3) << endl;

    //�Զ����÷������������ֵ�ĺ������������е����ֵ
	cout << getMax(numArr, 3) << endl;
	return 0;
}

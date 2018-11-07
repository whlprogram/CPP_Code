#include<iostream>

using namespace std;


/* ����˼��
1���ȴ�������ȡ��һ������Ϊ��׼����
2���������̣���������������ȫ�ŵ������ұߣ�С�ڻ����������ȫ�ŵ�������ߡ�
3���ٶ����������ظ��ڶ�����ֱ��������ֻ��һ������
*/
//  ��һ��  �ڿӷ�
/*���������*/
void Quick_Sort(int* a,int le,int ri){
	if (le >= ri){
		return;
	}
	int left = le;
	int right = ri;
	int key = a[right];	 //��һ����Ϊ���ҽ��	   //5 7 6 2 3 4 3
	while (left < right){ //�Ӵ�С
		while (left < right && a[left] <= key){   //��������ж� l < r  ��Ȼ��Ȼ�����ж��Ѿ��жϹ��ˣ�
			left++;						          //  �����while��++ -- �ͻ��ص� ����
		}
		a[right] = a[left];
		while (left < right && a[right] >= key){
			right--;
		}
		a[left] = a[right];
	}
	a[right] = key;
	Quick_Sort(a, le, right - 1);
	Quick_Sort(a, right + 1, ri);

}

/*���Ϳ�����   �����*/
void quick_Sort(int* arr, int left, int right){
	if (left >= right){
		return;
	}

	int left_index = left;
	int right_index = right;
	int key = arr[left];

	while (left_index < right_index){
		/*���������ߵĽڵ���Ϊ ��׼�㣬��ô��Ҫ���ұ߿�ʼ�Ƚϣ���֮��Ȼ*/
		//��С����
		while ((key <= arr[right_index]) && (left_index < right_index)){
			right_index--;
		}
		while ((key >= arr[left_index]) && (left_index < right_index)){
			left_index++;
		}
		if (left_index < right_index){
			swap(arr[left_index], arr[right_index]);
		}
	}
	/*��󽫻�׼λ��λ*/
	arr[left] = arr[left_index];
	arr[left_index] = key;

	quick_Sort(arr, left, left_index - 1);
	quick_Sort(arr, left_index+1, right);
}

int main()
{
	int a[10] = { 12, 14, 25, 23, 45, 23, 45, 12, 63, 24};
	quick_Sort(a, 0, 9);
	//Quick_Sort(a, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}

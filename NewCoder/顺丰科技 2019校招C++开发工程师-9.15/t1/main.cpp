#include <bits/stdc++.h>

using namespace std;

void maxheap_down(vector<int> &arr, int start, int end){
    int c = start;            // ��ǰ(current)�ڵ��λ��
    int left = 2*c + 1;        // ��(left)���ӵ�λ��
    int tmp = arr[c];            // ��ǰ(current)�ڵ�Ĵ�С
    for (; left <= end; c=left,left=2*left+1){
        // "left"�����ӣ�"left+1"���Һ���
        if ( left < end && arr[left] < arr[left+1])// ������������ѡ��ϴ��ߣ���heap[left+1]
            left++;
        if (tmp >= arr[left])
            break;        // ��������
        else            // ����ֵ
        {
            arr[c] = arr[left];
            arr[left]= tmp;
        }
    }
}

/*
 * ������(�����)
 * ����˵����
 *     a -- �����������
 *     n -- ����ĳ���
 */
void heap_sort(vector<int> &arr, int n){
    // ��(n/2-1) --> 0��α���������֮�󣬵õ�������ʵ������һ��(���)����ѡ�
    for (int i = n / 2 - 1; i >= 0; i--)
        maxheap_down(arr, i, n-1);
}
string str;
int main()
{
    cin >> str;
    vector<int> arr;
    if(str == "")
        return 0;
    int x1 = 0;
    int x2 = 0;
    int int_temp;
    string stemp;
    while (true){
        x2 = str.find(',', x1);//�����״�ƥ��Ķ��ŵ��±�
        if(x2 == -1)
            break;
        stemp = str.substr(x1, x2 - x1);//��ȡ���ַ���str�е�x1λ��ʼ�ĳ���Ϊ(x2-x1)���ַ���
        int_temp = atoi(stemp.c_str());
        arr.push_back(int_temp);
        x1 = x2 + 1;//�����´β�ѯ��ʼλ��
    }
    stemp = str.substr(x1, str.size()-x1);
    int_temp = atoi(stemp.c_str());
    arr.push_back(int_temp);

    if(arr.size() == 1){
        cout << arr[0];
        return 0;
    }
    heap_sort(arr, arr.size());

    for(int i=0; i<arr.size()-1; i++)
        cout << arr[i] << ',';
    cout << arr[arr.size()-1] << endl;
    return 0;
}
//4,1,3,2,16,9,10,14,8,7

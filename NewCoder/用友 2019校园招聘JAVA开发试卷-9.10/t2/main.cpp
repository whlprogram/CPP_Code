#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void foo(vector<int> &arr){
    if(arr.size() == 0)
        return;
    int startNum = arr[0];
    int maxCount = 1;

    int tempStart = arr[0];//��ǰ���������׸�����
    int tempCount = 1;

    for(int i=1; i<arr.size(); i++){
        //cout << "[tempStart=" << tempStart << ", tempCount=" << tempCount << "]" << endl;
        if(arr[i]-arr[i-1] == 1){
            tempCount++;
        }else{
            if(tempCount > maxCount){
                maxCount = tempCount;
                startNum = tempStart;
            }
            tempStart = arr[i];
            tempCount = 1;
        }
    }
    //�ÿӰ�  ���ź���һ���ո�   �˷Ѻó�ʱ�������
    cout << "[" << startNum << ", " << maxCount << "]" << endl;
}
int main()
{
    vector<int> arr;
    string str;
    getline(cin, str);
    if(str == ""){
        return 0;
    }
    int x1 = 0;
    int x2 = 0;
    int int_temp;
    string stemp;
    while (x2 != -1){
        x2 = str.find(0x20, x1);//�����״�ƥ��Ŀո���±� 0x20�ǿո��ASCII��
        stemp = str.substr(x1, x2 - x1);//��ȡ���ַ���str�е�x1λ��ʼ�ĳ���Ϊ(x2-x1)���ַ���
        int_temp = atoi(stemp.c_str());
        arr.push_back(int_temp);
        x1 = x2 + 1;//�����´β�ѯ��ʼλ��
    }
    stemp = str.substr(x1, str.size()-1-x1);
    int_temp = atoi(stemp.c_str());
    arr.push_back(int_temp);
    cout << endl;
    foo(arr);
    return 0;
}
//1 4 5 6 7 8 10 11 12 14 18 -1

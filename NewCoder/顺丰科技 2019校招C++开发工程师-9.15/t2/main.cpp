#include <bits/stdc++.h>

using namespace std;
int sum;
string str;

int countOfSum(vector<int> arr, int sum){
    int left = 0;
    int right = arr.size()-1;
    int res = 0;
    if(arr.size()==1 && arr[0]==sum)
        return 1;
    while(left < right){
        if(arr[left] == sum){
            res++;
            left++;
        }else if(arr[right] == sum){
            res++;
            right--;
        }else{
            if(arr[left] + arr[right] == sum){
                //cout << arr[left] << " " << arr[right] << endl;
                res++;
                left++;
                right--;
            }else if(arr[left] + arr[right] < sum){
                left++;
            }else{
                right--;
            }
        }

    }
    return res;
}

int main()
{
    cin >> sum;
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

    for(int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    sort(arr.begin(), arr.end());

    int res = countOfSum(arr, sum);
    cout << res << endl;
    return 0;
}
/*
5
1,2,3,4,5
*/

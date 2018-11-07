#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    bool flag = true;
    int findMaxOfLessNumber(vector<int> arr, int k){
        if(arr.size()==0 || k<=arr[0]){//�쳣����
            flag = false;
            return 0;
        }
        int left = 0;
        int right = arr.size()-1;
        int mid = 0;
        while(true){
            if(left == right && arr[left] != k){
                return arr[left];
                break;
            }
            mid = (left+right)/2;
            if(arr[mid] > k){
                right = mid-1;
                continue;
            }else if(arr[mid] < k){
                left = mid+1;
                continue;
            }else{//arr[mid] == k
                 for(int i=mid; i>=0; i--)
                    if(arr[i] < k)
                        return arr[i];
            }

        }//end while
    }

};
int main()
{
    Solution s;
    vector<int> arr;
    string str;
    cin >> str;
    if(str == ""){
        cout << "�����ַ���Ϊ��" << endl;
        return 0;
    }
    int x1 = 0;
    int x2 = 0;
    string s_temp;
    int int_temp;
    while (x2 != -1){
        x2 = str.find(',', x1);//�����״�ƥ���,�±�
        if(x2 == -1)
            break;
        s_temp = str.substr(x1, x2 - x1);//��ȡ���ַ���s_temp�е�x1λ��ʼ�ĳ���Ϊ(x2-x1)���ַ���
        int_temp = atoi(s_temp.c_str());
        arr.push_back(int_temp);
        x1 = x2 + 1;//�����´β�ѯ��ʼλ��
    }
    s_temp = str.substr(x1, s_temp.size()-1-x1);
    int_temp = atoi(s_temp.c_str());
    arr.push_back(int_temp);

    int k = 0;
    cin >> k;
    int res = s.findMaxOfLessNumber(arr, k);
    if(s.flag)
        cout << res << endl;
    else
        cout << "��������" << endl;
    return 0;
}
//0,1,2,3,4,5,6,7,8,9 0
//0,1,2,3,4,5,6,7,8,9 9
//0,1,2,3,4,5,6,7,8,9 7
//0,11,22,33,44,55,66,77,88,99 35
//0,11,22,33,44,55,66,77,88,99 0
//0,11,22,33,44,55,66,77,88,99 -1
//1 3



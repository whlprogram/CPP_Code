#include <bits/stdc++.h>
#define LLL long long
using namespace std;
bool cmp(pair<LLL, LLL> a, pair<LLL, LLL> b){
	return a.second < b.second;
}
bool cmp1(pair<LLL, LLL> a, pair<LLL, LLL> b){
	return a.first < b.first;
}
LLL fun(LLL decimal, LLL num){//decimal���Ƶ���num ת��Ϊʮ����
    LLL res = 0;
    LLL x = 1;
    while(num != 0){
        res += (num%10 * x);
        num /= 10;
        x *= decimal;
    }
    return res;
}
int main()
{
    vector<pair<LLL, LLL>> arr;
    vector<string> arrStr;
    string str;
    LLL decimal = 0;//����
    LLL num = 0;//����
    LLL i = 0;//��ʾ�����˳��
    while(true){
        cin >> str;
        if(str == "END")
            break;
        arrStr.push_back(str);//�����ַ���
        int pos = str.find('#', 0);
        string stemp = str.substr(0, pos);
        decimal = atoi(stemp.c_str());//��ȡ����
        stemp = str.substr(pos+1, str.size()-pos-1);
        num = atoi(stemp.c_str());//��ȡ����

        LLL NUMBER = fun(decimal, num);//��decimal���Ƶ���num ת��Ϊʮ����
        arr.push_back(make_pair(i, NUMBER));
        i++;
    }
    if(arrStr.size() == 1){
        cout << arrStr[0] << endl;
        return 0;
    }

    sort(arr.begin(), arr.end(), cmp);//����NUMBER��С����

    vector<pair<LLL, LLL>> res;
    //������ֻ����һ�ε�NUMBER�Ľڵ����res
    if(arr[1].second != arr[0].second){
        res.push_back(arr[0]);
    }
    for(int i=1; i<arr.size()-1; i++){
        if(arr[i].second != arr[i-1].second && arr[i].second != arr[i+1].second){
            res.push_back(arr[i]);
        }
    }
    if(arr[arr.size()-1].second != arr[arr.size()-2].second){
        res.push_back(arr[arr.size()-1]);
    }

    sort(res.begin(), res.end(), cmp1);//���ճ�ʼ������Ⱥ�˳������
    for(int i=0; i<res.size(); i++){
        cout <<  arrStr[res[i].first] << endl;//�����Ӧ���ַ���
    }
    return 0;
}
/*
10#15
4#32
4#33
8#17
END

10#15
4#32
4#33
8#17
8#11
8#13
9#67
12#55
END
*/

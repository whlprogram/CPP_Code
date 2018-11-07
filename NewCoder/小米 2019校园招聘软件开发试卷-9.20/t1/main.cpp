#include <bits/stdc++.h>
#define LLL long long
using namespace std;
bool cmp(pair<LLL, LLL> a, pair<LLL, LLL> b){
	return a.second < b.second;
}
bool cmp1(pair<LLL, LLL> a, pair<LLL, LLL> b){
	return a.first < b.first;
}
LLL fun(LLL decimal, LLL num){//decimal进制的数num 转化为十进制
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
    LLL decimal = 0;//进制
    LLL num = 0;//数字
    LLL i = 0;//表示输入的顺序
    while(true){
        cin >> str;
        if(str == "END")
            break;
        arrStr.push_back(str);//保存字符串
        int pos = str.find('#', 0);
        string stemp = str.substr(0, pos);
        decimal = atoi(stemp.c_str());//获取进制
        stemp = str.substr(pos+1, str.size()-pos-1);
        num = atoi(stemp.c_str());//获取数字

        LLL NUMBER = fun(decimal, num);//将decimal进制的数num 转化为十进制
        arr.push_back(make_pair(i, NUMBER));
        i++;
    }
    if(arrStr.size() == 1){
        cout << arrStr[0] << endl;
        return 0;
    }

    sort(arr.begin(), arr.end(), cmp);//按照NUMBER大小排序

    vector<pair<LLL, LLL>> res;
    //将所有只出现一次的NUMBER的节点存入res
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

    sort(res.begin(), res.end(), cmp1);//按照初始输入的先后顺序排序
    for(int i=0; i<res.size(); i++){
        cout <<  arrStr[res[i].first] << endl;//输出对应的字符串
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

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;
    string str;
    int res=0, sum=0;
    cin >> str;
    //cout << str << endl;
    for(int i=0; i<str.size(); i++){
        if(str[i]<'0' || str[i]>'9')
            return 0;
        int temp = str[i]-'0';
        //cout << "temp = " << temp << endl;
        arr.push_back(temp);
    }

    for(int i=0; i<arr.size(); i++){
        //cout << "arr[" << i << "] = " << arr[i] << endl;
        sum += arr[i];
        if(arr[i]%3 == 0){
            res++;
            sum = 0;
            continue;
        }
        if(sum%3 == 0){
            res++;
            sum = 0;
        }
    }
    cout << res << endl;
    return 0;
}

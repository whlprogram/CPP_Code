#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> arr;
int main()
{
    string str;
    cin >> str;
    if(str == "")
        return 0;
    int x1 = 0;
    int x2 = 0;
    int int_temp;
    string stemp;
    while (true){
        x2 = str.find(',', x1);//返回首次匹配的逗号的下标
        if(x2 == -1)
            break;
        stemp = str.substr(x1, x2 - x1);//截取从字符串str中第x1位开始的长度为(x2-x1)的字符串
        int_temp = atoi(stemp.c_str());
        arr.push_back(int_temp);
        x1 = x2 + 1;//更改下次查询起始位置
    }
    stemp = str.substr(x1, str.size()-x1);
    int_temp = atoi(stemp.c_str());
    arr.push_back(int_temp);

    multimap<int,int> myMultimap;
    for(int i=0; i<arr.size(); i++){
        myMultimap.insert( pair<int, int>(arr[i], i+1) );
    }

    int k;
    cin >> k;
    int count = 0;
    for(auto itemp = myMultimap.rbegin(); itemp!=myMultimap.rend(); itemp++){
        ++count;
        if(count == k)
            cout << itemp->second << endl;
    }
    return 0;
}
//1024,3,64,4,64,41,238 5

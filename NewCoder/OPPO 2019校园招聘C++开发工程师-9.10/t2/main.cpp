#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    string str;
    while(getline(cin, str)){
        set<int> mySet;
        if(str == "")
            return 0;
        int x1 = 0;
        int x2 = 0;
        int int_temp;
        string stemp;
        while (true){
            x2 = str.find(' ', x1);//返回首次匹配的空格的下标
            if(x2 == -1)
                break;
            stemp = str.substr(x1, x2 - x1);//截取从字符串str中第x1位开始的长度为(x2-x1)的字符串
            int_temp = atoi(stemp.c_str());
            mySet.insert(int_temp);
            x1 = x2 + 1;//更改下次查询起始位置
        }
        stemp = str.substr(x1, str.size()-x1);
        int_temp = atoi(stemp.c_str());
        mySet.insert(int_temp);
        int len = mySet.size();

        if(len == 0)
            return 0;

        auto it=mySet.begin();
        for(int i=0; i<len-1; i++){
            cout << *it << " ";
            it++;
        }
        cout << *mySet.rbegin();
    }
    //getline(cin, str);
    //4 2 3 4 5 9 7 6
    return 0;

}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int memberCount, carCount;
    cin >> memberCount >> carCount;
    int* members = new int[memberCount];
    for(int i=0; i<memberCount; i++){
        cin >> members[i];
    }
    vector<int> res;
    int remainder = memberCount%carCount;//余数
    int business = memberCount/carCount;//商 出去余数外剩余区间个数
    if(remainder){//最后面的区间加入数组
        for(int i=0; i<remainder; i++)
            res.push_back(members[business*carCount+i]);
    }
    memberCount -= remainder;
    for(int i=business-1; i>=0; i--){//区间从后往前依次加入数组
        for(int j=0; j<carCount; j++){
            res.push_back(members[carCount*i+j]);
        }
    }
    if(!res.size())
        return 0;
    for(int i=0; i<res.size()-1; i++)
        cout << res[i] << " ";
    cout << res[res.size()-1] << endl;
    delete[] members;
    return 0;
}
/*
5 3
1 3 5 2 4

9 3
1 2 3 4 5 6 7 8 9

2 3
1 2
*/

//字母加密 A代表1 B代表2 C代表3 ----- Z代表26
//输入一个字符串 输出加密种类
/*例如
输入 12
输出 2
解释AB(1 2) L(12)

输入 1212  输出 5
解释 ABAB(1 2 1 2) LL(12 12)
ABL(1 2 12) AUB(1 21 2) ABU(1 2 21)
*/
#include <bits/stdc++.h>
using namespace std;
int arr[10000000];
int main()
{
    string str;
    cin >> str;
    int len = str.size();
    if((len<1) || (len==1 && arr[0]=='0'))
        return 0;
    if(len == 1){
        cout << 1 << endl;
        return 0;
    }
    arr[0] = 1;
    int temp1 = (str[0]-'0')*10 + (str[1]-'0');
    if(temp1 <= 26)
        arr[1] = 2;
    else
        arr[1] = 1;
    for(int i=2; i<len; i++){
        int temp2 = (str[i-1]-'0')*10 + (str[i]-'0');
        if(temp2 <= 26)
            arr[i] = arr[i-1] + arr[i-2];
        else
            arr[i] = arr[i-1];
    }
    cout << arr[len-1] << endl;
    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;
char arr[255];
int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    for(int i=0; i<str2.size(); i++){
        if(arr[str2[i]] == 0){
            arr[str2[i]] = 1;
        }
    }
    for(int i=0; i<str1.size(); i++){
        if(arr[str1[i]] == 0)
            cout << str1[i];
    }
    return 0;
}

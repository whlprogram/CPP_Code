#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> arr;
int main()
{
    int a[11];
    for(int i=0; i<10; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<(1<<10); i++){
        int f=0;
        for(int j=0; j<10; j++){
            if(!((i&(1<<j)))&&a[j]){
                f=1;
                break;
            }
        }
        if(f)
            continue;
        string str="";
        for(int j=0; j<10; j++){
            if(i&(1<<j))
                str.push_back('0' + j);
        }
        //cout << str << endl;
        arr.push_back(str);
    }
    //cout << "==========" << endl;
    sort(arr.begin(),arr.end());
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<endl;
    return 0;
}

//给定非负数组，每个元素代表能跳跃的最大距离
//当前位置在数组首位，判断是否能跳到数组末尾
#include<iostream>
#include<vector>
using namespace std;

/*
bool isJumpToLast(vector<int> ivec,int n){
    if(n==1)//只有一个元素， 返回true
        return true;
    int i=0;
    while(i<n-1){
        i += ivec[i];
        if(ivec[i]==0 && i!=n-1)//当某一元素为0，并且它不是最后一个元素时，一定跳不到最后一个下标
            return false;
        if(i >= n-1)
            return true;
    }
}
*/
/*
7
2 3 0 3 2 0 0
上面方法判断为false
下面方法判断为true
*/
bool isJumpToLast(vector<int> ivec, int n, vector<int> arr){
    int i, j;
    arr[0] = 1;
    for(i=0; i<n; i++){
        if(arr[i]){//如果没有断路就继续
            for(j=i; j<=i+ivec[i]; j++)
                arr[j]=1;
        }else{   //如果出现断路 就证明根本跳不到
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> ivec;
    int num, temp;
    cin >> num;
    vector<int> arr(num, 0);//判断是否断路
    for(int i=0; i<num; i++){
        cin >> temp;
        ivec.push_back(temp);
    }
    if(isJumpToLast(ivec, num, arr))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;

}
/*
7
2 3 0 3 2 0 0
*/

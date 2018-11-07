#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
6
40
14 18 11 14 12 13

将钻石按照大小排序，从大到小得往容器里放
每次放入钻石时，遍历容器，将钻石放入第一个能容纳该钻石的容器里
*/
int numPieces, capacityContainer;
int carats[1000005];
int minContainer(int numPieces, int capacityContainer, int carats[]){
    vector<int> arr(numPieces, capacityContainer);
    sort(carats, carats+numPieces);
    for(int i=numPieces-1; i>=0; --i){
        for(int j=0; j<arr.size(); ++j){
            if(arr[j] >= carats[i]){
                arr[j] = arr[j] - carats[i];
                break;
            }
        }
    }
    int res = 0;
    for(int j=0; j<arr.size(); ++j){
        if(arr[j] != capacityContainer)
            res++;
    }
    return res;
}
int main()
{
    cin >> numPieces >> capacityContainer;
    for(int i=0; i<numPieces; i++)
        cin >> carats[i];
    cout << minContainer(numPieces, capacityContainer, carats) << endl;
    return 0;
}

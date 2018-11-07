#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int id;
    int start;
    int end;
};
bool cmp(node a, node b){
    if(a.end == b.end)
        return a.start < b.start;
    return a.end < b.end;
}
int main()
{
    vector<node> arr;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        node temp;
        temp.id = i;
        cin >> temp.start >> temp.end;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), cmp);


    int countt = 0;//计算冲突数量
    vector<int> res;
    for(int i=1; i<arr.size(); i++){
        if(arr[i].start < arr[i-1].end){
            countt++;
            if(arr[i].start < arr[i-1].end){
                res.push_back(arr[i].id);
                if(i>=2 && arr[i].start >= arr[i-2].end){
                    res.push_back(arr[i-1].id);
                }
            }
        }
    }
    sort(res.begin(), res.end());
    if(countt > 2){//过多冲突 无法安排
        cout << 0 << endl;
    }else if(countt == 0){//无冲突
        cout << n << endl;
        for(int i=1; i<=n; i++)
            cout << i << " ";
        cout << endl;
    }else if(countt == 1){//1冲突
        cout << res.size() << endl;
        for(int i=0; i<res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }else if(countt == 2 && res.size()==1){
        cout << 1 << endl;
        cout << res[0] <<endl;
    }else{
        cout << 0 << endl;
    }


    return 0;
}
/*
0个冲突
3
1 3
3 4
5 6

4
1 3
5 6
3 4
6 9

1个冲突
4
1 3
2 4
5 6
7 8(这个无法得出正确答案)

4
1 3
4 6
5 8
8 9

4
1 3
4 6
6 8
5 9

4
1 3
4 6
6 8
7 9

2个冲突 能解决
4
1 3
2 4
3 5
5 6

5
1 2
4 6
5 10
8 15
20 30

5
1 2
4 6
3 10
8 15
20 30

2个冲突 不能解决
5
1 2
4 6
3 10
5 15
20 30

5
1 4
3 6
8 10
9 15
20 30

不能解决
3
1 5
2 6
3 7
*/

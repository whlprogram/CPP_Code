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


    int countt = 0;//�����ͻ����
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
    if(countt > 2){//�����ͻ �޷�����
        cout << 0 << endl;
    }else if(countt == 0){//�޳�ͻ
        cout << n << endl;
        for(int i=1; i<=n; i++)
            cout << i << " ";
        cout << endl;
    }else if(countt == 1){//1��ͻ
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
0����ͻ
3
1 3
3 4
5 6

4
1 3
5 6
3 4
6 9

1����ͻ
4
1 3
2 4
5 6
7 8(����޷��ó���ȷ��)

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

2����ͻ �ܽ��
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

2����ͻ ���ܽ��
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

���ܽ��
3
1 5
2 6
3 7
*/

/*
在小红家里面，有n组开关，触摸每个开关，可以使得一组灯泡点亮。
现在问你，使用这n组开关，最多能够使得多少个灯泡点亮呢？

输入
第一行一个n，表示有n组开关。
接下来n行，每行第一个整数为k，表示这个开关控制k个灯泡，接下来k个整数，表示控制的灯泡序号。

满足:
1<=n<=1000
1<=k<=1000
序号是在int范围内正整数。

输出
输出最多多少个灯泡点亮。

输入
2
2 1 2
2 2 3
输出
3

输入
3
1 1
1 2
2 1 2
输出
2

关键点：题目只说开关点亮灯泡，两个开关同时开一个灯泡，依旧灯泡是亮的
set去重即可
*/
#include <iostream>
#include <set>
using namespace std;

int main()
{
    for(int n; cin>>n; ){
        set<int> s;
        for(int i=0; i<n; i++){
            int k; cin >> k;
            for(int j=0; j<k; j++){
                int temp;
                cin >> temp;
                s.insert(temp);
            }
        }
        cout << s.size() << endl;
    }

    return 0;
}

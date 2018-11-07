#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int s;
    int t;
};
bool cmp(node a, node b){
    if(a.s != b.s)
        return a.s < b.s;
    else if(a.s == b.s && a.t != b.t)
        return a.t < b.t;
    else
        return true;
}
int main()
{

    return 0;
}
/*
5 5
0 1
0 2
0 3
0 4
0 5

20 5
7 15
0 6
14 18
0 8
17 20

*/


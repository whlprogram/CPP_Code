#include <iostream>
#include <vector>
using namespace std;
void foo(long long row, long long column){
    long long res;
    if(row == 1){
        if(column >= 3)
            res = column - 2;
        if(column == 1)
            res = 1;
    }
    if(column == 1 && row >= 3){
        res = row - 2;
    }
    if(row==2 || column==2){
        res = 0;
    }
    if(row>2 && column>2){
        res = row*column - 2*row - 2*column + 4;

    }
    cout << res << endl;
}
int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        long long row, column;
        cin >> row >> column;
        foo(row, column);
    }
    return 0;
}

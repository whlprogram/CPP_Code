#include <iostream>
#include <cstdio>

using namespace std;
int f(int m, int n){
    if(m == 0){
        return n +1;
    } else if(n == 0){
        return f(m-1, 1);
    } else{
        return f(m-1, f(m,n-1));
    }
}
int main()
{
    int n=0,m=1,x=2;/*声明3个整型变量,并赋值*/
       if(!n) /*对n取反,如果n为0,则执行x=x-1,结果x=1*/
              x -=1;
      if(m) /*如果m为非0,则执行x=x-2,结果x=-1*/
             x -=2;
      if(x) /*如果n为非0,则执行x=x-3,结果x=-4*/
            x -=3;
      printf("%d\n",x); /*在屏幕上显示-4*/
    cout << f(3,3);
    return 0;
}

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
    int n=0,m=1,x=2;/*����3�����ͱ���,����ֵ*/
       if(!n) /*��nȡ��,���nΪ0,��ִ��x=x-1,���x=1*/
              x -=1;
      if(m) /*���mΪ��0,��ִ��x=x-2,���x=-1*/
             x -=2;
      if(x) /*���nΪ��0,��ִ��x=x-3,���x=-4*/
            x -=3;
      printf("%d\n",x); /*����Ļ����ʾ-4*/
    cout << f(3,3);
    return 0;
}

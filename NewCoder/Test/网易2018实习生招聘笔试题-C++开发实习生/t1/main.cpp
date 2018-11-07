#include <iostream>

using namespace std;
/*
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int *p=arr;
    //printf("%d\n",*p); //1
    //printf("%d\n",*(++p)); //2
    //printf("%d\n",*(p++)); //1
    //printf("%d,%d\n",*p,*(++p)); // 2 2

    *(p++)+=89;
    printf("%d,%d\n",*p,*(++p)); // 3 3
    return 0;
}
*/
class base1{
    private: int a,b;
    public:
    base1 ( int i ) : b(i+1),a(b){}
    base1():b(0),a(b){}
    int get_a(){return a;}
    int get_b(){return b;}
};
int main()
{
    base1 obj1(11);
    cout<<obj1.get_a()<<endl<<obj1.get_b()<<endl;
    return 0;
}

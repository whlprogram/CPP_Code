#include <iostream>
#include <string.h>
#include <stdbool.h>
using namespace std;

/*void f(int *b,int*s)
{
    int c;

    c=*b;
    *b=*s;
    *s=c;
}

int main()
{
    int a,b,*p1,*p2;
    cin>>a>>b;
    p1=&a;
    p2=&e;
    f(p1,p2);
    cout<<a<<" "<<e;
    cout << "Hello world!" << endl;
    return 0;
}*/

/*
void f(int b1,int b2)
{
    int c;
    c=b1;
    b1=b2;
    b2=c;
}
int main()
{

    void swap(int *p1,int *p2);
    int *a1,*a2,b,c;
  //    int b,c;
    cin >> b >> c;
     cout<< "dgsgd" <<b<<"  "<<c<<endl;
    a1=&b;
    a2=&c;
    swap(a1,a2);
  // f(b,c);
    cout<<b<<"  "<<c<<endl;
}
void swap (int *p1,int *p2)
{
    int *t;
    t=p1;
    p1=p2;
    p2=t;
}
*/
/*
int main()
{
    int a=6,b=0,c=0,d=0,m,n,l;
    string e = "vm\x43\\\np\102qu";
    a += a -= a*a;
    cout << e << endl;
    cout << "a=" << a << "******" << m << "n=" << n << "l=" << l<< endl;
    cout << char('A') << endl;
    cout << char('A'+2) << endl;
    return 0;
}
*/
/* 2007-4
class point {
    public:
    point(int vaI){
            x=val;
        }
    point£¦ operator++(){
            x++;
            return *this;
        }
    print operator++(int){
            point old=*this,++(*this);
            return old;
        }
    int GetX() const {
        return x;
        }
    private:
        int x;
};
int main()
{
point a(10);
cout<<(++a).GetX();
cout<<a++.GetX();
return();
}
*/
/*
int main()
{
    const int x=6;
    float a[x] = {1,2,3,4,5,6};
    int b[2][3] = {3,4,5};
    int c[][3] = {3,4,5};
    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
            cout << c[i][j] << endl;
    cout << "*************************" << endl;
    int d[2][3] = {0,1};
    int e[2][3] = {{0},{1}};
    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
            cout << e[i][j] << endl;
    cout << "*************************" << endl;
    char ca1[] = {'c','m','n'};
    char ca2 = 'name';
    char ca3[5] = "your";
    int array[] = {1,2,3,4};
    cout << ca2 << endl;
    cout << "*************************" << endl;
    char st[20]="hello\0\t\\";
    cout << strlen(st) << endl; //5
    cout << sizeof(st) << endl; //20
    cout << st;  //hello
    return 0;
}
*/
/*
//有n个人围成一圈，顺序排号。从第1个人开始报数，凡是报到3的人退出圈子，问最后留下的人原来排在第几号，编程求解
int main()
{
    int i, k, m, n, num[50], *p;
    cout << "输入人数: ";
    cin >> n;
    p = num;//此处赋的是num的首地址,所以用p接收
    for (i = 0;i<n;i++)
        *(p + i) = i + 1; // 以 1 至 n 为序给每个人编号
    i = 0; // i 为每次循环时计数变量
    k = 0; // k 为按 1,2,3 报数时的计数变量
    m = 0; // m 为退出人数
    while (m<n - 1) // 当退出人数比 n-1 少时(即未退出人数大于 1 时)执行循环体
    {
        if (*(p + i) != 0)
            k++;
        if (k == 3) // 将退出的人的编号置为 0
        {
            *(p + i) = 0;
            k = 0;
            m++;
        }
        i++;
        if (i == n) i = 0; // 报数到尾后，i 恢复为 0
    }
    while (*p == 0) p++;//从头开始找,第一个*p由于被杀,即指针被置为空指针,0,然后往下探,第二个,同样,直到没被杀得那个,它是有地址的,所以跳出循环,输出这个指针的值;
    cout << "最后留下来的人编号是: " << *p << endl;
    return 0;
}
*/
/*
//(基类A,派生类B,)
class A{
public:
    int i;
    void showa()
        {
            cout<<"i="<<i<<endl;
        }
protected:int e = 3;
private:int f;
};
class B:virtual public A      //此处采用虚继承
{
    public:
    int j;
};
class C:virtual public A      //此处采用虚继承
{
    public:
    int k;
};
class D:public B,public C//调用析构函数时先调用虚基类的构造函数,然后挨个最后调用基类的析构函数,构造函数反过来
{
    public:
    int m;
};
int main(){
    A a;
    B b;
    C c;
    a.i=1;
    a.showa();//1
    b.i=2;
    b.showa();//2
    c.i=3;
    c.showa();//3

    D d;
    d.i = 4;
    d.showa();//4

    cout << "***************" << endl;
    int q = 1 ;
    const int &ra=q;
    cout << &ra << endl;
    cout << ra << endl;
    return 0;
}
*/
int main(){
    string s = "";
    if(s[0] == 0)
        cout << "123456" << endl;
    return 0;
}

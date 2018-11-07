#include <iostream>
#define len 10
using namespace std;
class NumberTB
{
private:
    int top[len];
    int bottom[len];//随机赋值
    bool success;
public:
    NumberTB();
    int* getBottom();
    void setNextBottom();
    int getFrequecy(int num);
};

NumberTB::NumberTB()
{
    success = false;
    //format top
    for(int i=0;i<len;i++)
    {
        top[i] = i;
    }
}


int* NumberTB::getBottom()
{
    while(!success)//success等于false时一直执行下去
    {
        setNextBottom();
    }
    return bottom;
}

//set next bottom
void NumberTB::setNextBottom()
{
    bool reB = true;

    for(int i=0;i<len;i++)//i代表top[]的元素值0~9
    {
        int frequecy = getFrequecy(i);//getFrequecy计算i在数组bottom出现的次数

        if(bottom[i] != frequecy)
        {
            bottom[i] = frequecy;
            reB = false;
        }
    }
    //for(int j=0;j<len;j++)
    //{
    //    cout<<bottom[j]<<" ";
    //}
    //cout << "" <<endl;
    success = reB;
}

//getFrequecy计算num在数组bottom出现的次数 num即指top[]的元素
int NumberTB::getFrequecy(int num)
{
    int count = 0;
    for(int i=0;i<len;i++)
    {
        if(bottom[i] == num)
            count++;
    }
    return count;    //cout即对应 frequecy
}
int main()
{
    NumberTB nTB;
    int* result= nTB.getBottom();

    for(int i=0;i<len;i++)
    {
        cout<<*result++<<endl;
    }

    int n[][3] = {10,20,30,40,50,60};
    int (*p)[3];
    p=n;
    cout << p[0][0] << " " << *(p[0]+1) << " " << (*p)[2] << endl;
    cout << p[0][0] << " " << *(p[1]+1) << " " << (*p+1)[3] << endl;

    return 0;
}

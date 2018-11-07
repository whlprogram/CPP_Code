#include <iostream>
#define len 10
using namespace std;
class NumberTB
{
private:
    int top[len];
    int bottom[len];//�����ֵ
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
    while(!success)//success����falseʱһֱִ����ȥ
    {
        setNextBottom();
    }
    return bottom;
}

//set next bottom
void NumberTB::setNextBottom()
{
    bool reB = true;

    for(int i=0;i<len;i++)//i����top[]��Ԫ��ֵ0~9
    {
        int frequecy = getFrequecy(i);//getFrequecy����i������bottom���ֵĴ���

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

//getFrequecy����num������bottom���ֵĴ��� num��ָtop[]��Ԫ��
int NumberTB::getFrequecy(int num)
{
    int count = 0;
    for(int i=0;i<len;i++)
    {
        if(bottom[i] == num)
            count++;
    }
    return count;    //cout����Ӧ frequecy
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

#include <iostream>

using namespace std;

void Swap(char &a,char &b)
{
    char tmp;
    tmp=a;
    a=b;
    b=tmp;
}

void Perm(char R[],int low,int high)
{
    if(low==high)
    {
        int i;
        for(i=0;i<=high;i++)
            cout<<R[i]<<" ";
    }
    else
    {
        int m;
        for(m=low;m<=high;m++)
        {
            Swap(R[m],R[low]);
            Perm(R,low+1,high);
            Swap(R[m],R[low]);
        }
    }
}

int main(void)
{
    char R[100];
    int n,low,high;
    cin>>n;
    for(low=0;low<n;low++)
    {
        cin>>R[low];
    }
    Perm(R,0,n-1);
    return 0;

}


/*
#include <stdio.h>
#include <string.h>
#define N 10
int main()
{
    void input(int [],char name[][8]);
    void sort(int [],char name[][8]);
    void search(int ,int [],char name[][8]);
    int num[N],number,flag=1,c;
    char name[N][8];
    input(num,name);
    sort(num,name);
    while (flag==1)
    {
        printf("\ninput number to look for:");
        scanf("%d",&number);
        search(number,num,name);
        printf("continue ot not(Y/N)?");
        getchar();
        c=getchar();
        if (c=='N'||c=='n')
        flag=0;
    }
    return 0;
}
void input(int num[],char name[N][8])
{
    int i;
    for (i=0;i<N;i++)
    {
        printf("input NO.: ");
        scanf("%d",&num[i]);
        printf("input name: ");
        getchar();
        gets(name[i]);
    }
}
void sort(int num[],char name[N][8])
{
    int i,j,min,templ;
    char temp2[8];
    for (i=0;i<N-1;i++)
    {
        min=i;
        for (j=i;j<N;j++)
        if (num[min]>num[j])
        min=j;
        templ=num[i];
        strcpy(temp2,name[i]);
        num[i]=num[min];
        strcpy (name[i],name[min]);
        num[min]=templ;
        strcpy(name[min],temp2);
    }
    printf("\n result:\n");
    for (i=0;i<N;i++)
    printf("\n %5d%10s",num[i],name[i]);
}
void search(int n,int num[],char name[N][8])
{
    int top,bott,mid,loca,sign;
    top=0;
    bott=N-1;
    loca=0;
    sign=1;
    if ((n<num[0])||(n>num[N-1]))
    loca=-1;
    while((sign==1) && (top<=bott))
    {
        mid=(bott+top)/2;
        if (n==num[mid])
        {
            loca=mid;
            printf("NO. %d , his name is %s.\n",n,name[loca]);
            sign=-1;
        }
        else if (n<num[mid])
            bott=mid-1;
        else
            top=mid+1;
    }
    if (sign==1 || loca==-1)
        printf("%d not been found.\n",n);
}
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
/*    cout << "请输入5门课程:" << endl;
    string course[5]; //表示课程名数组
    for(int i=0;i<5;i++)
    {
        cin >> course[i];
    }
    cout << "请输入学号和各科成绩:" << endl;
    cout << "学号:";
    for(int i=0;i<5;i++)
    {
        if(i!=4)
            cout << course[i] << ',';
        else
            cout << course[i] ;
    }
    cout << endl;
*/
    char stuNum[4]={'01','02','03','04'};//表示学号数组
    double Num1Score[5],Num2Score[5],Num3Score[5],Num4Score[5];//学生各科成绩,给每个同学定义一个数组

    double c1Score[] = {Num1Score[0], Num2Score[0], Num3Score[0], Num4Score[0],}; //每科成绩定义一个数组
    double c2Score[] = {Num1Score[1], Num2Score[1], Num3Score[1], Num4Score[1],};
    double c3Score[] = {Num1Score[2], Num2Score[2], Num3Score[2], Num4Score[2],};
    double c4Score[] = {Num1Score[3], Num2Score[3], Num3Score[3], Num4Score[3],};
    double c5Score[] = {Num1Score[4], Num2Score[4], Num3Score[4], Num4Score[4],};

    for(int i=0;i<4;i++)
    {
        cin >> stuNum[i] >> c1Score[i] >> c2Score[i] >> c3Score[i] >> c4Score[i] >> c5Score[i];
    }

}

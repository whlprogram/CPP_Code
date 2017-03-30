/*
练习二、两个乒乓球队进行比赛，各出3人。甲队为A、B、C 3人，乙队为X，Y，Z 3人。已抽签决定比赛名单。
有人向队员打听比赛的名单，A说他不和X比，C说他不和X,Z比，编程实现找出3对选手的名单
C Y
A Z
B X
*/
#include <iostream>

using namespace std;

int main()
{
    string arr1[] = {"A", "B", "C"};
    string arr2[] = {"X", "Y", "Z"};
    for (int i=0; i<3; i++)
    {
        if(arr1[i] == "C")
        {
          cout << "C vs Y" <<endl;
          arr2[1] = "o1";
        }
    }

            for (int m=0; m<3; m++)
            {
                if(arr1[m] == "A")
                {
                    for (int a=0; a<3; a++)
                    {
                        if(arr2[a] != "X" && arr2[a] != "o1")
                        {
                        cout << "A vs " << arr2[a] <<endl;
                        arr2[a] = "o2";
                        }
                    }
                }
            }

            for (int n=0; n<3; n++)
            {
                if(arr1[n] == "B")
               {
                   for (int q=0; q<3; q++)
                    {
                        if(arr2[q] != "o1" && arr2[q] != "o2")
                        {
                            cout << "B vs " << arr2[q] <<endl;
                        }
                    }
                }
            }

    return 0;
}

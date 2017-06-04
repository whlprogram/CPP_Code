#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
class Solution {
public:
    void phoneSignal(int signal) {
        string s = "";
        if(signal>=90)
            s="4G";
        else if(signal>=60)
            s="3G";
        else
            s="E";
        //cout << "+-----+" <<endl;
        printf("%s\n","+-----+");
        if(s=="4G"){
            //cout << "|-  4G|" <<endl;
            //cout << "|--   |" <<endl;
            //cout << "|---  |" <<endl;
            //cout << "|---- |" <<endl;
            printf("%s\n","|-  4G|");
            printf("%s\n","|--   |");
            printf("%s\n","|---  |");
            printf("%s\n","|---- |");
            if(signal==100){
                //cout << "|-----|" <<endl;
                printf("%s\n","|-----|");
            }
            else
                //cout << "|     |" <<endl;
                printf("%s\n","|     |");
        }
        if(s=="3G"){
            //cout << "|-  3G|" <<endl;
            //cout << "|--   |" <<endl;
            //cout << "|---  |" <<endl;
            printf("%s\n","|-  3G|");
            printf("%s\n","|--   |");
            printf("%s\n","|---  |");
            if(signal>=80){
                //cout << "|---- |" <<endl;
                printf("%s\n","|---- |");
            }
            else{
                //cout << "|     |" <<endl;
                printf("%s\n","|     |");
            }
            //cout << "|     |" <<endl;
            printf("%s\n","|     |");
        }
        if(s=="E"){
            if(signal>=40){
                //cout << "|-   E|" <<endl;
                //cout << "|--   |" <<endl;
                printf("%s\n","|-   E|");
                printf("%s\n","|--   |");
            }
            else if(signal>=20){
                //cout << "|-   E|" <<endl;
                //cout << "|     |" <<endl;
                printf("%s\n","|-   E|");
                printf("%s\n","|     |");
            }
            else{
                //cout << "|    E|" <<endl;
                //cout << "|     |" <<endl;
                printf("%s\n","|-   E|");
                printf("%s\n","|     |");
            }
            for(int i=0; i<2; i++){
                    //cout << "|     |" <<endl;
                    printf("%s\n","|     |");
            }
        }
        //cout << "+-----+" <<endl;
        printf("%s","+-----+");
    }
};
int main()
{
    Solution s;
    int signal = 0;
    //cin >> signal;
    scanf("%d", &signal);
    if(signal<0)
        signal = 0;
    if(signal>100)
        signal = 100;
    s.phoneSignal(signal);
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        double n;
        cin >> n;
        double m = n - 5000;
        int res = 0;
        if(n <= 5000){
            res = 0;
        }else if(m <= 3000){
            res = int(m*0.03+0.5);
        }else if(m>3000 && m<=12000){
            res = 90 + int((m-3000)*0.1+0.5);
        }else if(m>12000 && m<=25000){
            res = 90 + 900 + int((m-12000)*0.2+0.5);
        }else if(m>25000 && m<=35000){
            res = 90 + 900 + 2600 + int((m-25000)*0.25+0.5);
        }else if(m>35000 && m<=55000){
            res = 90 + 900 + 2600 + 2500 + int((m-35000)*0.3+0.5);
        }else if(m>55000 && m<=80000){
            res = 90 + 900 + 2600 + 2500 + 6000 + int((m-55000)*0.35+0.5);
        }else if(m>80000){
            res = 90 + 900 + 2600 + 2500 + 6000 + 8750 + int((m-80000)*0.45+0.5);
        }
        cout << res << endl;
    }

    return 0;
}

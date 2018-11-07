#include <iostream>

using namespace std;

int main()
{
    int buf[16];
    cout << &buf[0] << endl;
    cout << &buf[1] << endl;
    cout << &buf << endl;
    cout << &buf+1 << endl;
    /*
    int res = 0;
    for(int i=1; i<=1000; i++){
        int sum = 0;
        int temp = i;
        while(temp != 0){
            sum += temp%10;
            temp /= 10;
        }
        if(sum%10 == 0)
            res++;
    }
    cout << res << endl;
    */
    /*
    int a = 7;
    float x = 2.5 , y = 4.7;
    cout << x+a%3*(int)(x+y)%2/4 << endl;
    */

    /*
    int t;
    cin >> t;
    if(t == 2){
        cout << "Yes" << endl;
        cout << "No" << endl;

    }else if(t == 3){
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "No" << endl;
    }else if(t == 4){
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
    }else if(t == 5){
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
        cout << "No" << endl;
    }else if(t == 6){
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
    }else if(t == 7){
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
        cout << "No" << endl;
    }else if(t == 8){
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "No" << endl;
    }else if(t == 9){
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
    }else if(t == 10){
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
        cout << "No" << endl;
        cout << "No" << endl;
        cout << "Yes" << endl;
        cout << "Yes" << endl;
    }else{
    	for(int i=0; i<t; i++)
            cout << "Yes" << endl;
    }
    */
    return 0;
}

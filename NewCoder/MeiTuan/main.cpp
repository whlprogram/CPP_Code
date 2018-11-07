#include <iostream>

using namespace std;
int getBit(int n)
{
    int arr[11] = {0, 1, 10, 100, 1000, 10000,
                100000, 1000000, 10000000, 100000000, 1000000000};
    for(int i=10; i>=0; i--){
        if(n >= arr[i])
        {
           return i;
        }
    }
    return 0;
}
int getBitSum(int n)
{
    int arr[11] = {1, 10, 100, 1000, 10000,
                100000, 1000000, 10000000, 100000000, 1000000000};
    int getSomeSum[11] = {0, 9, 90*2, 900*3, 9000*4, 90000*5,
                900000*6, 9000000*7, 90000000*8, 900000000*9, 10};
    int getMin[11] = {0, 0, 9, 99, 999, 9999,
                99999, 999999, 9999999, 99999999, 999999999};
    if(n<1 || n>1000000000)
        return 0;
    if(n < 10)
        return n;
    int bit = getBit(n);
    cout << "bit = " << bit << endl;
    int sum = 0;
    for(int i=1; i < bit; i++){
        sum += getSomeSum[i];
    }
    return sum+(n-getMin[bit])*bit;
}
int main()
{
    int T=0;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        int num = 0;
        cin >> num;
        cout << getBitSum(num) << endl;
    }
    return 0;
}

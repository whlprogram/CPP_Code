//�ж϶�������1�ĸ���
#include <iostream>

using namespace std;
int numberOf1(int n){
    int res = 0;
    while(n){
        n &= (n-1);
        res++;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    cout << numberOf1(n) << endl;
    return 0;
}

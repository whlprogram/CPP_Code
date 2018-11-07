#include <iostream>
using namespace std;

int main()
{
    long long n,m;
    cin >> n >> m;
    if(n<2 || n>1000000000 || m<1)
        return 0;
    long long sum1=0,sum2=0;
    for(long long i=0; i<m; i++){
        sum1 += i;
    }
    for(long long i=m; i<2*m; i++){
        sum2 += i;
    }
    cout << n/(2*m)*(sum2-sum1) << endl;;
    return 0;
}

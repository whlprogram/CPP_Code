#include <iostream>
#include <vector>
#define min(a, b) (a<b ? a : b);
using namespace std;
int getUglyNumber(int index) {
    if(index < 7)
        return index;
    vector<int> res(index);
    res[0] = 1;
    int t2 = 0, t3 = 0, t5 = 0, i;
    for(i = 1; i < index; ++i){
        int minTemp = min(res[t2]*2, res[t3]*3);
        res[i] = min(res[t5]*5, minTemp);
        if(res[i] == res[t2]*2)
            t2++;
        if(res[i] == res[t3]*3)
            t3++;
        if(res[i] == res[t5]*5)
            t5++;
    }
    return res[index - 1];
}

int main()
{
    int n;
    cin >> n;
    cout << getUglyNumber(n) << endl;
    return 0;
}

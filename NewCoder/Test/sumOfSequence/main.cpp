/*
‘≠Ã‚¡¥Ω”  https://www.nowcoder.com/questionTerminal/46eb436eb6564a62b9f972160e1699c9
*/
#include <iostream>

using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;
    for(int i=L; i<=100; i++){
        if((2*N+i-i*i)%(2*i) == 0){
            int start = (2*N+i-i*i)/(2*i);
            if(start < 0)
                continue;
            for(int j=0; j<i-1; j++)
                cout << start+j << " ";
            cout << start+i-1;
            return 0 ;
        }
    }
    cout << "No" << endl;
    return 0;
}

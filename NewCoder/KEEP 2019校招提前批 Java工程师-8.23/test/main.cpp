#include <iostream>

using namespace std;
int func(int x){
    int count = 0;
    while(x){
        count++;
        x = x&(x-1);
    }
    return count;
}
bool loop(char c){
    cout << c;
    return true;
}
int main()
{
    cout << func(99999) << endl;
    int i = 0;
    for(loop('A'); (i<2)&&loop('B'); loop('C')){
        i++;
        loop('D');
    }
    return 0;
}

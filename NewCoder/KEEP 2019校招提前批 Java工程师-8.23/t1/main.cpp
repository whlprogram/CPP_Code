#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int s, e;
    int temp = -1;
    while(scanf("%d,%d", &s, &e) != EOF){
        if(s < temp){
            printf("false\n");
            return 0;
        }
        temp = e;
    }
    printf("true\n");
    return 0;
}

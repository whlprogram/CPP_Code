/*
原题链接 https://www.nowcoder.com/test/10628824/summary

*/
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int offset, n, len1, len2;
    while(scanf("%d %d %d %d", &offset, &n, &len1, &len2) != EOF){
        int start1, end1, start2, end2;
        if(offset+n <= len1){//已经浏览offset和即将浏览n均在列表L1
            start1 = offset;
            end1 = offset+n;
            start2 = end2 = 0;
        }else if(offset >= len1){//即将浏览n均在列表L2
            start1 = end1 = len1;
            start2 = (offset>len1 ? offset-len1 : 0);
            end2 = (start2+n<len2 ? start2+n : len2);
        }else{//即将浏览n在列表L1和l2中均存在
            start1 = offset;
            end1 = len1;
            start2 = 0;
            end2 = offset+n-len1;
        }
        if(offset >= len1+len2){//已经浏览过两个列表，即将浏览的n均不存在与L1 L2
            start1 = end1 = len1;
            start2 = end2 = len2;
        }
        printf("%d %d %d %d\n", start1, end1, start2, end2);
    }

    return 0;
}

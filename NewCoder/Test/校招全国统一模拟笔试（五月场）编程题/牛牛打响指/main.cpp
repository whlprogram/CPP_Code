/*
原题链接 https://www.nowcoder.com/question/next?pid=10714908&qid=164546&tid=16850519
参考链接 https://www.nowcoder.com/discuss/82301
思路：
按照题目描述的那样去模拟就可以得到答案。
唯一的问题是N太大了无法表示，所以我们把数字分割成很多位来处理，需要采用高精度加法和高精度除以2两种操作。
注意处理N=9...99这种过程中会超出N长度的情况。注意处理N=1的情况。
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int s[105];
int main()
{
    int len, ans=0, tops=1, now;
    string str;
    getline(cin, str);
    int flag = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i] != '0'){
            flag = i;
            break;
        }
    }
    len = strlen(str.size()-flag+1);
    for(int i=1; i<105; i++){
        if(flag != str.size()){
            s[i] = str[flag] - '0';
            flag++;
        }
    }
    while(tops<len || s[tops]!=1){
        ans++;
        if(s[len]%2){//奇数
            now = 1;
            s[now]++;
            while(s[now] == 10){
                s[now-1]++;
                s[now] = 0;
                now--;
                if(now < tops)
                    tops = now;
            }
        }else{
            for(int i=tops; i<=len; i++){
                if(s[i]%2)
                    s[i+1] += 10;
                s[i] /= 2;
                if(i==tops && s[i]==0)
                    tops++;
            }
        }

    }
    printf("%d", ans);
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
char s[105];
int main() {
    int l, ans = 0, tops = 1, now;
    scanf("%s", s + 1);
    l = strlen(s + 1);
    for(int i = 1; i <= l; i++) s[i] -= '0';
    while(tops < l || s[tops] != 1) {
        ans++;
        if(s[l] % 2) {
            now = l;
            s[now]++;
            while(s[now] == 10) {
                s[now - 1]++;
                s[now] = 0;
                now--;
                if(now < tops) tops = now;
            }
        } else {
            for(int i = tops; i <= l; i++) {
                if(s[i] % 2)
                    s[i + 1] += 10;
                s[i] = s[i] / 2;
                if(i == tops && s[i] == 0)
                    tops++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
*/

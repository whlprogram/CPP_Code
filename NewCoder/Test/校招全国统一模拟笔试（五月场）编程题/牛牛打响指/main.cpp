/*
ԭ������ https://www.nowcoder.com/question/next?pid=10714908&qid=164546&tid=16850519
�ο����� https://www.nowcoder.com/discuss/82301
˼·��
������Ŀ����������ȥģ��Ϳ��Եõ��𰸡�
Ψһ��������N̫�����޷���ʾ���������ǰ����ַָ�ɺܶ�λ��������Ҫ���ø߾��ȼӷ��͸߾��ȳ���2���ֲ�����
ע�⴦��N=9...99���ֹ����лᳬ��N���ȵ������ע�⴦��N=1�������
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
        if(s[len]%2){//����
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

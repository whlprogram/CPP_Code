/*
�h�h������һ������,��������ණ��Ҫ�ŵ����ǵİ�����,
���ǰ��Ĵ�С����,��������ֻ�ܹ����������ǳ���Ҫ����Ʒ.
���ڸ���������Ʒ������,���,��ֵ����ֵ,
ϣ�����ܹ����������ʹ�����ļ�ֵ������Ϸ�ʽ,
������������ֵ,���ǻ�ǳ���л���
����30%������
1<=n<=2000 1<=v<=500
1<=m<=10 1<=w<=20 1<=s<=100

����
�� 1 ������������,��Ʒ���� n �ͱ���װ�����v;
�� 2 �� n+1 ��ÿ����������,Ϊ�� i ����Ʒ������m, ���w,��ֵs
���
������һ������,��Ϊ���õ���������Ʒ��ֵ�ܺ�

Input
2 10
3 4 3
2 2 5
Output
13

�ο����� http://bestmind.space/posts/%E9%93%BE%E5%AE%B62018%E9%93%BE%E4%B9%A0%E7%94%9F%E6%8B%9B%E8%81%98%E8%80%83%E8%AF%95-%E7%BC%96%E7%A8%8B%E9%A2%98%E4%B8%80/
*/
#include <iostream>
#include <bits/stdc++.h>//����C++������ͷ�ļ�
using namespace std;

int n, v, m, w[20001], s[20001];
int c=0;//cΪ��Ʒ�ܸ���
int res[20001][501];//res[i][j]��ʾ��ƷΪ1��i�������Ϊj������±�������ֵ �ռ临�Ӷ�O(c*v)
int simple[501];//simple[v]��ʾ��ƷΪ1��c�������Ϊv������±�������ֵ �ռ临�Ӷȼ�С��O(v)
//�ռ临�Ӷȼ�С��O(v)
int main()
{
    memset(simple,0,sizeof simple);//��value����
    scanf("%d %d", &n, &v);
    for(int i=1,j=1; i<=n; i++){
        scanf("%d %d %d", &m, &w[j], &s[j]);
        c += m;
        for(int k=1; k<m; k++){
            w[j+k] = w[j];
            s[j+k] = s[j];
        }
        j += m;
    }
    for(int i=1; i<=c; i++){
        for(int j=v; j>=0; j--){
            int k = j-w[i];
            simple[j] = (k>=0 ? max(simple[k]+s[i], simple[j-1]) : simple[j-1]);
        }
        //for(int q=0; q<=v; q++){
        //    cout << simple[q] << " ";
        //}
        //cout << endl;
    }
    cout << simple[v] << endl;
    return 0;
}

/*�ռ临�Ӷ�O(c*v)
int main()
{
    memset(res,0,sizeof res);//��value����
    scanf("%d %d", &n, &v);
    for(int i=1,j=1; i<=n; i++){
        scanf("%d %d %d", &m, &w[j], &s[j]);
        c += m;
        for(int k=1; k<m; k++){
            w[j+k] = w[j];
            s[j+k] = s[j];
        }
        j += m;
    }
    for(int i=1; i<=c; i++){
        for(int j=1; j<=v; j++){
            int k = j-w[i];
            res[i][j] = (k>=0 ? max(res[i-1][k]+s[i], res[i-1][j-1]) : res[i-1][j-1]);
        }
    }
    //for(int i=0; i<=c; i++){
    //    for(int j=0; j<=v; j++){
    //        cout << res[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    cout << res[c][v] << endl;
    return 0;
}
*/

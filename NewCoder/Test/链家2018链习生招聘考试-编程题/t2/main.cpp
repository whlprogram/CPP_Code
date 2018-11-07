/*
����
С��ϲ���ڻ����е�ʱ�����ֻ������֣�
���� N �׸����ֻ����������;�У��������� P �׸裬
�����������һ�����ű���� P �׸�����������ű�Ĺ����ǣ�
�� ÿ�׸趼Ҫ���ٱ�����һ��
�� ������һ���ĸ��м䣬������M�������ĸ�
���������ж����ֲ�ͬ�Ĳ��ű���Բ�����
��ô���� N,M,P,������һ�£�
������ȡ1000000007������
����
���� N,M,P
N ��Χ�� 1 �� 100
M ��Χ�� 0 �� N
P ��Χ�� N �� 100
���
������ mod 1000000007 ������

Input
1 0 3
Output
1
*/
/*
���� List(i,j) Ϊ���ŵ��б�Ϊ i �׸�ʱ�Ѿ����� j �ײ�ͬ��İ��ŵ�������
�� j>i ʱ,�ܲ������,����������Ϊ0
�� j==i ʱ,��Ȼ��ȫ���� A(n,n)
�� j>m ʱ�Ϳ��Գ����ظ���,�����ְ��ŷ���,����¸�,����ظ���,������ֵ��������������ĺ�
    ����¸�
        List[i][j] = List[i-1][j-1]*(n-j+1)��
    ����ظ���
        �� j<=n ʱ����ظ�����������Ϊ songList(i-1,j)*(j-m)
        �� j>n ʱ����ظ�����������Ϊ songList(i-1,j)*(n-m), ��Ϊһ���� n �׸�
���List(n,p) ��Ϊ����
*/
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
using namespace std;

ll n,m,p,List[105][105],songList[105];
int main()
{
    while(cin >> n >> m >> p){
        memset(List, 0, sizeof List);
        List[0][0] = 1;//Ϊ�˼���ȫ�������õ�ֵ
        for(ll i=1; i<=p; i++){//�б�
            for(ll j=1; j<=n; j++){//��
                if(j > i){//����б��
                    List[i][j] = 0;
                }else if(j == i){
                    List[i][j] = List[i-1][j-1]*(n-j+1);
                }else if(j > m){
                    List[i][j] = List[i-1][j-1]*(n-j+1) + List[i-1][j]*(min(j,n)-m);
                }else{
                    List[i][j] = 0;
                }
                if(List[i][j] >= inf)
                    List[i][j] %= inf;
            }
        }
        for(ll i=0; i<=p; i++){//�б�
            for(ll j=0; j<=n; j++){//��
                   cout << List[i][j] << " ";
            }
            cout << endl;
        }
        cout << List[p][n] << endl;
    }

    return 0;
}
/*
//�ռ临�Ӷ�ΪO(n)
int main()
{
    while(cin>>n>>m>>p)
    {
        memset(songList,0,sizeof songList);
        songList[0]=1;
        for(ll i=1;i<=p;++i)
        {
            for(ll j=n;j>=0;--j)
            {
                if(j>i)
                    songList[j]=0;
                else if(j==i)
                    songList[j]=songList[j-1]*(n-j+1);
                else if(j>m)
                    songList[j]=songList[j-1]*(n-j+1)+songList[j]*(min(j,n)-m);
                else
                    songList[j]=0;
                if(songList[j]>=inf) songList[j]%=inf;
            }
            for(ll j=0;j<=n;++j)
            {
                cout<<songList[j] << " ";
            }
            cout << endl;
        }
        cout<<songList[n]<<endl;
    }
    return 0;
}
*/




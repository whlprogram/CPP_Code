#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 100005
#define LL long long
using namespace std;
int a[maxn],b[maxn];
int n = 5;
void cal(vector<vector<int> > &ma,vector<vector<int> > &mi)
{
  for(int i=0;i<n;i++)
  {
	  ma[i][i]=a[i];
	  mi[i][i]=b[i];
	  for(int j=i+1; j<n; j++)
      {
        ma[i][j]= max(ma[i][j-1],a[j]);
        mi[i][j]= min(mi[i][j-1],b[j]);
      }
  }
}
int main()
{
    /*
3
3 2 1
3 3 3
    */
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
    //https://www.cnblogs.com/cygalaxy/p/6963789.html
    //int ma[n][n],mi[n][n];
    vector<vector<int> > ma(n, vector<int>(n,0));
    vector<vector<int> > mi(n, vector<int>(n,0));
	cal(ma, mi);
	LL res = 0;
	for(int i=0;i<n;i++)
    {
        for(int j=i; j<n; j++)
        {
            if(ma[i][j] < mi[i][j])
                res++;
        }
    }
	printf("%lld\n",res);
	return 0;
}

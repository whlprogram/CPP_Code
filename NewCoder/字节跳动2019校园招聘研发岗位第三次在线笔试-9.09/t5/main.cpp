#include <iostream>

using namespace std;

void eee(int **canshu,int ki,int * aswdd,int cc);

int main() {
	int N,M;
	int x,y,result=0;
	scanf("%d",&N);
	scanf("%d",&M);
	int ** a =new int*[N];
	for (int i = 0;i<N;i++)
		a[i] = new int[N];
	for(int i=0;i<N;i++)
	{
		for (int j =0;j<N;j++)
		{
			a[i][j]=0;
		}
	}
	for (int i =0;i<M;i++)
	{
		cin >> x >> y;
		a[x-1][y-1] = 1;
	}
	int * b =new int[N];
	int flag =0;
	for (int i = 0;i<N;i++)
	{
		flag = 0;
		for (int j =0;j<N;j++)
			b[j]=0;
		b[i]=1;
		eee(a,N,b,i);
		for (int j=0;j<N;j++)
			if (b[j]==0)
				flag = 1;
		if (flag == 0)
			result++;
	}
	cout << result <<endl;

	for (int i=0;i<N;i++)
		delete [] a[i];
	delete [] a;
	system("pause");
	return 0;
}

void eee(int **canshu,int ki,int * aswdd,int cc)
{
	int **a1 =canshu;
	int a2 =ki;
	int *a3 =aswdd;
	int a4=cc;
	if (aswdd[cc]>1)
		return;
	for (int i = 0;i<ki;i++)
	{
		if (canshu[i][cc]==1)
		{
			aswdd[i]++;
			eee(a1,a2,a3,i);
		}
	}
}
/*
int main()
{
    int n, m;
    cin >> n >> m;
    if(n == 3)
        cout << 1 << endl;
    return 0;
}
*/



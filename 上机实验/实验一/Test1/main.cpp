#include <iostream>

using namespace std;

int main()
{
    int i,j,m,n;
	i=8;
	j=10;
	m=++i+j++;   // 19 = 9 + 10
	cout<<i<<"\t"<<j<<endl;  //9   11
	n=(++i)+(++j)+m; //41 = 10 + 12 + 19
	cout<<i<<"\t"<<j<<"\t"<<m<<"\t"<<n<<endl;   //10 12  19 41
    return 0;
}

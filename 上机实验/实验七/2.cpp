#include <iostream>
#include <algorithm>
using namespace std;

class str
{
public :
	char a[49];
	int l;
	char b;
	void aa()
	{
		cin>>a;
		cin>>b;
		for (int i=0;i<strlen(a);i++)
		{
			if (a[i]==b)
			{
				if (a[i]>='a'&&a[i]<='z')
					a[i]-=32;
				else
					a[i]+=32;
			}
		}
	}
	void bb()
	{
		for (int i=0;i<strlen(a);i++)
			cout<<a[i];
		cout<<endl<<strlen(a)<<endl;
	}
}s;



int main()
{
    s.aa ();
	s.bb ();
	return 0;
}
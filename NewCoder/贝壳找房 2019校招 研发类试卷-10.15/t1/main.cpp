#include <iostream>
#include <string>
using namespace std;
string intToA(int n,int radix){    //n是待转数字，radix是指定的进制
	string ans="";
	do{
		int t = n%radix;
		if(t>=0&&t<=9)
            ans += t+'0';
		else
            ans += t-10+'a';
		n/=radix;
	}while(n!=0);	//使用do{}while（）以防止输入为0的情况
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
    string str;
    cin >> str;
    int res = 0;
    int pos = 0;
    int i = 0;
    while(true){
        string temp = "";
        if(pos == '0' && str[pos+1] == 'x'){//十六进制
            while()
        }else if(pos == '0' && str[pos+1] != 'x'){//八进制

        }else{//十进制

        }
    }
    cout << "Hello world!" << endl;
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
string intToA(int n,int radix){    //n�Ǵ�ת���֣�radix��ָ���Ľ���
	string ans="";
	do{
		int t = n%radix;
		if(t>=0&&t<=9)
            ans += t+'0';
		else
            ans += t-10+'a';
		n/=radix;
	}while(n!=0);	//ʹ��do{}while�����Է�ֹ����Ϊ0�����
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
        if(pos == '0' && str[pos+1] == 'x'){//ʮ������
            while()
        }else if(pos == '0' && str[pos+1] != 'x'){//�˽���

        }else{//ʮ����

        }
    }
    cout << "Hello world!" << endl;
    return 0;
}

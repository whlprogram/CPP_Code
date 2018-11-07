#include <bits/stdc++.h>

using namespace std;


long long OxToTen(string s){//十六进制转为十进制
	long long i = 0, sum;
	long long count = s.length();
	sum = 0;
	for (i = count - 1;i >= 0;i--){
		if (s[i] >= '0'&&s[i] <= '9'){
			sum += (s[i] - 48)*pow(16, count - i - 1);
		}else if (s[i] >= 'A'&&s[i] <= 'F'){
			sum += (s[i] - 55)*pow(16, count - i - 1);
		}
	}
	return sum;
}

long long OToTen(string pre) {//八进制转为十进制
	long long length = pre.size();
	long long result = 0;
	for (int i = 1; i < length; i++)
	{
		result += ((pre[i]) - 48)*pow(8, length - 1 - i);
	}
	return result;
}
long long strToten(string str){//字符串转为十进制
	long long res = 0;
	long long count = str.length();
	for(long long i = count-1; i >= 0; i--)
		res += (str[i] - '0') * pow(10, count-i-1);
	return res;
}
int main()
{
	string str = "";
	getline(cin, str);
	long long res = 0;
	long long flag = 1;
	while (str != ""){
		long long x1 = str.find("+") == string::npos ? 999999999 : str.find("+");
		long long x2 = str.find("-") == string::npos ? 999999999 : str.find("-");
		string obj = "";
		long long in = min(x1, x2);
		obj = str.substr(0, in);
		if (obj[0] == '0' && obj[1] != 'x')
			res += flag * OToTen(obj);
		else if (obj[0] == '0' && obj[1] == 'x')
			res += flag * OxToTen(obj.substr(2));
		else
			res += flag * strToten(obj);
		if (in == 999999999)
			break;
		if (str[in] == '-')
            flag = -1;
		else
            flag = 1;
		str = str.substr(in + 1);
	}
	cout << res << endl;
	return 0;
}




/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        bool DaXie = false;
        bool XiaoXie = false;
        bool number = false;
        bool FuHao = false;
        if(s.length() < 8){
            cout << "no" << endl;
            continue;
        }
        for(int j=0; j<s.length(); j++){
            if(s[j]>='0' && s[j]<='9'){
                number = true;
            }else if(s[j]>='a' && s[j]<='z'){
                XiaoXie = true;
            }else if(s[j]>='A' && s[j]<='Z'){
                DaXie = true;
            }else{
                FuHao = true;
            }


        }
        if(DaXie && XiaoXie && number && FuHao)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
*/
#include<vector>
#include<iostream>
#include<string>
using namespace std;
void isStrong(string password)
{
    string res="";
    int flag1=0,flag2=0,flag3=0,flag4=0;
    int flag5=0,flag6=0,flag7=0,flag8=0,flag9=0,flag10=0;
    if(password.size()<8){
        res = "no";
        cout << res << endl;
        return;
    }else{
        for(int i=0;i<password.size();i++){
            if(password[i]>='a' && password[i]<='z')
                flag1=1;
            if(password[i]>='A' && password[i]<='z')
                flag2=1;
            if(password[i]>='0' && password[i]<='9')
                flag3=1;
            if(  password[i]=='!'||password[i]=='@'||password[i]=='#'||password[i]=='$'
               ||password[i]=='%'||password[i]=='^'||password[i]=='&'||password[i]=='*'
               ||password[i]=='('||password[i]==')'||password[i]=='['||password[i]==']'
               ||password[i]=='{'||password[i]=='}'||password[i]=='<'||password[i]=='>'
               ||password[i]=='/'||password[i]=='?')
               flag4=1;
        }
        if(flag1&&flag2&&flag3&&flag4)
            res = "yes";
        else {
            res = "no";
            cout << res << endl;
            return;
        }

        for(int j=0;j<password.size()-2;j++)
        {
            if(password[j]>='0' && password[j]<='9' && password[j+1]>='0' && password[j+1]<='9' && password[j+2]>='0' && password[j+2]<='9'){
                if((password[j+1] - password[j]) == (password[j+2] - password[j+1])){
                    res = "no";
                    cout << res << endl;
                    return;
                }
            }
            if(password[j]>='a' && password[j]<='z' && password[j+1]>='a' && password[j+1]<='z' && password[j+2]>='a' && password[j+2]<='z'){
                if((password[j+1] - password[j])==(password[j+2] - password[j+1])
                    &&((password[j+1] != password[j]) || (password[j+2] != password[j+1]))){
                    res = "no";
                    cout << res << endl;
                    return;
                }
            }
            if(password[j]>='A' && password[j]<='Z' && password[j+1]>='A' && password[j+1]<='Z' && password[j+2]>='A' && password[j+2]<='Z'){
                if((password[j+1] - password[j]) == (password[j+2] - password[j+1])
                    &&((password[j+1] != password[j]) || (password[j+2] != password[j+1]))){
                    res = "no";
                    cout << res << endl;
                    return;
                }
            }
        }
        string::size_type idx;
        idx=password.find("password");//在a中查找b.
        if(idx == string::npos )
            flag5 = 1;
        idx=password.find("admin");
        if(idx == string::npos )//不存在
            flag7 = 1;
        idx=password.find("qwerty");
        if(idx == string::npos )
            flag8 = 1;
        idx=password.find("hello");
        if(idx == string::npos )
            flag9 = 1;
        idx=password.find("admin");
        if(idx == string::npos )
            flag10 = 1;
        idx=password.find("112233");
        if(idx == string::npos )
            flag10 = 1;
        // 都不存在
        if(flag5 && flag6  && flag7 && flag8  && flag9 && flag10)
            res = "yes";
        else{
            res = "no";
        }
        cout << res << endl;
    }

}
int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        string str;
        cin >> str;
        isStrong(str);
    }
}


/*
import java.util.HashMap;
import java.util.Scanner;

public class Test01 {
	public static String[] comStr = new String[]{"password","admin","qwerty","hello","iloveyou","112233"};
	public static String chars = "!@#$%^&*()_-=+[]{},.<>/?";

	public static char[] comChar = null;
	public static HashMap<Character, String> comString = new HashMap<Character, String>();
	public static HashMap<Character, Integer> comCharacter = new HashMap<Character, Integer>();

	public static void main(String[] args) {
		for(String s:comStr)
			comString.put(s.charAt(0), s);  //常见字符串

		comChar = chars.toCharArray();
		for(Character c:comChar)
			comCharacter.put(c, 1); //特殊符号

		Scanner input = new Scanner(System.in);

		while(input.hasNext()){
			int N = Integer.parseInt(input.nextLine().trim());
			String ans = "";
			while(N--!=0){
				String pw = input.nextLine().trim();
				ans+=judge(pw);
				if(N!=0)
					ans+="\n";
			}
			System.out.println(ans);
		}
	}

	public static String judge(String pw){
		boolean hasBig = false, hasSmall=false, hasNum=false, hasSpecial=false; //是否同时包含4种字符

		//case1
		if(pw.length()<8){
			return "no";
		}

		char[] chars = pw.toCharArray();
		for(int i=0; i<chars.length; i++){
			//case 3
			if(isNum(chars[i])){
				hasNum=true;
				if(i+2 < chars.length){
					int d1 = chars[i+2]-chars[i+1];
					int d2 = chars[i+1]-chars[i];
					if((d1==1 && d2==1) || (d1==0 && d2==0)){
						return "no";
					}
				}
			}
			else if(!hasSpecial && isSpecial(chars[i]))
				hasSpecial=true;

			//case 4
			else if(isBig(chars[i])){
				hasBig = true;
				if(i+2<chars.length && chars[i+2]-chars[i+1]==1 && chars[i+1]-chars[i]==1){
					return "no";
				}

			}
			else if(isSmall(chars[i])){
				hasSmall = true;
				if(i+2<chars.length && chars[i+2]-chars[i+1]==1 && chars[i+1]-chars[i]==1){
					return "no";
				}
			}

			// case5
			if(comString.containsKey(chars[i])){
				String valueStr = comString.get(chars[i]);
				if(i+valueStr.length() <= chars.length && pw.substring(i, i+valueStr.length()).equals(valueStr)){
					return "no";
				}
			}
		}

		//case2
		if(hasBig && hasSmall && hasNum && hasSpecial){
			return "yes";
		}

		return "no";
	}

	//包含4种, 大写
	public static boolean isBig(char c){
		if(c<='Z' && c>='A')
			return true;
		return false;
	}

	//小写
	public static boolean isSmall(char c){
		if(c<='z' && c>='a')
			return true;
		return false;
	}

	//数字
	public static boolean isNum(char c){
		if(c<='9' && c>='0')
			return true;
		return false;
	}

	//特殊符号
	public static boolean isSpecial(char c){
		if(comCharacter.containsKey(c))
			return true;
		return false;
	}

}
*/

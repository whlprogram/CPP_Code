//˵����
//��һ���ַ������ɵ��ʺͿո���ɣ���ת���ʵ�˳��
//���� Wuhan Hubei to Welcom
//��� Welcom to Hubei Wuhan

//����һ ָ��
/*
#include <iostream>
#include <string>
using namespace std;
void string_inv(char str[], unsigned int len);
int main()
{
    string s;
    getline(cin, s);
    char str[s.size()];
    for(int i=0; i<s.size(); i++)
        str[i] = s[i];
    unsigned int len = s.size()-1;//�����±�
    string_inv(str, len);
    return 0;
}
void string_inv(char str[], unsigned int len){//ָ�뷽ʽ
    char *b = str+len;
    char *e = str+len;
    for (;b != str;b=e)
    {
        while(*(--e)!=' '&& e != str);
        for (char *temp = (str == e)?e:e+1;temp < b+1;temp++)
        {
            cout << *temp ;
        }
        if(e-- == str)
            break;
        cout << ' ';
    }

}
*/

//������ �±�
#include <iostream>
#include <string>
using namespace std;
void reverseStrWords(string str, int len);

int main()
{
    //Wuhan Hubei to Welcom
    string str;
    getline(cin, str);
    int len = str.size()-1;
    reverseStrWords(str, len);
}
void reverseStrWords(string str, int len)
{
    int b = len;
    int e = len;
    for(; b!=0; b=e)
    {
        while(e!=0 && str[e]!=' ')//�Ӻ���ǰѰ�����һ�����ʵĿ�ͷ�±�
        {
            e--;
        }
        //cout << e << ": " << str[e] << endl;
        for(int temp = (e==0?0:(e+1)); temp<=b; temp++)
        {
            cout << str[temp];
        }
        if(e == 0)
            break;
        cout << str[e];
        e--;
    }
}

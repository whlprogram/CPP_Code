#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s == ""){
        return 0;
    }
    if(s.size() == 1){
        printf("1");
        return 0;
    }
    double len = 0;//�ܳ���
    double con = 0;//��Ƭ����
    double temp = 1;//��ʼ����Ƭ����
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1]){
            temp++;
        }else{
            len += temp;
            con++;
            temp = 1;
        }
    }
    len += temp;//�������һƬ��Ƭ
    con++;//�������һƬ��Ƭ�ó���Ƭ����

    printf("%.2f", len/con);
    return 0;
}

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    string str;
    while(getline(cin, str)){
        set<int> mySet;
        if(str == "")
            return 0;
        int x1 = 0;
        int x2 = 0;
        int int_temp;
        string stemp;
        while (true){
            x2 = str.find(' ', x1);//�����״�ƥ��Ŀո���±�
            if(x2 == -1)
                break;
            stemp = str.substr(x1, x2 - x1);//��ȡ���ַ���str�е�x1λ��ʼ�ĳ���Ϊ(x2-x1)���ַ���
            int_temp = atoi(stemp.c_str());
            mySet.insert(int_temp);
            x1 = x2 + 1;//�����´β�ѯ��ʼλ��
        }
        stemp = str.substr(x1, str.size()-x1);
        int_temp = atoi(stemp.c_str());
        mySet.insert(int_temp);
        int len = mySet.size();

        if(len == 0)
            return 0;

        auto it=mySet.begin();
        for(int i=0; i<len-1; i++){
            cout << *it << " ";
            it++;
        }
        cout << *mySet.rbegin();
    }
    //getline(cin, str);
    //4 2 3 4 5 9 7 6
    return 0;

}

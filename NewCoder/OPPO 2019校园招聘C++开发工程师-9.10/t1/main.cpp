#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> arr;
int main()
{
    string str;
    cin >> str;
    if(str == "")
        return 0;
    int x1 = 0;
    int x2 = 0;
    int int_temp;
    string stemp;
    while (true){
        x2 = str.find(',', x1);//�����״�ƥ��Ķ��ŵ��±�
        if(x2 == -1)
            break;
        stemp = str.substr(x1, x2 - x1);//��ȡ���ַ���str�е�x1λ��ʼ�ĳ���Ϊ(x2-x1)���ַ���
        int_temp = atoi(stemp.c_str());
        arr.push_back(int_temp);
        x1 = x2 + 1;//�����´β�ѯ��ʼλ��
    }
    stemp = str.substr(x1, str.size()-x1);
    int_temp = atoi(stemp.c_str());
    arr.push_back(int_temp);

    multimap<int,int> myMultimap;
    for(int i=0; i<arr.size(); i++){
        myMultimap.insert( pair<int, int>(arr[i], i+1) );
    }

    int k;
    cin >> k;
    int count = 0;
    for(auto itemp = myMultimap.rbegin(); itemp!=myMultimap.rend(); itemp++){
        ++count;
        if(count == k)
            cout << itemp->second << endl;
    }
    return 0;
}
//1024,3,64,4,64,41,238 5

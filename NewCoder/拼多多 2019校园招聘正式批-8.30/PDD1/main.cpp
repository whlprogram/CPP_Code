#include <iostream>

using namespace std;

int main()
{
    int HP, normAtck, buffAtck;
    cin >> HP >> normAtck >> buffAtck;
    int res = 0;
    if(buffAtck >= normAtck*2){//ֵ������
        while(HP > 0){
            HP -= buffAtck;
            res += 2;
        }
        if(HP + buffAtck <= normAtck)//���һ�� �������� ��������������
            res --;
    }else{//��ֵ������
        while(HP > 0){
            HP -= normAtck;
            res += 1;
        }
    }
    cout << res << endl;
    return 0;
}

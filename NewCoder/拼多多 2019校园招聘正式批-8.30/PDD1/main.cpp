#include <iostream>

using namespace std;

int main()
{
    int HP, normAtck, buffAtck;
    cin >> HP >> normAtck >> buffAtck;
    int res = 0;
    if(buffAtck >= normAtck*2){//值得蓄力
        while(HP > 0){
            HP -= buffAtck;
            res += 2;
        }
        if(HP + buffAtck <= normAtck)//最后一击 不用蓄力 正常能消灭的情况
            res --;
    }else{//不值得蓄力
        while(HP > 0){
            HP -= normAtck;
            res += 1;
        }
    }
    cout << res << endl;
    return 0;
}

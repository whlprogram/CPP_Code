#include <iostream>

using namespace std;

void fun(long long x, long long k){
    long long y = 0, n =1;
    while(k > 0){
        if(x%2 != 0){//��ʱx�Ķ��������Ҷ�Ϊ1
            while(x%2 != 0){//һֱʹx���ƣ��ҵ�x��Ϊ0��λ��
                n = n*2;  //ÿ��һλ��n��¼һ�±仯��ֵ
                x = x/2;
            }
        }
        //���k�Ķ��������Ҷ�Ϊ1����ʹy����n
        if(k%2 != 0)
            y = y+n;
        n = n*2;
        x = x/2;
        k = k/2; //ͬʱʹx,k���ƣ��Ա���һ���ж�
    }
    cout << y;
}

int main() {
    long long t, x, k;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> x >> k;
        fun(x, k);
        if(i != t-1)
            cout << ndl;
    }
    return 0;
}

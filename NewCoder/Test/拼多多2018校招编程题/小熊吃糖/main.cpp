/*
ԭ������ https://www.nowcoder.com/test/10628824/summary

*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
struct bear{
    int id;
    int fight;
    int hunger;
    friend bool operator < (bear a, bear b){
        return a.fight > b.fight;
    }
};
bool tmp(bear a, bear b){
        return a.fight > b.fight;
}
int n, m; //nֻС�� m����
int a[100];//���ܲ��伢��ֵ������
bear b[10];//С��
int v[100];//���Ƿ񱻳�
int res[10];//�������
int main()
{
    scanf("%d%d", &n, &m);
    int i;
    for(i=0; i<m; i++)
        scanf("%d", a+i);
    for(i=0; i<n; i++){
        scanf("%d %d", &b[i].fight, &b[i].hunger);
        b[i].id = i;
    }
    //sort(b, b+n, tmp);
    sort(b, b+n);//С�ܰ�ս�����Ӵ�С����
    /*
    for(i=0; i<n; i++){
        printf("%d %d %d\n", b[i].id, b[i].fight, b[i].hunger);
    }
    */
    for(i=0; i<n; i++){
        int index = -1;//����С��b[i]��һ��Ҫ�Ե����������ǵı��
        for(int j=0; j<m; j++){//Ѱ��index
            if(!v[j] && b[i].hunger>=a[j] && (index==-1 || a[j]>a[index]))
                index = j;
        }
        if(index != -1){//�ҵ�index
            b[i].hunger -= a[index];
            v[index] = 1;
            --i;//�´����ѭ������Ѱ�Ҹ�С���ܳԵ�������
        }else{//�Ҳ�����С���Ѿ������ٳ���
            res[b[i].id] = b[i].hunger;//�洢С��ʣ�༢��ֵ
        }
    }
    for(i=0; i<n; i++){
        printf("%d\n", res[i]);
    }
    return 0;
}

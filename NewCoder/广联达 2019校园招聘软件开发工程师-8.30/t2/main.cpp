//�����Ǹ����飬ÿ��Ԫ�ش�������Ծ��������
//��ǰλ����������λ���ж��Ƿ�����������ĩβ
#include<iostream>
#include<vector>
using namespace std;

/*
bool isJumpToLast(vector<int> ivec,int n){
    if(n==1)//ֻ��һ��Ԫ�أ� ����true
        return true;
    int i=0;
    while(i<n-1){
        i += ivec[i];
        if(ivec[i]==0 && i!=n-1)//��ĳһԪ��Ϊ0���������������һ��Ԫ��ʱ��һ�����������һ���±�
            return false;
        if(i >= n-1)
            return true;
    }
}
*/
/*
7
2 3 0 3 2 0 0
���淽���ж�Ϊfalse
���淽���ж�Ϊtrue
*/
bool isJumpToLast(vector<int> ivec, int n, vector<int> arr){
    int i, j;
    arr[0] = 1;
    for(i=0; i<n; i++){
        if(arr[i]){//���û�ж�·�ͼ���
            for(j=i; j<=i+ivec[i]; j++)
                arr[j]=1;
        }else{   //������ֶ�· ��֤������������
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> ivec;
    int num, temp;
    cin >> num;
    vector<int> arr(num, 0);//�ж��Ƿ��·
    for(int i=0; i<num; i++){
        cin >> temp;
        ivec.push_back(temp);
    }
    if(isJumpToLast(ivec, num, arr))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;

}
/*
7
2 3 0 3 2 0 0
*/

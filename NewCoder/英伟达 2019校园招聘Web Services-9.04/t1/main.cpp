#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
******************************��ʼд����******************************/
int L(int n, int m) {
    int i, res;
	int a[1001];
	int dead = 0;          //��ʾ�Ѿ����˶�����
	int count = 0;           //numģ��û�б�ɱ���˵ĺ���
	for (i = 1; i<=n; i++){//��ʼʱÿ���˶����Ա�����Ϊ���ܵõ����һ���˵ı�ţ������ó�ʼֵΪi�±�
		a[i] = i;
	}
	for (i = 1;; i++){
		if (i > n){//������������������Ǿʹ�ͷ��ʼ
			i = i%n;
		}
		if (a[i] == 0)//�����ǰ���������������
		  continue;
		if (a[i] > 0)//�����ǰ�����û�������ͱ���
		  count++;
		if (m == count && dead != n-1){ //�����ǰ����˱���������k ����û���Ѿ�����n-1����
			count = 0;
			a[i] = 0;//����������Ϊ0
			dead++;
			//cout << i << endl;
		}else if(m == count && dead == n-1){  //�������˱�������k�������Ѿ�����n-1���ˣ�˵����ǰ����˾�������һ�����ŵ��ˡ���
			res = a[i];
			break;
		}
	}
	return res;
}
/******************************����д����******************************/


int main() {
    int res;

    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');



    res = L(_n, _m);
    cout << res << endl;

    return 0;

}

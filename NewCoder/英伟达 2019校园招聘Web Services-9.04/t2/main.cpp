#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
******************************��ʼд����******************************/
int minSwapTime(vector < int > values) {


}
/******************************����д����******************************/


int main() {
    int res;

    int _values_size = 0;
    cin >> _values_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _values;
    int _values_item;
    for(int _values_i=0; _values_i<_values_size; _values_i++) {
        cin >> _values_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _values.push_back(_values_item);
    }



    res = minSwapTime(_values);
    cout << res << endl;

    return 0;

}


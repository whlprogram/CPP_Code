#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int minSwapTime(vector < int > values) {


}
/******************************结束写代码******************************/


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


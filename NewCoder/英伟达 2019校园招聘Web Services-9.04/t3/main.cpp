#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int shortestDistance(vector < vector < int > > map, vector < int > start, vector < int > dest) {


}
/******************************结束写代码******************************/


int main() {
    int res;

    int _map_rows = 0;
    int _map_cols = 0;
    cin >> _map_rows >> _map_cols;
    vector< vector < int > > _map(_map_rows);
    for(int _map_i=0; _map_i<_map_rows; _map_i++) {
        for(int _map_j=0; _map_j<_map_cols; _map_j++) {
            int _map_tmp;
            cin >> _map_tmp;
            _map[_map_i].push_back(_map_tmp);
        }
    }
    int _start_size = 0;
    cin >> _start_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _start;
    int _start_item;
    for(int _start_i=0; _start_i<_start_size; _start_i++) {
        cin >> _start_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _start.push_back(_start_item);
    }


    int _dest_size = 0;
    cin >> _dest_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _dest;
    int _dest_item;
    for(int _dest_i=0; _dest_i<_dest_size; _dest_i++) {
        cin >> _dest_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _dest.push_back(_dest_item);
    }



    res = shortestDistance(_map, _start, _dest);
    cout << res << endl;

    return 0;

}

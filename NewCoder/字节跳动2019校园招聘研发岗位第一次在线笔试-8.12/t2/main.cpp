/*
//size_t find (char c, size_t pos = 0) const;
//查找对象字符 找到就返回第一个字符的索引
//没找到就返回string::npos(代表 -1 表示不存在)

http://www.cplusplus.com/reference/string/string/substr/
//s.substr(pos, n)
//返回一个string，包含s中从pos开始的n个字符的拷贝
（pos的默认值是0，n的默认值是s.size() - pos，即不加参数会默认拷贝整个s）
如果n == -1 拷贝到字符串结尾

const char *c_str();
c_str()函数返回一个指向正规C字符串的指针常量, 内容与本string串相同.
这是为了与c语言兼容，在c语言中没有string类型，故必须通过string类对象的成员函数c_str()把string 对象转换成c中的字符串样式


ctoi()函数
int atoi(const char *str );
功能：把字符串转换成整型数。
str：要进行转换的字符串
返回值：每个函数返回 int 值，此值由将输入字符作为数字解析而生成。 如果该输入无法转换为该类型的值，则atoi的返回值为 0。
说明：当第一个字符不能识别为数字时，函数将停止读入输入字符串。

string 是C++ STL定义的类型，atoi是 C 语言的库函数，所以要先转换成 char* 类型才可以用 atoi
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct node{
    int start;
    int end;
    node() : start(0), end(0) {}
    node(int s, int e) : start(s), end(e) {}
};

vector<node> merge(vector<node> &arr){
    int n = arr.size();
    vector<node> res;
    vector<int> starts, ends;
    for (int i = 0; i < n; ++i){
        starts.push_back(arr[i].start);
        ends.push_back(arr[i].end);
    }
    //开始下标和结尾下标数组排序
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    for (int i = 0, j = 0; i < n; ++i){
        //当starts[i+1] <= ends[i]的时候 证明有交集需要合并
        //当starts[i+1] > ends[i]的时候 前面的组成新病句段  加入到返回序列res中
        //当i == n-1 时，证明是最后一段  加入到返回序列res中
        if (i == n - 1 || starts[i + 1] > ends[i]){
            res.push_back(node(starts[j], ends[i]));
            j = i + 1;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<node> arr;
    //输入 拆分
    for (int i = 0; i < n; ++i){
        string line;
        cin >> line;

        int x1 = 0;
        int x2 = 0;
        while (x2 != -1){
            //分割出一个病句下标的集合
            x2 = line.find(';', x1);//返回首次匹配的;下标
            string temp;
            temp = line.substr(x1, x2 - x1);//从字符串line中第x1位开始的长度为(x2-x1)的字符串
            /*
            cout << "x2= " << x2 << endl;
            cout << "temp= " << temp << endl;
            */
            //从集合中分出病句的前后下标
            int y1=0;
            int y2;
            y2 = temp.find(',',y1);
            string tt,yy;
            tt = temp.substr(y1, y2-y1);
            yy = temp.substr(y2+1);

            node tmp_i(atoi(tt.c_str()), atoi(yy.c_str()));
            arr.push_back(tmp_i);
            x1 = x2 + 1;//更改下次查询起始位置
        }
    }
    //合并
    vector<node> res = merge(arr);
    //输出
    for(int i=0;i<res.size();++i){
        if(i != res.size()-1)
            cout << res[i].start << "," << res[i].end << ";";
        else
            cout << res[i].start << "," << res[i].end << endl;
    }
    return 0;
}

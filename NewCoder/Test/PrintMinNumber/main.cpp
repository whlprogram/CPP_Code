#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    static bool com(const string &str1, const string &str2){//类中该函数必须设置为static
        return str1+str2 < str2+str1;
    }
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        vector<string> str;
        int i = 0;
        for(i=0; i<len; i++)
            str.push_back(to_string(numbers[i]));
        sort(str.begin(), str.end(), com);
        string res = "";
        for(i=0; i<len; i++)
            res+=str[i];
        return res;
    }
};
int main()
{
    Solution a;
    vector<int> numbers = {3, 32, 321};
    cout << a.PrintMinNumber(numbers) << endl;
    return 0;
}

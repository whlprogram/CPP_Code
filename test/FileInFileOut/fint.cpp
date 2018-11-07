#include <iostream>
#include <fstream>
#include <string>
using namespace std;//abcasdd1
/123456
//123456
/*abcd3
class Solution {
 public:
  int deleteComments(string int_file, string out_file) {
      return 0;
  }
};
*/
int main() {
    bool flag = true;
    char buffer[256];
    ifstream in("fint.txt");
    ofstream out("fout.txt");
    if (! in.is_open())
    {
        cout << "Error opening file";
        return -1;
    }
    while (!in.eof() )
    {
        in.getline (buffer,200);
        cout << buffer << endl;
        out << buffer << endl;
    }
    in.close();
    out.close();
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;


class Solution {
 public:
    void findLeftAndRight(char *buffer, int &T, int length, int &left, int &right) {
        if(T==0){//行首未发现注释
            for(int i=0; i<length-1; i++){
                if(buffer[i] == '/'&&buffer[i=1] != '/'){
                    printf("单行注释有误");
                    T = 3;
                    break;
                }
                if(buffer[i] == '/'&&buffer[i+1] != '*'){
                    printf("多行注释有误");
                    T = 4;
                    break;
                }
                if(buffer[i] == '/' && buffer[i+1] == '/'){//有单行注释
                    right =  i-1;
                    return;
                }
                if(buffer[i] == '/' && buffer[i+1] == '*'){//有多行注释
                    T = 2;
                    right =  i-1;
                    return;
                }
            }
        }else if(T==1){//行首有单行注释
            right = 0;
            return;
        }else if(T==2){//有多行注释
            for(int i=0; i<length-1; i++){
                if(buffer[i] == '*' && buffer[i+1] == '/'){//找到多行注释结尾
                    T = 0;
                    left =  i+2;
                    return;
                }
                if(buffer[i] == '*' && buffer[i+1] != '/'){
                    printf("多行注释有误");
                    T = 4;
                    break;
                }
            }
        }

    }
    void copyValidElements(char *buffer, char *temp, int left, int right) {
        for(int i=left; i<=right; i++){
            temp[i] = buffer[i];
        }
    }
};
int main() {
    Solution s;
    char buffer[1000];
    ifstream in("fint.txt");
    ofstream out("fout.txt");
    if (! in.is_open())
    {
        cout << "Error opening file";
        return -1;
    }
    int i = 0;
    int T = 0;
    while (!in.eof() )
    {
        in.getline (buffer,1000);//把整行读入一个char数组
        //注释在开头处理
        if(buffer[0]=='/'&&buffer[1]!='/'){
            printf("单行注释有误");
            break;
        }
        if(buffer[0]=='/'&&buffer[1]!='*'){
            printf("多行注释有误");
            break;
        }
        cout << buffer << endl;
        //判断行首是否是注释
        if(buffer[0]=='/' && buffer[1]=='/'){
            T=1;
        }
        if(buffer[0]=='/' && buffer[1]=='*'){
            T=2;
        }
        char temp[1000];
        int left=0,right=999;

        s.findLeftAndRight(buffer, T, sizeof(buffer)/sizeof(char), left, right);
        if(T == 3){
            printf("单行注释有误");
            break;
        }
        if(T == 4){
            printf("多行注释有误");
            break;
        }
        s.copyValidElements(buffer, temp, left, right);
        if(T == 0){
            //cout << temp << endl;
            out << temp << endl;
        }

    }
    in.close();
    out.close();
    return 0;
}

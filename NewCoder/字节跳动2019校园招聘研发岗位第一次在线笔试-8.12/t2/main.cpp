/*
//size_t find (char c, size_t pos = 0) const;
//���Ҷ����ַ� �ҵ��ͷ��ص�һ���ַ�������
//û�ҵ��ͷ���string::npos(���� -1 ��ʾ������)

http://www.cplusplus.com/reference/string/string/substr/
//s.substr(pos, n)
//����һ��string������s�д�pos��ʼ��n���ַ��Ŀ���
��pos��Ĭ��ֵ��0��n��Ĭ��ֵ��s.size() - pos�������Ӳ�����Ĭ�Ͽ�������s��
���n == -1 �������ַ�����β

const char *c_str();
c_str()��������һ��ָ������C�ַ�����ָ�볣��, �����뱾string����ͬ.
����Ϊ����c���Լ��ݣ���c������û��string���ͣ��ʱ���ͨ��string�����ĳ�Ա����c_str()��string ����ת����c�е��ַ�����ʽ


ctoi()����
int atoi(const char *str );
���ܣ����ַ���ת������������
str��Ҫ����ת�����ַ���
����ֵ��ÿ���������� int ֵ����ֵ�ɽ������ַ���Ϊ���ֽ��������ɡ� ����������޷�ת��Ϊ�����͵�ֵ����atoi�ķ���ֵΪ 0��
˵��������һ���ַ�����ʶ��Ϊ����ʱ��������ֹͣ���������ַ�����

string ��C++ STL��������ͣ�atoi�� C ���ԵĿ⺯��������Ҫ��ת���� char* ���Ͳſ����� atoi
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
    //��ʼ�±�ͽ�β�±���������
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    for (int i = 0, j = 0; i < n; ++i){
        //��starts[i+1] <= ends[i]��ʱ�� ֤���н�����Ҫ�ϲ�
        //��starts[i+1] > ends[i]��ʱ�� ǰ�������²����  ���뵽��������res��
        //��i == n-1 ʱ��֤�������һ��  ���뵽��������res��
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
    //���� ���
    for (int i = 0; i < n; ++i){
        string line;
        cin >> line;

        int x1 = 0;
        int x2 = 0;
        while (x2 != -1){
            //�ָ��һ�������±�ļ���
            x2 = line.find(';', x1);//�����״�ƥ���;�±�
            string temp;
            temp = line.substr(x1, x2 - x1);//���ַ���line�е�x1λ��ʼ�ĳ���Ϊ(x2-x1)���ַ���
            /*
            cout << "x2= " << x2 << endl;
            cout << "temp= " << temp << endl;
            */
            //�Ӽ����зֳ������ǰ���±�
            int y1=0;
            int y2;
            y2 = temp.find(',',y1);
            string tt,yy;
            tt = temp.substr(y1, y2-y1);
            yy = temp.substr(y2+1);

            node tmp_i(atoi(tt.c_str()), atoi(yy.c_str()));
            arr.push_back(tmp_i);
            x1 = x2 + 1;//�����´β�ѯ��ʼλ��
        }
    }
    //�ϲ�
    vector<node> res = merge(arr);
    //���
    for(int i=0;i<res.size();++i){
        if(i != res.size()-1)
            cout << res[i].start << "," << res[i].end << ";";
        else
            cout << res[i].start << "," << res[i].end << endl;
    }
    return 0;
}

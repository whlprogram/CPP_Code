/*
����ѧ����Student���������ѧ�š��ɼ�����˽�����ݳ�Ա�������ⶨ��һ������Max�ҳ�ѧ���гɼ�����߲����
��Ҫ��ѧ��������5����������ͨ����Ĺ��г�Ա�����������ݳ�Ա��
*/
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class stu
{
	int no;
	double grade;
public:
	stu(int id, double g):no(id), grade(g) {}
	int getid()
	{
		return no;
	}
	void setid(int i)
	{
		no = i;
	}
	double getgrade()
	{
		return grade;
	}
	void setgrade(double g)
	{
		grade = g;
	}
	friend stu & max(vector<stu> & slist);
};

stu & max(vector<stu> & slist)
{
	double f = 0;
	int no;
	for (size_t i = 0; i < slist.size(); ++i)
	{
		if (slit.grade > f)
		{
			f = slist.at(i).grade;
			no = i;
		}
	}
	return slist.at(i);
}

int main (int argc, char ** argv)
{
	vector<stu> slist;
	string name;
	int id;
	double g;
	while (cin>>name)
	{
		cin>>id;
		cin>>g;
		stu(id, name, g);
		slist.push_back(stu);
	}
	cout<<max(slist).name<<endl;
}

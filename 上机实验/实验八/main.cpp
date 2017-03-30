/*
创建学生类Student，该类具有学号、成绩两个私有数据成员，在类外定义一个函数Max找出学生中成绩最高者并输出
（要求：学生不少于5个；不允许通过类的公有成员函数访问数据成员）
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

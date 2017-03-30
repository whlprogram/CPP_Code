// 1-3.cpp: 主项目文件。

#include <iostream>
using namespace std;
class Student          //声名一个类，类名student
{
	private :                // 类中的私有部分声名
		int num;          //定义私有变量num
		int score;         //定义私有变量score
	public:                  //类中的公有部分声名
		Student()
		{}
		void setdata( )  // 定义公有函数setdata
		{
			cin>>num;
			cin>>score;
		}
		void display( )       // 定义公有函数display
		{
			cout<<"num="<<num<<endl;
			cout<<"score="<<score<<endl;
		}
};
Student s1,s2;
int main()
{
	s1.setdata();
	s2.setdata();
	s1.display();
	s2.display();
}

// 1-3.cpp: ����Ŀ�ļ���

#include <iostream>
using namespace std;
class Student          //����һ���࣬����student
{
	private :                // ���е�˽�в�������
		int num;          //����˽�б���num
		int score;         //����˽�б���score
	public:                  //���еĹ��в�������
		Student()
		{}
		void setdata( )  // ���幫�к���setdata
		{
			cin>>num;
			cin>>score;
		}
		void display( )       // ���幫�к���display
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

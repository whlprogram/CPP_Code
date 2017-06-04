/*
C++实验：某学校对教师每月工资的计算规定如下：固定工资+课时补贴。 30
实验题目：某学校对教师每月工资的计算规定如下：固定工资+课时补贴；教授的固定工资为5000元，每个课时补贴50元；副教授的固定工资为3000元，每个课时补贴30元;讲师的固定工资为2000元，每个课时补贴20元。定义教师抽象类，派生不同职称的教师类，编写程序求若干个教师的月工资。
(1) 基本要求
(a) 题目解析及要求：
1.	抽象基类Teacher中包含2个纯虚函数salary()和print()，分别用来为类族提供计算月工资和显示相关信息的统一接口。将各派生类共有的“姓名”（name）和“课时”（lesson）属性也放在该类中。
2.	在各派生类中给出salary( )和print( )函数的具体实现，并调用基类Teacher的构造函数给name和lessons赋值。
3.	在主函数中运用赋值兼容规则。可以统一用基类指针指向各派生类对象，当对象较多时可循环处理，以动态联编的方式调用虚函数来实现多态。
（b）测试数据：
教授：姓名：Tang XiHua 课时: 12
副教授： 姓名 ：Li HanPin 课时：16
讲师： 姓名：Zhang Yue 课时：20
*/
#include <iostream>
#include <string>
using namespace std;
class Teacher//教师类
{
public:
	virtual int Salary()=0;//计算月工资
	virtual void Print(int)=0;//显示相关信息
};

class Professor:public Teacher//教授类
{
private:
	string name;
	int lessons;
public:
	Professor()
	{
		cout<<"请输入姓名：";
		cin>>name;      //姓名
		cout<<"请输入课时：";
		cin>>lessons;   //必须输入数字
	};
	int Salary()
	{
		return (5000+lessons*50);
	};
	void Print(int salary)
	{
		cout<<"职称：教授 姓名："<<name<<" 薪水："<<salary<<endl;
	};
};

class AssociateProfessor:public Teacher//副教授类
{
private:
	string name;
	int lessons;
public:
	AssociateProfessor()
	{
		cout<<"请输入姓名：";
		cin>>name;
		cout<<"请输入课时：";
		cin>>lessons;
	};
	int Salary()
	{
		return (3000+lessons*30);
	};
	void Print(int salary)
	{
		cout<<"职称：副教授 姓名："<<name<<" 薪水："<<salary<<endl<<endl;
	};
};

class Lecturer:public Teacher//讲师类
{
private:
	string name;
	int lessons;
public:
	Lecturer()
	{
		cout<<"请输入姓名：";
		cin>>name;
		cout<<"请输入课时：";
		cin>>lessons;
	};
	int Salary()
	{
		return (2000+lessons*20);
	};
	void Print(int salary)
	{
		cout<<"职称：讲师 姓名："<<name<<"薪水："<<salary<<endl<<endl;
	};
};

int main()
{
    /*
    Teacher *t = NULL;
	int money=0;
	//教授
    t = new Professor();
	money = t->Salary();
	t->Print(money);
	delete t;

	//副教授
	t = new AssociateProfessor();
	money = t->Salary();
	t->Print(money);
	delete t;

	//讲师
	t = new Lecturer();
	money = t->Salary();
	t->Print(money);
	delete t;
	t = NULL;
	*/

	//教授
    Teacher *P = new Professor();
	int salary1 = P->Salary();
    P->Print(salary1);
	//副教授
	Teacher *A = new AssociateProfessor();
	int salary2 = A->Salary();
    A->Print(salary2);
	//讲师
	Teacher *L = new Lecturer();
	int salary3 = L->Salary();
    L->Print(salary3);
    return 0;
}

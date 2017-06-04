#include <iostream>

using namespace std;
class Teacher//教师类
{
public:
    Teacher(string name="", string job="", int lessons=0);  //有默认参数的构造函数
    void setTeacher(string ,string, int);  //设置坐标值
    string getName( ) {return name;}  //读取姓名
    string getJob( ) {return job;}  //读取职称
    int getLessons( ) {return lessons;}  //读取职称
	virtual int Salary()=0;//计算月工资
	virtual void Print(int)=0;//显示相关信息
protected:  //受保护成员
   string name, job;//姓名 职称
   int lessons;//课时
};
Teacher::Teacher(string n, string j, int l) //Teacher的构造函数
{  //对Teacher初始化
   name=n;
   job=j;
   lessons=l;
}
void Teacher::setTeacher(string n, string j, int l)
{
   name=n;
   job=j;
   lessons=l;
}
class Professor:public Teacher//教授类
{
public:
	Professor()
	{
	    string n;
	    string j = "教授";
	    int l;
		cout<<"请输入教授姓名：";
		cin>>n;      //姓名
		cout<<"请输入课时：";
		cin>>l;   //必须输入数字
		setTeacher(n, j, l);
	};
	int Salary()
	{
		return (5000+getLessons()*50);
	};
	void Print(int salary)
	{
		cout<<"职称：" << getJob() << " 姓名："<<getName()<<" 薪水："<<salary<<endl;
	};
};
class AssociateProfessor:public Teacher//副教授类
{
public:
	AssociateProfessor()
	{
		string n;
	    string j = "副教授";
	    int l;
		cout<<"请输入副教授姓名：";
		cin>>n;      //姓名
		cout<<"请输入课时：";
		cin>>l;   //必须输入数字
		setTeacher(n, j, l);
	};
	int Salary()
	{
		return (3000+getLessons()*30);
	};
	void Print(int salary)
	{
		cout<<"职称：" << getJob() << " 姓名："<<getName()<<" 薪水："<<salary<<endl;
	};
};

class Lecturer:public Teacher//讲师类
{
public:
	Lecturer()
	{
		string n;
	    string j = "讲师";
	    int l;
		cout<<"请输入讲师姓名：";
		cin>>n;      //姓名
		cout<<"请输入课时：";
		cin>>l;   //必须输入数字
		setTeacher(n, j, l);
	};
	int Salary()
	{
		return (2000+getLessons()*20);
	};
	void Print(int salary)
	{
		cout<<"职称：" << getJob() << " 姓名："<<getName()<<" 薪水："<<salary<<endl;
	};
};
int main()
{
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

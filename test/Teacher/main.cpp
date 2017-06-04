#include <iostream>

using namespace std;
class Teacher//��ʦ��
{
public:
    Teacher(string name="", string job="", int lessons=0);  //��Ĭ�ϲ����Ĺ��캯��
    void setTeacher(string ,string, int);  //��������ֵ
    string getName( ) {return name;}  //��ȡ����
    string getJob( ) {return job;}  //��ȡְ��
    int getLessons( ) {return lessons;}  //��ȡְ��
	virtual int Salary()=0;//�����¹���
	virtual void Print(int)=0;//��ʾ�����Ϣ
protected:  //�ܱ�����Ա
   string name, job;//���� ְ��
   int lessons;//��ʱ
};
Teacher::Teacher(string n, string j, int l) //Teacher�Ĺ��캯��
{  //��Teacher��ʼ��
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
class Professor:public Teacher//������
{
public:
	Professor()
	{
	    string n;
	    string j = "����";
	    int l;
		cout<<"���������������";
		cin>>n;      //����
		cout<<"�������ʱ��";
		cin>>l;   //������������
		setTeacher(n, j, l);
	};
	int Salary()
	{
		return (5000+getLessons()*50);
	};
	void Print(int salary)
	{
		cout<<"ְ�ƣ�" << getJob() << " ������"<<getName()<<" нˮ��"<<salary<<endl;
	};
};
class AssociateProfessor:public Teacher//��������
{
public:
	AssociateProfessor()
	{
		string n;
	    string j = "������";
	    int l;
		cout<<"�����븱����������";
		cin>>n;      //����
		cout<<"�������ʱ��";
		cin>>l;   //������������
		setTeacher(n, j, l);
	};
	int Salary()
	{
		return (3000+getLessons()*30);
	};
	void Print(int salary)
	{
		cout<<"ְ�ƣ�" << getJob() << " ������"<<getName()<<" нˮ��"<<salary<<endl;
	};
};

class Lecturer:public Teacher//��ʦ��
{
public:
	Lecturer()
	{
		string n;
	    string j = "��ʦ";
	    int l;
		cout<<"�����뽲ʦ������";
		cin>>n;      //����
		cout<<"�������ʱ��";
		cin>>l;   //������������
		setTeacher(n, j, l);
	};
	int Salary()
	{
		return (2000+getLessons()*20);
	};
	void Print(int salary)
	{
		cout<<"ְ�ƣ�" << getJob() << " ������"<<getName()<<" нˮ��"<<salary<<endl;
	};
};
int main()
{
    //����
    Teacher *P = new Professor();
	int salary1 = P->Salary();
    P->Print(salary1);
    //������
	Teacher *A = new AssociateProfessor();
	int salary2 = A->Salary();
    A->Print(salary2);
	//��ʦ
	Teacher *L = new Lecturer();
	int salary3 = L->Salary();
    L->Print(salary3);
    return 0;
}

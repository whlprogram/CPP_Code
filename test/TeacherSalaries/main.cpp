/*
C++ʵ�飺ĳѧУ�Խ�ʦÿ�¹��ʵļ���涨���£��̶�����+��ʱ������ 30
ʵ����Ŀ��ĳѧУ�Խ�ʦÿ�¹��ʵļ���涨���£��̶�����+��ʱ���������ڵĹ̶�����Ϊ5000Ԫ��ÿ����ʱ����50Ԫ�������ڵĹ̶�����Ϊ3000Ԫ��ÿ����ʱ����30Ԫ;��ʦ�Ĺ̶�����Ϊ2000Ԫ��ÿ����ʱ����20Ԫ�������ʦ�����࣬������ְͬ�ƵĽ�ʦ�࣬��д���������ɸ���ʦ���¹��ʡ�
(1) ����Ҫ��
(a) ��Ŀ������Ҫ��
1.	�������Teacher�а���2�����麯��salary()��print()���ֱ�����Ϊ�����ṩ�����¹��ʺ���ʾ�����Ϣ��ͳһ�ӿڡ����������๲�еġ���������name���͡���ʱ����lesson������Ҳ���ڸ����С�
2.	�ڸ��������и���salary( )��print( )�����ľ���ʵ�֣������û���Teacher�Ĺ��캯����name��lessons��ֵ��
3.	�������������ø�ֵ���ݹ��򡣿���ͳһ�û���ָ��ָ�����������󣬵�����϶�ʱ��ѭ�������Զ�̬����ķ�ʽ�����麯����ʵ�ֶ�̬��
��b���������ݣ�
���ڣ�������Tang XiHua ��ʱ: 12
�����ڣ� ���� ��Li HanPin ��ʱ��16
��ʦ�� ������Zhang Yue ��ʱ��20
*/
#include <iostream>
#include <string>
using namespace std;
class Teacher//��ʦ��
{
public:
	virtual int Salary()=0;//�����¹���
	virtual void Print(int)=0;//��ʾ�����Ϣ
};

class Professor:public Teacher//������
{
private:
	string name;
	int lessons;
public:
	Professor()
	{
		cout<<"������������";
		cin>>name;      //����
		cout<<"�������ʱ��";
		cin>>lessons;   //������������
	};
	int Salary()
	{
		return (5000+lessons*50);
	};
	void Print(int salary)
	{
		cout<<"ְ�ƣ����� ������"<<name<<" нˮ��"<<salary<<endl;
	};
};

class AssociateProfessor:public Teacher//��������
{
private:
	string name;
	int lessons;
public:
	AssociateProfessor()
	{
		cout<<"������������";
		cin>>name;
		cout<<"�������ʱ��";
		cin>>lessons;
	};
	int Salary()
	{
		return (3000+lessons*30);
	};
	void Print(int salary)
	{
		cout<<"ְ�ƣ������� ������"<<name<<" нˮ��"<<salary<<endl<<endl;
	};
};

class Lecturer:public Teacher//��ʦ��
{
private:
	string name;
	int lessons;
public:
	Lecturer()
	{
		cout<<"������������";
		cin>>name;
		cout<<"�������ʱ��";
		cin>>lessons;
	};
	int Salary()
	{
		return (2000+lessons*20);
	};
	void Print(int salary)
	{
		cout<<"ְ�ƣ���ʦ ������"<<name<<"нˮ��"<<salary<<endl<<endl;
	};
};

int main()
{
    /*
    Teacher *t = NULL;
	int money=0;
	//����
    t = new Professor();
	money = t->Salary();
	t->Print(money);
	delete t;

	//������
	t = new AssociateProfessor();
	money = t->Salary();
	t->Print(money);
	delete t;

	//��ʦ
	t = new Lecturer();
	money = t->Salary();
	t->Print(money);
	delete t;
	t = NULL;
	*/

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

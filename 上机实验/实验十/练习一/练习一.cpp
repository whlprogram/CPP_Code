// ��ϰһ.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include "string"
#include<iostream>
using namespace System;
using namespace std;

class obj
{
public:
	string name;
	string num;
public:
	obj(){name="0",num="0";}
	obj(string x,string y)
	{
		name=x;
		num=y;
	}
	
};
class book:public obj
{
public:
		string writer;
public:
book():obj(){writer="0";}
};


class reader:public obj
{
private:
	book b[5];
	const int MAX;
	static int num;
public:
	reader(string x,string y):obj(x,y),MAX(5)
	{

	}
int rentook();
void print();
};

int reader::num =0;
int reader::rentook()
{
	int i;
	cout<<"����ѡ�0���˳���1�����飬2������"<<endl;

	while(cin>>i)
	{
		switch(i)
		{
		case 0:
		/*	cout<<"!!!"<<endl;*/
			return 0;
			case 1:
				if(num==4)cout<<"�Ѿ�����5��"<<endl;
				else
				{
					string na,nu,author;
					cout<<"�������������������";
						cin>>na;
					cout<<"������������ı�ţ�";
						cin>>nu;
					cout<<"������ͼ������ߣ�";
						cin>>author;

					b[num].name=na;
					b[num].num=nu;
					b[num].writer=author;
					num++;

				}
				break;
			/*case 2:
				if(num==0)cout<<"û���鼮���Ի���"<<endl;
				else
				{
					string na;
					int i;
					for(i=0;i<MAX;i++)
						if(b[i].name==na)
						{
							b[i].name="0";b[i].writer="0";cout<<"����ɹ�"<<endl;goto B;
						}
						cout<<"û�д���"<<endl;

				}
				B:break;*/

				




		}
		/*cout<<"����ѡ�0���˳���1�����飬2������"<<endl;*/

	}
return 0;
}

void reader::print()
{
	int i;
	cout<<"������"<<obj::name<<"ѧ�ţ�"<<obj::num<<endl;
	cout<<"����"<<"\t"<<"���"<<"\t"<<"����"<<endl;
	for(i=0;i<MAX;i++)
		if(b[i].name!="0")
			cout<<b[i].name<<"\t"<<b[i].num<<"\t"<<b[i].writer<<endl;

}
int main(array<System::String ^> ^args)
{
	reader a("wang","1234");
	a.rentook();
	a.print();
    
    return 0;
}

// 练习一.cpp: 主项目文件。

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
	cout<<"输入选项：0、退出，1、借书，2、还书"<<endl;

	while(cin>>i)
	{
		switch(i)
		{
		case 0:
		/*	cout<<"!!!"<<endl;*/
			return 0;
			case 1:
				if(num==4)cout<<"已经借满5本"<<endl;
				else
				{
					string na,nu,author;
					cout<<"请输入所借书的书名：";
						cin>>na;
					cout<<"请输入所借书的编号：";
						cin>>nu;
					cout<<"请输入图书的作者：";
						cin>>author;

					b[num].name=na;
					b[num].num=nu;
					b[num].writer=author;
					num++;

				}
				break;
			/*case 2:
				if(num==0)cout<<"没有书籍可以还！"<<endl;
				else
				{
					string na;
					int i;
					for(i=0;i<MAX;i++)
						if(b[i].name==na)
						{
							b[i].name="0";b[i].writer="0";cout<<"还书成功"<<endl;goto B;
						}
						cout<<"没有此书"<<endl;

				}
				B:break;*/

				




		}
		/*cout<<"输入选项：0、退出，1、借书，2、还书"<<endl;*/

	}
return 0;
}

void reader::print()
{
	int i;
	cout<<"姓名："<<obj::name<<"学号："<<obj::num<<endl;
	cout<<"书名"<<"\t"<<"编号"<<"\t"<<"作者"<<endl;
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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
float get_position(pair<float,float> a,pair<float,float> b)
{
	float val=0.0;
	if(a.first==b.first)
	{
		val=10000000.0;
	}
	else
	{
		val=(a.second-b.second)/(a.first-b.first);
	}
	return val;
}
vector<float> fun(vector<pair<float,float>> data)
{
	vector<float> temp;
	for(int i=1;i<data.size();i++)
	{
		float tem=get_position(data[0],data[i]);
		temp.push_back(tem);
	}
	for(int i=1;i<data.size()-1;i++)
	{
		float tem=get_position(data[i+1],data[i]);
		temp.push_back(tem);
	}
	return temp;
}
int main()
{
	int num;
	cin>>num;
	vector<pair<float,float>> data1;
	vector<pair<float,float>> data2;
	for(int i=0;i<num;i++)
	{
		float a,b;
		cin>>a>>b;
		data1.push_back(make_pair(a,b));
	}
    for(int i=0;i<num;i++)
	{
		float a,b;
		cin>>a>>b;
		data2.push_back(make_pair(a,b));
	}
	string s="Yes";
	vector<float> result1=fun(data1);
	vector<float> result2=fun(data2);
	for(int i=0;i<result1.size();i++)
	{
		if(result1[i]!=result2[i])
		{
			s="No";
			break;
		}
	}
	cout<<s;
}

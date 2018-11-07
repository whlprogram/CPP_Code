#include<vector>
#include<iostream>
using namespace std;
class Point
{
public:
	Point(){
		cout << "construction" << endl;
	}
	Point(const Point& p){
		cout << "copy construction" << endl;
	}
	~Point(){
		cout << "destruction" << endl;
	}
};
int main()
{
	Point test[10];
	cout << "**************************" << endl;
	vector<Point> arr;
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(test[i]);
		cout << "capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
		cout << "--------------------------" << endl;
	}
	system("pause");
}


/*
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
    string str1 = "hello";
    cout <<  sizeof(str1) << endl;//4
    str1 = "helloworld";
    cout <<  sizeof(str1) << endl;//4
    //sizeof(vector) = 12
    vector<string> str;
    cout <<  sizeof(str) << endl;//12
    vector<char> c;
    cout <<  sizeof(c) << endl;//12
    vector<long> l;
    cout <<  sizeof(l) << endl;//12
    vector<double> d;
    cout <<  sizeof(d) << endl;//12
    vector<float> f;
    cout <<  sizeof(f) << endl;//12
    vector<int> a;
    cout << a.capacity() << " " << sizeof(a) << endl;//0 12
    a.push_back(0);
    cout << a.capacity() << " " << sizeof(a) << endl;//1  12
    a.push_back(1);
    cout << a.capacity() << " " << sizeof(a) << endl;//2
    a.push_back(2);
    cout << a.capacity() << " " << sizeof(a) << endl;//4
    a.push_back(3);
    cout << a.capacity() << " " << sizeof(a) << endl;//4
    a.push_back(4);
    cout << a.capacity() << " " << sizeof(a) << endl;//8
    a.push_back(5);
    cout << a.capacity() << " " << sizeof(a) << endl;//8
    a.push_back(6);
    cout << a.capacity() << " " << sizeof(a) << endl;//8
    a.push_back(7);
    cout << a.capacity() << " " << sizeof(a) << endl;//8

    a.push_back(8);
    cout << a.capacity() << " " << sizeof(a) << endl;//16
    a.push_back(9);
    cout << a.capacity() << " " << sizeof(a) << endl;//16
    a.push_back(10);
    cout << a.capacity() << " " << sizeof(a) << endl;//16
    a.push_back(11);
    cout << a.capacity() << " " << sizeof(a) << endl;//16
    a.push_back(12);
    cout << a.capacity() << " " << sizeof(a) << endl;//16
    a.push_back(13);
    cout << a.capacity() << " " << sizeof(a) << endl;//16
    a.push_back(14);
    cout << a.capacity() << " " << sizeof(a) << endl;//16
    a.push_back(15);
    cout << a.capacity() << " " << sizeof(a) << endl;//16
    cout << "Hello world!" << endl;


//    map<int, int> m = {{3,6}, {1,7}, {2,8}};
//    for(auto i : m)
//    {
//        cout << i.first << " " << i.second << " ";
//    }
//    //以下陷入死循环
//
//    for(auto i : m)
//    {
//        //cout << i.first << endl;
//        if(m[i.first+1] > 6)
//            ++i.second;
//    }
//    for(auto i : m)
//    {
//        cout << i.first << " " << i.second << " ";
//    }

    return 0;
}
*/

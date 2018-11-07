#include<bits/stdc++.h>

using namespace std;

struct node{
	int a;
	int b;
	int c;
};

int main(){
    vector<node> arr;
	int count = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int res = 0;
	cin >> count;

	for (int i = 0; i < count; ++i){
		cin >> a >> b >> c;
		node temp;
		temp.a = a;
		temp.b = b;
		temp.c = c;
		arr.push_back(temp);
	}

	for (int i = 0; i < count; ++i){
		for (int j = 0; j < count; ++j){
			if (i == j)
				continue;
			if (arr[j].a > arr[i].a &&  arr[j].b > arr[i].b && arr[j].c > arr[i].c){
				++res;
				break;
			}
		}
	}
	cout << res << endl;

	return 0;
}

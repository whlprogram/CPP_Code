#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int key;
    string val;
    int sum;
};
bool cmp(node a, node b){
    if(a.key != b.key)
        return a.key < b.key;
    if(a.key==b.key && a.sum!=b.sum)
        return a.sum < b.sum;
}

int main()
{
	 string str;
	 cin >> str;
	 vector<node> arr;
	 string s = "";
	 int xint = 0;
	 int xsum = 0;
	 for(int i=0; i<str.size(); i++){
        node temp;
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
            s += str[i];
            if(str[i]>='a' && str[i]<='z')
                xsum += (str[i]-'a');
            else
                xsum += (str[i]-'A');
        }
        if(str[i]>='0' && str[i]<='9')
            xint = xint*10 + (str[i]-'0');
        if( (str[i]>='0'&&str[i]<='9') &&
            (i==str.size()-1 || (str[i+1]<'0'||str[i+1]>'9'))
            ){
            temp.key = xint;
            temp.val = s;
            temp.sum = xsum;
            arr.push_back(temp);
            xint = 0;
            s = "";
            xsum = 0;
        }
	 }
	 sort(arr.begin(), arr.end(), cmp);
     /*
     for(int i=0; i<arr.size(); i++){
        cout << arr[i].key << " " << arr[i].val << endl;
	 }
	 cout << endl;
    */
	 string res = "";
	 for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].key; j++)
            res += arr[i].val;
	 }
	 cout << res << endl;
	 return 0;
}
/*
a11b2bac3bad3abcd2
*/
/*
int arr[26];
int main()
{
	 string str1, str2;
	 cin >> str1 >> str2;
     int arr[26];
     bool flag = true;
	 for(int i=0; i<str1.size(); i++){
        int temp1 = str1[i]-'A';
        arr[temp1] = 1;
	 }
     for(int i=0; i<str2.size(); i++){
        int temp2 = str2[i]-'A';
        if(arr[temp2] != 1){
            flag = false;
            break;
        }
	 }
	 cout << flag << endl;
	 return 0;
}
*/

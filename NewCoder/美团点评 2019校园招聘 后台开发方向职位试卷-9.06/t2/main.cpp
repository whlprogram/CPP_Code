#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, int> MAP;
bool isFirst = true;
bool IsAccessT(vector<int>& arr, int left, int right, int t){
 	if(isFirst){
        isFirst = false;
        for(int i=left; i<=right; i++){
            MAP[arr[i]]++;
        }
 	}else{
        MAP[arr[left-1]]--;
        MAP[arr[right]]++;
 	}
 	auto it = MAP.begin();
    for(; it!=MAP.end(); it++)
        if(it->second >= t)
            return true;
    return false;

}

int fun(vector<int>& arr, int k, int t){
    int count = 0;
    for(int left=0; left<arr.size(); ++left){
        int right = k-1+left;
        if(right >= arr.size())
            break;
        if(right<arr.size() && IsAccessT(arr, left, right, t))
            count++;
    }
    return count;
}
/*
5 3 2
3 1 1 1 2
*/
int main(){
	int n,k,t;
    cin >> n >> k >> t;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int res = fun(arr, k, t);
    cout << res << endl;
    return 0;
}


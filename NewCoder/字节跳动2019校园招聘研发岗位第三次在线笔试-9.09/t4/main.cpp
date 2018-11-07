//LeetCode µÚ393Ìâ
#include <bits/stdc++.h>

using namespace std;

bool isUTF8(vector<int>& arr) {
    int mask1=128, mask2=192, cnt=0;
    for(int i = 0; i < arr.size(); i++){
        int cur = arr[i];

        if (cnt == 0) {
            while ((cur & mask1) != 0){
                cur <<= 1;
                cnt++;
            }
            if (cnt == 1)
                return false;
            cnt = max(0, cnt - 1);
        }else{
            if ((arr[i] & mask2) != mask1)
                return false;
            cnt--;
        }
    }
    return cnt == 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << isUTF8(arr) << endl;
    return 0;
}

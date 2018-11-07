#include <bits/stdc++.h>

using namespace std;

void maxheap_down(vector<int> &arr, int start, int end){
    int c = start;            // 当前(current)节点的位置
    int left = 2*c + 1;        // 左(left)孩子的位置
    int tmp = arr[c];            // 当前(current)节点的大小
    for (; left <= end; c=left,left=2*left+1){
        // "left"是左孩子，"left+1"是右孩子
        if ( left < end && arr[left] < arr[left+1])// 左右两孩子中选择较大者，即heap[left+1]
            left++;
        if (tmp >= arr[left])
            break;        // 调整结束
        else            // 交换值
        {
            arr[c] = arr[left];
            arr[left]= tmp;
        }
    }
}

/*
 * 堆排序(大根堆)
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void heap_sort(vector<int> &arr, int n){
    // 从(n/2-1) --> 0逐次遍历。遍历之后，得到的数组实际上是一个(最大)二叉堆。
    for (int i = n / 2 - 1; i >= 0; i--)
        maxheap_down(arr, i, n-1);
}
string str;
int main()
{
    cin >> str;
    vector<int> arr;
    if(str == "")
        return 0;
    int x1 = 0;
    int x2 = 0;
    int int_temp;
    string stemp;
    while (true){
        x2 = str.find(',', x1);//返回首次匹配的逗号的下标
        if(x2 == -1)
            break;
        stemp = str.substr(x1, x2 - x1);//截取从字符串str中第x1位开始的长度为(x2-x1)的字符串
        int_temp = atoi(stemp.c_str());
        arr.push_back(int_temp);
        x1 = x2 + 1;//更改下次查询起始位置
    }
    stemp = str.substr(x1, str.size()-x1);
    int_temp = atoi(stemp.c_str());
    arr.push_back(int_temp);

    if(arr.size() == 1){
        cout << arr[0];
        return 0;
    }
    heap_sort(arr, arr.size());

    for(int i=0; i<arr.size()-1; i++)
        cout << arr[i] << ',';
    cout << arr[arr.size()-1] << endl;
    return 0;
}
//4,1,3,2,16,9,10,14,8,7

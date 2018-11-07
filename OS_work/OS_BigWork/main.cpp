#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;
double FCFS(int arr[], int n, int start);
double SSTF(int arr[], int n, int start);
double SCAN(int arr[], int n, int start, bool F);
int cmp(int a, int b){return a>b;}
void copyArr(int arr1[], int arr2[], int n);
int main()
{
    //int arr[] = {55, 58, 39, 18, 90, 160, 150, 38, 184};//请求队列
    int n = 0;//初始队列长度
    printf("请输入请求队列长度:");
    scanf("%d", &n);
    printf("请依次输入请求队列数据:");
    int arr[n] = {0};//初始请求队列
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("磁盘调度算法有:\n");
    printf("1.先来先服务算法(FCFS)\n");
    printf("2.最短寻道时间优先算法(SSTF)\n");
    printf("3.扫描算法(SCAN)\n");
    for(int k=0; k<3; k++){
        printf("请输入编号选择算法:");
        int chack;
        scanf("%d", &chack);
        while(1){
            if(chack==1 || chack==2 || chack==3)
                break;
            printf("输入编号有误,请重新输入:");
            cin >> chack;
        }
        int start = 100;//从100号磁道开始
        bool F = true;//移动方向  向右
        if(chack == 1){
            double sum = FCFS(arr, n, start);
            double res = sum/n;
            printf("磁头移动的总磁道数为：%.1f\n", sum);
            printf("磁头移动的平均磁道数为：%.1f\n", res);
        }else if(chack == 2){
            double sum = SSTF(arr, n, start);
            double res = sum/n;
            printf("磁头移动的总磁道数为：%.1f\n", sum);
            printf("磁头移动的平均磁道数为：%.1f\n", res);
        }else if(chack == 3){
            double sum = SCAN(arr, n, start, F);
            double res = sum/n;
            printf("磁头移动的总磁道数为：%.1f\n", sum);
            printf("磁头移动的平均磁道数为：%.1f\n", res);
        }
    }
    return 0;
}
double FCFS(int arr[], int n, int start){//先来先服务算法(FCFS)
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += abs(arr[i] - start);
        start = arr[i];
    }
    return sum;
}
void copyArr(int arr1[], int arr2[], int n){//将arr2数据拷贝数组arr1中
    for(int i=0; i<n; i++){
        arr1[i] = arr2[i];
    }
}
double SSTF(int Arr[], int n, int start){//最短寻道时间优先算法(SSTF
    int arr[n] = {0};
    copyArr(arr, Arr, n);
    sort(arr, arr+n);//从小到大排列
    if(arr[0] >= start)//起始位置在队列最前面
        return FCFS(arr, n, start);
    if(arr[n-1] <= start){//起始位置在队列最后面
        sort(arr, arr+n, cmp);
        return FCFS(arr, n, start);
    }
    //起始位置在队列中间
    double sum = 0;
    int tmp = 0;
    for(int i=0; i<n; i++){
       if(arr[i] > start){
            tmp = i;
            break;
       }
    }
    int left = tmp-1;//距离起始位置左边最近的点的下标
    int right = tmp;//距离起始位置右边最近的点的下标
    bool flag = true;
    while(flag){
        if((start-arr[left])<=(arr[right]-start) && (left >= 0)){//距离左边近 并且左边有未遍历的元素
                sum += (start - arr[left]);
                start = arr[left];
                arr[left] = -1;
                left -= 1;
        }else{//距离右边近
            if(right < n){//右边有未遍历的元素
                sum += (arr[right] - start);
                start = arr[right];
                arr[right] = -1;
                right += 1;
            }
        }
        /*for(int k=0; k<n; k++){//检测
            printf("%d ", arr[k]);
        }
        printf("\n");*/
        flag = false;
        for(int j=0; j<n; j++){//判断是否全部遍历
            if(arr[j] > 0){
                flag = true;
                break;
            }
        }
    }
    return sum;
}
double SCAN(int Arr[], int n, int start, bool F){//扫描算法(SCAN)
    int arr[n] = {0};
    copyArr(arr, Arr, n);
    sort(arr, arr+n);//从小到大排列
    if(arr[0] >= start)//起始位置在队列最前面
        return FCFS(arr, n, start);
    if(arr[n-1] <= start){//起始位置在队列最后面
        sort(arr, arr+n, cmp);
        return FCFS(arr, n, start);
    }
    //起始位置在队列中间
    double sum = 0;
    int tmp = 0;
    for(int i=0; i<n; i++){
       if(arr[i] > start){
            tmp = i;
            break;
       }
    }
    int left = tmp-1;//距离起始位置左边最近的点的下标
    int right = tmp;//距离起始位置右边最近的点的下标
    bool flag = true;
    while(flag){
        if(!F && (left>=0)){//移动方向向左 并且左边有未遍历的元素
            sum += (start - arr[left]);
            start = arr[left];
            arr[left] = -1;
            left -= 1;
            if(left == -1)//左边元素遍历完毕 方向向右
                F = true;
        }else{//移动方向向右
            if(right < n){//右边有未遍历的元素
                sum += (arr[right] - start);
                start = arr[right];
                arr[right] = -1;
                right += 1;
                if(right == n)//右边元素遍历完毕 方向向左
                    F = false;
            }
        }
        /*for(int k=0; k<n; k++){//检测
            printf("%d ", arr[k]);
        }
        printf("\n");*/
        flag = false;
        for(int j=0; j<n; j++){//判断是否全部遍历
            if(arr[j] > 0){
                flag = true;
                break;
            }
        }
    }
    return sum;
}



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
    //int arr[] = {55, 58, 39, 18, 90, 160, 150, 38, 184};//�������
    int n = 0;//��ʼ���г���
    printf("������������г���:");
    scanf("%d", &n);
    printf("���������������������:");
    int arr[n] = {0};//��ʼ�������
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("���̵����㷨��:\n");
    printf("1.�����ȷ����㷨(FCFS)\n");
    printf("2.���Ѱ��ʱ�������㷨(SSTF)\n");
    printf("3.ɨ���㷨(SCAN)\n");
    for(int k=0; k<3; k++){
        printf("��������ѡ���㷨:");
        int chack;
        scanf("%d", &chack);
        while(1){
            if(chack==1 || chack==2 || chack==3)
                break;
            printf("����������,����������:");
            cin >> chack;
        }
        int start = 100;//��100�Ŵŵ���ʼ
        bool F = true;//�ƶ�����  ����
        if(chack == 1){
            double sum = FCFS(arr, n, start);
            double res = sum/n;
            printf("��ͷ�ƶ����ܴŵ���Ϊ��%.1f\n", sum);
            printf("��ͷ�ƶ���ƽ���ŵ���Ϊ��%.1f\n", res);
        }else if(chack == 2){
            double sum = SSTF(arr, n, start);
            double res = sum/n;
            printf("��ͷ�ƶ����ܴŵ���Ϊ��%.1f\n", sum);
            printf("��ͷ�ƶ���ƽ���ŵ���Ϊ��%.1f\n", res);
        }else if(chack == 3){
            double sum = SCAN(arr, n, start, F);
            double res = sum/n;
            printf("��ͷ�ƶ����ܴŵ���Ϊ��%.1f\n", sum);
            printf("��ͷ�ƶ���ƽ���ŵ���Ϊ��%.1f\n", res);
        }
    }
    return 0;
}
double FCFS(int arr[], int n, int start){//�����ȷ����㷨(FCFS)
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += abs(arr[i] - start);
        start = arr[i];
    }
    return sum;
}
void copyArr(int arr1[], int arr2[], int n){//��arr2���ݿ�������arr1��
    for(int i=0; i<n; i++){
        arr1[i] = arr2[i];
    }
}
double SSTF(int Arr[], int n, int start){//���Ѱ��ʱ�������㷨(SSTF
    int arr[n] = {0};
    copyArr(arr, Arr, n);
    sort(arr, arr+n);//��С��������
    if(arr[0] >= start)//��ʼλ���ڶ�����ǰ��
        return FCFS(arr, n, start);
    if(arr[n-1] <= start){//��ʼλ���ڶ��������
        sort(arr, arr+n, cmp);
        return FCFS(arr, n, start);
    }
    //��ʼλ���ڶ����м�
    double sum = 0;
    int tmp = 0;
    for(int i=0; i<n; i++){
       if(arr[i] > start){
            tmp = i;
            break;
       }
    }
    int left = tmp-1;//������ʼλ���������ĵ���±�
    int right = tmp;//������ʼλ���ұ�����ĵ���±�
    bool flag = true;
    while(flag){
        if((start-arr[left])<=(arr[right]-start) && (left >= 0)){//������߽� ���������δ������Ԫ��
                sum += (start - arr[left]);
                start = arr[left];
                arr[left] = -1;
                left -= 1;
        }else{//�����ұ߽�
            if(right < n){//�ұ���δ������Ԫ��
                sum += (arr[right] - start);
                start = arr[right];
                arr[right] = -1;
                right += 1;
            }
        }
        /*for(int k=0; k<n; k++){//���
            printf("%d ", arr[k]);
        }
        printf("\n");*/
        flag = false;
        for(int j=0; j<n; j++){//�ж��Ƿ�ȫ������
            if(arr[j] > 0){
                flag = true;
                break;
            }
        }
    }
    return sum;
}
double SCAN(int Arr[], int n, int start, bool F){//ɨ���㷨(SCAN)
    int arr[n] = {0};
    copyArr(arr, Arr, n);
    sort(arr, arr+n);//��С��������
    if(arr[0] >= start)//��ʼλ���ڶ�����ǰ��
        return FCFS(arr, n, start);
    if(arr[n-1] <= start){//��ʼλ���ڶ��������
        sort(arr, arr+n, cmp);
        return FCFS(arr, n, start);
    }
    //��ʼλ���ڶ����м�
    double sum = 0;
    int tmp = 0;
    for(int i=0; i<n; i++){
       if(arr[i] > start){
            tmp = i;
            break;
       }
    }
    int left = tmp-1;//������ʼλ���������ĵ���±�
    int right = tmp;//������ʼλ���ұ�����ĵ���±�
    bool flag = true;
    while(flag){
        if(!F && (left>=0)){//�ƶ��������� ���������δ������Ԫ��
            sum += (start - arr[left]);
            start = arr[left];
            arr[left] = -1;
            left -= 1;
            if(left == -1)//���Ԫ�ر������ ��������
                F = true;
        }else{//�ƶ���������
            if(right < n){//�ұ���δ������Ԫ��
                sum += (arr[right] - start);
                start = arr[right];
                arr[right] = -1;
                right += 1;
                if(right == n)//�ұ�Ԫ�ر������ ��������
                    F = false;
            }
        }
        /*for(int k=0; k<n; k++){//���
            printf("%d ", arr[k]);
        }
        printf("\n");*/
        flag = false;
        for(int j=0; j<n; j++){//�ж��Ƿ�ȫ������
            if(arr[j] > 0){
                flag = true;
                break;
            }
        }
    }
    return sum;
}



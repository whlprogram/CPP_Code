#include <iostream>
#include <string>
using namespace std;
/*
struct LinkList
{
    LinkList* pNext;
};
//Ҫ�󣺿��ǵ�����ռ���ڴ�ռ�ܴ�>1G��������� ����ʵ�־�������ʹ�ö����ڴ�
LinkList* revertList(LinkList* pList){
    LinkList* pre = nullptr;
    LinkList* node = pList;
    LinkList* next = nullptr;
    if(node==nullptr  || node->pNext==nullptr)//����Ϊ�� ����ֻ��һ���ڵ�
        return node;
    while(node != nullptr){
        next = node->pNext;
        node->pNext = pre;
        if(next == nullptr){
            break;
        }
        pre = node;
        node = next;
    }
    return node;
}
*/
/*
bool isValid(const char* szInput){
    int temp = 0;
    while(*szInput!='\0'){
        if(temp < 0)
            break;
        if(*szInput=='(')
            temp++;
        if(*szInput==')')
            temp--;
        *szInput++;
    }
    return temp==0 ? true : false;
}*/
struct Tree
{
vector<Tree*> children;
};
int Max = 0;
int getTreeWidth(const Tree* pRoot){
    if()
}
int main()
{
    //char *s = new char[4];
    //s =  "(((())))";
    //bool falg = isValid(s);
    //cout << falg <<endl;
    return 0;
}

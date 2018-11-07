#include <iostream>
#include <string>
using namespace std;
/*
struct LinkList
{
    LinkList* pNext;
};
//要求：考虑到链表占用内存空间很大（>1G）的情况， 函数实现尽可能少使用额外内存
LinkList* revertList(LinkList* pList){
    LinkList* pre = nullptr;
    LinkList* node = pList;
    LinkList* next = nullptr;
    if(node==nullptr  || node->pNext==nullptr)//链表为空 或者只有一个节点
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

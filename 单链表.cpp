#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
}ListNode,*LinkList;

// 初始化单链表
void initList(LinkList &L) {
    L = new ListNode;
    L->next = NULL;
}

// 头插法建立单链表
void creatLinkListHead(LinkList &node, int n) {
    initList(node);
    for(int i = 0; i < n; i++) {
        ListNode *p = new ListNode;
        cin>>p->data;                    
        p->next = node->next;
        node->next = p;
    }
}

// 尾插法建立单链表
void creatLinkListTail(LinkList &node, int n) {
    initList(node);
    LinkList r = node; 
    for(int i = 0; i < n; i++) {
        ListNode *p = new ListNode;
        cin>>p->data;
        r->next = p;
        r = p; 
    }
    r->next = NULL;
}

// 打印单链表
void printLinkList(string name,LinkList L) {
    cout<<name<<"->(HEAD)";
    ListNode *p = L->next;
    while(p != NULL) {
        cout<<"->("<<p->data<<")";
        p = p->next;
    }
    cout<<endl;
}

// 判断单链表中是否存在元素
int isExist(LinkList L, int x) {
    LinkList p = L->next;
    while (p) {
        if(p->data == x) 
            return 1;
        p = p->next;
    }
    return 0;
}

// 向链表尾插入元素
void insert(LinkList &head,int x) {
    LinkList p,q;
	p = head;
	q = new ListNode;
	q->data = x;
	q->next = NULL;
	while(p->next) { //带头结点的链表
		p = p->next;
	}
	p->next = q;
}

// 求两单链表交集
void intersection(LinkList LA, LinkList LB, LinkList &LC) {
    LinkList p;
    p = LA->next;
    while(p) {
        if(isExist(LB,p->data)) {
            insert(LC,p->data);
        }
        p = p->next;
    }
}

// 合并两个有序链表
void mergeTwoLists(LinkList &LA, LinkList &LB, LinkList &LC) {
    ListNode *pa = LA->next;
    ListNode *pb = LB->next;
    LC = LA;
    ListNode *pc = LC;

    while(pa != NULL && pb != NULL) {
        if(pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }

    pc->next = (pa != NULL) ? pa : pb;
    delete LB;
}

// 判断链表是否中心对称
bool isSymmetry(LinkList L, int n) {
    if(L==NULL) 
        return false;
    int i;  
    LinkList p;    
    p=L->next;
    stack<int> s;
    for(i=0;i<n/2;i++) {
	    s.push(p->data);
	    p=p->next;
    }
    if(n%2==1) 
        p=p->next;
    while(p){
	    if(p->data == s.top()){
		    s.pop();
		    p=p->next;
	    } else {  
            return false;  
        }
    }
    return true;
}

int main()
{
    /* LinkList LA,LB,LC;
    cout<<"创建单链表A: "<<endl;
    creatLinkListHead(LA,5);
    cout<<"创建单链表B: "<<endl;
    creatLinkListHead(LB,5);
    cout<<"输出单链表A: "<<endl;
    printLinkList("LA",LA);
    cout<<"输出单链表B: "<<endl;
    printLinkList("LB",LB);

    mergeTwoLists(LA,LB,LC);
    cout<<"输出单链表C: "<<endl;
    printLinkList("LC",LC); */

    /* LinkList LA;
    cout<<"创建单链表A: "<<endl;
    creatLinkListHead(LA,5);
    cout<<"输出单链表A: "<<endl;
    printLinkList("LA",LA);
    cout<<isSymmetry(LA,5)<<endl; */

    /* LinkList LA;
    cout<<"创建单链表A: "<<endl;
    creatLinkListTail(LA,5);
    cout<<"输出单链表A: "<<endl;
    printLinkList("LA",LA); */

    LinkList LA,LB,LC;
    cout<<"创建单链表A: "<<endl;
    creatLinkListTail(LA,5);
    cout<<"创建单链表B: "<<endl;
    creatLinkListTail(LB,5);
    cout<<"输出单链表A: "<<endl;
    printLinkList("LA",LA);
    cout<<"输出单链表B: "<<endl;
    printLinkList("LB",LB);
    initList(LC);
    intersection(LA,LB,LC);
    cout<<"输出单链表C: "<<endl;
    printLinkList("LC",LC);

    return 0;
}
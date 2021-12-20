#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define maxSize 20
using namespace std;
typedef struct {
    int r[maxSize+1]; // r[0]闲置或用作哨兵单元
    int length; // 顺序表长度
}LNode,*SqList; // 顺序表类型

typedef struct node {
    int data;
    struct node *next;
}ListNode,*LinkList;

void initList(SqList &L) {
    cout<<"输入顺序表(输入0停止)："<<endl;
    int i = 1;
    int x;
    cin>>x;
    while(x) {
        L->r[i] = x;
        i++;
        L->length++;
        cin>>x;
    }
}

void printList(SqList L) {
    cout<<"输出顺序表："<<endl;
    for(int i = 1; i <= L->length; ++i) {
        cout<<L->r[i]<<" ";
    }
    cout<<endl;
}

// 快速排序核心算法
int Partition(SqList &L, int low, int high) {
    // 交换顺序表L中子表r[low..high]的记录，枢轴记录到位，并返回其所在位置，此时在它之前（后）的记录均不大（小）于它
    L->r[0] = L->r[low]; // 用子表的第一个记录作为枢轴记录
    int pivotkey = L->r[low]; // 枢轴记录关键字
    while(low < high) { // 从表的两端交替地向中间扫描
        while(low < high && L->r[high] >= pivotkey) 
            --high;
        L->r[low] = L->r[high]; // 将比枢轴记录小的记录移到低端
        while(low < high && L->r[low] <= pivotkey) 
            ++low;
        L->r[high] = L->r[low]; // 将比枢轴记录大的记录移到高端
    }
    L->r[low] = L->r[0]; // 枢轴记录到位
    return low; // 返回枢轴位置
}

// 递归形式的快速排序算法
void QSort(SqList &L, int low, int high) {
    // 对顺序表L中的子序列L.r[low..high]作快速排序
    if(low < high) {
        int pivotloc = Partition(L, low, high); // 将L.r[low..high]一分为二
        QSort(L, low, pivotloc-1); // 对低子表递归排序，pivotloc是枢轴位置
        QSort(L, pivotloc+1, high); // 对高子表递归排序
    }
}

// 对顺序表L作快速排序
void QuickSort(SqList &L) {
    QSort(L, 1, L->length);
}

// 将元素k为根的子树进行调整
void HeapAdjust(int arr[], int k, int len) { 
    arr[0] = arr[k]; // arr[0]暂存字数的根结点
    for(int i = 2*k; i < len; i*=2) { // 沿key较大的子结点向下筛选
        if(i < len && arr[i] < arr[i+1]) {
            i++; // 取key较大的子结点的下标
        }
        if(arr[0] >= arr[i]) 
            break; // 筛选结束
        else {
            arr[k] = arr[i]; // 将arr[i]调整到双亲结点上
            k = i;
        }
    }
    arr[k] = arr[0]; // 被筛选结点的值放入最终位置
}

void BuildMaxHeap(int arr[], int len) {
    for(int i = len/2; i > 0; --i) { // 从i = [n/2] ~ 1, 反复调整堆
        HeapAdjust(arr, i, len);
    }
}

// 堆排序算法
void HeapSort(int arr[], int len) {
    BuildMaxHeap(arr, len); // 初始建堆
    for(int i = len; i > 1; i--) { // n-1趟的交换和建堆过程
        // 和堆底元素交换
        int temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        // 调整，把剩余的i-1个元素整理成堆
        HeapAdjust(arr,1,i-1); 
    }
}

// 对不带头结点的单链表L执行简单选择排序
void selectSort(LinkList &L) {
    LinkList h = L,p,q,s,r;
    L = NULL;
    while(h != NULL) {
        // 指针s和r记忆最大结点和其前驱；p为工作指针，q为其前驱
        p = s = h;
        q = r = NULL;
        while(p != NULL) { // 扫描原链表寻找最大结点s
            if(p->data > s->data) { // 找到更大的，记忆它和它的前驱
                s = p;
                r = q;
            }
            q = p;
            p = p->next; // 继续寻找
        }
        if(s == h) {
            h = h->next; // 最大结点在原链表前端
        } else {
            r->next = s->next; // 最大结点在原链表表内
        }
        s->next = L; 
        L = s; // 结点s插入结果链前端
    }
}

// 对带头结点的单链表L执行简单选择排序
void insertionSort(LinkList &h) {
    LinkList p,p1,q,pre;
    if(h->next != NULL) {
        p = h->next->next; // p指向第二个关键字结点
        h->next->next = NULL; // 产生只带一个结点的有序表
        while(p != NULL) {
            pre = h; // pre指向q的前驱结点
            q = pre->next;
            while(q != NULL && q->data < p->data) { // 在有序表中找到一个结点q，其data刚好大于p的data
                pre = q;
                q = q->next;
            }
            p1 = p->next;
            // 将p插入到pre之后
            p->next = pre->next; 
            pre->next = p;
            p = p1;
        }
    }
}

int main() {
    /* SqList L = new ListNode;
    initList(L);
    cout<<"排序前";
    printList(L);
    QuickSort(L);
    cout<<"排序后";
    printList(L); */


    return 0;
}
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
using namespace std;
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

// 按先序次序输入二叉树
void createBiTree(BiTree &t) {
    char ch;
    cin>>ch;
    if(ch == '#') {
        t = NULL;
    } else {
        t = (BiTree)malloc(sizeof(BiTNode));
        t->data = ch;
        createBiTree(t->lchild);
        createBiTree(t->rchild);
    }
}

// 先序遍历
void preOrder(BiTree p) {
    if(p != NULL) {
        cout<<p->data;
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

// 中序遍历
void inOrder(BiTree p) {
    if(p != NULL) {
        inOrder(p->lchild);
        cout<<p->data;
        inOrder(p->rchild);
    }
}

// 后序遍历
void postOrder(BiTree p) {
    if(p != NULL) {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout<<p->data;
    }
}

// 销毁二叉树
void deleteTree(BiTree p) {
    if(p != NULL) {
        deleteTree(p->lchild);
        deleteTree(p->rchild);
        free(p);
    }
}

// 计算二叉树高度
int depth(BiTree t) {
    int deep1,deep2;
    if(t == NULL) {
        return 0;
    } else {
        deep1 = depth(t->lchild);
        deep2 = depth(t->rchild);
        return deep1 > deep2 ? (deep1+1):(deep2+1);
    }
}

// 求二叉树某一层的宽度
int findWidth(BiTree t, int level) {
    if(t == NULL) { // 某一结点为空
        return 0;
    } else {
        if(level == 1) {
            return 1;
        } else {
            return findWidth(t->lchild, level-1)+findWidth(t->rchild, level-1); // 返回左子树宽度＋右子树宽度
        }
    }
}

// 求二叉树最大宽度
int maxFindWidth(BiTree t) {
    int max = 0; // 最大宽度
    int width = 0; // 当前宽度
    int h = depth(t); // 深度
    for(int i = 1; i <= h; ++i) {
        width = findWidth(t,i);
        if(max < width) {
            max = width;
        }
    }
    return max;
}

int main() {
    BiTree t = NULL;
	createBiTree(t);
    cout<<"先序：";
   /*  preOrder(t);
    cout<<endl;
    cout<<"中序：";
    inOrder(t);
    cout<<endl;
    cout<<"后序：";
    postOrder(t);
    cout<<endl;

    cout<<"二叉树深度为："<<depth(t)<<endl;
    cout<<"二叉树最大宽度为："<<maxFindWidth(t)<<endl; */

    

    deleteTree(t);
    //ABC##D##EF##G##
    /* 
            A
          B   E
         CD   FG     
     */
    return 0;
}
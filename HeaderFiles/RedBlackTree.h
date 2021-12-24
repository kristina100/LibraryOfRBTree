//
// Created by HUAWEI on 2021-12-04.
//
#ifndef REDBLACKTREE_REDBLACKTREE_H
#define REDBLACKTREE_REDBLACKTREE_H
#include"Common.h"

#define RED   0 /* 红色结点标志 */
#define BLACK 1 /* 黑色结点标志 */

#define RBTreeColor(r) ((r)->color)
#define RBTreeParent(r) ((r)->parent)
#define RBTreeIsRed(r) ((r)->color == RED)
#define RBTreeIsBlack(r) ((r)->color == BLACK)
#define RBTreeSetColor(r, c) do {(r)->color = (c);} while(0)
#define RBTreeSetParent(r, p) do {(r)->parent = (p);} while(0)
#define RBTreeSetRed(r) do {(r)->color = RED;} while(0)
#define RBTreeSetBlack(r) do {(r)->color = BLACK;} while(0)

typedef struct{
//    BookNumType number; //no prefix 'ISBN'
//    NameType name;
//    NameType author;
//    int stock; //current amount of the book
//    int total; //total amount of the book
    int elem;
}Book,RBTreeElemType;

/* 红黑树的结点 */
typedef struct RBTreeNode{
    RBTreeElemType data;       /* 数据域 */
    char color;                /* 颜色 */
    struct RBTreeNode *left;   /* 左孩子结点 */
    struct RBTreeNode *right;  /* 右孩子结点 */
    struct RBTreeNode *parent; /* 父结点 */
} Node, *RBTree;

/* 红黑树的根结点 */
typedef struct RB_Root{
    Node *node;
} RBRoot;

/* 创建红黑树 */
RBRoot *createRBTree();

/* 销毁红黑树 */
Status destroyRBTree(RBRoot *root);

/* 前序遍历红黑树 */
Status preorderRBTree(RBRoot *root);

/* 中序遍历红黑树 */
Status inorderRBTree(RBRoot *root);

/* 后序遍历红黑树 */
Status postorderRBTree(RBRoot *root);

/* 递归查找红黑树 */
Status recursiveSearchRBTree(RBRoot *root, RBTreeElemType x);

/* 红黑树插入结点 */
Status insertRBTree(RBRoot *root, RBTreeElemType x);

/* 红黑树删除结点 */
Status deleteRBTree(RBRoot *root, RBTreeElemType x);

/* 打印红黑树信息 */
Status printRBTree(RBRoot *root);


#endif //REDBLACKTREE_REDBLACKTREE_H
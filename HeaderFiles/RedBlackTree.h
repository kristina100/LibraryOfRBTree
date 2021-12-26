/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-24 17:05:47
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-25 10:21:53
 */
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

typedef struct RBTElem{
//    BookNumType number; //no prefix 'ISBN'
//    NameType name;
//    NameType author;
//    int stock; //current amount of the book
//    int total; //total amount of the book
//    int ISBN;   
    char *Title; //书名
    char *Author;   //作者
    char *press;    //出版社
    char *score;    //书本评分
    int page_num; //书的页数
    // char *publishing_year;  //出版时间 
    // char *classification; //书的类型
    // float price;    //价格
    int status;  //状态 0为借出状态, 1为可借状态
    int elem;   //书的编号ISBN
}RBTElem, *RBTreeElemType;

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
}RBRoot;

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

/**
 * @brief 输入elem数据
 * 
 * @param e 
 * @return Status 
 */
Status inputRBTElem(RBTreeElemType &e);

/**
 * @brief 初始化elem
 * 
 * @param e 
 * @return Status 
 */
Status InitRBTElem(RBTreeElemType &e);

/**
 * @brief 将红黑树写入文件
 * 
 * @param root 
 * @return Status 
 */
Status FILE_WriteRBT(RBRoot root);

/**
 * @brief 基于前序遍历的红黑树文件写入
 * 
 * @param tree 
 * @param fp 
 */
void FILE_preWrite(RBTree tree, FILE *fp);

/**
 * @brief 从文件中读取数据并构建红黑树
 * 
 * @param root 
 * @return Status 
 */
Status FILE_ReadRBT(RBRoot *root);


/**
 * @name printBookInfo
 * @brief Print information about a Book
 * @param e  
 * @return Status 
 */
Status PrintBookInfo(RBTreeElemType e);

#endif //REDBLACKTREE_REDBLACKTREE_H
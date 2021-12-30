/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-24 17:05:47
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-29 11:32:21
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
    char *Author;   //作�?
    char *press;    //出版�?
    char *score;    //书本评分
    int page_num; //书的页数
    // char *publishing_year;  //出版时间 
    // char *classification; //书的类型
    // float price;    //价格
    int status;  //状�? 0为借出状�?, 1为可借状�?
    long long int elem;   //书的编号ISBN
}RBTElem, *RBTreeElemType;

/* 红黑树的结点 */
typedef struct RBTreeNode{
    RBTreeElemType data;       /* 数据�? */
    char color;                /* 颜色 */
    struct RBTreeNode *left;   /* 左孩子结�? */
    struct RBTreeNode *right;  /* 右孩子结�? */
    struct RBTreeNode *parent; /* 父结�? */
} Node, *RBTree;

/* 红黑树的根结�? */
typedef struct RB_Root{
    Node *node;
}RBRoot;

/* 创建红黑�? */
RBRoot *createRBTree();

/* 销毁红黑树 */
Status destroyRBTree(RBRoot *root);

/* 前序遍历红黑�? */
Status preorderRBTree(RBRoot *root);

/* 中序遍历红黑�? */
Status inorderRBTree(RBRoot *root);

/* 后序遍历红黑�? */
Status postorderRBTree(RBRoot *root);

/* 递归查找红黑�? */
Status recursiveSearchRBTree(RBRoot *root, RBTreeElemType x);

/* 红黑树插入结�? */
Status insertRBTree(RBRoot *root, RBTreeElemType x);

/* 红黑树删除结�? */
Status deleteRBTree(RBRoot *root, RBTreeElemType x);

/* 打印红黑树信�? */
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
 * @brief 通过ISBN在红黑树中查找书本，并返�?
 * 
 * @param R
 * @param ISBN 
 * @return RBTreeElemType 
 */
RBTreeElemType RBT_SearchByISBN(RBTree R, long long int ISBN);


/**
 * @name RBT_SearchByName
 * @brief 根据书名准确搜索
 * @param  root
 * @param  name
 * @return  RBTreeElemType
 */
RBTreeElemType RBT_SearchByName(RBTree node,char *name);

/**
 * @name RBT_SearchBookByAuthor
 * @brief 根据作者准确搜�?
 * @param  root
 * @param  author
 * @return  RBTreeElemType
 */
RBTreeElemType RBT_SearchBookByAuthor(RBTree node,char *author);

// /**
//  * @name RBT_FuzzySearchByName
//  * @brief 根据书名模糊搜索
//  * @param  root
//  * @param  name
//  * @param  books
//  * @return  status
//  */
// Status RBT_FuzzySearchByName(RBTree node,char *name,MyBook books);

#endif //REDBLACKTREE_REDBLACKTREE_H
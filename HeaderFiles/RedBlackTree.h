//
// Created by HUAWEI on 2021-12-04.
//
#ifndef REDBLACKTREE_REDBLACKTREE_H
#define REDBLACKTREE_REDBLACKTREE_H
#include"Common.h"

#define RED   0 /* 绾㈣壊缁撶偣鏍囧織 */
#define BLACK 1 /* 榛戣壊缁撶偣鏍囧織 */

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
    char *Title; //涔﹀悕
    char *Author;   //浣滐拷?
    char *press;    //鍑虹増锟�?
    char *score;    //涔︽湰璇勫垎
    int page_num; //涔︾殑椤垫暟
    // char *publishing_year;  //鍑虹増鏃堕棿 
    // char *classification; //涔︾殑绫诲瀷
    // float price;    //浠锋牸
    int status;  //鐘讹拷? 0涓哄€熷嚭鐘讹拷?, 1涓哄彲鍊熺姸锟�?
    long long int elem;   //涔︾殑缂栧彿ISBN
}RBTElem, *RBTreeElemType;

/* 绾㈤粦鏍戠殑缁撶偣 */
typedef struct RBTreeNode{
    RBTreeElemType data;       /* 鏁版嵁锟�? */
    char color;                /* 棰滆壊 */
    struct RBTreeNode *left;   /* 宸﹀瀛愮粨锟�? */
    struct RBTreeNode *right;  /* 鍙冲瀛愮粨锟�? */
    struct RBTreeNode *parent; /* 鐖剁粨锟�? */
} Node, *RBTree;

/* 绾㈤粦鏍戠殑鏍圭粨锟�? */
typedef struct RB_Root{
    Node *node;
}RBRoot;

/* 鍒涘缓绾㈤粦锟�? */
RBRoot *createRBTree();

/* 閿€姣佺孩榛戞爲 */
Status destroyRBTree(RBRoot *root);

/* 鍓嶅簭閬嶅巻绾㈤粦锟�? */
Status preorderRBTree(RBRoot *root);

/* 涓簭閬嶅巻绾㈤粦锟�? */
Status inorderRBTree(RBRoot *root);

/* 鍚庡簭閬嶅巻绾㈤粦锟�? */
Status postorderRBTree(RBRoot *root);

/* 閫掑綊鏌ユ壘绾㈤粦锟�? */
Status recursiveSearchRBTree(RBRoot *root, RBTreeElemType x);

/* 绾㈤粦鏍戞彃鍏ョ粨锟�? */
Status insertRBTree(RBRoot *root, RBTreeElemType x);

/* 绾㈤粦鏍戝垹闄ょ粨锟�? */
Status deleteRBTree(RBRoot *root, RBTreeElemType x);

/* 鎵撳嵃绾㈤粦鏍戜俊锟�? */
Status printRBTree(RBRoot *root);

/**
 * @brief 杈撳叆elem鏁版嵁
 * 
 * @param e 
 * @return Status 
 */
Status inputRBTElem(RBTreeElemType &e);

/**
 * @brief 鍒濆鍖杄lem
 * 
 * @param e 
 * @return Status 
 */
Status InitRBTElem(RBTreeElemType &e);

/**
 * @brief 灏嗙孩榛戞爲鍐欏叆鏂囦欢
 * 
 * @param root 
 * @return Status 
 */
Status FILE_WriteRBT(RBRoot root);

/**
 * @brief 鍩轰簬鍓嶅簭閬嶅巻鐨勭孩榛戞爲鏂囦欢鍐欏叆
 * 
 * @param tree 
 * @param fp 
 */
void FILE_preWrite(RBTree tree, FILE *fp);

/**
 * @brief 浠庢枃浠朵腑璇诲彇鏁版嵁骞舵瀯寤虹孩榛戞爲
 * 
 * @param root 
 * @return Status 
 */
Status FILE_ReadRBT(RBRoot *root);

/**
 * @brief 閫氳繃ISBN鍦ㄧ孩榛戞爲涓煡鎵句功鏈紝骞惰繑锟�?
 * 
 * @param R
 * @param ISBN 
 * @return RBTreeElemType 
 */
RBTreeElemType RBT_SearchByISBN(RBTree R, int ISBN);


/**
 * @name RBT_SearchByName
 * @brief 鏍规嵁涔﹀悕鍑嗙‘鎼滅储
 * @param  root
 * @param  name
 * @return  RBTreeElemType
 */
RBTreeElemType RBT_SearchByName(RBTree node,char *name);

/**
 * @name RBT_SearchBookByAuthor
 * @brief 鏍规嵁浣滆€呭噯纭悳锟�?
 * @param  root
 * @param  author
 * @return  RBTreeElemType
 */
RBTreeElemType RBT_SearchBookByAuthor(RBTree node,char *author);

#endif //REDBLACKTREE_REDBLACKTREE_H
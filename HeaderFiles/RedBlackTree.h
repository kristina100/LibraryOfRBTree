//
// Created by HUAWEI on 2021-12-04.
//
#ifndef REDBLACKTREE_REDBLACKTREE_H
#define REDBLACKTREE_REDBLACKTREE_H
#include"Common.h"

#define RED   0 /* ��ɫ����־ */
#define BLACK 1 /* ��ɫ����־ */

#define RBTreeColor(r) ((r)->color)
#define RBTreeParent(r) ((r)->parent)
#define RBTreeIsRed(r) ((r)->color == RED)
#define RBTreeIsBlack(r) ((r)->color == BLACK)
#define RBTreeSetColor(r, c) do {(r)->color = (c);} while(0)
#define RBTreeSetParent(r, p) do {(r)->parent = (p);} while(0)
#define RBTreeSetRed(r) do {(r)->color = RED;} while(0)
#define RBTreeSetBlack(r) do {(r)->color = BLACK;} while(0)

typedef struct RBTElem{ 
    char Title[100]; //����
    char Author[100];   //����
    char press[100];    //������
    char score[150];    //�鱾����
    int page_num; //���ҳ��
    // char *publishing_year;  //����ʱ�� 
    // char *classification; //�������
    // float price;    //�۸�
    int status;  //״̬ 0Ϊ���״̬, 1Ϊ�ɽ�״̬
    long long int elem;   //��ı��ISBN
}RBTElem, *RBTreeElemType;

/* ������Ľ�� */
typedef struct RBTreeNode{
    RBTreeElemType data;       /* ������ */
    char color;                /* ��ɫ */
    struct RBTreeNode *left;   /* ���ӽ�� */
    struct RBTreeNode *right;  /* �Һ��ӽ�� */
    struct RBTreeNode *parent; /* ����� */
} Node, *RBTree;

/* ������ĸ���� */
typedef struct RB_Root{
    Node *node;
}RBRoot;

/* ��������� */
RBRoot *createRBTree();

/* ���ٺ���� */
Status destroyRBTree(RBRoot *root);

/* ǰ���������� */
Status preorderRBTree(RBRoot *root);

/* ������������ */
Status inorderRBTree(RBRoot *root);

/* ������������ */
Status postorderRBTree(RBRoot *root);

/* �ݹ���Һ���� */
Status recursiveSearchRBTree(RBRoot *root, RBTreeElemType x);

/* ����������� */
Status insertRBTree(RBRoot *root, RBTreeElemType x);

/* �����ɾ����� */
Status deleteRBTree(RBRoot *root, RBTreeElemType x);

/* ��ӡ�������Ϣ */
Status printRBTree(RBRoot *root);

/**
 * @brief ����elem����
 * 
 * @param e 
 * @return Status 
 */
Status inputRBTElem(RBTreeElemType &e);

/**
 * @brief ��ʼ����Elem
 * 
 * @param e 
 * @return Status 
 */
Status InitRBTElem(RBTreeElemType &e);

/**
 * @brief �������д���ļ�
 * 
 * @param root 
 * @return Status 
 */
Status FILE_WriteRBT(RBRoot root);

/**
 * @brief ����ǰ������ĺ�����ļ�д��
 * 
 * @param tree 
 * @param fp 
 */
void FILE_preWrite(RBTree tree, FILE *fp);

/**
 * @brief ���ļ��ж�ȡ���ݲ����������
 * 
 * @param root 
 * @return Status 
 */
Status FILE_ReadRBT(RBRoot *root);

/**
 * @brief ͨ��ISBN�ں�����в����鱾��������
 * 
 * @param R 
 * @param ISBN 
 * @return RBTreeElemType 
 */
RBTreeElemType RBT_SearchByISBN(RBTree R, long long int ISBN);

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
 * @brief 鏍规嵁浣滆€呭噯纭悳锟�??
 * @param  root
 * @param  author
 * @return  RBTreeElemType
 */
RBTreeElemType RBT_SearchBookByAuthor(RBTree node,char *author);

#endif //REDBLACKTREE_REDBLACKTREE_H
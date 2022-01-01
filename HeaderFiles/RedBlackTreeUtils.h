//
// Created by HUAWEI on 2021-12-04.
//
#ifndef REDBLACKTREE_REDBLACKTREEUTILS_H
#define REDBLACKTREE_REDBLACKTREEUTILS_H
#include"Common.h"

/* ������������ */
RBTree createRBTreeNode(RBTreeElemType x, Node *parent, Node *left, Node *right);

/* ��������������ƽ�� */
Status RBTreeInsertSelfBalancing(RBRoot *root, Node *node);

/* �����������С��� */
Status minRBTreeNode(RBRoot *root, RBTreeElemType minVal);

/* �������������� */
Status maxRBTreeNode(RBRoot *root, RBTreeElemType maxVal);

/* �����ɾ��������ƽ�� */
Status RBTreeDeleteSelfBalancing(RBRoot *root, Node *node, Node *parent);

/* �����ɾ�����ָ�� */
//__attribute__((unused)) Status deleteRBTreeNode(RBRoot *root, Node *node);
Status deleteRBTreeNode(RBRoot *root, Node *node);

/* �������Ϣ�Ĵ�ӡ */
Status PrintRBTreeInfo(RBTree tree, RBTreeElemType data, int position);

/* ���뷨��ӡ����� */
Status recessedPrintRBTree(RBTree tree, int depth);

#endif //REDBLACKTREE_REDBLACKTREEUTILS_H

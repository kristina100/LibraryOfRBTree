//
// Created by HUAWEI on 2021-12-05.
//
#ifndef REDBLACKTREE_BINARYTREE_H
#define REDBLACKTREE_BINARYTREE_H
#include"Common.h"
#include "RedBlackTree.h"

/* ���ٶ����� */
Status destroyBinaryTree(RBTree tree);

/* ǰ����������� */
Status preorderBiTree(RBTree tree);

/* ������������� */
Status inorderBiTree(RBTree tree);

/* ������������� */
Status postorderBiTree(RBTree tree);

/* �ݹ���Ҷ�����tree��������Ϊx�Ľ�� */
RBTree recursiveSearchNode(RBTree tree, RBTreeElemType x);

#endif //REDBLACKTREE_BINARYTREE_H

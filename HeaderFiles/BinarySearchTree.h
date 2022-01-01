/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-24 17:05:47
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-02 00:12:09
 */
//
// Created by HUAWEI on 2021-12-04.
//
#ifndef REDBLACKTREE_BINARYSEARCHTREE_H
#define REDBLACKTREE_BINARYSEARCHTREE_H
#include"Common.h"
#include "RedBlackTree.h"

/* ��������������� */
Status insertBinarySearchTree(RBRoot *root, Node *node);

/* ���������������С��� */
RBTree minBinarySearchTreeNode(RBTree tree);

/* ������������������ */
RBTree maxBinarySearchTreeNode(RBTree tree);

/* �������������ǰ����� */
RBTree BSTreePrecursor(RBTree node);

/* ������������Һ�̽�� */
RBTree BSTreeSuccessor(RBTree node);

#endif //REDBLACKTREE_BINARYSEARCHTREE_H

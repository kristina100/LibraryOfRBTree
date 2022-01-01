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

/* 二叉查找树插入结点 */
Status insertBinarySearchTree(RBRoot *root, Node *node);

/* 二叉查找树查找最小结点 */
RBTree minBinarySearchTreeNode(RBTree tree);

/* 二叉查找树查找最大结点 */
RBTree maxBinarySearchTreeNode(RBTree tree);

/* 二叉查找树查找前驱结点 */
RBTree BSTreePrecursor(RBTree node);

/* 二叉查找树查找后继结点 */
RBTree BSTreeSuccessor(RBTree node);

#endif //REDBLACKTREE_BINARYSEARCHTREE_H

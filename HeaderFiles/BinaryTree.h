//
// Created by HUAWEI on 2021-12-05.
//
#ifndef REDBLACKTREE_BINARYTREE_H
#define REDBLACKTREE_BINARYTREE_H
#include"Common.h"
#include "RedBlackTree.h"

/* 销毁二叉树 */
Status destroyBinaryTree(RBTree tree);

/* 前序遍历二叉树 */
Status preorderBiTree(RBTree tree);

/* 中序遍历二叉树 */
Status inorderBiTree(RBTree tree);

/* 后序遍历二叉树 */
Status postorderBiTree(RBTree tree);

/* 递归查找二叉树tree中数据域为x的结点 */
RBTree recursiveSearchNode(RBTree tree, RBTreeElemType x);

#endif //REDBLACKTREE_BINARYTREE_H

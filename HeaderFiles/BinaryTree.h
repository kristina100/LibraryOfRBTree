//
// Created by HUAWEI on 2021-12-05.
//

#ifndef REDBLACKTREE_BINARYTREE_H
#define REDBLACKTREE_BINARYTREE_H

#include "RedBlackTree.h"

/* 销毁二叉树 */
Status destroyBinaryTree(RBTree tree);

/* 前序遍历二叉树 */
Status preorderBiTree(RBTree tree);

/* 中序遍历二叉树 */
Status inorderBiTree(RBTree tree);

/* 后序遍历二叉树 */
Status postorderBiTree(RBTree tree);

/* 查找结点 */
RBTree recursiveSearchNode(RBTree tree, RBTreeElemType x);

#endif //REDBLACKTREE_BINARYTREE_H

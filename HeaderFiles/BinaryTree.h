//
// Created by HUAWEI on 2021-12-05.
//
#ifndef REDBLACKTREE_BINARYTREE_H
#define REDBLACKTREE_BINARYTREE_H
#include"Common.h"
#include "RedBlackTree.h"

/* 閿€姣佷簩鍙夋爲 */
Status destroyBinaryTree(RBTree tree);

/* 鍓嶅簭閬嶅巻浜屽弶鏍� */
Status preorderBiTree(RBTree tree);

/* 涓簭閬嶅巻浜屽弶鏍� */
Status inorderBiTree(RBTree tree);

/* 鍚庡簭閬嶅巻浜屽弶鏍� */
Status postorderBiTree(RBTree tree);

/* 鏌ユ壘缁撶偣 */
RBTree recursiveSearchNode(RBTree tree, RBTreeElemType x);

#endif //REDBLACKTREE_BINARYTREE_H

/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-24 17:05:47
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-02 00:12:18
 */
//
// Created by HUAWEI on 2021-12-05.
//

#ifndef REDBLACKTREE_BALANCEDBINARYTREE_H
#define REDBLACKTREE_BALANCEDBINARYTREE_H
#include"Common.h"
#include "RedBlackTree.h"

/* ƽ�������������� */
Status RBTreeLeftRotate(RBRoot *root, Node *node);

/* ƽ�������������� */
Status RBTreeRightRotate(RBRoot *root, Node *node);

#endif //REDBLACKTREE_BALANCEDBINARYTREE_H

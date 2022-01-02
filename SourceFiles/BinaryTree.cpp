/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-24 17:05:47
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-02 00:09:54
 */
//
// Created by HUAWEI on 2021-12-06.
//


#include "../HeaderFiles/BinaryTree.h"

/**
 * ���ٶ�����
 *
 * @param[in]  tree  the node of the binary tree
 * @return  the operation status, SUCCESS is 1, FALSE is 0
 */
Status destroyBinaryTree(RBTree tree)
{
    if (!tree) return FALSE;

    if (tree->left) destroyBinaryTree(tree->left);
    if (tree->right) destroyBinaryTree(tree->right);

    free(tree);

    return SUCCESS;
}

/**
 * ǰ�����������
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, SUCCESS is 1, FALSE is 0
 */
Status preorderBiTree(RBTree tree)
{
    if (!tree) return FALSE;
    else {
        printf("%d ", tree->data->elem);
        preorderBiTree(tree->left);
        preorderBiTree(tree->right);
    }
    return SUCCESS;
}

/**
 * �������������
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, SUCCESS is 1, FALSE is 0
 */
Status inorderBiTree(RBTree tree)
{
    if (!tree) return FALSE;
    else {
        inorderBiTree(tree->left);
        printf("%d ", tree->data->elem);
        inorderBiTree(tree->right);
    }

    return SUCCESS;
}

/**
 * �������������
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, SUCCESS is 1, FALSE is 0
 */
Status postorderBiTree(RBTree tree)
{
    if (!tree) return FALSE;
    else {
        postorderBiTree(tree->left);
        postorderBiTree(tree->right);
        printf("%d ", tree->data->elem);
    }

    return SUCCESS;
}

/**
 * �ݹ���Ҷ�����tree��������Ϊx�Ľ��
 *
 * @param[in]  tree: the node of the binary tree
 * @param[in]  x   : the data of the node
 * @return  the target node
 */
RBTree recursiveSearchNode(RBTree tree, RBTreeElemType x)
{
    if (!tree || tree->data->elem == x->elem) 
        return tree;
    else if (tree->data->elem > x->elem) 
        return recursiveSearchNode(tree->left, x);
    else 
        return recursiveSearchNode(tree->right, x);

    return NULL;
}

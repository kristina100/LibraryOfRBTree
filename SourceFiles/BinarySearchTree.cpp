//
// Created by HUAWEI on 2021-12-06.
//

#include "../HeaderFiles/BinarySearchTree.h"

/**
 * ���������������
 *
 * @param[in]  root: the root of the binary search tree
 * @param[in]  node: the inserted node
 * @return  the operation status, SUCCESS is 1, FALSE is 0
 */
Status insertBinarySearchTree(RBRoot *root, Node *node)
{
    Node *p = root->node;
    Node *last = NULL;

    while (p)
    {
        last = p;
        // ���������������
        if (node->data->elem < p->data->elem)
            p = p->left;
        else
            p = p->right;
    }
    // last ��ʱΪnode��parent
    RBTreeParent(node) = last;
    // last����
    if (last)
    {
        if (node->data->elem < last->data->page_num)
            last->left = node;
        else
            last->right = node;
    }
    else
        root->node = node;

    node->color = RED;

    return SUCCESS;
}

/**
 * ���������������С���
 *
 * @param[in]  tree: the root of the binary search tree
 * @return  the minimum node of the binary search tree
 */
RBTree minBinarySearchTreeNode(RBTree tree)
{
    if (!tree) return NULL;

    while (tree->left) tree = tree->left;

    return tree;
}

/**
 * ������������������
 *
 * @param[in]  tree: the root of the binary search tree
 * @return  the maximum node of the binary search tree
 */
RBTree maxBinarySearchTreeNode(RBTree tree)
{
    if (!tree) return NULL;

    while (tree->right)
        tree = tree->right;

    return tree;
}

/**
 * ������������ҽ��node��ǰ�����
 *
 * @param[in]  node: the node to be found its precursor
 * @return  the target precursor node
 */
RBTree BSTreePrecursor(RBTree node)
{
    if (node->left) return maxBinarySearchTreeNode(node->left);

    Node *p = node->parent;
    while (p && (node == p->left))
    {
        node = p;
        p = p->parent;
    }
    return p;
}

///**
// * ������������ҽ��node�ĺ�̽��
// *
// * @param[in]  node: the node to be found its successor
// * @return  the target successor node
// */
//RBTree BSTreeSuccessor(RBTree node)
//{
//    if (node->right) return minBinarySearchTreeNode(node->right);
//
//    Node *p = node->parent;
//    while (p && (node == p->right)) {
//        node = p;
//        p = p->parent;
//    }
//
//    return p;
//}

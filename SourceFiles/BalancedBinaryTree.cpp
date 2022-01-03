//
// Created by HUAWEI on 2021-12-06.
//

#include "../HeaderFiles/BalancedBinaryTree.h"

/**
 * ��ƽ��������Ľ��node����
 *
 * ʾ��: �Խ��1����
 *        1                 3
 *      /  \              /  \
 *     2    3    -->     1    5
 *        /  \         /  \
 *       4    5       2    4
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  node: the node of the red-black tree
 * @return  the operation status, SUCCESS is 1, FALSE is 0
 */
Status RBTreeLeftRotate(RBRoot *root, Node *node)
{
    // 空出右儿子的左子树
    Node *p = node->right;
    node->right = p->left;
    // 右孩子的左子树不为空，更新左子树的父节点为根结点
    if (p->left) p->left->parent = node;

    // 右儿子父结点更新为根结点的父结点
    p->parent = node->parent;

    // root直接指向右儿子，右儿子成为整棵树的根节点
    if (!node->parent) root->node = p;
    else {
        // 如果根节点是父结点的左子树，右儿子成为父结点的左儿子
        if (node->parent->left == node) node->parent->left = p;
        // 根节点是父节点的右子树，则右儿子成为父节点的右儿子
        else node->parent->right = p;
    }

    // 根结点变为右儿子的左子树
    p->left = node;
    node->parent = p;

    return SUCCESS;
}

/**
 * ��ƽ��������Ľ��node����
 *
 * ʾ��: �Խ��1����
 *        1            2
 *      /  \         /  \
 *     2    3  -->  4    1
 *   /  \              /  \
 *  4    5            5    3
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  node: the node of the red-black tree
 * @return  the operation status, SUCCESS is 1, FALSE is 0
 */
Status RBTreeRightRotate(RBRoot *root, Node *node)
{
    // 空出左儿子的右子树
    Node *p = node->left;
    node->left = p->right;

    // 更新右子树的父节点为根节点
    if (p->right) p->right->parent = node;

    //  左儿子的父节点更新为根节点的父节点
    p->parent = node->parent;

    // 左儿子成为整棵树的根节点
    if (!node->parent) root->node = p;
    else {
        // 根节点为父节点的右子树，左儿子成为根节点的右子树
        if (node == node->parent->right) node->parent->right = p;
            // 根节点为父节点的左子树，左儿子成为父节点的左子树
        else node->parent->left = p;
    }

    // 将根节点变成左儿子的右子树。
    p->right = node;
    node->parent = p;

    return SUCCESS;
}

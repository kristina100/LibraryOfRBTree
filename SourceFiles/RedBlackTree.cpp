//
// Created by HUAWEI on 2021-12-06.
//

#include "../HeaderFiles/RedBlackTree.h"
#include "../HeaderFiles/RedBlackTreeUtils.h"
#include "../HeaderFiles/BinarySearchTree.h"
#include "../HeaderFiles/BinaryTree.h"

/**
 * 创建红黑树
 *
 * @param[in]  none
 * @return  the root of the red-black tree
 */
RBRoot *createRBTree()
{
    RBRoot *root = (RBRoot *) malloc(sizeof(RBRoot));
    root->node = NULL;
    return root;
}

/**
 * 销毁红黑树
 *
 * @param[in]  root  the root of the red-black tree
 * @return  the operation status, SUCCESS is 0, FALSE is -1
 */
Status destroyRBTree(RBRoot *root)
{
    if (!root)
        return FALSE;
    else
        destroyBinaryTree(root->node);
    free(root);
    return SUCCESS;
}

/**
 * 前序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, SUCCESS is 0, FALSE is -1
 */
Status preorderRBTree(RBRoot *root)
{
    if (!root) return FALSE;
    else preorderBiTree(root->node);

    return SUCCESS;
}

/**
 * 中序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, SUCCESS is 0, FALSE is -1
 *
 */
Status inorderRBTree(RBRoot *root)
{
    if (!root) return FALSE;
    else inorderBiTree(root->node);

    return SUCCESS;
}

/**
 * 后序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, SUCCESS is 0, FALSE is -1
 */
Status postorderRBTree(RBRoot *root)
{
    if (!root) return FALSE;
    else postorderBiTree(root->node);

    return SUCCESS;
}

/**
 * 递归查找红黑树tree中数据域为x的结点
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  x   : the data of the node
 * @return  the operation status, SUCCESS is 0, FALSE is -1
 */
Status recursiveSearchRBTree(RBRoot *root, RBTreeElemType x)
{
    if (root) return recursiveSearchNode(root->node, x) ? SUCCESS : FALSE;
    return SUCCESS;
}

/**
 * 红黑树插入数据域为x的结点
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  x   : the data of the node
 * @return  the operation status, SUCCESS is 0, FALSE is -1
 */
Status insertRBTree(RBRoot *root, RBTreeElemType x)
{
    // 已存在
    if (recursiveSearchNode(root->node, x)) return FALSE;

    Node *node;
    node = createRBTreeNode(x, NULL, NULL, NULL);
    if (!node) return FALSE;

    insertBinarySearchTree(root, node);
    RBTreeInsertSelfBalancing(root, node);

    return SUCCESS;
}

/**
 * 红黑树删除数据域为x的结点
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  key : the data of the node to be deleted
 * @return  the operation status, SUCCESS is 0, FALSE is -1
 */
Status deleteRBTree(RBRoot *root, RBTreeElemType x)
{
    Node *p;
    // 递归查找
    p = recursiveSearchNode(root->node, x);
    if (p)
    {
        deleteRBTreeNode(root, p);
        return SUCCESS;
    }
    return FALSE;
}

/**
 * 打印红黑树信息
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, SUCCESS is 0, FALSE is -1
 */
Status printRBTree(RBRoot *root)
{
    if (root && root->node)
    {
        PrintRBTreeInfo(root->node, root->node->data, 0);
        return SUCCESS;
    }
    // 根节点为头结点，不存储信息
    return FALSE;
}


//
// Created by HUAWEI on 2021-12-06.
//

//
// Created by HUAWEI on 2021-12-06.
//

#include <stdio.h>
#include <stdlib.h>
#include "../HeaderFiles/RedBlackTree.h"
#include "../HeaderFiles/RedBlackTreeUtils.h"
#include "../HeaderFiles/BinarySearchTree.h"
#include "../HeaderFiles/BinaryTree.h"

/**
 * ���������
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
 * ���ٺ����
 *
 * @param[in]  root  the root of the red-black tree
 * @return  the operation status, SUCCESS is 1, FAILED is 0
 */
Status destroyRBTree(RBRoot *root)
{
    if (!root)
        return FAILED;
    else
        destroyBinaryTree(root->node);
    free(root);
    return SUCCESS;
}

/**
 * ǰ����������
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, SUCCESS is 1, FAILED is 0
 */
Status preorderRBTree(RBRoot *root)
{
    if (!root) return FAILED;
    else preorderBiTree(root->node);

    return SUCCESS;
}

/**
 * ������������
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, SUCCESS is 1, FAILED is 0
 *
 */
Status inorderRBTree(RBRoot *root)
{
    if (!root) return FAILED;
    else inorderBiTree(root->node);

    return SUCCESS;
}

/**
 * ������������
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, SUCCESS is 1, FAILED is 0
 */
Status postorderRBTree(RBRoot *root)
{
    if (!root) return FAILED;
    else postorderBiTree(root->node);

    return SUCCESS;
}

/**
 * �ݹ���Һ����tree��������Ϊx�Ľ��
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  x   : the data of the node
 * @return  the operation status, SUCCESS is 1, FAILED is 0
 */
Status recursiveSearchRBTree(RBRoot *root, RBTreeElemType x)
{
    if (root) return recursiveSearchNode(root->node, x) ? SUCCESS : FAILED;
    return SUCCESS;
}

/**
 * ���������������Ϊx�Ľ��
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  x   : the data of the node
 * @return  the operation status, SUCCESS is 1, FAILED is 0
 */
Status insertRBTree(RBRoot *root, RBTreeElemType x)
{
    // �Ѵ���
    if (recursiveSearchNode(root->node, x)) return FAILED;

    Node *node;
    node = createRBTreeNode(x, NULL, NULL, NULL);
    if (!node) return FAILED;

    insertBinarySearchTree(root, node);
    RBTreeInsertSelfBalancing(root, node);

    return SUCCESS;
}

/**
 * �����ɾ��������Ϊx�Ľ��
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  key : the data of the node to be deleted
 * @return  the operation status, SUCCESS is 1, FAILED is 0
 */
Status deleteRBTree(RBRoot *root, RBTreeElemType x)
{
    Node *p;
    // �ݹ����
    p = recursiveSearchNode(root->node, x);
    if (p)
    {
        deleteRBTreeNode(root, p);
        return SUCCESS;
    }
    return FAILED;
}

/**
 * ��ӡ�������Ϣ
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, SUCCESS is 1, FAILED is 0
 */
Status printRBTree(RBRoot *root)
{
    if (root && root->node)
    {
        PrintRBTreeInfo(root->node, root->node->data, 0);
        return SUCCESS;
    }
    // ���ڵ�Ϊͷ��㣬���洢��Ϣ
    return FAILED;
}


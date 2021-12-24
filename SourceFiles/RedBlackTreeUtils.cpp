//
// Created by HUAWEI on 2021-12-06.
//

#include <stdio.h>
#include <stdlib.h>
#include "../HeaderFiles/RedBlackTree.h"
#include "../HeaderFiles/BinarySearchTree.h"
#include "../HeaderFiles/BalancedBinaryTree.h"

/**
 * ������������
 *
 * @param[in]  x     : the data of the node
 * @param[in]  parent: its parent node
 * @param[in]  left  : its left child node
 * @param[in]  right : its right child node
 * @return  the new red-black tree node pointer
 */
RBTree createRBTreeNode(RBTreeElemType x, Node *parent, Node *left, Node *right)
{
    RBTree node = (Node *) malloc(sizeof(Node));
    if (!node) return NULL;

    node->data = x;
    node->left = left;
    node->right = right;
    node->parent = parent;
    node->color = BLACK;

    return node;
}

/**
 * ��������������ƽ��
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  node: the inserted node
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status RBTreeInsertSelfBalancing(RBRoot *root, Node *node)
{
    Node *parent, *grandparent;
    /* �����Ϊ��ɫ��� */

    while ((parent = RBTreeParent(node)) && RBTreeIsRed(parent))
    {
        grandparent = RBTreeParent(parent);

        /* ��������游�������ӽ�㡱 */
        if (parent == grandparent->left)
        {
            Node *uncle = grandparent->right;

            /* �������Ǻ�ɫ��� */
            if (uncle && RBTreeIsRed(uncle))
            {
                RBTreeSetBlack(parent);
                RBTreeSetBlack(uncle);
                RBTreeSetRed(grandparent);
                node = grandparent;
                continue;
            }

            /* �����㲻����, �Ҳ��������丸�������ӽ�� */
            if (node == parent->left)
            {
                RBTreeSetBlack(parent);
                RBTreeSetRed(grandparent);
                RBTreeRightRotate(root, grandparent);
            }

            /* �����㲻����, �Ҳ��������丸�����Һ��ӽ�� */
            if (node == parent->right)
            {
                Node *temp;
                RBTreeLeftRotate(root, parent);
                temp = parent;
                parent = node;
                node = temp;
            }
        }
        else
        { /* ��������游�����Һ��ӽ�㡱 */
            Node *uncle = grandparent->left;

            /* �������Ǻ�ɫ��� */
            if (uncle && RBTreeIsRed(uncle))
            {
                RBTreeSetBlack(uncle);
                RBTreeSetBlack(parent);
                RBTreeSetRed(grandparent);
                node = grandparent;
                continue;
            }

            /* �����㲻����, �Ҳ��������丸�����Һ��ӽ�� */
            if (node == parent->right)
            {
                RBTreeSetBlack(parent);
                RBTreeSetRed(grandparent);
                RBTreeLeftRotate(root, grandparent);
            }

            /* �����㲻����, �Ҳ��������丸�������ӽ�� */
            if (node == parent->left)
            {
                Node *temp;
                RBTreeRightRotate(root, parent);
                temp = parent;
                parent = node;
                node = temp;
            }
        }
    }

    RBTreeSetBlack(root->node);

    return SUCCESS;
}

/**
 * �����������С���
 *
 * @param[in]  root  : the root of the red-black tree
 * @param[in]  minVal: the minimum value of the red-black tree
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status minRBTreeNode(RBRoot *root, RBTreeElemType *minVal)
{
    Node *node = NULL;

    if (root) node = minBinarySearchTreeNode(root->node);
    if (!node) return FAILED;

    *minVal = node->data;

    return SUCCESS;
}

/**
 * ��������������
 *
 * @param[in]  root  : the root of the red-black tree
 * @param[in]  maxVal: the maximum value of the red-black tree
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status maxRBTreeNode(RBRoot *root, RBTreeElemType *maxVal)
{
    Node *node = NULL;

    if (root) node = maxBinarySearchTreeNode(root->node);
    if (!node) return FAILED;

    *maxVal = node->data;

    return SUCCESS;
}

/**
 * �����ɾ��������ƽ��
 *
 * @param[in]  root  : ��������ڵ�
 * @param[in]  node  : the deleted node
 * @param[in]  parent: the deleted node
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status RBTreeDeleteSelfBalancing(RBRoot *root, Node *node, Node *parent)
{
    Node *Sibling = NULL;

    while ((!node || RBTreeIsBlack(node)) && node != root->node) {
        if (node == parent->left) {
            Sibling = parent->right;
            /* node���ֵܽ��sibling�Ǻ�ɫ��� */
            if (RBTreeIsRed(Sibling))
            {
                RBTreeSetBlack(Sibling);
                RBTreeSetRed(parent);
                RBTreeLeftRotate(root, parent);
                Sibling = parent->right;
            }
            /* node���ֵܽ��sibling�Ǻ�ɫ���, sibling��2�����ӽ�㶼�Ǻ�ɫ��� */
            if ((!Sibling->left || RBTreeIsBlack(Sibling->left)) &&
                (!Sibling->right || RBTreeIsBlack(Sibling->right)))
            {
                RBTreeSetRed(Sibling);
                node = parent;
                parent = RBTreeParent(node);
            } else {
                /* node���ֵܽ��sibling�Ǻ�ɫ���, sibling�������Ǻ�ɫ, �Һ����Ǻ�ɫ */
                if (!Sibling->right || RBTreeIsBlack(Sibling->right))
                {
                    RBTreeSetRed(Sibling);
                    RBTreeSetBlack(Sibling->left);
                    RBTreeRightRotate(root, Sibling);
                    Sibling = parent->right;
                }
                /* node���ֵܽ��sibling�Ǻ�ɫ���, sibling��������������ɫ, �Һ����Ǻ�ɫ */
                RBTreeSetColor(Sibling, RBTreeColor(parent));
                RBTreeSetBlack(parent);
                RBTreeSetBlack(Sibling->right);
                RBTreeLeftRotate(root, parent);
                node = root->node;
                break;
            }
        }
        else
        {
            Sibling = parent->left;
            /* node���ֵܽ��sibling�Ǻ�ɫ��� */
            if (RBTreeIsRed(Sibling))
            {
                RBTreeSetBlack(Sibling);
                RBTreeSetRed(parent);
                RBTreeRightRotate(root, parent);
                Sibling = parent->left;
            }
            /* node���ֵܽ��sibling�Ǻ�ɫ���, sibling��2�����ӽ�㶼�Ǻ�ɫ��� */
            if ((!Sibling->left || RBTreeIsBlack(Sibling->left)) &&
                (!Sibling->right || RBTreeIsBlack(Sibling->right)))
            {
                RBTreeSetRed(Sibling);
                node = parent;
                parent = RBTreeParent(node);
            } else {
                /* node���ֵܽ��sibling�Ǻ�ɫ���, sibling�������Ǻ�ɫ, �Һ����Ǻ�ɫ */
                if (!Sibling->left || RBTreeIsBlack(Sibling->left))
                {
                    RBTreeSetBlack(Sibling->right);
                    RBTreeSetRed(Sibling);
                    RBTreeLeftRotate(root, Sibling);
                    Sibling = parent->left;
                }
                /* node���ֵܽ��sibling�Ǻ�ɫ���, sibling��������������ɫ, �Һ����Ǻ�ɫ */
                RBTreeSetColor(Sibling, RBTreeColor(parent));
                RBTreeSetBlack(parent);
                RBTreeSetBlack(Sibling->left);
                RBTreeRightRotate(root, parent);
                node = root->node;
                break;
            }
        }
    }
    if (node) RBTreeSetBlack(node);

    return SUCCESS;
}

/**
 * �����ɾ�����ָ��
 *
 * @param[in]  root: ������ĸ�
 * @param[in]  node: ��ɾ���Ľ��
 * @return  ����״̬, SUCCESS : 0, FAILED : -1
 */
Status deleteRBTreeNode(RBRoot *root, Node *node)
{
    Node *child = NULL, *parent = NULL;
    int color;

    // ɾ���������Һ��ӽ�㶼����
    if (node->left && node->right)
    {
        Node *successor = node;
        // ������, ����̽��
        successor = successor->right;
        // ��ȡ��С�ĺ�̽��
        while (successor->left)
            successor = successor->left;

        // node��㲻�Ǹ����
        if (RBTreeParent(node))
        {
            if (node == RBTreeParent(node)->left)
                RBTreeParent(node)->left = successor;
            else
                RBTreeParent(node)->right = successor;
        }
        else
            root->node = successor;  // node����Ǹ����

        // child����������Һ���, ������Ҫ��������λ��
        child = successor->right;
        // ����������ĸ����
        parent = RBTreeParent(successor);
        // �������������ɫ
        color = RBTreeColor(successor);

        // ��������ɾ�������Һ��ӽ��
        if (parent == node)
            parent = successor;
        else
        {
            if (child)
                RBTreeSetParent(child, parent);
            // ��������Һ��ӽ����������λ��(�����㲻���������ӽ��, ��������Ǻ�̽��)
            parent->left = child;
            successor->right = node->right;
            RBTreeSetParent(node->right, successor);
        }

        // ���������
        successor->parent = node->parent;
        successor->color = node->color;
        successor->left = node->left;
        node->left->parent = successor;

        // ������Ϊ��ɫ, ��Ҫ��ƽ�� 
        if (color == BLACK) RBTreeDeleteSelfBalancing(root, child, parent);
        free(node);

        return SUCCESS;
    }

    // ɾ�����ֻ����һ�����ӽ�����û�к��ӽ��
    if (node->left)
        child = node->left;
    else
        child = node->right;
    parent = node->parent;
    color = node->color;
    if (child)
        child->parent = parent;

    /* node��㲻�Ǹ���� */
    if (parent)
    {
        if (node == parent->left)
            parent->left = child;
        else
            parent->right = child;
    }
    else
        root->node = child;

    if (color == BLACK)
        RBTreeDeleteSelfBalancing(root, child, parent);
    free(node);
    return SUCCESS;
}

/**
 * �������Ϣ�Ĵ�ӡ
 *
 * @param[in]  tree    : ������Ľ�㼯��
 * @param[in]  data    : �����ֵ
 * @param[in]  position: 0 - ��ǰ����Ǹ��ڵ�
 *                      -1 - ��ǰ�ڵ�������
 *                       1 - ��ǰ������Һ���
 * @return  ���ز���״̬, SUCCESS : 0, FAILED : -1
 */
Status PrintRBTreeInfo(RBTree tree, RBTreeElemType data, int position)
{
    if (tree)
    {
        if (position == 0)
            printf("[%d] (BLACK) is root.\n", tree->data);
        else
            printf("[%d] (%s) is [%d] 's {%s} child node\n", tree->data, RBTreeIsRed(tree) ? "RED" : "BLACK",
                    data, position == -1 ? "LEFT" : "RIGHT");
        // ���ӵݹ����
        PrintRBTreeInfo(tree->left, tree->data, -1);
        // �Һ��ӵݹ����
        PrintRBTreeInfo(tree->right, tree->data, 1);
        return SUCCESS;
    }
    return FAILED;
}

/**
 * ��ӡ�����
 *
 * @param[in]  tree : ������Ľ�㼯��
 * @param[in]  depth: ����������
 * @return  ����״̬ SUCCESS : 0, FAILED : -1
 */
Status recessedPrintRBTree(RBTree tree, int depth)
{
    if (!tree) return FAILED;
    recessedPrintRBTree(tree->right, depth + 1);
    for (int i = 0; i < depth; i++) printf("    ");
    printf("[%-d(%s)]\n", tree->data, RBTreeIsRed(tree) ? "RED" : "BLACK");
    recessedPrintRBTree(tree->left, depth + 1);
    return SUCCESS;
}


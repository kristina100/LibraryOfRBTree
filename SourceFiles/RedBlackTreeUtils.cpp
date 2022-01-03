//
// Created by HUAWEI on 2021-12-06.
//

#include "../HeaderFiles/RedBlackTree.h"
#include "../HeaderFiles/BinarySearchTree.h"
#include "../HeaderFiles/BalancedBinaryTree.h"

/**
 * 鍒涘缓绾㈤粦鏍戠粨鐐�?1�?7
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
 *
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  node: the inserted node
 * @return  the operation status, SUCCESS is 1, FALSE is 0
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

            /* ���һ���������Ǻ�ɫ��� */
            if (uncle && RBTreeIsRed(uncle))
            {
                // �Ƚ�������������Ⱦ�ɺ�ɫ
                RBTreeSetBlack(parent);
                RBTreeSetBlack(uncle);
                // �ٽ��游�Ľ��Ⱦ�ɺ�ɫ
                RBTreeSetRed(grandparent);
                // �������游�ĸ�����γ������ĺ�ɫ��㣬��Ҫ�ݹ����ϵ���
                node = grandparent;
                continue;
            }

            /* ����������������丸�������ӽ�� */
            if (node == parent->left)
            {
                // ���ױ�ɺ�ɫ �游��ɺ�ɫ �������ĺ�ɫ�߶ȱ��
                RBTreeSetBlack(parent);
                RBTreeSetRed(grandparent);
                // ���游�����������ø�����Ϊ�µ��游���ָ��������ĸ߶�
                RBTreeRightRotate(root, grandparent);
            }

            /* ����������������丸�����Һ��ӽ�㣬���������� */
            if (node == parent->right)
            {
                Node *temp;
                temp = parent;
                // ���׳�Ϊ�µ�Ŀ����node
                parent = node;
                // �Ը��׽�����������������������
                RBTreeLeftRotate(root, parent);
                // ���µ�node���д��� ��ԭ���ĸ��׽��
                node = temp;
            }
        }
        else
        { /* ��������游�����Һ��ӽ�㡱 */
            Node *uncle = grandparent->left;

            /* ����ģ��������Ǻ�ɫ��� */
            if (uncle && RBTreeIsRed(uncle))
            {
                // ���׺����嶼��ɺ�ɫ ��֤������
                RBTreeSetBlack(uncle);
                RBTreeSetBlack(parent);
                // ���游��ɺ�ɫ ��֤������
                RBTreeSetRed(grandparent);
                // ���游��ʼ����������
                node = grandparent;
                continue;
            }

            /* ����壺���������丸�����Һ��ӽ�� */
            if (node == parent->right)
            {
                // ���ױ�Ϊ��ɫ
                RBTreeSetBlack(parent);
                // �游��Ϊ��ɫ ��������ɫ�߶Ƚ���
                RBTreeSetRed(grandparent);
                // ���游�����������ָ���������ɫ�߶�
                RBTreeLeftRotate(root, grandparent);
            }

            /* ������Ϊ��ɫ����������ڵ㲻���� ���������丸�������ӽ�� */
            if (node == parent->left)
            {
                Node *temp;
                temp = parent;
                parent = node;
                // �Ը��׽�����������������������ĳ�ʼ���
                RBTreeRightRotate(root, parent);
                // ���µ�node���д��� ��ԭ���ĸ��׽��
                node = temp;
            }
        }
    }
    // �����Ϊ��ɫ�������򵥣�����Ҫ������
    RBTreeSetBlack(root->node);

    return SUCCESS;
}

/**
 * 绾㈤粦鏍戞煡鎵炬渶灏忕粨鐐�1�?7
 *
 * @param[in]  root  : the root of the red-black tree
 * @param[in]  minVal: the minimum value of the red-black tree
 * @return  the operation status, SUCCESS is 1, FALSE is 0
 */
Status minRBTreeNode(RBRoot *root, RBTreeElemType minVal)
{
    Node *node = NULL;

    if (root) node = minBinarySearchTreeNode(root->node);
    if (!node) return FALSE;

    minVal = node->data;

    return SUCCESS;
}

/**
 * 绾㈤粦鏍戞煡鎵炬渶澶х粨鐐�?1�?7
 *
 * @param[in]  root  : the root of the red-black tree
 * @param[in]  maxVal: the maximum value of the red-black tree
 * @return  the operation status, SUCCESS is 1, FALSE is 0
 */
Status maxRBTreeNode(RBRoot *root, RBTreeElemType maxVal)
{
    Node *node = NULL;

    if (root) node = maxBinarySearchTreeNode(root->node);
    if (!node) return FALSE;

    maxVal = node->data;

    return SUCCESS;
}

/**
 * �����ɾ��������ƽ��
*/
Status RBTreeDeleteSelfBalancing(RBRoot *root, Node *node, Node *parent)
{
    Node *Sibling = NULL;

    while ((!node || RBTreeIsBlack(node)) && node != root->node) 
    {
        // node�Ǹ���������
        if (node == parent->left) 
        {
            Sibling = parent->right;
            /* node���ֵܽ��sibling�Ǻ�ɫ��� */
            if (RBTreeIsRed(Sibling))
            {
                // �ֵܽ���Ϊ��ɫ
                RBTreeSetBlack(Sibling);
                // ������Ϊ��ɫ ��ʱ�Ը����Ϊ������������ɫ�߶Ƚ���
                RBTreeSetRed(parent);
                // �Ը��������������ָ���������ɫ�߶�
                RBTreeLeftRotate(root, parent);
                // �ֵܵ����ӳ�Ϊ�µ��ֵ�
                Sibling = parent->right;
            }
            /* node���ֵܽ��sibling�Ǻ�ɫ���, sibling��2�����ӽ�㶼�Ǻ�ɫ��� */
            if ((!Sibling->left || RBTreeIsBlack(Sibling->left)) &&
                (!Sibling->right || RBTreeIsBlack(Sibling->right)))
            {
                // ���ֵܱ�Ϊ��ɫ
                RBTreeSetRed(Sibling);
                // nodeָ�򸸽��
                node = parent;
                parent = RBTreeParent(node);
            } else {
                /* node���ֵܽ��sibling�Ǻ�ɫ���, sibling�������Ǻ�ɫ, �Һ����Ǻ�ɫ */
                if (!Sibling->right || RBTreeIsBlack(Sibling->right))
                {
                    // �ֵܱ�Ϊ��ɫ
                    RBTreeSetRed(Sibling);
                    // ��ֶ�ӱ��ɫ
                    RBTreeSetBlack(Sibling->left);
                    // ���ֵ�Ϊ������������ɫ�߶Ƚ��� ����
                    RBTreeRightRotate(root, Sibling);
                    // ��ֶ�ӳ�Ϊ�µ����ֵ�
                    Sibling = parent->right;
                }
                /* node���ֵܽ��sibling�Ǻ�ɫ���, sibling��������������ɫ, �Һ����Ǻ�ɫ */
                // �ֵ���ɫ�ĳ��븸���һ��
                RBTreeSetColor(Sibling, RBTreeColor(parent));
                // ��ֶ�Ӻ͸�����Ϊ��ɫ
                RBTreeSetBlack(parent);
                RBTreeSetBlack(Sibling->right);
                // ���׽������
                RBTreeLeftRotate(root, parent);
                // node ָ������
                node = root->node;
                // ����ѭ��
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
 * 绾㈤粦鏍戝垹闄ょ粨鐐规寚閽�1�?7
 *
 * @param[in]  root: 绾㈤粦鏍戠殑鏍�1�?7
 * @param[in]  node: 琚垹闄ょ殑缁撶�?
 * @return  鎿嶄綔鐘舵€�?1�?7, SUCCESS : 0, FALSE : -1
 */
Status deleteRBTreeNode(RBRoot *root, Node *node)
{
    Node *child = NULL, *parent = NULL;
    int color;

    // 鍒犻櫎缁撶偣鐨勫乏鍙冲瀛愮粨鐐归兘瀛樺�?
    if (node->left && node->right)
    {
        Node *successor = node;
        // 鏇夸唬缁撶偣, 鍗冲悗缁х粨鐐�?1�?7
        successor = successor->right;
        // 鑾峰彇鏈€灏忕殑鍚庣户缁撶偣
        while (successor->left)
            successor = successor->left;

        // node缁撶偣涓嶆槸鏍圭粨鐐�?1�?7
        if (RBTreeParent(node))
        {
            if (node == RBTreeParent(node)->left)
                RBTreeParent(node)->left = successor;
            else
                RBTreeParent(node)->right = successor;
        }
        else
            root->node = successor;  // node缁撶偣鏄牴缁撶�?

        // child鏄浛浠ｇ粨鐐圭殑鍙冲瀛�1�?7, 鍙兘闇€瑕佸～琛ユ浛浠ｇ粨鐐圭殑浣嶇疆
        child = successor->right;
        // 淇濆瓨鏇夸唬缁撶偣鐨勭埗缁撶�?
        parent = RBTreeParent(successor);
        // 淇濆瓨鏇夸唬缁撶偣鐨勯鑹�1�?7
        color = RBTreeColor(successor);

        // 鏇夸唬缁撶偣鏄垹闄ょ粨鐐圭殑鍙冲瀛愮粨鐐�?1�?7
        if (parent == node)
            parent = successor;
        else
        {
            if (child)
                RBTreeSetParent(child, parent);
            // 鏇夸唬缁撶偣鐨勫彸瀛╁瓙缁撶偣濉ˉ鏇夸唬缁撶偣鐨勪綅缃�?1�?7(鏇夸唬缁撶偣涓嶅彲鑳芥湁宸﹀瀛愮粨鐐�?1�?7, 鍚﹀垯鍏舵墠鏄悗缁х粨鐐�?1�?7)
            parent->left = child;
            successor->right = node->right;
            RBTreeSetParent(node->right, successor);
        }

        // 鏇夸唬缁撶偣鎿嶄�?
        successor->parent = node->parent;
        successor->color = node->color;
        successor->left = node->left;
        node->left->parent = successor;

        // 鏇夸唬缁撶偣涓洪粦鑹�?1�?7, 闇€瑕佽嚜骞宠　 
        if (color == BLACK) RBTreeDeleteSelfBalancing(root, child, parent);
        free(node);

        return SUCCESS;
    }

    // 鍒犻櫎缁撶偣鍙瓨鍦ㄤ竴涓瀛愮粨鐐规垨鑰呮病鏈夊瀛愮粨鐐�?1�?7
    if (node->left)
        child = node->left;
    else
        child = node->right;
    parent = node->parent;
    color = node->color;
    if (child)
        child->parent = parent;

    /* node缁撶偣涓嶆槸鏍圭粨鐐�?1�?7 */
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
 * 绾㈤粦鏍戜俊鎭殑鎵撳嵃
 *
 * @param[in]  tree    : 绾㈤粦鏍戠殑缁撶偣闆嗗悎
 * @param[in]  data    : 缁撶偣鏁板€�?1�?7
 * @param[in]  position: 0 - 褰撳墠缁撶偣鏄牴鑺傜偣
 *                      -1 - 褰撳墠鑺傜偣鏄乏瀛╁�?
 *                       1 - 褰撳墠缁撶偣鏄彸瀛╁�?
 * @return  杩斿洖鎿嶄綔鐘舵€�1�?7, SUCCESS : 0, FALSE : -1
 */
Status PrintRBTreeInfo(RBTree tree, RBTreeElemType data, int position)
{
    if (tree)
    {
        if (position == 0)
            printf("[%d] (BLACK) is root.\n", tree->data);
        else
            printf("[%lld] (%s) is [%lld] 's {%s} child node\n", tree->data->elem, RBTreeIsRed(tree) ? "RED" : "BLACK",
                    data->elem, position == -1 ? "LEFT" : "RIGHT");
        // 宸﹀瀛愰€掑綊閬嶅巻
        PrintRBTreeInfo(tree->left, tree->data, -1);
        // 鍙冲瀛愰€掑綊閬嶅巻
        PrintRBTreeInfo(tree->right, tree->data, 1);
        return SUCCESS;
    }
    return FALSE;
}

/**
 * 鎵撳嵃绾㈤粦鏍�1�?7
 *
 * @param[in]  tree : 绾㈤粦鏍戠殑缁撶偣闆嗗悎
 * @param[in]  depth: 绾㈤粦鏍戠殑娣卞�?
 * @return  鎿嶄綔鐘舵€�?1�?7 SUCCESS : 0, FALSE : -1
 */
Status recessedPrintRBTree(RBTree tree, int depth)
{
    
    if (!tree) return FALSE;
    recessedPrintRBTree(tree->right, depth + 1);
    for (int i = 0; i < depth; i++) printf("    ");
    printf("[%-lld(%s)]\n", tree->data->elem, RBTreeIsRed(tree) ? "RED" : "BLACK");
    recessedPrintRBTree(tree->left, depth + 1);
    return SUCCESS;
}


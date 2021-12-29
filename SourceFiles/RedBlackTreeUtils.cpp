//
// Created by HUAWEI on 2021-12-06.
//

#include "../HeaderFiles/RedBlackTree.h"
#include "../HeaderFiles/BinarySearchTree.h"
#include "../HeaderFiles/BalancedBinaryTree.h"

/**
 * 鍒涘缓绾㈤粦鏍戠粨鐐�1�7
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
 * 绾㈤粦鏍戞彃鍏ョ粨鐐瑰悗鑷钩琛�1�7
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  node: the inserted node
 * @return  the operation status, SUCCESS is 1, FALSE is 0
 */
Status RBTreeInsertSelfBalancing(RBRoot *root, Node *node)
{
    Node *parent, *grandparent;

    /* 鐖剁粨鐐逛负绾㈣壊缁撶偣 */
    while ((parent = RBTreeParent(node)) && RBTreeIsRed(parent))
    {
        grandparent = RBTreeParent(parent);

        /* 鐖剁粨鐐规槸绁栫埗缁撶偣鐨勫乏瀛╁瓙缁撶偣鈥�1�7 */
        if (parent == grandparent->left)
        {
            Node *uncle = grandparent->right;

            /* 鎯呭喌涓€锛氬彅鍙旂粨鐐规槸绾㈣壊缁撶偣 */
            if (uncle && RBTreeIsRed(uncle))
            {
                // 鍏堝皢鐖剁粨鐐瑰拰鍙斿彅缁撶偣鏌撴垚榛戣壊
                RBTreeSetBlack(parent);
                RBTreeSetBlack(uncle);
                // 鍐嶅皢绁栫埗鐨勭粨鐐规煋鎴愰粦鑹�1�7
                RBTreeSetRed(grandparent);
                // 鍙兘涓庣鐖剁殑鐖剁粨鐐瑰舰鎴愯繛缁殑绾㈣壊缁撶偣锛岄渶瑕侀€掑綊鍚戜笂璋冩暣
                node = grandparent;
                continue;
            }

            /* 鎯呭喌浜岋細鎻掑叆缁撶偣鏄叾鐖剁粨鐐圭殑宸﹀瀛愮粨鐐�1�7 */
            if (node == parent->left)
            {
                // 鐖朵翰鍙樻垚榛戣壊 绁栫埗鍙樻垚绾㈣壊 鍙冲瓙鏍戠殑榛戣壊楂樺害鍙樹綆
                RBTreeSetBlack(parent);
                RBTreeSetRed(grandparent);
                // 瀵圭鐖惰繘琛屽乏鏃嬶紝璁╃埗缁撶偣鎴愪负鏂扮殑绁栫埗锛屾仮澶嶅彸瀛愭爲鐨勯珮搴�1�7
                RBTreeRightRotate(root, grandparent);
            }

            /* 鎯呭喌涓夛細鎻掑叆缁撶偣鏄叾鐖剁粨鐐圭殑鍙冲瀛愮粨鐐癸紝鏋勯€犳垚鎯呭喌浜�1�7 */
            if (node == parent->right)
            {
                Node *temp;
                temp = parent;
                // 鐖朵翰鎴愪负鏂扮殑鐩爣缁撶偣node
                parent = node;
                // 瀵圭埗浜茶繘琛屽乏鏃嬫搷浣滐紝鏋勯€犳垚鎯呭喌浜�1�7
                RBTreeLeftRotate(root, parent);
                // 瀵规柊鐨刵ode杩涜澶勭悊 鍗冲師鏉ョ殑鐖朵翰缁撶偣
                node = temp;
            }
        }
        else
        { /* 鐖剁粨鐐规槸绁栫埗缁撶偣鐨勫彸瀛╁瓙缁撶偣鈥�1�7 */
            Node *uncle = grandparent->left;

            /* 鎯呭喌鍥涳細鍙斿彅缁撶偣鏄孩鑹茬粨鐐�1�7 */
            if (uncle && RBTreeIsRed(uncle))
            {
                // 鐖朵翰鍜屽彅鍙旈兘鍙樻垚榛戣壊 淇濊瘉瑙勫垯鍥�1�7
                RBTreeSetBlack(uncle);
                RBTreeSetBlack(parent);
                // 灏嗙鐖跺彉鎴愮孩鑹�1�7 淇濊瘉瑙勫垯浜�1�7
                RBTreeSetRed(grandparent);
                // 浠庣鐖跺紑濮嬶紝缁х画璋冩暣
                node = grandparent;
                continue;
            }

            /* 鎯呭喌浜旓細鎻掑叆缁撶偣鏄叾鐖剁粨鐐圭殑鍙冲瀛愮粨鐐�1�7 */
            if (node == parent->right)
            {
                // 鐖朵翰鍙樹负榛戣壊
                RBTreeSetBlack(parent);
                // 绁栫埗鍙樹负绾㈣壊 宸﹀瓙鏍戦粦鑹查珮搴﹂檷浣�1�7
                RBTreeSetRed(grandparent);
                // 瀵圭鐖惰繘琛屽乏鏃嬶紝鎭㈠宸﹀瓙鏍戦粦鑹查珮搴�1�7
                RBTreeLeftRotate(root, grandparent);
            }

            /* 鍙斿彅缁撶偣涓洪粦鑹诧紝鎴栬€呭彅鍙旇妭鐐逛笉瀛樺湪 鎻掑叆缁撶偣鏄叾鐖剁粨鐐圭殑宸﹀瀛愮粨鐐�1�7 */
            if (node == parent->left)
            {
                Node *temp;
                temp = parent;
                parent = node;
                // 瀵圭埗浜茶繘琛屽彸鏃嬫搷浣滐紝鏋勯€犳儏鍐典簩鐨勫垵濮嬫儏鍐�1�7
                RBTreeRightRotate(root, parent);
                // 瀵规柊鐨刵ode杩涜澶勭悊 鍗冲師鏉ョ殑鐖朵翰缁撶偣
                node = temp;
            }
        }
    }
    // 鐖剁粨鐐逛负榛戣壊鐨勬儏鍐垫渶绠€鍗曪紝涓嶉渶瑕佸仛璋冩暣
    RBTreeSetBlack(root->node);

    return SUCCESS;
}

/**
 * 绾㈤粦鏍戞煡鎵炬渶灏忕粨鐐�1�7
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
 * 绾㈤粦鏍戞煡鎵炬渶澶х粨鐐�1�7
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
 * 绾㈤粦鏍戝垹闄ょ粨鐐瑰悗鑷钩琛�1�7
 *
 * @param[in]  root  : 绾㈤粦鏍戞牴鑺傜偣
 * @param[in]  node  : the deleted node
 * @param[in]  parent: the deleted node
 * @return  the operation status, SUCCESS is 1, FALSE is 0
 */
Status RBTreeDeleteSelfBalancing(RBRoot *root, Node *node, Node *parent)
{
    Node *Sibling = NULL;

    while ((!node || RBTreeIsBlack(node)) && node != root->node) {
        if (node == parent->left) {
            Sibling = parent->right;
            /* node鐨勫厔寮熺粨鐐箂ibling鏄孩鑹茬粨鐐�1�7 */
            if (RBTreeIsRed(Sibling))
            {
                RBTreeSetBlack(Sibling);
                RBTreeSetRed(parent);
                RBTreeLeftRotate(root, parent);
                Sibling = parent->right;
            }
            /* node鐨勫厔寮熺粨鐐箂ibling鏄粦鑹茬粨鐐�1�7, sibling鐨�1�72涓瀛愮粨鐐归兘鏄粦鑹茬粨鐐�1�7 */
            if ((!Sibling->left || RBTreeIsBlack(Sibling->left)) &&
                (!Sibling->right || RBTreeIsBlack(Sibling->right)))
            {
                RBTreeSetRed(Sibling);
                node = parent;
                parent = RBTreeParent(node);
            } else {
                /* node鐨勫厔寮熺粨鐐箂ibling鏄粦鑹茬粨鐐�1�7, sibling鐨勫乏瀛╁瓙鏄孩鑹�1�7, 鍙冲瀛愭槸榛戣壊 */
                if (!Sibling->right || RBTreeIsBlack(Sibling->right))
                {
                    RBTreeSetRed(Sibling);
                    RBTreeSetBlack(Sibling->left);
                    RBTreeRightRotate(root, Sibling);
                    Sibling = parent->right;
                }
                /* node鐨勫厔寮熺粨鐐箂ibling鏄粦鑹茬粨鐐�1�7, sibling鐨勫乏瀛╁瓙鏄换鎰忛鑹�1�7, 鍙冲瀛愭槸绾㈣壊 */
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
            /* node鐨勫厔寮熺粨鐐箂ibling鏄孩鑹茬粨鐐�1�7 */
            if (RBTreeIsRed(Sibling))
            {
                RBTreeSetBlack(Sibling);
                RBTreeSetRed(parent);
                RBTreeRightRotate(root, parent);
                Sibling = parent->left;
            }
            /* node鐨勫厔寮熺粨鐐箂ibling鏄粦鑹茬粨鐐�1�7, sibling鐨�1�72涓瀛愮粨鐐归兘鏄粦鑹茬粨鐐�1�7 */
            if ((!Sibling->left || RBTreeIsBlack(Sibling->left)) &&
                (!Sibling->right || RBTreeIsBlack(Sibling->right)))
            {
                RBTreeSetRed(Sibling);
                node = parent;
                parent = RBTreeParent(node);
            } else {
                /* node鐨勫厔寮熺粨鐐箂ibling鏄粦鑹茬粨鐐�1�7, sibling鐨勫乏瀛╁瓙鏄孩鑹�1�7, 鍙冲瀛愭槸榛戣壊 */
                if (!Sibling->left || RBTreeIsBlack(Sibling->left))
                {
                    RBTreeSetBlack(Sibling->right);
                    RBTreeSetRed(Sibling);
                    RBTreeLeftRotate(root, Sibling);
                    Sibling = parent->left;
                }
                /* node鐨勫厔寮熺粨鐐箂ibling鏄粦鑹茬粨鐐�1�7, sibling鐨勫乏瀛╁瓙鏄换鎰忛鑹�1�7, 鍙冲瀛愭槸绾㈣壊 */
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
 * 绾㈤粦鏍戝垹闄ょ粨鐐规寚閽�1�7
 *
 * @param[in]  root: 绾㈤粦鏍戠殑鏍�1�7
 * @param[in]  node: 琚垹闄ょ殑缁撶偣
 * @return  鎿嶄綔鐘舵€�1�7, SUCCESS : 0, FALSE : -1
 */
Status deleteRBTreeNode(RBRoot *root, Node *node)
{
    Node *child = NULL, *parent = NULL;
    int color;

    // 鍒犻櫎缁撶偣鐨勫乏鍙冲瀛愮粨鐐归兘瀛樺湪
    if (node->left && node->right)
    {
        Node *successor = node;
        // 鏇夸唬缁撶偣, 鍗冲悗缁х粨鐐�1�7
        successor = successor->right;
        // 鑾峰彇鏈€灏忕殑鍚庣户缁撶偣
        while (successor->left)
            successor = successor->left;

        // node缁撶偣涓嶆槸鏍圭粨鐐�1�7
        if (RBTreeParent(node))
        {
            if (node == RBTreeParent(node)->left)
                RBTreeParent(node)->left = successor;
            else
                RBTreeParent(node)->right = successor;
        }
        else
            root->node = successor;  // node缁撶偣鏄牴缁撶偣

        // child鏄浛浠ｇ粨鐐圭殑鍙冲瀛�1�7, 鍙兘闇€瑕佸～琛ユ浛浠ｇ粨鐐圭殑浣嶇疆
        child = successor->right;
        // 淇濆瓨鏇夸唬缁撶偣鐨勭埗缁撶偣
        parent = RBTreeParent(successor);
        // 淇濆瓨鏇夸唬缁撶偣鐨勯鑹�1�7
        color = RBTreeColor(successor);

        // 鏇夸唬缁撶偣鏄垹闄ょ粨鐐圭殑鍙冲瀛愮粨鐐�1�7
        if (parent == node)
            parent = successor;
        else
        {
            if (child)
                RBTreeSetParent(child, parent);
            // 鏇夸唬缁撶偣鐨勫彸瀛╁瓙缁撶偣濉ˉ鏇夸唬缁撶偣鐨勪綅缃�1�7(鏇夸唬缁撶偣涓嶅彲鑳芥湁宸﹀瀛愮粨鐐�1�7, 鍚﹀垯鍏舵墠鏄悗缁х粨鐐�1�7)
            parent->left = child;
            successor->right = node->right;
            RBTreeSetParent(node->right, successor);
        }

        // 鏇夸唬缁撶偣鎿嶄綔
        successor->parent = node->parent;
        successor->color = node->color;
        successor->left = node->left;
        node->left->parent = successor;

        // 鏇夸唬缁撶偣涓洪粦鑹�1�7, 闇€瑕佽嚜骞宠　 
        if (color == BLACK) RBTreeDeleteSelfBalancing(root, child, parent);
        free(node);

        return SUCCESS;
    }

    // 鍒犻櫎缁撶偣鍙瓨鍦ㄤ竴涓瀛愮粨鐐规垨鑰呮病鏈夊瀛愮粨鐐�1�7
    if (node->left)
        child = node->left;
    else
        child = node->right;
    parent = node->parent;
    color = node->color;
    if (child)
        child->parent = parent;

    /* node缁撶偣涓嶆槸鏍圭粨鐐�1�7 */
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
 * @param[in]  data    : 缁撶偣鏁板€�1�7
 * @param[in]  position: 0 - 褰撳墠缁撶偣鏄牴鑺傜偣
 *                      -1 - 褰撳墠鑺傜偣鏄乏瀛╁瓙
 *                       1 - 褰撳墠缁撶偣鏄彸瀛╁瓙
 * @return  杩斿洖鎿嶄綔鐘舵€�1�7, SUCCESS : 0, FALSE : -1
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
 * 鎵撳嵃绾㈤粦鏍�1�7
 *
 * @param[in]  tree : 绾㈤粦鏍戠殑缁撶偣闆嗗悎
 * @param[in]  depth: 绾㈤粦鏍戠殑娣卞害
 * @return  鎿嶄綔鐘舵€�1�7 SUCCESS : 0, FALSE : -1
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


//
// Created by HUAWEI on 2021-12-06.
//

#include "../HeaderFiles/RedBlackTree.h"
#include "../HeaderFiles/BinarySearchTree.h"
#include "../HeaderFiles/BalancedBinaryTree.h"

/**
 * é’æ¶˜ç¼“ç»¾ãˆ¤ç²¦éæˆ ç²¨éï¿?1ï¿?7
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

    /* ¸¸½áµãÎªºìÉ«½áµã */
    while ((parent = RBTreeParent(node)) && RBTreeIsRed(parent))
    {
        grandparent = RBTreeParent(parent);

        /* ¸¸½áµãÊÇ×æ¸¸½áµãµÄ×óº¢×Ó½áµã¡± */
        if (parent == grandparent->left)
        {
            Node *uncle = grandparent->right;

            /* Çé¿öÒ»£ºÊåÊå½áµãÊÇºìÉ«½áµã */
            if (uncle && RBTreeIsRed(uncle))
            {
                // ÏÈ½«¸¸½áµãºÍÊåÊå½áµãÈ¾³ÉºÚÉ«
                RBTreeSetBlack(parent);
                RBTreeSetBlack(uncle);
                // ÔÙ½«×æ¸¸µÄ½áµãÈ¾³ÉºÚÉ«
                RBTreeSetRed(grandparent);
                // ¿ÉÄÜÓë×æ¸¸µÄ¸¸½áµãÐÎ³ÉÁ¬ÐøµÄºìÉ«½áµã£¬ÐèÒªµÝ¹éÏòÉÏµ÷Õû
                node = grandparent;
                continue;
            }

            /* Çé¿ö¶þ£º²åÈë½áµãÊÇÆä¸¸½áµãµÄ×óº¢×Ó½áµã */
            if (node == parent->left)
            {
                // ¸¸Ç×±ä³ÉºÚÉ« ×æ¸¸±ä³ÉºìÉ« ÓÒ×ÓÊ÷µÄºÚÉ«¸ß¶È±äµÍ
                RBTreeSetBlack(parent);
                RBTreeSetRed(grandparent);
                // ¶Ô×æ¸¸½øÐÐ×óÐý£¬ÈÃ¸¸½áµã³ÉÎªÐÂµÄ×æ¸¸£¬»Ö¸´ÓÒ×ÓÊ÷µÄ¸ß¶È
                RBTreeRightRotate(root, grandparent);
            }

            /* Çé¿öÈý£º²åÈë½áµãÊÇÆä¸¸½áµãµÄÓÒº¢×Ó½áµã£¬¹¹Ôì³ÉÇé¿ö¶þ */
            if (node == parent->right)
            {
                Node *temp;
                temp = parent;
                // ¸¸Ç×³ÉÎªÐÂµÄÄ¿±ê½áµãnode
                parent = node;
                // ¶Ô¸¸Ç×½øÐÐ×óÐý²Ù×÷£¬¹¹Ôì³ÉÇé¿ö¶þ
                RBTreeLeftRotate(root, parent);
                // ¶ÔÐÂµÄnode½øÐÐ´¦Àí ¼´Ô­À´µÄ¸¸Ç×½áµã
                node = temp;
            }
        }
        else
        { /* ¸¸½áµãÊÇ×æ¸¸½áµãµÄÓÒº¢×Ó½áµã¡± */
            Node *uncle = grandparent->left;

            /* Çé¿öËÄ£ºÊåÊå½áµãÊÇºìÉ«½áµã */
            if (uncle && RBTreeIsRed(uncle))
            {
                // ¸¸Ç×ºÍÊåÊå¶¼±ä³ÉºÚÉ« ±£Ö¤¹æÔòËÄ
                RBTreeSetBlack(uncle);
                RBTreeSetBlack(parent);
                // ½«×æ¸¸±ä³ÉºìÉ« ±£Ö¤¹æÔòÎå
                RBTreeSetRed(grandparent);
                // ´Ó×æ¸¸¿ªÊ¼£¬¼ÌÐøµ÷Õû
                node = grandparent;
                continue;
            }

            /* Çé¿öÎå£º²åÈë½áµãÊÇÆä¸¸½áµãµÄÓÒº¢×Ó½áµã */
            if (node == parent->right)
            {
                // ¸¸Ç×±äÎªºÚÉ«
                RBTreeSetBlack(parent);
                // ×æ¸¸±äÎªºìÉ« ×ó×ÓÊ÷ºÚÉ«¸ß¶È½µµÍ
                RBTreeSetRed(grandparent);
                // ¶Ô×æ¸¸½øÐÐ×óÐý£¬»Ö¸´×ó×ÓÊ÷ºÚÉ«¸ß¶È
                RBTreeLeftRotate(root, grandparent);
            }

            /* ÊåÊå½áµãÎªºÚÉ«£¬»òÕßÊåÊå½Úµã²»´æÔÚ ²åÈë½áµãÊÇÆä¸¸½áµãµÄ×óº¢×Ó½áµã */
            if (node == parent->left)
            {
                Node *temp;
                temp = parent;
                parent = node;
                // ¶Ô¸¸Ç×½øÐÐÓÒÐý²Ù×÷£¬¹¹ÔìÇé¿ö¶þµÄ³õÊ¼Çé¿ö
                RBTreeRightRotate(root, parent);
                // ¶ÔÐÂµÄnode½øÐÐ´¦Àí ¼´Ô­À´µÄ¸¸Ç×½áµã
                node = temp;
            }
        }
    }
    // ¸¸½áµãÎªºÚÉ«µÄÇé¿ö×î¼òµ¥£¬²»ÐèÒª×öµ÷Õû
    RBTreeSetBlack(root->node);

    return SUCCESS;
}

/**
 * ç»¾ãˆ¤ç²¦éæˆžç…¡éŽµç‚¬æ¸¶çå¿•ç²¨éï¿½1ï¿?7
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
 * ç»¾ãˆ¤ç²¦éæˆžç…¡éŽµç‚¬æ¸¶æ¾¶Ñ…ç²¨éï¿?1ï¿?7
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
 * ºìºÚÊ÷É¾³ý½áµãºó×ÔÆ½ºâ
*/
Status RBTreeDeleteSelfBalancing(RBRoot *root, Node *node, Node *parent)
{
    Node *Sibling = NULL;

    while ((!node || RBTreeIsBlack(node)) && node != root->node) 
    {
        // nodeÊÇ¸¸½áµãµÄ×óº¢×Ó
        if (node == parent->left) 
        {
            Sibling = parent->right;
            /* nodeµÄÐÖµÜ½áµãsiblingÊÇºìÉ«½áµã */
            if (RBTreeIsRed(Sibling))
            {
                // ÐÖµÜ½áµã±äÎªºÚÉ«
                RBTreeSetBlack(Sibling);
                // ¸¸½áµã±äÎªºìÉ« ´ËÊ±ÒÔ¸¸½áµãÎªÆðµãµÄ×ó×ÓÊ÷ºÚÉ«¸ß¶È½µµÍ
                RBTreeSetRed(parent);
                // ¶Ô¸¸½áµã½øÐÐ×óÐý£¬»Ö¸´×ó×ÓÊ÷ºÚÉ«¸ß¶È
                RBTreeLeftRotate(root, parent);
                // ÐÖµÜµÄ×óº¢×Ó³ÉÎªÐÂµÄÐÖµÜ
                Sibling = parent->right;
            }
            /* nodeµÄÐÖµÜ½áµãsiblingÊÇºÚÉ«½áµã, siblingµÄ2¸öº¢×Ó½áµã¶¼ÊÇºÚÉ«½áµã */
            if ((!Sibling->left || RBTreeIsBlack(Sibling->left)) &&
                (!Sibling->right || RBTreeIsBlack(Sibling->right)))
            {
                // ½«ÐÖµÜ±äÎªºìÉ«
                RBTreeSetRed(Sibling);
                // nodeÖ¸Ïò¸¸½áµã
                node = parent;
                parent = RBTreeParent(node);
            } else {
                /* nodeµÄÐÖµÜ½áµãsiblingÊÇºÚÉ«½áµã, siblingµÄ×óº¢×ÓÊÇºìÉ«, ÓÒº¢×ÓÊÇºÚÉ« */
                if (!Sibling->right || RBTreeIsBlack(Sibling->right))
                {
                    // ÐÖµÜ±äÎªºìÉ«
                    RBTreeSetRed(Sibling);
                    // ×óÖ¶×Ó±äºÚÉ«
                    RBTreeSetBlack(Sibling->left);
                    // ÒÔÐÖµÜÎªÆðµãµÄÓÒ×ÓÊ÷ºÚÉ«¸ß¶È½µµÍ ÓÒÐý
                    RBTreeRightRotate(root, Sibling);
                    // ×óÖ¶×Ó³ÉÎªÐÂµÄÓÒÐÖµÜ
                    Sibling = parent->right;
                }
                /* nodeµÄÐÖµÜ½áµãsiblingÊÇºÚÉ«½áµã, siblingµÄ×óº¢×ÓÊÇÈÎÒâÑÕÉ«, ÓÒº¢×ÓÊÇºìÉ« */
                // ÐÖµÜÑÕÉ«¸Ä³ÉÓë¸¸½áµãÒ»ÖÂ
                RBTreeSetColor(Sibling, RBTreeColor(parent));
                // ÓÒÖ¶×ÓºÍ¸¸½áµã¸ÄÎªºÚÉ«
                RBTreeSetBlack(parent);
                RBTreeSetBlack(Sibling->right);
                // ¸¸Ç×½áµã×óÐý
                RBTreeLeftRotate(root, parent);
                // node Ö¸Ïò¸ù½áµã
                node = root->node;
                // ½áÊøÑ­»·
                break;
            }
        }
        else
        {
            Sibling = parent->left;
            /* nodeµÄÐÖµÜ½áµãsiblingÊÇºìÉ«½áµã */
            if (RBTreeIsRed(Sibling))
            {
                RBTreeSetBlack(Sibling);
                RBTreeSetRed(parent);
                RBTreeRightRotate(root, parent);
                Sibling = parent->left;
            }
            /* nodeµÄÐÖµÜ½áµãsiblingÊÇºÚÉ«½áµã, siblingµÄ2¸öº¢×Ó½áµã¶¼ÊÇºÚÉ«½áµã */
            if ((!Sibling->left || RBTreeIsBlack(Sibling->left)) &&
                (!Sibling->right || RBTreeIsBlack(Sibling->right)))
            {
                RBTreeSetRed(Sibling);
                node = parent;
                parent = RBTreeParent(node);
            } else {
                /* nodeµÄÐÖµÜ½áµãsiblingÊÇºÚÉ«½áµã, siblingµÄ×óº¢×ÓÊÇºìÉ«, ÓÒº¢×ÓÊÇºÚÉ« */
                if (!Sibling->left || RBTreeIsBlack(Sibling->left))
                {
                    RBTreeSetBlack(Sibling->right);
                    RBTreeSetRed(Sibling);
                    RBTreeLeftRotate(root, Sibling);
                    Sibling = parent->left;
                }
                /* nodeµÄÐÖµÜ½áµãsiblingÊÇºÚÉ«½áµã, siblingµÄ×óº¢×ÓÊÇÈÎÒâÑÕÉ«, ÓÒº¢×ÓÊÇºìÉ« */
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
 * ç»¾ãˆ¤ç²¦éæˆåž¹é—„ã‚‡ç²¨éè§„å¯šé–½ï¿½1ï¿?7
 *
 * @param[in]  root: ç»¾ãˆ¤ç²¦éæˆ æ®‘éï¿½1ï¿?7
 * @param[in]  node: çšî‚¢åž¹é—„ã‚‡æ®‘ç¼æ’¶å?
 * @return  éŽ¿å¶„ç¶”é˜èˆµâ‚¬ï¿?1ï¿?7, SUCCESS : 0, FALSE : -1
 */
Status deleteRBTreeNode(RBRoot *root, Node *node)
{
    Node *child = NULL, *parent = NULL;
    int color;

    // é’çŠ»æ«Žç¼æ’¶å£é¨å‹«ä¹é™å†²î„¢ç€›æ„®ç²¨éå½’å…˜ç€›æ¨ºæ¹?
    if (node->left && node->right)
    {
        Node *successor = node;
        // é‡å¤¸å”¬ç¼æ’¶å£, é—å†²æ‚—ç¼Ñ…ç²¨éï¿?1ï¿?7
        successor = successor->right;
        // é‘¾å³°å½‡éˆâ‚¬çå¿•æ®‘éšåº£æˆ·ç¼æ’¶å£
        while (successor->left)
            successor = successor->left;

        // nodeç¼æ’¶å£æ¶“å¶†æ§¸éåœ­ç²¨éï¿?1ï¿?7
        if (RBTreeParent(node))
        {
            if (node == RBTreeParent(node)->left)
                RBTreeParent(node)->left = successor;
            else
                RBTreeParent(node)->right = successor;
        }
        else
            root->node = successor;  // nodeç¼æ’¶å£é„îˆ›ç‰´ç¼æ’¶å?

        // childé„îˆ›æµ›æµ ï½‡ç²¨éåœ­æ®‘é™å†²î„¢ç€›ï¿½1ï¿?7, é™îˆå…˜é—‡â‚¬ç‘•ä½¸ï½žç›ãƒ¦æµ›æµ ï½‡ç²¨éåœ­æ®‘æµ£å¶‡ç–†
        child = successor->right;
        // æ·‡æ¿†ç“¨é‡å¤¸å”¬ç¼æ’¶å£é¨å‹­åŸ—ç¼æ’¶å?
        parent = RBTreeParent(successor);
        // æ·‡æ¿†ç“¨é‡å¤¸å”¬ç¼æ’¶å£é¨å‹¯î–é‘¹ï¿½1ï¿?7
        color = RBTreeColor(successor);

        // é‡å¤¸å”¬ç¼æ’¶å£é„îˆšåž¹é—„ã‚‡ç²¨éåœ­æ®‘é™å†²î„¢ç€›æ„®ç²¨éï¿?1ï¿?7
        if (parent == node)
            parent = successor;
        else
        {
            if (child)
                RBTreeSetParent(child, parent);
            // é‡å¤¸å”¬ç¼æ’¶å£é¨å‹«å½¸ç€›â•ç“™ç¼æ’¶å£æ¿‰î‚¥Ë‰é‡å¤¸å”¬ç¼æ’¶å£é¨å‹ªç¶…ç¼ƒï¿?1ï¿?7(é‡å¤¸å”¬ç¼æ’¶å£æ¶“å¶…å½²é‘³èŠ¥æ¹å®¸ï¹€î„¢ç€›æ„®ç²¨éï¿?1ï¿?7, éšï¹€åž¯éèˆµå¢ é„îˆšæ‚—ç¼Ñ…ç²¨éï¿?1ï¿?7)
            parent->left = child;
            successor->right = node->right;
            RBTreeSetParent(node->right, successor);
        }

        // é‡å¤¸å”¬ç¼æ’¶å£éŽ¿å¶„ç¶?
        successor->parent = node->parent;
        successor->color = node->color;
        successor->left = node->left;
        node->left->parent = successor;

        // é‡å¤¸å”¬ç¼æ’¶å£æ¶“æ´ªç²¦é‘¹ï¿?1ï¿?7, é—‡â‚¬ç‘•ä½½åšœéªžå® ã€€ 
        if (color == BLACK) RBTreeDeleteSelfBalancing(root, child, parent);
        free(node);

        return SUCCESS;
    }

    // é’çŠ»æ«Žç¼æ’¶å£é™î„ç“¨é¦ã„¤ç«´æ¶“î„î„¢ç€›æ„®ç²¨éè§„åž¨é‘°å‘®ç—…éˆå¤Šî„¢ç€›æ„®ç²¨éï¿?1ï¿?7
    if (node->left)
        child = node->left;
    else
        child = node->right;
    parent = node->parent;
    color = node->color;
    if (child)
        child->parent = parent;

    /* nodeç¼æ’¶å£æ¶“å¶†æ§¸éåœ­ç²¨éï¿?1ï¿?7 */
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
 * ç»¾ãˆ¤ç²¦éæˆœä¿ŠéŽ­îˆœæ®‘éŽµæ’³åµƒ
 *
 * @param[in]  tree    : ç»¾ãˆ¤ç²¦éæˆ æ®‘ç¼æ’¶å£é—†å——æ‚Ž
 * @param[in]  data    : ç¼æ’¶å£éæ¿â‚¬ï¿?1ï¿?7
 * @param[in]  position: 0 - è¤°æ’³å¢ ç¼æ’¶å£é„îˆ›ç‰´é‘ºå‚œå£
 *                      -1 - è¤°æ’³å¢ é‘ºå‚œå£é„îˆšä¹ç€›â•ç“?
 *                       1 - è¤°æ’³å¢ ç¼æ’¶å£é„îˆšå½¸ç€›â•ç“?
 * @return  æ©æ–¿æ´–éŽ¿å¶„ç¶”é˜èˆµâ‚¬ï¿½1ï¿?7, SUCCESS : 0, FALSE : -1
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
        // å®¸ï¹€î„¢ç€›æ„°â‚¬æŽ‘ç¶Šé–¬å¶…å·»
        PrintRBTreeInfo(tree->left, tree->data, -1);
        // é™å†²î„¢ç€›æ„°â‚¬æŽ‘ç¶Šé–¬å¶…å·»
        PrintRBTreeInfo(tree->right, tree->data, 1);
        return SUCCESS;
    }
    return FALSE;
}

/**
 * éŽµæ’³åµƒç»¾ãˆ¤ç²¦éï¿½1ï¿?7
 *
 * @param[in]  tree : ç»¾ãˆ¤ç²¦éæˆ æ®‘ç¼æ’¶å£é—†å——æ‚Ž
 * @param[in]  depth: ç»¾ãˆ¤ç²¦éæˆ æ®‘å¨£åžå®?
 * @return  éŽ¿å¶„ç¶”é˜èˆµâ‚¬ï¿?1ï¿?7 SUCCESS : 0, FALSE : -1
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


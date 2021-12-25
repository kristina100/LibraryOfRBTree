//
// Created by HUAWEI on 2021-12-06.
//

#include "../HeaderFiles/RedBlackTree.h"
#include "../HeaderFiles/RedBlackTreeUtils.h"
#include "../HeaderFiles/BinarySearchTree.h"
#include "../HeaderFiles/BinaryTree.h"

//存储书本数据的文件
char Data_Book[] = "book_data.txt";

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

/**
 * @brief 输入elem数据
 *        只有管理员添加书本的时候会调用此方法创建新elem
 *        根据输入的字长分配空间之后赋给对应值
 */
Status inputRBTElem(RBTreeElemType &e){

    e = (RBTreeElemType)malloc(sizeof(RBTElem));
    if(e == NULL)   return OVERFLOW;

    //初始化输入域，作者，评分，书名
    // char *author = NULL, *score = NULL, *title = NULL;
    // author = (char*)malloc(sizeof(char)*20);
    // score = (char*)malloc(sizeof(char)*20);
    // title = (char*)malloc(sizeof(char)*20);

    char str[20] = "";

    //输入书名
    printf("please input Title:");
    scanf("%s", str);
    e->Title = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e->Title, str);

    //输入IBSN
    // printf("please input ISBN:");
    // scanf("%d", &e->elem);

    //输入作者
    printf("please input Author:");
    scanf("%s", str);
    e->Author = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e->Author, str);

    //输入评分
    printf("please input score:");
    scanf("%s", str);
    e->score = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e->score, str);

    //输入出版社
    printf("please input press:");
    scanf("%s", str);
    e->press = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e->press, str);

    //输入出版社
    printf("please input number of page:");
    scanf("%d", &e->page_num);
    
    //新插入的书默认未借出
    e->status = 1;
   
    return SUCCESS;
}

/**
 * @brief 初始化elem(测试用)
 */
Status InitRBTElem(RBTreeElemType &e){

    e = (RBTreeElemType)malloc(sizeof(RBTElem));
    if(e == NULL)   return OVERFLOW;

    e->Author = NULL;
    e->elem = 0;
    e->page_num = 0;
    e->press = NULL;
    e->score = NULL;
    e->status = 0;
    e->Title = NULL;

    return SUCCESS;
}

/**
 * @brief 从文件中读取数据并构建红黑树
 */
Status FILE_ReadRBT(RBRoot *root){
    int a;
    FILE *fp=fopen("book_data.txt","r");
    if(NULL==fp)
    {
        printf ("Failed to open the file!\n");
        exit (0);
    }
    fscanf (fp,"%d",&a) ; //从fp所指文件中读取一个整数保存到变量a中
    while(!feof(fp))//如果位置指针不在文件末尾,即没有读到文件末尾
    {
        fscanf(fp,"%d",&a);//读入下一条记录
        printf("%d\n",a);
        RBTreeElemType temp = NULL;
        InitRBTElem(temp);
        temp->elem = a;
        insertRBTree(root, temp);
    }
    fclose(fp);
    return SUCCESS;
}

/**
 * @brief 将红黑树写入文件
 */
Status FILE_WriteRBT(RBRoot root){

    //空树
    if(root.node == NULL) return ERROR;

    FILE *fp = NULL;
    //以"w"模式打开文件, 文件不存在则创建新文件，文件存在则覆盖原内容
    fp = fopen(Data_Book, "w");

    //传入根节点，开始前序递归插入
    FILE_preWrite(root.node, fp);
    fclose(fp);

    return SUCCESS;
}

/**
 * @brief 基于前序遍历的红黑树文件写入
 */
void FILE_preWrite(RBTree tree, FILE *fp){
    
    if(!tree) return;
    //写入结点数据
    // fwrite(tree->data, sizeof(RBTElem), 1, fp);
    fprintf(fp, "%d", tree->data->elem);
    fprintf(fp, "%s", tree->data->Title);
    fprintf(fp, "%s", tree->data->Author);
    fprintf(fp, "%s", tree->data->press);
    fprintf(fp, "%s", tree->data->score);
    fprintf(fp, "%d", tree->data->page_num);
    fprintf(fp, "%d", tree->data->status);
    //递归插入
    FILE_preWrite(tree->left, fp);
    FILE_preWrite(tree->right, fp);
}


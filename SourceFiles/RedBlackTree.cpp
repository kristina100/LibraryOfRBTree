//
// Created by HUAWEI on 2021-12-06.
//

#include "../HeaderFiles/RedBlackTree.h"
#include "../HeaderFiles/RedBlackTreeUtils.h"
#include "../HeaderFiles/BinarySearchTree.h"
#include "../HeaderFiles/BinaryTree.h"
#include"Utils.h"

//��������ļ�
char Data_Book[] = "book_data.txt";

/**
 * 创建红黑�??
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
 * 前序遍历红黑�??
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
 * �?序遍历红黑�?
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
 * 后序遍历红黑�??
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
 * 递归查找红黑树tree�?数据域为x的结�??
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  x   : the data of the node
 * @return  the operation status, SUCCESS is 0, FALSE is -1
 */
Status recursiveSearchRBTree(RBRoot *root, RBTreeElemType x)
{
    if (root) 
        return recursiveSearchNode(root->node, x) ? SUCCESS : FALSE;
    return SUCCESS;
}

/**
 * 红黑树插入数�?域为x的结�??
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  x   : the data of the node
 * @return  the operation status, SUCCESS is 0, FALSE is -1
 */
Status insertRBTree(RBRoot *root, RBTreeElemType x)
{
    // 已存�??
    if (recursiveSearchNode(root->node, x)) return FALSE;

    Node *node;
    node = createRBTreeNode(x, NULL, NULL, NULL);
    if (!node) return FALSE;

    insertBinarySearchTree(root, node);
    RBTreeInsertSelfBalancing(root, node);

    return SUCCESS;
}

/**
 * 红黑树删除数�?域为x的结�??
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
 * 打印红黑树信�??
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
    // 根节点为头结点，不存储信�??
    return FALSE;
}

/**
 * @brief ����elem����
 */
Status inputRBTElem(RBTreeElemType &e){

    e = (RBTreeElemType)malloc(sizeof(RBTElem));
    if(e == NULL)   return OVERFLOW;

    char str[20] = "";

    //输入书名
    printf("please input Title:");
    scanf("%s", str);
    e->Title = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e->Title, str);

    //输入IBSN
    printf("please input ISBN:");
    e->elem = InputInteger();
    // scanf("%lld", &e->elem);

    //输入作�?
    printf("please input Author:");
    scanf("%s", str);
    e->Author = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e->Author, str);

    //输入评分
    printf("please input score:");
    scanf("%s", str);
    e->score = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e->score, str);

    //输入出版�??
    printf("please input press:");
    scanf("%s", str);
    e->press = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e->press, str);

    //输入书本页数
    printf("please input number of page:");
    scanf("%d", &e->page_num);
    
    //新插入的书默认未借出
    e->status = 1;
   
    return SUCCESS;
}

/**
 * @brief 初�?�化elem(测试�??)
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
 * @brief ���ļ��ж�ȡ���ݲ����������
 */
Status FILE_ReadRBT(RBRoot *root){

    FILE *fp = fopen(Data_Book,"r");

    if(NULL==fp) return ERROR;
    

    char str[20] = "";

    //判断
    int status;
    while(!feof(fp)){

        RBTreeElemType e = NULL;
        InitRBTElem(e);
        //��ȡelem(ISBN)
        fscanf(fp, "%lld", &e->elem);

        //������һ���ַ�����
        if(e->elem == 0) break;

        //��ȡ����
        fscanf(fp, "%s", str);
        e->Title = (char*)malloc(sizeof(char) * strlen(str));
        strcpy(e->Title, str);
        fgetc(fp);
        
        //��ȡ����
        fscanf(fp, "%s", str);
        e->Author = (char*)malloc(sizeof(char) * strlen(str));
        strcpy(e->Author, str);
        fgetc(fp);

        //��ȡ������
        fscanf(fp, "%s", str);
        e->press = (char*)malloc(sizeof(char) * strlen(str));
        strcpy(e->press, str);
        fgetc(fp);

        //��ȡ����
        fscanf(fp, "%s", str);
        e->score = (char*)malloc(sizeof(char) * strlen(str));
        strcpy(e->score, str);
        fgetc(fp);

        //��ȡҳ��
        fscanf(fp, "%d", &e->page_num);
        fgetc(fp);

        //��ȡ״̬
        fscanf(fp, "%d", &e->status);   

        //��������
        insertRBTree(root, e);
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
    //�??"w"模式打开文件, 文件不存在则创建新文件，文件存在则�?�盖原内�?
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
    
    //定义数据分割符和结束
    char mid = ' ', end = '\n';

    //写入结点数据
    //写入ISBN
    fprintf(fp, "%lld", tree->data->elem);
    fputc(mid,fp);
    //写入书名
    fprintf(fp, "%s", tree->data->Title);
    fputc(mid,fp);
    //写入作�?
    fprintf(fp, "%s", tree->data->Author);
    fputc(mid,fp);
    //写入出版�??
    fprintf(fp, "%s", tree->data->press);
    fputc(mid,fp);
    //写入得分
    fprintf(fp, "%s", tree->data->score);
    fputc(mid,fp);
    //写入页数
    fprintf(fp, "%d", tree->data->page_num);
    fputc(mid,fp);
    //写入状�?
    fprintf(fp, "%d", tree->data->status);
    fputc(end,fp);
    
    //递归插入
    FILE_preWrite(tree->left, fp);
    FILE_preWrite(tree->right, fp);
}

/**
 * @brief 通过ISBN在红黑树�?查找书本，并返�?
 */
RBTreeElemType RBT_SearchByISBN(RBTree R, long long int ISBN){
    
    if(R == NULL) return NULL;
    if (R->data->elem == ISBN) 
        return R->data;
    else if (R->data->elem > ISBN) 
        return RBT_SearchByISBN(R->left, ISBN);
    else 
        return RBT_SearchByISBN(R->right, ISBN);

    return NULL;
}

/**
 * @name RBT_SearchByName
 * @brief 根据书名准确搜索
 * @param  root
 * @param  name
 * @return  RBTreeElemType
 */
RBTreeElemType RBT_SearchByName(RBTree node,char *name){
    if (!node || strcmp(name,node->data->Title)==0) 
        return node->data;
    if(NULL!=RBT_SearchByName(node->right,name))return RBT_SearchByName(node->right,name);
    else if(NULL!=RBT_SearchByName(node->left,name))return RBT_SearchByName(node->left,name);
    else return NULL;
}

/**
 * @name RBT_SearchBookByAuthor
 * @brief 根据作者准�?搜�?
 * @param  root
 * @param  author
 * @return  RBTreeElemType
 */
RBTreeElemType RBT_SearchBookByAuthor(RBTree node,char *author){
    if (!node || strcmp(author,node->data->Author)==0) 
        return node->data;
    if(NULL!=RBT_SearchByName(node->right,author))return RBT_SearchByName(node->right,author);
    else if(NULL!=RBT_SearchByName(node->left,author))return RBT_SearchByName(node->left,author);
    else return NULL;
}



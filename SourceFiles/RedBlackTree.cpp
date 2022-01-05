//
// Created by HUAWEI on 2021-12-06.
//

#include "../HeaderFiles/RedBlackTree.h"
#include "../HeaderFiles/RedBlackTreeUtils.h"
#include "../HeaderFiles/BinarySearchTree.h"
#include "../HeaderFiles/BinaryTree.h"
#include"Utils.h"

//�鱾���ݴ洢�ļ�
char Data_Book[] = "book_data.txt";

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
 * ǰ����������
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
 * ������������
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
 * ������������
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
 * �ݹ���Һ����tree��������Ϊx�Ľ��
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
 * ���������������Ϊx�Ľ��
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  x   : the data of the node
 * @return  the operation status, SUCCESS is 0, FALSE is -1
 */
Status insertRBTree(RBRoot *root, RBTreeElemType x)
{
    // �Ѵ���
    if (recursiveSearchNode(root->node, x)) 
        return FALSE;

    Node *node;
    node = createRBTreeNode(x, NULL, NULL, NULL);
    if (!node) return FALSE;

    insertBinarySearchTree(root, node);
    RBTreeInsertSelfBalancing(root, node);

    return SUCCESS;
}

/**
 * �����ɾ��������Ϊx�Ľ��
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  key : the data of the node to be deleted
 * @return  the operation status, SUCCESS is 0, FALSE is -1
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
    return FALSE;
}

/**
 * ��ӡ�������Ϣ
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
    // ���ڵ�Ϊͷ��㣬���洢��???
    return FALSE;
}

/**
 * @brief ����elem����
 */
Status inputRBTElem(RBTreeElemType &e){

    e = (RBTreeElemType)malloc(sizeof(RBTElem));
    if(e == NULL)   return OVERFLOW;

    //��������
    printf("please input Title:");
    scanf("%s", e->Title);

    //����IBSN
    printf("please input ISBN:");
    e->elem = InputInteger();
    // scanf("%lld", &e->elem);

    //��������
    printf("please input Author:");
    scanf("%s", e->Author);

    //��������
    printf("please input score:");
    scanf("%s", e->score);

    //���������
    printf("please input press:");
    scanf("%s", e->press);

    //�����鱾ҳ��
    printf("please input number of page:");
    scanf("%d", &e->page_num);
    
    //�²������Ĭ��δ���
    e->status = 1;
   
    return SUCCESS;
}

/**
 * @brief ��ʼ����Elem
 */
Status InitRBTElem(RBTreeElemType &e){

    e = (RBTreeElemType)malloc(sizeof(RBTElem));
    if(e == NULL)   return OVERFLOW;
    e->elem = 0;
    e->page_num = 0;
    e->status = 0;
    return SUCCESS;
}

/**
 * @brief ��ȡ���ݲ����ɺ����
 */
Status FILE_ReadRBT(RBRoot *root){

    FILE *fp = fopen(Data_Book,"r");

    if(NULL==fp) return ERROR;
    
    char str[20] = "";

    int num = 0;
    //�ж�
    int status;
    while(!feof(fp)){

        RBTreeElemType e = NULL;
        InitRBTElem(e);
        //��ȡISBN
        fscanf(fp, "%lld", &e->elem);

        //������һ���س�����
        if(e->elem == 0) break;

        //��ȡ����
        fscanf(fp, "%s", e->Title);
        fgetc(fp);
        
        //��ȡ����
        fscanf(fp, "%s", e->Author);
        fgetc(fp);

        //��ȡ������
        fscanf(fp, "%s", e->press);
        fgetc(fp);

        //��ȡ����
        fscanf(fp, "%s", e->score);
        fgetc(fp);

        //��ȡҳ��
        fscanf(fp, "%d", &e->page_num);
        fgetc(fp);

        //��ȡ״̬
        fscanf(fp, "%d", &e->status);   

        //��������
        if(insertRBTree(root, e) != FALSE)
            num++;
    }
    fclose(fp);
    printf("%d", num);
    return SUCCESS;
}

/**
 * @brief �������д���ļ�
 */
Status FILE_WriteRBT(RBRoot root){

    //����
    if(root.node == NULL) return ERROR;

    FILE *fp = NULL;
    //��"w"ģʽ���ļ�, �ļ��������򴴽����ļ����ļ������򸲸�ԭ����
    fp = fopen(Data_Book, "w");

    //������ڵ㣬��ʼǰ��ݹ����
    FILE_preWrite(root.node, fp);
    fclose(fp);

    return SUCCESS;
}

/**
 * @brief ����ǰ������ĺ�����ļ�д��
 */
void FILE_preWrite(RBTree tree, FILE *fp){
    
    if(!tree) return;
    
    //�������ݷָ���ͽ���
    char mid = ' ', end = '\n';

    //д��������
    //д��ISBN
    fprintf(fp, "%lld", tree->data->elem);
    fputc(mid,fp);
    //д������
    fprintf(fp, "%s", tree->data->Title);
    fputc(mid,fp);
    //д������
    fprintf(fp, "%s", tree->data->Author);
    fputc(mid,fp);
    //д�������
    fprintf(fp, "%s", tree->data->press);
    fputc(mid,fp);
    //д��÷�
    fprintf(fp, "%s", tree->data->score);
    fputc(mid,fp);
    //д��ҳ��
    fprintf(fp, "%d", tree->data->page_num);
    fputc(mid,fp);
    //д��״̬
    fprintf(fp, "%d", tree->data->status);
    fputc(end,fp);
    
    //�ݹ����
    FILE_preWrite(tree->left, fp);
    FILE_preWrite(tree->right, fp);
}

/**
 * @brief ͨ��ISBN�ں�����в����鱾�������鱾
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
 * @brief ��������׼ȷ����
 * @param  root
 * @param  name
 * @return  RBTreeElemType
 */
RBTreeElemType RBT_SearchByName(RBTree node,char *name){
    if(node==NULL) return NULL;
    if ( strcmp(name,node->data->Title)==0) 
        return node->data;
    if(NULL!=RBT_SearchByName(node->right,name))return RBT_SearchByName(node->right,name);
    else if(NULL!=RBT_SearchByName(node->left,name))return RBT_SearchByName(node->left,name);
    else return NULL;
}

/**
 * @name RBT_SearchBookByAuthor
 * @brief ��������׼ȷ����
 * @param  root
 * @param  author
 * @return  RBTreeElemType
 */
RBTreeElemType RBT_SearchBookByAuthor(RBTree node,char *author){
    if(node==NULL) return NULL;
    if (strcmp(author,node->data->Author)==0) 
        return node->data;
    if(NULL!=RBT_SearchBookByAuthor(node->right,author))return RBT_SearchByName(node->right,author);
    else if(NULL!= RBT_SearchBookByAuthor(node->left,author))return RBT_SearchByName(node->left,author);
    else return NULL;
}



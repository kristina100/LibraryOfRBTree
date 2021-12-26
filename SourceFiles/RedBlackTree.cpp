//
// Created by HUAWEI on 2021-12-06.
//

#include "../HeaderFiles/RedBlackTree.h"
#include "../HeaderFiles/RedBlackTreeUtils.h"
#include "../HeaderFiles/BinarySearchTree.h"
#include "../HeaderFiles/BinaryTree.h"

//�洢�鱾���ݵ��ļ�
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
    if (root) return recursiveSearchNode(root->node, x) ? SUCCESS : FALSE;
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
    if (recursiveSearchNode(root->node, x)) return FALSE;

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
    // ���ڵ�Ϊͷ��㣬���洢��Ϣ
    return FALSE;
}

/**
 * @brief ����elem����
 *        ֻ�й���Ա�����鱾��ʱ�����ô˷���������elem
 *        ����������ֳ�����ռ�֮�󸳸���Ӧֵ
 */
Status inputRBTElem(RBTreeElemType &e){

    e = (RBTreeElemType)malloc(sizeof(RBTElem));
    if(e == NULL)   return OVERFLOW;

    //��ʼ�����������ߣ����֣�����
    // char *author = NULL, *score = NULL, *title = NULL;
    // author = (char*)malloc(sizeof(char)*20);
    // score = (char*)malloc(sizeof(char)*20);
    // title = (char*)malloc(sizeof(char)*20);

    char str[20] = "";

    //��������
    printf("please input Title:");
    scanf("%s", str);
    e->Title = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e->Title, str);

    //����IBSN
    // printf("please input ISBN:");
    // scanf("%d", &e->elem);

    //��������
    printf("please input Author:");
    scanf("%s", str);
    e->Author = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e->Author, str);

    //��������
    printf("please input score:");
    scanf("%s", str);
    e->score = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e->score, str);

    //���������
    printf("please input press:");
    scanf("%s", str);
    e->press = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e->press, str);

    //���������
    printf("please input number of page:");
    scanf("%d", &e->page_num);
    
    //�²������Ĭ��δ���
    e->status = 1;
   
    return SUCCESS;
}

/**
 * @brief ��ʼ��elem(������)
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
    FILE *fp=fopen("book_data.txt","r");
    if(NULL==fp)
    {
        printf ("Failed to open the file!\n");
        exit (0);
    }

    char str[20] = "";

    // fscanf (fp,"%d",&a) ; //��fp��ָ�ļ��ж�ȡһ���������浽����a��
    while(!feof(fp)){//���λ��ָ�벻���ļ�ĩβ,��û�ж����ļ�ĩβ

        RBTreeElemType e = NULL;
        InitRBTElem(e);
        //����elem(ISBN)
        fscanf(fp, "%d", &e->elem);

        //����������ڱ���������һ���ַ�����
        if(e->elem == 0) break;

        //��������
        fscanf(fp, "%s", str);
        e->Title = (char*)malloc(sizeof(char) * strlen(str));
        strcpy(e->Title, str);
        fgetc(fp);

        //��������
        fscanf(fp, "%s", str);
        e->Author = (char*)malloc(sizeof(char) * strlen(str));
        strcpy(e->Author, str);
        fgetc(fp);

        //����������
        fscanf(fp, "%s", str);
        e->press = (char*)malloc(sizeof(char) * strlen(str));
        strcpy(e->press, str);

        //��������
        fscanf(fp, "%s", str);
        e->score = (char*)malloc(sizeof(char) * strlen(str));
        strcpy(e->score, str);
        fgetc(fp);

        //����ҳ��
        fscanf(fp, "%d", &e->page_num);
        //����״̬
        fscanf(fp, "%d", &e->status);   

        //д������
        insertRBTree(root, e);
    }
    fclose(fp);
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
    fprintf(fp, "%d", tree->data->elem);
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
 * @name printBookInfo
 * @brief Print information about a Book
 * @param e  
 * @return Status 
 */
Status PrintBookInfo(RBTreeElemType e){
    if(e==NULL) return ERROR;
    printf("The title of a book  is %s\n",e->Title);
    printf("The author of the book is %s\n",e->Author);
    printf("The score of the book is %s\n",e->score);
    printf("The press of the book is %s\n",e->press);
    printf("The page number of the book is %d\n",e->page_num);
    printf("The ISBN of the book is %d\n",e->elem);
    printf("The press of the book is %s\n",e->press);
    if(e->status==1) printf("This book is on loan.");
    else printf("This book is not for lending.");
    return SUCCESS;
}

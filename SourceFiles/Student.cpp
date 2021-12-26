/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 14:33:31
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-27 00:16:29
 */
#include"Student.h"
#include"Utils.h"
#include"RedBlackTree.h"

/**
 * @brief ��ʼ��Stu
 */
Status Stu_Init(Stu &stu){

    stu = (Stu)malloc(sizeof(student));
    if(stu == NULL) return OVERFLOW;
    stu->mybook = NULL;
    stu->power = 0;

    return SUCCESS;
}

/**
 * @brief ��ӡѧ��ѡ��
 */
void Stu_Options(Stu stu){
    Clean();
    printf("\t\t<ѧ��ѡ��>\n");
    printf("\n");
    printf("\t1.��ѯ�鼮");
    printf("\t2.�����鼮");
    printf("\n");
    printf("\t3.�黹�鼮");
    printf("\t4.������Ϣ");
    printf("\n");
    printf("\t0.����\n");

    printf("\n\t\t");
    printf("��ѡ��: ");                      
}

/**
 * @brief ��ӡ��ѯѡ��
 */
void Print_Search_Options(){
    Clean();
    printf("\t\t<��ѯѡ��>\n");
    printf("\n");
    printf("\t[1.ISBN��ѯ]");
    printf("\t[2.������ѯ]");
    printf("\n");
    printf("\t[3.���߲�ѯ]");
    printf("\t[4.����]");
    printf("\n");
    printf("\t[0.����]\n");

    printf("\n\t\t");
    printf("��ѡ��: ");      
}

/**
 * @brief ��ӡ����ѡ��
 * 
 */
void Print_Borrow_Options(){
    Clean();
    printf("\t\t<�����鼮>\n");
    printf("\n");
    printf("\t[0.����]\n");
    printf("\t���������ISBN��:");
}

/**
 * @brief �鿴�ҵ���Ϣ
 */
void Stu_MyInfo(Stu stu){
    
}

/**
 * @brief ѧ������
 */
void Stu_Operation(Stu &stu){

    //��ʼ�������
    RBRoot *root = NULL;
    root = createRBTree();
    FILE_ReadRBT(root);

    //ѡ��
    int choose;
    
    while (true){
        Stu_Options(stu);
        scanf("%d", &choose);
     
        switch (choose){
            
            //������һ��
            case 0:{
                //����д���ļ�
                FILE_WriteRBT(root);
                return;
            }break;

            //��ѯ�鼮
            case 1:{
                Stu_SearchBook(root);
            }break;

            //�����鼮
            case 2:{
                Stu_Borrow(stu, root);
            }break;

            //�黹�鼮
            case 3:{
                
            }break;

            //������Ϣ
            case 4:{
                Stu_MyInfo(stu);
            }break;
            default:{
                printf("\n����������\n");
                Pause();
            }break;
        }
    Clean();
    }
}

/**
 * @brief ����
 */
Status Stu_Borrow(Stu stu, RBRoot *root){

    //ѡ��
    int input;
    while(true){
        Print_Borrow_Options();
        scanf("%d", &input);

        switch (input){
            
            //������һ��
            case 0:{
                return FALSE;
            }break;

            default:{
                RBTreeElemType book = NULL;
                //����input�ں����������
                book = RBT_SearchByISBN(root->node, input);
                //�鱾����
                if(book != NULL){
                    while(true){
                        Clean();
                        //��ӡ�鱾��Ϣ
                        Print_BookInfo(book);
                        //�ж��鱾״̬
                        //�鱾δ���
                        if(book->status == 1){
                            printf("�Ƿ���ı���?Y/N");
                            char ch;
                            scanf("%c", &ch);
                            //ȷ������
                            if(ch == 'Y' || ch == 'y'){
                                if(Stu_AddBook(stu, book) == SUCCESS){
                                    printf("���ĳɹ�\n");
                                }
                                else{
                                    printf("����ʧ��\n");
                                }
                            }
                            //��������
                            else if(ch == 'N' || ch == 'n'){
                                break;
                            }
                            //��������ж�
                            else{
                                printf("��������\n");
                            }
                        }
                        Pause();
                    }
                }
                //�鱾������
                else{
                    printf("�鱾������");
                }
            }break;
        }
    Clean();
    } 
}

/**
 * @brief ����
 */
Status Stu_return(Stu stu){
    
    //ѧ��û�н���
    if(stu->mybook == NULL)
        return FALSE;

    //��ӡ�ѽ����
    Print_Book(stu->mybook);
    return SUCCESS;
}

/**
 * @brief ��ӡ�ѽ����
 */
void Print_Book(MyBook b){

    Clean();
    printf("\n\n\n\n*-----------------------�������----------------------------------*\n");
    printf("ISBN\t");
    printf("����\n");

    MyBook p = b;
    while(p != NULL){
        
        //��ӡISBN
        printf("%d\t", p->book->elem);
        //��ӡ����
        printf("%s\n", p->book->Title);
        //ָ����һ����
        p = p->next;
    }
}

/**
 * @brief �����鱾
 */
void Stu_SearchBook(RBRoot *root){

    //ѭ��������־
    int flag = 1;
    //ѡ��
    int choose;
    
    while (flag){
        Print_Search_Options();
        scanf("%d", &choose);
     
        switch (choose){
            
            //������һ��
            case 0:{
                return;
            }break;

            //��ISBN����
            case 1:{
                printf("��ISBN����");
                Pause();
            }break;

            //����������
            case 2:{
                printf("����������");
                Pause();
            }break;

            //�����߲���
            case 3:{
                printf("�����߲���");
                Pause();
            }break;

            //����
            case 4:{
                printf("����");
                Pause();
            }

            default:{
                printf("\n����������\n");
                Pause();
            }break;
        }
    Clean();
    }
}

/**
 * @brief ��ѧ���˻������һ���飬����������Ϊ�ѽ��״̬
 */
Status Stu_AddBook(Stu stu, RBTreeElemType b){

    //ѧ����ǰû���ѽ����
    if(stu->mybook = NULL){

        //����ռ�
        stu->mybook = (MyBook)malloc(sizeof(mybook));
        if(stu->mybook == NULL)
            return OVERFLOW;

        //����һ����Ӹ�ѧ��
        stu->mybook->book = b;
        stu->mybook->next = NULL;
    }
    //ѧ����ǰ���ѽ����
    else{

        //��ʼ��MyBook��������ĵ���
        MyBook mb = NULL;
        mb = (MyBook)malloc(sizeof(mybook));
        if(mb == NULL)
            return OVERFLOW;
        mb->book = b;

        //ͷ�巨�����ĵ������
        mb->next = stu->mybook;
        stu->mybook = mb;
    }
    //�鱾״̬��Ϊ0,Ϊ���״̬
    b->status = 0;
    return SUCCESS;
}
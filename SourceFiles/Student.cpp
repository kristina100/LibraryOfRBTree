/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 14:33:31
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-28 16:29:34
 */
#include"Student.h"
#include"Utils.h"
#include"RedBlackTree.h"
#include"Login.h"

/**
 * @brief ��ʼ��Stu
 */
Status Stu_Init(Stu &stu){

    stu = (Stu)malloc(sizeof(student));
    if(stu == NULL) return OVERFLOW;
    stu->mybook = NULL;
    stu->power = 0;
    stu->next = NULL;

    return SUCCESS;
}

/**
 * @brief ��ӡѧ��ѡ��
 */
void Stu_Options(Stu stu){
    Clean();
    printf("\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("|                         <Student Options>                               |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|           1.Search Book                 2.Borrow book                   |\n");
    printf("|                                                                         |\n");
    printf("|           3.Return book                 4.Self Info                     |\n");
    printf("|                                                                         |\n");
    printf("|                         0.System Return                                 |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("*-------------------------------------------------------------------------*\n");     
    printf("\n\t\t");
    printf("Please choose: ");             
}

/**
 * @brief ��ӡ��ѯѡ��
 */
void Print_Search_Options(){
    Clean();
    printf("\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("|                           <Search Options>                              |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|           1.Search By ISBN              2.Search By Title               |\n");
    printf("|                                                                         |\n");
    printf("|           3.Search By Author            0.System Return                 |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("*-------------------------------------------------------------------------*\n");     
    printf("\n\t\t");
    printf("Please choose: ");      
}

/**
 * @brief ��ӡ����ѡ��
 * 
 */
void Print_Borrow_Options(){
    Clean();
    printf("\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("|                         <Search By ISBN>                                |\n");
    printf("|                                                                         |\n");
    printf("|                         0.System Return                                 |\n");
    
    printf("\n\t\t");
    printf("Please input ISBN: ");     
}

/**
 * @brief ��ӡ�ҵ���Ϣ
 */
void Stu_Print_MyInfo(Stu stu){

    Clean();
    printf("\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("                                 <My Info>                                 \n");
    printf("Name: %s ", stu->name);
    printf("ID: %s ", stu->ID);
    printf("account: %s \n", stu->account);
    Print_Book(stu->mybook);
    
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
                FILE_WriteRBT(*root);
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
                Stu_Print_MyInfo(stu);
                Pause();
            }break;
            default:{
                printf("\nOperation does not exist\n");
                Pause();
            }break;
        }
    Clean();
    }
}

/**
 * @brief ����
 */
void Stu_Borrow(Stu stu, RBRoot *root){

    //ѡ��
    int input;
    while(true){
        Print_Borrow_Options();
        scanf("%d", &input);

        switch (input){
            
            //������һ��
            case 0:{
                return;
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
                            printf("whether borrow this book? 1.Yes  2.No\n");
                            printf("choose: ");
                            int confirm = -1;
                            scanf("%d", &confirm);
                            //ȷ������
                            if(confirm == 1){
                                if(Stu_AddBook(stu, book) == SUCCESS){
                                    printf("Success, you have the book now.\n");
                                    Updata_StuInfo(stu);
                                    Pause();
                                }
                                else{
                                    printf("Fail\n");
                                }
                            }
                            //��������
                            else if(confirm == 2){
                                break;
                            }
                            //��������ж�
                            else{
                                printf("Error! Please check your input.\n");
                            }
                        }
                        //�鱾�ѽ��
                        else{
                            printf("Fail! The books have been borrowed.");
                        }
                        Pause();
                    }
                }
                //�鱾������
                else{
                    printf("The book does not exist");
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

    MyBook p = b;
    printf("\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("                           <My Books>                                      \n");
    printf("    ISBN    |        Title        |        Author        |       Press       ");
    
    while(p != NULL){
        //��ӡISBN
        printf("%-15lld | ", p->book->elem);
        //��ӡ����
        printf("%-15s | ", p->book->Title);
        //��ӡ����
        printf("%-15s | ", p->book->Author);
        //��ӡ������
        printf("%-15s \n", p->book->press);
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
                printf("\nOperation does not exist\n");
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
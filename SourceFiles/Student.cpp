/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 14:33:31
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-04 11:49:43
 */
#include"Student.h"
#include"Utils.h"
#include"RedBlackTree.h"
#include"Login.h"
#include"EscapeRote.h"

/**
 * @brief ��ʼ��Stu
 */
Status Stu_Init(Stu &stu){

    stu = (Stu)malloc(sizeof(student));
    if(stu == NULL) return OVERFLOW;
    stu->mybook = NULL;
    stu->power = 0;
    stu->bookNum = 0;
    stu->next = NULL;

    for(int i = 0; i < 15; i++){
        stu->account[i] = '\0';
        stu->password[i] = '\0';
        if(i < 10)
            stu->name[i] = '\0';
        if(i < 11)
            stu->ID[i] = '\0';
    }
    return SUCCESS;
}

/**
 * @brief ��ӡѧ��ѡ��
 */
void Stu_Options(){
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
    printf("|           5.Show escape Rote            0.System Return                 |\n");
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
    printf("|                              <Input ISBN>                               |\n");
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
    printf("                                 <My Info>                                 \n\n");
    printf("\tName: %s ", stu->name);
    printf("\tID: %s ", stu->ID);
    printf("\t\tAccount: %s \n", stu->account);
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
        Stu_Options();
        scanf("%d", &choose);
     
        switch (choose){
            
            //������һ��
            case 0:{
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
                if(Stu_return(stu, root) == SUCCESS){
                    printf("Return the book successfully!\n");
                }
                Pause();
            }break;

            //������Ϣ
            case 4:{
                Stu_Print_MyInfo(stu);
                Pause();
            }break;

            case 5://����·��
		{
            if(getEscapeRote()!=SUCCESS)
				printf("Failed to show escape rote!\n");
			break;
		}
            default:{
                printf("\nOperation does not exist!\n");
                Pause();
            }break;
        }
    Clean();
    }
}

/**
 * @brief ����
 */
void Stu_Borrow(Stu &stu, RBRoot *root){

    //ѡ��
    long long int input;
    while(true){
        Print_Borrow_Options();
        input = InputInteger();

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

                                    //�鱾״̬��Ϊ0,Ϊ���״̬
                                    book->status = 0;
                                    //�����鱾��Ϣ
                                    FILE_WriteRBT(*root);
                                    //����ѧ����Ϣ
                                    Updata_StuInfo(stu);

                                    printf("Success, you have the book now.\n");
                                    Pause();
                                    break;
                                }
                                else{
                                    printf("Fail!\n");
                                }
                            }
                            //��������
                            else if(confirm == 2){
                                break;
                            }
                            //��������ж�
                            else{
                                printf("Error! Please check your input.\n");
                                Pause();
                            }
                        }
                        //�鱾�ѽ��
                        else{
                            printf("Fail! The books have been borrowed.\n");
                            Pause();
                            break;
                        }
                    }
                }
                //�鱾������
                else{
                    printf("The book does not exist!\n");
                    Pause();
                }
            }break;
        }
    }
}

/**
 * @brief ��ӡ�鱾
 */
void Print_Book(MyBook b){

    MyBook p = b;
    printf("\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("                                <Books>                                \n\n");
    printf("  Num  |     ISBN     |         Title         |      Author      |    Press    \n\n");
    int num = 1;
    while(p != NULL && p->book != NULL){
        //��ӡ���
        printf(" %-3d",num);
        //��ӡISBN
        printf("%15lld\t", p->book->elem);
        //��ӡ����
        printf("%10s\t", p->book->Title);
        //��ӡ����
        printf("%10s\t", p->book->Author);
        //��ӡ������
        printf("%10s \n", p->book->press);
        //ָ����һ����
        p = p->next;
        num++;
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
                Stu_SearchBookByISBN(root);
                Pause();
            }break;

            //����������
            case 2:{
                //������������
                MyBook books = (MyBook)malloc(sizeof(mybook));
                books->book = NULL;
                books->next = NULL;
                char str[20] = "";

                printf("\tPlease enter the title: ");
                scanf("%s", str);

                //����
                Stu_SearchBookByTitle(root->node, str, books);
                
                //��ӡ�鱾
                if(books->book)
                    Print_Book(books);
                else
                    printf("No book exists!\n");

                Pause();
            }break;

            //�����߲���
            case 3:{
                //������������
                MyBook books = (MyBook)malloc(sizeof(mybook));
                books->book = NULL;
                books->next = NULL;
                char str[20] = "";

                printf("\tPlease enter the title: ");
                scanf("%s", str);

                //����
                Stu_SearchBookByAuthor(root->node, str, books);

                //��ӡ�鱾
                if(books->book)
                    Print_Book(books);
                else
                    printf("No book exists!\n");

                Pause();
            }break;

            default:{
                printf("\nOperation does not exist\n");
                Pause();
            }
        }
    }
}
/**
 * @brief ����ISBN�����鱾
 */
void Stu_SearchBookByISBN(RBRoot *root){
    
    Clean();
    printf("\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("|                            <Search By ISBN>                             |\n");
    printf("|                                                                         |\n");
    printf("|                             0.System Return                             |\n");
    
    printf("\n\t\t");
    printf("Please input ISBN: ");   
    long long int ISBN = InputInteger();

    if(ISBN == 0)
        return;

    RBTreeElemType e = NULL;
    //����������
    e = RBT_SearchByISBN(root->node, ISBN);
    
    if(e == NULL)
        printf("Sorry, Book does not exist!\n");
    else 
        Print_BookInfo(e);

}

/**
 * @brief ������������
 */
void Stu_SearchBookByTitle(RBTree node, char *name, MyBook &books){

    //node�п�
    if(node == NULL) return;
    
    //�ַ����ж�
    if(strpbrk(name, node->data->Title) != NULL){

        MyBook newBook = (MyBook)malloc(sizeof(mybook));
        
        //books��û������
        if(books->book == NULL)
            books->book = node->data;
        
        //books��������
        else{
            newBook->book = node->data;
            newBook->next = NULL;
            //ͷ����
            newBook->next = books;
            books = newBook;
        }
    }
    //ǰ������ݹ����
    Stu_SearchBookByTitle(node->left, name, books);
    Stu_SearchBookByTitle(node->right, name, books);
}

/**
 * @brief ��������ģ������
 */
void Stu_SearchBookByAuthor(RBTree node, char *author, MyBook &books){

    //node�п�
    if(node == NULL) return;
    
    //�ַ����ж�
    if(strpbrk(author, node->data->Author) != NULL){

        MyBook newBook = (MyBook)malloc(sizeof(mybook));
        
        //books��û������
        if(books->book == NULL)
            books->book = node->data;
        
        //books��������
        else{
            newBook->book = node->data;
            newBook->next = NULL;
            //ͷ����
            newBook->next = books;
            books = newBook;
        }
    }
    //ǰ������ݹ����
    Stu_SearchBookByAuthor(node->left, author, books);
    Stu_SearchBookByAuthor(node->right, author, books);
}

/**
 * @brief ��ѧ���˻������һ����
 */
Status Stu_AddBook(Stu &stu, RBTreeElemType b){

    //ѧ����ǰû���ѽ����
    if(stu->mybook == NULL){

        //����ռ�
        stu->mybook = (MyBook)malloc(sizeof(mybook));
        if(stu->mybook == NULL)
            return OVERFLOW;

        //��ӵ�һ����
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
    //�������+1
    stu->bookNum++;
    return SUCCESS;
}

/**
 * @brief ѧ������
 */
Status Stu_return(Stu &stu, RBRoot *root){

    //ѧ��û�н���
    if(stu->mybook == NULL || stu->mybook->book == NULL){
        printf("You have borrowed no books!\n");
        return ERROR;
    }
    //��ӡ�ѽ����
    Clean();
    Print_Book(stu->mybook);

    int num = 0;
    printf("\rPlease choose a book to return: ");
    num = InputInteger();
    
    RBTreeElemType e = NULL;
    MyBook q = NULL, p = NULL;
    q = p = stu->mybook;
    //��stu->mybook���ҵ���Ӧ��
    while(p && num != 1){
        num--;
        //ָ����һ��
        q = p;
        //ָ����һ��
        p = p->next;
    }
    //��Ŵ����鲻����
    if(!p){
        printf("Input error!, the book does not exist!\n");
        return FALSE;
    }

    //ɾȥ��һ����
    if(q == p){
        //ֱ��ָ����һ��
        stu->mybook = stu->mybook->next;
    }
    //����
    else{
        q->next = p->next;
        p->next = NULL;
    }
    //�����и���ISBN�ҵ���
    e = RBT_SearchByISBN(root->node, p->book->elem);

    //�鲻����
    if(e == NULL){
        return ERROR;
    }

    //��״̬��Ϊ1
    e->status = 1;

    //���������1
    stu->bookNum--;

    //�����鱾�ļ�
    FILE_WriteRBT(*root);
    //����ѧ���ļ�
    Updata_StuInfo(stu);
    return SUCCESS;
}

/**
 * @brief ��ȡѧ����Ϣ����������
 */
Stu Stu_ReadData(){

    //�洢ѧ�����ݵ��ļ�
    char Data_Stu[] = "Students.dat";

    //��ѧ�������ļ�
    FILE *fp = NULL;
    fp = fopen(Data_Stu, "rb");

    if(fp == NULL)
        return NULL;

    //��ʼ��
    Stu temp = NULL, head = NULL;
    RBTreeElemType e = NULL;
    MyBook MB = NULL;
    
    //����ѧ���ṹ��
    while(!feof(fp)){
        Stu_Init(temp);
        fread(temp, sizeof(student), 1, fp);

        //����������
        if(strcmp(temp->account,"") == 0)
            break;

        //ѧ���н����¼����ʼ��ȡ�鱾��Ϣ����
        if(temp->bookNum != 0){

            //����ѧ���鱾��Ϣ
            for(int i = 0; i < temp->bookNum; i++){

                //����ռ�
                MB = (MyBook)malloc(sizeof(mybook));
                MB->book = NULL;
                MB->next = NULL;
                InitRBTElem(e);

                //����һ����
                fread(e, sizeof(RBTElem), 1, fp);
                MB->book = e;
                //��һ����
                if(i == 0){
                    MB->next = NULL;
                    temp->mybook = MB;
                }
                //�ǵ�һ���飬ͷ�巨����
                else{
                    MB->next = temp->mybook;
                    temp->mybook = MB;
                }
            }
        }

        //ͷ�巨����ѧ����Ϣ
        if(head != NULL){
            temp->next = head;
            head = temp;
        }else
            head = temp;
    }

    return head;
}

/**
 * @brief ��ʽ��д��ѧ���ļ�
 */
Status Stu_WriteData(Stu stu){

    //�洢ѧ�����ݵ��ļ�
    char Data_Stu[] = "Students.dat";

    //��stu
    if(stu == NULL) return ERROR;
    
    //��ѧ�������ļ�
    FILE *fp = NULL;
    fp = fopen(Data_Stu, "wb");

    if(fp == NULL)
        return ERROR;

    //��ʼ��
    Stu p = stu;
    MyBook mb = NULL;
    //д��ѧ����Ϣ
    while(p != NULL){

        //д��ѧ���ṹ��
        fwrite(p, sizeof(student), 1, fp);

        //ѧ�����ѽ��鼮��д���鱾��Ϣ
        if(p->bookNum > 0){
            mb = p->mybook;
            while(mb != NULL && mb->book != NULL){
                fwrite(mb->book, sizeof(RBTElem), 1, fp);
                mb = mb->next;
            }
        }
        //ָ����һ��ѧ��
        p = p->next;
    }
    //�ر��ļ�
    fclose(fp);
    return SUCCESS;
}
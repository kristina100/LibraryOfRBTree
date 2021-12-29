/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 14:33:31
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-29 11:45:17
 */
#include"Student.h"
#include"Utils.h"
#include"RedBlackTree.h"
#include"Login.h"

/**
 * @brief 初始化Stu
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
 * @brief 打印学生选项
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
    printf("|                         0.System Return                                 |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("*-------------------------------------------------------------------------*\n");     
    printf("\n\t\t");
    printf("Please choose: ");             
}

/**
 * @brief 打印查询选项
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
 * @brief 打印借书选项
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
 * @brief 打印我的信息
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
 * @brief 学生操作
 */
void Stu_Operation(Stu &stu){

    //初始化红黑树
    RBRoot *root = NULL;
    root = createRBTree();
    FILE_ReadRBT(root);

    //选择
    int choose;
    
    while (true){
        Stu_Options();
        scanf("%d", &choose);
     
        switch (choose){
            
            //返回上一级
            case 0:{
                return;
            }break;

            //查询书籍
            case 1:{
                Stu_SearchBook(root);
            }break;

            //借阅书籍
            case 2:{
                Stu_Borrow(stu, root);
            }break;

            //归还书籍
            case 3:{
                if(Stu_return(stu, root) == SUCCESS){
                    printf("Return the book successfully!");
                }
                Pause();
            }break;

            //个人信息
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
 * @brief 借书
 */
void Stu_Borrow(Stu stu, RBRoot *root){

    //选择
    int input;
    while(true){
        Print_Borrow_Options();
        scanf("%d", &input);

        switch (input){
            
            //返回上一级
            case 0:{
                return;
            }break;

            default:{
                RBTreeElemType book = NULL;
                //根据input在红黑树中找书
                book = RBT_SearchByISBN(root->node, input);
                //书本存在
                if(book != NULL){
                    while(true){
                        Clean();
                        //打印书本信息
                        Print_BookInfo(book);
                        //判断书本状态
                        //书本未借出
                        if(book->status == 1){
                            printf("whether borrow this book? 1.Yes  2.No\n");
                            printf("choose: ");
                            int confirm = -1;
                            scanf("%d", &confirm);
                            //确定借阅
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
                            //放弃借阅
                            else if(confirm == 2){
                                break;
                            }
                            //输入错误判断
                            else{
                                printf("Error! Please check your input.\n");
                            }
                        }
                        //书本已借出
                        else{
                            printf("Fail! The books have been borrowed.");
                        }
                        Pause();
                    }
                }
                //书本不存在
                else{
                    printf("The book does not exist");
                }
            }break;
        }
    Clean();
    }
}

/**
 * @brief 还书
 */
Status Stu_return(Stu stu){
    
    //学生没有借书
    if(stu->mybook == NULL)
        return FALSE;

    //打印已借的书
    Print_Book(stu->mybook);
    return SUCCESS;
}

/**
 * @brief 打印已借的书
 */
void Print_Book(MyBook b){

    MyBook p = b;
    printf("\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("                                <My Books>                                \n\n");
    printf("  Num  |     ISBN     |         Title         |      Author      |    Press    \n\n");
    int num = 1;
    while(p != NULL){
        //打印编号
        printf("  %-3d\t",num);
        //打印ISBN
        printf("%-15lld", p->book->elem);
        //打印书名
        printf("%-25s", p->book->Title);
        //打印作者
        printf("%-20s", p->book->Author);
        //打印出版社
        printf("%-20s \n", p->book->press);
        //指向下一本书
        p = p->next;
        num++;
    }
}

/**
 * @brief 查找书本
 */
void Stu_SearchBook(RBRoot *root){

    //循环操作标志
    int flag = 1;
    //选择
    int choose;
    
    while (flag){
        Print_Search_Options();
        scanf("%d", &choose);
     
        switch (choose){
            
            //返回上一级
            case 0:{
                return;
            }break;

            //按ISBN查找
            case 1:{
                printf("按ISBN查找");
                Pause();
            }break;

            //按书名查找
            case 2:{
                printf("按书名查找");
                Pause();
            }break;

            //按作者查找
            case 3:{
                printf("按作者查找");
                Pause();
            }break;

            //待定
            case 4:{
                printf("待定");
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
 * @brief 向学生账户上添加一本书，并将书设置为已借出状态
 */
Status Stu_AddBook(Stu &stu, RBTreeElemType b){

    //学生当前没有已借的书
    if(stu->mybook == NULL){

        //分配空间
        stu->mybook = (MyBook)malloc(sizeof(mybook));
        if(stu->mybook == NULL)
            return OVERFLOW;

        //将第一本书接给学生
        stu->mybook->book = b;
        stu->mybook->next = NULL;
    }
    //学生当前有已借的书
    else{

        //初始化MyBook，加入借阅的书
        MyBook mb = NULL;
        mb = (MyBook)malloc(sizeof(mybook));
        if(mb == NULL)
            return OVERFLOW;
        mb->book = b;

        //头插法将借阅的书插入
        mb->next = stu->mybook;
        stu->mybook = mb;
    }
    //书本状态置为0,为借出状态
    b->status = 0;
    return SUCCESS;
}

/**
 * @brief 学生还书
 */
Status Stu_return(Stu &stu, RBRoot *root){

    //没有已借的书
    if(stu->mybook == NULL || stu->mybook->book == NULL){
        printf("You have borrowed no books!");
        return ERROR;
    }
    //打印已借的书
    Clean();
    Print_Book(stu->mybook);

    int num = 0;
    printf("\rPlease choose a book to return: ");
    num = InputInteger();
    
    RBTreeElemType e = NULL;
    MyBook q = NULL, p = NULL;
    q = p = stu->mybook;
    //在stu->mybook中找到对应编号的书
    while(p && num != 1){
        num--;
        //保存上一个位置
        q = p;
        //指向下一本
        p = p->next;
    }
    //输入错误，书本不存在
    if(!p){
        printf("Input error!, the book does not exist!");
    }

    //删去第一本书
    if(q == p){
        //指向下一本
        stu->mybook = stu->mybook->next;
    }
    //删去中间部分的书
    else{
        q->next = p->next;
        p->next = NULL;
    }
    //在树中找到对应数据
    e = RBT_SearchByISBN(root->node, p->book->elem);

    //没有找到书，测试用
    if(e == NULL){
        return ERROR;
    }

    //将状态改为1
    e->status = 1;

    //更新书本文件
    FILE_WriteRBT(*root);
    //更新学生数据
    Updata_StuInfo(stu);
    return SUCCESS;
}
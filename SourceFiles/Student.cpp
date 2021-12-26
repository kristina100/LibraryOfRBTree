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
 * @brief 初始化Stu
 */
Status Stu_Init(Stu &stu){

    stu = (Stu)malloc(sizeof(student));
    if(stu == NULL) return OVERFLOW;
    stu->mybook = NULL;
    stu->power = 0;

    return SUCCESS;
}

/**
 * @brief 打印学生选项
 */
void Stu_Options(Stu stu){
    Clean();
    printf("\t\t<学生选项>\n");
    printf("\n");
    printf("\t1.查询书籍");
    printf("\t2.借阅书籍");
    printf("\n");
    printf("\t3.归还书籍");
    printf("\t4.个人信息");
    printf("\n");
    printf("\t0.返回\n");

    printf("\n\t\t");
    printf("请选择: ");                      
}

/**
 * @brief 打印查询选项
 */
void Print_Search_Options(){
    Clean();
    printf("\t\t<查询选项>\n");
    printf("\n");
    printf("\t[1.ISBN查询]");
    printf("\t[2.书名查询]");
    printf("\n");
    printf("\t[3.作者查询]");
    printf("\t[4.待定]");
    printf("\n");
    printf("\t[0.返回]\n");

    printf("\n\t\t");
    printf("请选择: ");      
}

/**
 * @brief 打印借书选项
 * 
 */
void Print_Borrow_Options(){
    Clean();
    printf("\t\t<借阅书籍>\n");
    printf("\n");
    printf("\t[0.返回]\n");
    printf("\t请输入书的ISBN号:");
}

/**
 * @brief 查看我的信息
 */
void Stu_MyInfo(Stu stu){
    
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
        Stu_Options(stu);
        scanf("%d", &choose);
     
        switch (choose){
            
            //返回上一级
            case 0:{
                //将树写入文件
                FILE_WriteRBT(root);
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
                
            }break;

            //个人信息
            case 4:{
                Stu_MyInfo(stu);
            }break;
            default:{
                printf("\n操作不存在\n");
                Pause();
            }break;
        }
    Clean();
    }
}

/**
 * @brief 借书
 */
Status Stu_Borrow(Stu stu, RBRoot *root){

    //选择
    int input;
    while(true){
        Print_Borrow_Options();
        scanf("%d", &input);

        switch (input){
            
            //返回上一级
            case 0:{
                return FALSE;
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
                            printf("是否借阅本书?Y/N");
                            char ch;
                            scanf("%c", &ch);
                            //确定借阅
                            if(ch == 'Y' || ch == 'y'){
                                if(Stu_AddBook(stu, book) == SUCCESS){
                                    printf("借阅成功\n");
                                }
                                else{
                                    printf("借阅失败\n");
                                }
                            }
                            //放弃借阅
                            else if(ch == 'N' || ch == 'n'){
                                break;
                            }
                            //输入错误判断
                            else{
                                printf("请检查输入\n");
                            }
                        }
                        Pause();
                    }
                }
                //书本不存在
                else{
                    printf("书本不存在");
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

    Clean();
    printf("\n\n\n\n*-----------------------借阅情况----------------------------------*\n");
    printf("ISBN\t");
    printf("书名\n");

    MyBook p = b;
    while(p != NULL){
        
        //打印ISBN
        printf("%d\t", p->book->elem);
        //打印书名
        printf("%s\n", p->book->Title);
        //指向下一本书
        p = p->next;
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
                printf("\n操作不存在\n");
                Pause();
            }break;
        }
    Clean();
    }
}

/**
 * @brief 向学生账户上添加一本书，并将书设置为已借出状态
 */
Status Stu_AddBook(Stu stu, RBTreeElemType b){

    //学生当前没有已借的书
    if(stu->mybook = NULL){

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
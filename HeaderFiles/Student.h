/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 14:33:25
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-01 23:57:31
 */
#ifndef STUDENT_H_INCLUDE
#define STUDENT_H_INCLUDE
#include"Common.h"
#include"RedBlackTree.h"

//书本结构体
typedef struct mybook{
    RBTreeElemType book; //
    struct mybook *next; //下一本
}mybook,*MyBook;

//学生结构体
typedef struct student{
    char name[10]; //姓名
    char account[10];  //账号
    char ID[11];   //学号
    char password[10];//密码
    MyBook mybook;    //书
    int power;  //权限
    struct student *next;   //下一个学生
}student, *Stu;

/**
 * @brief 初始化Stu
 * 
 * @param stu 
 * @return Status 
 */
Status Stu_Init(Stu &stu);

/**
 * @brief 学生操作
 * 
 */
void Stu_Operation(Stu &stu);

/**
 * @brief 打印学生选项
 * 
 */
void Stu_Options();

/**
 * @brief 借书
 * 
 * @param stu 
 * @param root 
 */
void Stu_Borrow(Stu stu, RBRoot *root);

/**
 * @brief 学生还书
 * 
 * @param stu 
 * @param root 
 * @return Status 
 */
Status Stu_return(Stu &stu, RBRoot *root);

/**
 * @brief 打印我的信息
 * 
 * @param stu 
 */
void Stu_Print_MyInfo(Stu stu);

/**
 * @brief 閹垫儳娲栫�靛棛鐖?
 * 
 * @param stu 
 * @return Status 
 */
Status Stu_FindPassword(Stu stu);

/**
 * @brief 閺囧瓨鏁肩�靛棛鐖?
 * 
 * @return Status 
 */
Status Stu_ChangePassword(Stu stu);

/**
 * @brief 打印已借的书
 * 
 * @param b 
 */
void Print_Book(MyBook b);

/**
 * @brief 查找书本
 * 
 * @param root 
 */
void Stu_SearchBook(RBRoot *root);

/**
 * @brief 打印查询选项
 * 
 */
void Print_Search_Options();

/**
 * @brief 打印借书选项
 * 
 */
void Print_Borrow_Options();

/**
 * @brief 向学生账户上添加一本书，并将书设置为已借出状态
 * 
 * @param stu 
 * @param b 
 * @return Status 
 */
Status Stu_AddBook(Stu &stu, RBTreeElemType b);

#endif  //STUDENT_H_INCLUDE
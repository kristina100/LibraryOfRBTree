/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 14:33:25
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-27 21:33:13
 */
#ifndef STUDENT_H_INCLUDE
#define STUDENT_H_INCLUDE
#include"Common.h"
#include"RedBlackTree.h"

//我的书
typedef struct mybook{
    RBTreeElemType book;//借的书
    struct mybook *next;//下一本书
}mybook,*MyBook;

//学生结构体
typedef struct student{
    char name[10]; //学生姓名
    char account[10];  //账号
    char ID[11];   //学号
    char password[10];//密码
    MyBook mybook;    //我借的书
    int power;  //学生权力
    struct student *next;//指向下一个学生
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
void Stu_Options(Stu stu);

/**
 * @brief 学生借书
 * 
 * @param stu 
 * @param root 
 */
void Stu_Borrow(Stu stu, RBRoot *root);

/**
 * @brief 学生还书
 * 
 * @param stu 
 * @return Status 
 */
Status Stu_return(Stu stu);

/**
 * @brief 打印我的信息
 * 
 * @param stu 
 */
void Stu_Print_MyInfo(Stu stu);

/**
 * @brief 找回密码
 * 
 * @param stu 
 * @return Status 
 */
Status Stu_FindPassword(Stu stu);

/**
 * @brief 更改密码
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
Status Stu_AddBook(Stu stu, RBTreeElemType b);

#endif  //STUDENT_H_INCLUDE
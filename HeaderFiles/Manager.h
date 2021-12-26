/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 17:37:21
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-24 20:14:20
 */
#ifndef MANAGER_H_INCLUDE
#define MANAGER_H_INCLUDE
#include"Common.h"
#include"RedBlackTree.h"

//管理员结构体
typedef struct manager{
    char name[10]; //管理员姓名
    char account[10]; //账号
    char password[10];//密码
    int power;
}manager, *Manager;

/**
 * @brief 初始化Manager
 * 
 * @param man 
 * @return Status 
 */
Status Man_Init(Manager &M);

/**
 * @name Man_ChoiceMenu
 * @brief 打印管理员菜单
 * @param   
 * @return  Status
 */
void Man_ChoiceMenu();

/**
 * @name Man_Fuction
 * @brief 登录成功后进入管理员页面
 * @param  M
 * @return Status 
 */
Status Man_Fuction(Manager &M);

/**
 * @name Man_ManageAccount
 * @brief 管理账号功能
 * @param   M root
 * @return  Status
 */
Status Man_ManageAccount(Manager M,RBRoot *root);

/**
 * @name Man_Grounding
 * @brief  上架书籍
 * @param   M root
 * @return  status
 */
Status Man_Grounding(Manager M,RBRoot *root);


/**
 * @name Man_OffShelf
 * @brief 下架书籍
 * @param   M root
 * @return  status
 */
Status Man_OffShelf(Manager M,RBRoot *root);

/**
 * @name Man_SearchBook
 * @brief  搜索书籍
 * @param   M root
 * @return  status
 */
Status Man_SearchBook(Manager M,RBRoot *root);

/**
 * @name Man_GetBookTree
 * @brief 获取书籍
 * @param  root
 * @return  Status
 */
Status Man_GetBookTree(RBRoot *root);

#endif  //MANAGER_H_INCLUDE

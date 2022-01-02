/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 17:37:21
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-02 16:23:49
 */
#ifndef MANAGER_H_INCLUDE
#define MANAGER_H_INCLUDE
#include"Common.h"
#include"Student.h"
#include"RedBlackTree.h"
#include"RedBlackTreeUtils.h"
#include"BinarySearchTree.h"
#include"BinaryTree.h"

//管理员结构体
typedef struct manager{
    char name[10]; //姓名
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
 * @brief 获取书籍(从文件读取树)
 * @param  root
 * @return  Status
 */
Status Man_GetBookTree(RBRoot *root);

/**
 * @name Man_SearchMenu
 * @brief 管理员查找功能
 * @param   
 * @return 
 */
void Man_SearchMenu();

/**
 * @name Man_AccountMenu
 * @brief 账号管理菜单
 * @param   
 * @return 
 */
void Man_AccountMenu();

/**
 * @name SearchByName
 * @brief 根据书名准确搜索
 * @param  root
 * @param  name
 * @return  RBTreeElemType
 */
RBTreeElemType SearchByName(RBRoot *root);

/**
 * @name SearchBookByAuthor
 * @brief 根据作者准确搜索
 * @param  root
 * @param  author
 * @return  RBTreeElemType
 */
RBTreeElemType SearchBookByAuthor(RBRoot *root);

/**
 * @name FuzzySearchByName
 * @brief 按书名模糊搜索
 * @param  root
 * @return  status
 */
MyBook FuzzySearchByName(RBRoot *root);

/**
 * @name RBT_FuzzySearchByName
 * @brief 按书名模糊搜索
 * @param  root
 * @param  name
 * @return  status
 */
Status RBT_FuzzySearchByName(RBTree node,char *name,MyBook &books);

/**
 * @name printBookInfo
 * @brief Print information about a Book
 * @param e  
 * @return Status 
 */
Status PrintBookInfo(RBTreeElemType e);

#endif  //MANAGER_H_INCLUDE

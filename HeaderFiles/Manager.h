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
#include"Student.h"
#include"RedBlackTree.h"
#include"RedBlackTreeUtils.h"
#include"BinarySearchTree.h"
#include"BinaryTree.h"

//绠＄悊鍛樼粨鏋勪綋
typedef struct manager{
    char name[10]; //绠＄悊鍛樺锟???
    char account[10]; //璐﹀彿
    char password[10];//瀵嗙爜
    int power;
}manager, *Manager;

/**
 * @brief 鍒濆鍖朚anager
 * 
 * @param man 
 * @return Status 
 */
Status Man_Init(Manager &M);

/**
 * @name Man_ChoiceMenu
 * @brief 鎵撳嵃绠＄悊鍛樿彍锟??
 * @param   
 * @return  Status
 */
void Man_ChoiceMenu();

/**
 * @name Man_Fuction
 * @brief 鐧诲綍鎴愬姛鍚庤繘鍏ョ鐞嗗憳椤甸潰
 * @param  M
 * @return Status 
 */
Status Man_Fuction(Manager &M);

/**
 * @name Man_ManageAccount
 * @brief 绠＄悊璐﹀彿鍔熻兘
 * @param   M root
 * @return  Status
 */
Status Man_ManageAccount(Manager M,RBRoot *root);

/**
 * @name Man_Grounding
 * @brief  涓婃灦涔︾睄
 * @param   M root
 * @return  status
 */
Status Man_Grounding(Manager M,RBRoot *root);


/**
 * @name Man_OffShelf
 * @brief 涓嬫灦涔︾睄
 * @param   M root
 * @return  status
 */
Status Man_OffShelf(Manager M,RBRoot *root);

/**
 * @name Man_SearchBook
 * @brief  鎼滅储涔︾睄
 * @param   M root
 * @return  status
 */
Status Man_SearchBook(Manager M,RBRoot *root);

/**
 * @name Man_GetBookTree
 * @brief 鑾峰彇涔︾睄
 * @param  root
 * @return  Status
 */
Status Man_GetBookTree(RBRoot *root);

/**
 * @name Man_SearchMenu
 * @brief 绠＄悊鍛樻煡鎵惧姛鑳借彍锟??
 * @param   
 * @return 
 */
void Man_SearchMenu();

/**
 * @name Man_AccountMenu
 * @brief 璐﹀彿绠＄悊鑿滃崟
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
 * @brief 根据书名模糊搜索
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

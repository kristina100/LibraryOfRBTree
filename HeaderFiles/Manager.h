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

//����Ա�ṹ��
typedef struct manager{
    char name[10]; //����
    char account[10]; //�˺�
    char password[10];//����
    int power;
}manager, *Manager;

/**
 * @brief ��ʼ��Manager
 * 
 * @param man 
 * @return Status 
 */
Status Man_Init(Manager &M);

/**
 * @name Man_ChoiceMenu
 * @brief ��ӡ����Ա�˵�
 * @param   
 * @return  Status
 */
void Man_ChoiceMenu();

/**
 * @name Man_Fuction
 * @brief ��¼�ɹ���������Աҳ��
 * @param  M
 * @return Status 
 */
Status Man_Fuction(Manager &M);

/**
 * @name Man_ManageAccount
 * @brief �����˺Ź���
 * @param   M root
 * @return  Status
 */
Status Man_ManageAccount(Manager M,RBRoot *root);

/**
 * @name Man_Grounding
 * @brief  �ϼ��鼮
 * @param   M root
 * @return  status
 */
Status Man_Grounding(Manager M,RBRoot *root);


/**
 * @name Man_OffShelf
 * @brief �¼��鼮
 * @param   M root
 * @return  status
 */
Status Man_OffShelf(Manager M,RBRoot *root);

/**
 * @name Man_SearchBook
 * @brief  �����鼮
 * @param   M root
 * @return  status
 */
Status Man_SearchBook(Manager M,RBRoot *root);

/**
 * @name Man_GetBookTree
 * @brief ��ȡ�鼮(���ļ���ȡ��)
 * @param  root
 * @return  Status
 */
Status Man_GetBookTree(RBRoot *root);

/**
 * @name Man_SearchMenu
 * @brief ����Ա���ҹ���
 * @param   
 * @return 
 */
void Man_SearchMenu();

/**
 * @name Man_AccountMenu
 * @brief �˺Ź���˵�
 * @param   
 * @return 
 */
void Man_AccountMenu();

/**
 * @name SearchByName
 * @brief ��������׼ȷ����
 * @param  root
 * @param  name
 * @return  RBTreeElemType
 */
RBTreeElemType SearchByName(RBRoot *root);

/**
 * @name SearchBookByAuthor
 * @brief ��������׼ȷ����
 * @param  root
 * @param  author
 * @return  RBTreeElemType
 */
RBTreeElemType SearchBookByAuthor(RBRoot *root);

/**
 * @name FuzzySearchByName
 * @brief ������ģ������
 * @param  root
 * @return  status
 */
MyBook FuzzySearchByName(RBRoot *root);

/**
 * @name RBT_FuzzySearchByName
 * @brief ������ģ������
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

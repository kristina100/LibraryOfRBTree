/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 14:33:25
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-01 23:41:44
 */
#ifndef STUDENT_H_INCLUDE
#define STUDENT_H_INCLUDE
#include"Common.h"
#include"RedBlackTree.h"

//�鱾�ṹ��
typedef struct mybook{
    RBTreeElemType book; //
    struct mybook *next; //��һ��
}mybook,*MyBook;

//ѧ���ṹ��
typedef struct student{
    char name[10]; //����
    char account[10];  //�˺�
    char ID[11];   //ѧ��
    char password[10];//����
    MyBook mybook;    //��
    int power;  //Ȩ��
    struct student *next;   //��һ��ѧ��
}student, *Stu;

/**
 * @brief ��ʼ��Stu
 * 
 * @param stu 
 * @return Status 
 */
Status Stu_Init(Stu &stu);

/**
 * @brief ѧ������
 * 
 */
void Stu_Operation(Stu &stu);

/**
 * @brief ��ӡѧ��ѡ��
 * 
 */
void Stu_Options(Stu stu);

/**
 * @brief ����
 * 
 * @param stu 
 * @param root 
 */
void Stu_Borrow(Stu stu, RBRoot *root);

/**
 * @brief 瀛︾敓杩樹功
 * 
 * @param stu 
 * @param root 
 * @return Status 
 */
Status Stu_return(Stu &stu, RBRoot *root);

/**
 * @brief 鎵撳嵃鎴戠殑淇℃�?
 * 
 * @param stu 
 */
void Stu_Print_MyInfo(Stu stu);

/**
 * @brief 鎵惧洖瀵嗙�?
 * 
 * @param stu 
 * @return Status 
 */
Status Stu_FindPassword(Stu stu);

/**
 * @brief 鏇存敼瀵嗙�?
 * 
 * @return Status 
 */
Status Stu_ChangePassword(Stu stu);

/**
 * @brief 鎵撳嵃宸插€熺殑涔�
 * 
 * @param b 
 */
void Print_Book(MyBook b);

/**
 * @brief 鏌ユ壘涔︽湰
 * 
 * @param root 
 */
void Stu_SearchBook(RBRoot *root);

/**
 * @brief 鎵撳嵃鏌ヨ閫夐�?
 * 
 */
void Print_Search_Options();

/**
 * @brief 鎵撳嵃鍊熶功閫夐�?
 * 
 */
void Print_Borrow_Options();

/**
 * @brief 
 * 
 * @param stu 
 * @param b 
 * @return Status 
 */
Status Stu_AddBook(Stu &stu, RBTreeElemType b);

#endif  //STUDENT_H_INCLUDE
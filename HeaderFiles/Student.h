/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 14:33:25
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-02 01:25:39
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
void Stu_Options();

/**
 * @brief ����
 * 
 * @param stu 
 * @param root 
 */
void Stu_Borrow(Stu stu, RBRoot *root);

/**
 * @brief ѧ������
 * 
 * @param stu 
 * @param root 
 * @return Status 
 */
Status Stu_return(Stu &stu, RBRoot *root);

/**
 * @brief ��ӡ�ҵ���Ϣ
 * 
 * @param stu 
 */
void Stu_Print_MyInfo(Stu stu);

/**
 * @brief �һ�����
 * 
 * @param stu 
 * @return Status 
 */
Status Stu_FindPassword(Stu stu);

/**
 * @brief �޸�����
 * 
 * @return Status 
 */
Status Stu_ChangePassword(Stu stu);

/**
 * @brief ��ӡ�鱾
 * 
 * @param b 
 */
void Print_Book(MyBook b);

/**
 * @brief �����鱾
 * 
 * @param root 
 */
void Stu_SearchBook(RBRoot *root);

/**
 * @brief ����ISBN�����鱾
 * 
 * @param root 
 */
void Stu_SearchBookByISBN(RBRoot *root);

/**
 * @brief ������������
 * 
 * @param node 
 * @param name 
 * @param books 
 */
void Stu_SearchBookByTitle(RBTree node, char *name, MyBook &books);

/**
 * @brief ��ӡ��ѯѡ��
 * 
 */
void Print_Search_Options();

/**
 * @brief ��ӡ����ѡ��
 * 
 */
void Print_Borrow_Options();

/**
 * @brief ��ѧ���˻������һ���飬����������Ϊ�ѽ��״̬
 * 
 * @param stu 
 * @param b 
 * @return Status 
 */
Status Stu_AddBook(Stu &stu, RBTreeElemType b);

#endif  //STUDENT_H_INCLUDE
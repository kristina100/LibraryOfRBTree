/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 14:33:25
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-03 22:26:24
 */
#ifndef STUDENT_H_INCLUDE
#define STUDENT_H_INCLUDE
#include"Common.h"
#include"RedBlackTree.h"

//�鱾���ݽṹ��
typedef struct mybook{
    RBTreeElemType book; //�洢����
    struct mybook *next; //��һ��
}mybook,*MyBook;

//ѧ���ṹ��
typedef struct student{
    char name[10]; //����
    char account[15];  //�˺�
    char ID[11];   //ѧ��
    char password[15];//����
    MyBook mybook;    //��
    int power;  //Ȩ��
    int bookNum; //�������
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
 * @param stu 
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
void Stu_Borrow(Stu &stu, RBRoot *root);

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
 * @brief ��������ģ������
 * 
 * @param node 
 * @param name 
 * @param books 
 */
void Stu_SearchBookByTitle(RBTree node, char *name, MyBook &books);

/**
 * @brief ��������ģ������
 * 
 * @param node 
 * @param author 
 * @param books 
 */
void Stu_SearchBookByAuthor(RBTree node, char *author, MyBook &books);

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
 * @brief ��ѧ���˻������һ����
 * 
 * @param stu 
 * @param b 
 * @return Status 
 */
Status Stu_AddBook(Stu &stu, RBTreeElemType b);

/**
 * @brief ��ȡѧ����Ϣ����������
 * 
 * @return Stu 
 */
Stu Stu_ReadData();

/**
 * @brief ��ʽ��д��ѧ���ļ�
 * 
 * @param stu 
 * @return Status 
 */
Status Stu_WriteData(Stu stu);

#endif  //STUDENT_H_INCLUDE
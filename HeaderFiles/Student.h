/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 14:33:25
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-29 11:26:12
 */
#ifndef STUDENT_H_INCLUDE
#define STUDENT_H_INCLUDE
#include"Common.h"
#include"RedBlackTree.h"

//鎴戠殑涔�
typedef struct mybook{
    RBTreeElemType book;//鍊熺殑涔�
    struct mybook *next;//涓嬩竴鏈功
}mybook,*MyBook;

//瀛︾敓缁撴瀯浣�
typedef struct student{
    char name[10]; //瀛︾敓濮撳悕
    char account[10];  //璐﹀彿
    char ID[11];   //瀛﹀彿
    char password[10];//瀵嗙爜
    MyBook mybook;    //鎴戝€熺殑涔�
    int power;  //瀛︾敓鏉冨姏
    struct student *next;//鎸囧悜涓嬩竴涓鐢�
}student, *Stu;

/**
 * @brief 鍒濆鍖朣tu
 * 
 * @param stu 
 * @return Status 
 */
Status Stu_Init(Stu &stu);

/**
 * @brief 瀛︾敓鎿嶄綔
 * 
 */
void Stu_Operation(Stu &stu);

/**
 * @brief 鎵撳嵃瀛︾敓閫夐」
 * 
 */
void Stu_Options();

/**
 * @brief 瀛︾敓鍊熶功
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
 * @brief 鎵撳嵃鎴戠殑淇℃伅
 * 
 * @param stu 
 */
void Stu_Print_MyInfo(Stu stu);

/**
 * @brief 鎵惧洖瀵嗙爜
 * 
 * @param stu 
 * @return Status 
 */
Status Stu_FindPassword(Stu stu);

/**
 * @brief 鏇存敼瀵嗙爜
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
 * @brief 鎵撳嵃鏌ヨ閫夐」
 * 
 */
void Print_Search_Options();

/**
 * @brief 鎵撳嵃鍊熶功閫夐」
 * 
 */
void Print_Borrow_Options();

/**
 * @brief 鍚戝鐢熻处鎴蜂笂娣诲姞涓€鏈功锛屽苟灏嗕功璁剧疆涓哄凡鍊熷嚭鐘舵€�
 * 
 * @param stu 
 * @param b 
 * @return Status 
 */
Status Stu_AddBook(Stu &stu, RBTreeElemType b);

#endif  //STUDENT_H_INCLUDE
/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-24 21:49:11
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-02 22:30:51
 */
#include"Common.h"
#include"HeaderFiles/RedBlackTree.h"
#include"HeaderFiles/RedBlackTreeUtils.h"
#include"HeaderFiles/BinarySearchTree.h"
#include"HeaderFiles/Utils.h"
#include"Login.h"

int main(){

    // Stu stu = NULL;
    // Stu_Init(stu);
    
    // strcpy(stu->account, "test");
    // strcpy(stu->ID, "3120004969");
    // strcpy(stu->name, "Hx");
    // strcpy(stu->password, "123456");
    // stu->power = 0;
    // stu->next = NULL;
    // stu->mybook = NULL;

    // RBTreeElemType e1 = NULL;
    // RBTreeElemType e2 = NULL;
    // InitRBTElem(e1);
    // InitRBTElem(e2);


    // strcpy(e1->Title, "TheGivingTree");
    // strcpy(e1->Author, "ShelSilverstein");
    // strcpy(e1->score, "¶¹°ê9.5·Ö");
    // strcpy(e1->press, "Harper&Row");
    // e1->elem = 9878786926581;
    
    // strcpy(e2->Title, "Charlotte'sWeb");
    // strcpy(e2->Author, "None");
    // strcpy(e2->score, "¶¹°ê8.5·Ö");
    // strcpy(e2->press, "HarperCollins");
    
    // e2->elem = 9878376497823;
    // Stu_AddBook(stu, e1);
    // Stu_AddBook(stu, e2);

    // Stu_WriteData(stu);
    // Stu res = Stu_ReadData();
    // Print_Book(res->mybook);

    // Stu_Operation(stu);
    Login_Operation();
    Pause();
    return 1;
}
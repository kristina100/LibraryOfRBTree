/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-24 21:49:11
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-27 00:26:42
 */
#include"Common.h"
#include"HeaderFiles/RedBlackTree.h"
#include"HeaderFiles/RedBlackTreeUtils.h"
#include"HeaderFiles/BinarySearchTree.h"
#include"HeaderFiles/Utils.h"
#include"Login.h"

int main(){

    Stu stu = (Stu)malloc(sizeof(student));
    
    strcpy(stu->account, "test");
    strcpy(stu->ID, "3120004969");
    strcpy(stu->name, "Hx");
    strcpy(stu->password, "123456");
    stu->power = 0;
    Stu_Operation(stu);

    return 1;
}
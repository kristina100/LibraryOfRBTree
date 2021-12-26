/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-22 12:54:10
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-26 22:40:19
 */
#include"Utils.h"

/**
 * @brief 暂停
 */
void Pause(){
   system("pause");
}

/**
 * @brief 清空屏幕
 */
void Clean(){
   system("cls");
}

/**
 * @brief 打印书本信息
 */
void Print_BookInfo(RBTreeElemType e){
   printf("<书本信息>\n");
   printf("ISBN: %d\n", e->elem);
   printf("书名: %s\n", e->Title);
   printf("作者: %s\n", e->Author);
   printf("出版社: %s\n", e->press);
   printf("评分: %s\n", e->score);
   printf("书本状态:");
   if(e->status == 1)
      printf("书本未借出\n");
   else
      printf("书本已借出\n");
}
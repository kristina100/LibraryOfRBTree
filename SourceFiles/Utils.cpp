/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-22 12:54:10
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-26 22:40:19
 */
#include"Utils.h"

/**
 * @brief ��ͣ
 */
void Pause(){
   system("pause");
}

/**
 * @brief �����Ļ
 */
void Clean(){
   system("cls");
}

/**
 * @brief ��ӡ�鱾��Ϣ
 */
void Print_BookInfo(RBTreeElemType e){
   printf("<�鱾��Ϣ>\n");
   printf("ISBN: %d\n", e->elem);
   printf("����: %s\n", e->Title);
   printf("����: %s\n", e->Author);
   printf("������: %s\n", e->press);
   printf("����: %s\n", e->score);
   printf("�鱾״̬:");
   if(e->status == 1)
      printf("�鱾δ���\n");
   else
      printf("�鱾�ѽ��\n");
}
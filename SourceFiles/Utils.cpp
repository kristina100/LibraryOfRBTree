/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-22 12:54:10
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-27 00:23:06
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

/**
 * 检测用户整数输入
 *
 * @param[in]  none
 * @return  legal integer
 */
int InputInteger()
{
    /* store converted numbers */
    int integer;
    /* flag status */
    int  status;
    /* receive string */
    char str[100];

    do {
        scanf("%s", str);
        status = TRUE;
        int i;
        for (i = 0; str[i] != '\0'; i++) {
            /* check for illegal characters */
            if (i == 0) {
                if (str[i] == '-' || str[i] == '+') continue;
            } else {
                if (str[i] < '0' || str[i] > '9') status = FALSE;
            }
        }
        if (status == FALSE) {
            printf("Input illegally, please re-enter:");
            continue;
        } else {
            /* Convert string to number */
            for (i = 0, integer = 0; str[i] != '\0'; i++) {
                if (i == 0) {
                    if (str[i] == '-' || str[i] == '+') continue;
                    else {
                        integer *= 10;
                        integer += (str[i] - 48);
                    }
                } else {
                    integer *= 10;
                    integer += (str[i] - 48);
                }
            }
            if (str[0] == '-') integer = -integer;

            /* check if the number entered is out of bounds */
            if (i >= 10) {
                printf("Overflow, please re-enter:");
                status = FALSE;
            }
        }
    } while (status == FALSE);

    return integer;
}



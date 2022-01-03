/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-22 12:54:10
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-03 02:29:01
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
    Clean();
    printf("\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("                              <Book Info>                                  \n\n");
    printf("\tTitle: %s\n", e->Title);
    printf("\tISBN: %lld\n", e->elem);
    printf("\tAuthor: %s\n", e->Author);
    printf("\tPress: %s\n", e->press);
    printf("\tScore: %s\n", e->score);
    printf("\tStatus: ");
    if(e->status == 1)
        printf("Book Available\n");
    else
        printf("Book Unavailable\n");
    printf("*-------------------------------------------------------------------------*\n");     
}

/**
 * 检测用户整数输入
 *
 * @param[in]  none
 * @return  legal integer
 */
long long int InputInteger()
{
    /* store converted numbers */
    long long int integer;
    /* flag status */
    int  status;
    /* receive string */
    char str[100] = "";

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
            if (i >= 20) {
                printf("Overflow, please re-enter:");
                status = FALSE;
            }
        }
    } while (status == FALSE);

    return integer;
}



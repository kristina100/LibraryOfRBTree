/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-22 12:54:10
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-27 00:23:06
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

/**
 * ����û���������
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



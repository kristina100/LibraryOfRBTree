/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 14:33:31
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-25 21:33:53
 */
#include"Student.h"
#include"Utils.h"


/**
 * @brief ��ʼ��Stu
 */
Status Stu_Init(Stu &stu){

    stu = (Stu)malloc(sizeof(student));
    if(stu == NULL) return OVERFLOW;
    stu->book = NULL;
    stu->power = 0;

    return SUCCESS;
}

/**
 * @brief ��ӡѧ��ѡ��
 */
void Stu_Options(){
        Clean();
        printf("\n\n\n\n*-----------------------------------------------------------------*\n");
        printf("                            <ѧ��ѡ��>                                     \n");
        printf("                                                                          \n");
        printf("                                                                          \n");
        printf("           1.��ѯ�鼮                       2.�����鼮                     \n");
        printf("                                                                          \n");
        printf("           3.�黹�鼮                       4.������Ϣ                     \n");
        printf("                                                                          \n");
        printf("           0.����                                                         \n");
        printf("                                                                          \n");
        printf("*-------------------------------------------------------------------------*\n");
        printf("*-------------------------------------------------------------------------*\n");
        
        printf("\n\t\t");
        printf("��ѡ��: ");                      
}

/**
 * @brief ѧ������
 */
void Stu_Operation(Stu &stu){

    //ѭ��������־
    int flag = 1;
    //ѡ��
    int choose;
    
    while (flag){
        Stu_Options();
        scanf("%d", &choose);
     
        switch (choose){
            
            //������һ��
            case 0:{
                return;
            }break;

            //����
            case 1:{
                
            }break;

            default:{
                printf("\n����������\n");
                Pause();
            }break;
        }
    Clean();
    }
}

/**
 * @brief ����
 */
Status Stu_Borrow(){
    return SUCCESS;
}

/**
 * @brief ����
 */
Status Stu_return(){
    return SUCCESS;
}

/**
 * @brief �鿴��Ϣ
 */
void Stu_MyInfo(){

}

/**
 * @brief �һ�����
 */
Status Stu_FindPassword(){
    return SUCCESS;
}

/**
 * @brief ��������
 */
Status Stu_ChangePassword(){
    return SUCCESS;
}
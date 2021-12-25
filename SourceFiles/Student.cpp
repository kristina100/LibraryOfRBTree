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
 * @brief 初始化Stu
 */
Status Stu_Init(Stu &stu){

    stu = (Stu)malloc(sizeof(student));
    if(stu == NULL) return OVERFLOW;
    stu->book = NULL;
    stu->power = 0;

    return SUCCESS;
}

/**
 * @brief 打印学生选项
 */
void Stu_Options(){
        Clean();
        printf("\n\n\n\n*-----------------------------------------------------------------*\n");
        printf("                            <学生选项>                                     \n");
        printf("                                                                          \n");
        printf("                                                                          \n");
        printf("           1.查询书籍                       2.借阅书籍                     \n");
        printf("                                                                          \n");
        printf("           3.归还书籍                       4.个人信息                     \n");
        printf("                                                                          \n");
        printf("           0.返回                                                         \n");
        printf("                                                                          \n");
        printf("*-------------------------------------------------------------------------*\n");
        printf("*-------------------------------------------------------------------------*\n");
        
        printf("\n\t\t");
        printf("请选择: ");                      
}

/**
 * @brief 学生操作
 */
void Stu_Operation(Stu &stu){

    //循环操作标志
    int flag = 1;
    //选择
    int choose;
    
    while (flag){
        Stu_Options();
        scanf("%d", &choose);
     
        switch (choose){
            
            //返回上一级
            case 0:{
                return;
            }break;

            //借书
            case 1:{
                
            }break;

            default:{
                printf("\n操作不存在\n");
                Pause();
            }break;
        }
    Clean();
    }
}

/**
 * @brief 借书
 */
Status Stu_Borrow(){
    return SUCCESS;
}

/**
 * @brief 还书
 */
Status Stu_return(){
    return SUCCESS;
}

/**
 * @brief 查看信息
 */
void Stu_MyInfo(){

}

/**
 * @brief 找回密码
 */
Status Stu_FindPassword(){
    return SUCCESS;
}

/**
 * @brief 更改密码
 */
Status Stu_ChangePassword(){
    return SUCCESS;
}
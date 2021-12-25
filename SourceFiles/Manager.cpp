/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 17:37:27
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-24 20:17:10
 */

#include"Manager.h"

/**
 * @brief 初始化Manager
 */
Status Man_Init(Manager &M){
    M = (Manager)malloc(sizeof(manager));
    if(M == NULL) return OVERFLOW;
    M->power = 0;
    return SUCCESS;
}
Status Man_Init(Manager &M);

/**
 * @name Man_ChoiceMenu
 * @brief 打印管理员菜单
 * @param   
 * @return  Status
 */
Status Man_ChoiceMenu(){
    return SUCCESS;
}

/**
 * @name Man_Fuction
 * @brief 登录成功后进入管理员页面
 * @param  M
 * @return Status 
 * 
 */
Status Man_Fuction(Manager &M){
    return SUCCESS;
}

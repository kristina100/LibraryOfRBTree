/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 17:37:21
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-24 20:14:20
 */
#ifndef MANAGER_H_INCLUDE
#define MANAGER_H_INCLUDE
#include"Common.h"

//管理员结构体
typedef struct manager{
    char name[10]; //管理员姓名
    char account[10]; //账号
    char password[10];//密码
    int power;
}manager, *Manager;

/**
 * @brief 初始化Manager
 * 
 * @param man 
 * @return Status 
 */
Status Man_Init(Manager &M);

/**
 * @name Man_ChoiceMenu
 * @brief 打印管理员菜单
 * @param   
 * @return  Status
 */
Status Man_ChoiceMenu();

/**
 * @name Man_Fuction
 * @brief 登录成功后进入管理员页面
 * @param  M
 * @return Status 
 */
Status Man_Fuction(Manager &M);

#endif  //MANAGER_H_INCLUDE

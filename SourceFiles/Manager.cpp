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
void Man_ChoiceMenu(){
        printf("\n\n\n\n*-----------------------------------------------------------------------*\n");
        printf("|  Welcome to MangerFuction ~  Some operations on it ~                    |\n");
        printf("|                                                                         |\n");
        printf("|                                                                         |\n");
        printf("|    1.mamager                       2.put book                           |\n");
        printf("|                                                                         |\n");
        printf("|    3.get off book                  4.search book                        |\n");
        printf("|                                                                         |\n");
        printf("|    5.exchange id                   6.Quit System                        |\n");
        printf("|                                                                         |\n");
        printf("*-------------------------------------------------------------------------*\n");
        printf("*-------------------------------------------------------------------------*\n");
}

/**
 * @name Man_Fuction
 * @brief 登录成功后进入管理员页面
 * @param  M
 * @return Status 
 * 
 */
Status Man_Fuction(Manager &M){
	RBRoot *root;
	root = createRBTree();
    int choice=-1;
    do {
		Man_ChoiceMenu();
		//choice = InputInteger();
        scanf("%d",&choice);
		switch (choice) {
		case 1://管理账号
		{
			
			break;
		}
		case 2://上架书籍
		{

			break;
		}
		case 3://下架书籍
		{
			break;
		}
		case 4:
		{

			break;
		}
		case 5://退出 返回上一级
		{
            return SUCCESS;
			break;
		}
		default:printf("输入有误，请重新输入!（0-10）");
		}
	} while (choice!=5);
    return SUCCESS;   
}
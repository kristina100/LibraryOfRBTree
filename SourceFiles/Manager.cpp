/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 17:37:27
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-24 20:17:10
 */

#include"Manager.h"
#include"Utils.h"

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
	//创建空树
	RBRoot *root;
	root = createRBTree();
    //初始化书本树
	Man_GetBookTree(root);
	int choice=-1;
    do {
		Man_ChoiceMenu();
		//choice = InputInteger();
        scanf("%d",&choice);
		switch (choice) {
		case 1://管理账号
		{
			Man_ManageAccount(M,root);
			break;
		}
		case 2://上架书籍
		{
			Man_Grounding(M,root);
			break;
		}
		case 3://下架书籍
		{
			Man_OffShelf(M,root);
			break;
		}
		case 4://查找书籍
		{
			Man_SearchBook(M,root);
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

/**
 * @name Man_ManageAccount
 * @brief 管理账号功能
 * @param   M root
 * @return  Status
 */
Status Man_ManageAccount(Manager M,RBRoot *root){
	return SUCCESS;
}

/**
 * @name Man_Grounding
 * @brief  上架书籍
 * @param   M root
 * @return  status
 */
Status Man_Grounding(Manager M,RBRoot *root){
	int saveFile;
	RBTreeElemType insert_x = NULL;
    inputRBTElem(insert_x);
    Status insert_status;
    double cost;
    printf("Please enter the node you want to insert:");
    insert_x->elem = InputInteger();
    insert_status = insertRBTree(root, insert_x);
    if (insert_status == SUCCESS) {
        printf("Insert node successfully!\nDelete time consuming: %lf ms.\n", cost);
        // 文件尚未存盘
        saveFile = 1;
    }
    else
        printf("Insert node failed, the node already exists!\n");
	return SUCCESS;
}


/**
 * @name Man_OffShelf
 * @brief 下架书籍
 * @param   M root
 * @return  status
 */
Status Man_OffShelf(Manager M,RBRoot *root){
	return SUCCESS;
}

/**
 * @name Man_SearchBook
 * @brief  搜索书籍
 * @param   M root
 * @return  status
 */
Status Man_SearchBook(Manager M,RBRoot *root){
	return SUCCESS;
}

/**
 * @name Man_GetBookTree
 * @brief 获取书籍(从文件读取树)
 * @param  root
 * @return  Status
 */
Status Man_GetBookTree(RBRoot *root){
	FILE_ReadRBT(root);
	return SUCCESS;
}
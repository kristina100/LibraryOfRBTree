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
    printf("\n*-----------------------------------------------------------------------*\n");
    printf("|         Welcome to MangerFuction !  Some operations on it               |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|           1.mamager                     2.put book                      |\n");
    printf("|                                                                         |\n");
    printf("|           3.get off book                4.search book                   |\n");
    printf("|                                                                         |\n");
    printf("|           5.exchange id                 6.Quit System                   |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("*-------------------------------------------------------------------------*\n");
	return;
}

/**
 * @name Man_SearchMenu
 * @brief 管理员查找功能
 * @param  root 
 * @return  Status
 */
void Man_SearchMenu(){
	printf("\n*-----------------------------------------------------------------------*\n");
    printf("|       Welcome to MangerSearchingFuction !  Some operations on it        |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|       1.Search By the ISBN of book     2.Search By the name of book     |\n");
    printf("|                                                                         |\n");
    printf("|       3.Search By the author of book   4.Return to the previous level   |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("*-------------------------------------------------------------------------*\n");
	return;
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
	//Man_GetBookTree(root);
	int choice=-1;
    do {
		Man_ChoiceMenu();
		//打印测试
		recessedPrintRBTree(root->node, 0);
		printRBTree(root);
        choice = InputInteger();
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
		case 6://退出 返回上一级
		{
            return SUCCESS;
			break;
		}
		default:printf("输入有误，请重新输入!（0-10）");
		}
	} while (choice!=6);
	//返回上一级后保存图书信息--把树存到文件里面
	FILE_WriteRBT(*root);
    printf("\n");
	//保存后删除树
	destroyRBTree(root);
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
	RBTreeElemType insert_x = NULL;
    inputRBTElem(insert_x);
    Status insert_status;
    printf("Please enter the ISBN of the book you want to input:");
    insert_x->elem = InputInteger();
    insert_status = insertRBTree(root, insert_x);
    if (insert_status == SUCCESS) {
        printf("Insert node successfully!\n");
    }
    else
        printf("Inputing failed, the book already exists!\n");
	return SUCCESS;
}


/**
 * @name Man_OffShelf
 * @brief 下架书籍
 * @param   M root
 * @return  status
 */
Status Man_OffShelf(Manager M,RBRoot *root){
	RBTreeElemType delete_x=(RBTreeElemType)malloc(sizeof(RBTElem));
    printf("Please enter the ISBN of the Book you want to get off self:");
	delete_x->elem = InputInteger();
    if (deleteRBTree(root, delete_x) == SUCCESS)
        printf("Get off book successfully ~ \n");
    else
        printf("Failed to get off book, no book exists!\n");
	free(delete_x);
	return SUCCESS;
}

/**
 * @name Man_SearchBook
 * @brief  搜索书籍
 * @param   M root
 * @return  status
 */
Status Man_SearchBook(Manager M,RBRoot *root){
	int choice=-1;
    do {
		Man_SearchMenu();
		//打印测试
		recessedPrintRBTree(root->node, 0);
		printRBTree(root);
        choice = InputInteger();
		switch (choice) {
		case 1://按ISBN搜索
		{
			RBTreeElemType search_x=(RBTreeElemType)malloc(sizeof(RBTElem));
            RBTree targe,first;
			//RBTreeElemType search_x=(RBTreeElemType)malloc(sizeof(RBTElem));
            printf("Please enter the ISBN of book you want to search:");
            search_x->elem = InputInteger();
			targe =recursiveSearchNode(root->node, search_x);
            if (targe!=NULL){
                printf("\nThe information in the book is as follows:\n");
                PrintBookInfo(targe->data);
			}else
                printf("Failed to search, no book exists!\n");		
			break;
		}
		case 2://按书名搜索
		{
			Man_Grounding(M,root);
			break;
		}
		case 3://按作者搜索
		{
			Man_OffShelf(M,root);
			break;
		}
		case 4://退出 返回上一级
		{
            return SUCCESS;
			break;
		}
		default:printf("输入有误，请重新输入!（1-4）");
		}
	} while (choice!=4);
	return SUCCESS;
}

/**
 * @name Man_GetBookTree
 * @brief 获取书籍(从文件读取树)
 * @param  root
 * @return  Status
 */
Status Man_GetBookTree(RBRoot *root){
	return FILE_ReadRBT(root);
}



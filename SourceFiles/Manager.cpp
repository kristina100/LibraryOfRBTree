/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 17:37:27
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-27 00:30:38
 */

#include"Manager.h"
#include"Login.h"
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
    printf("\n*-------------------------------------------------------------------------*\n");
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
	printf("\n*-------------------------------------------------------------------------*\n");
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
 * @name Man_AccountMenu
 * @brief 账号管理菜单
 * @param   
 * @return 
 */
void Man_AccountMenu(){
	printf("\n*-------------------------------------------------------------------------*\n");
    printf("|         Welcome to MangerAccountFuction !  Some operations on it        |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|         1.get the information              2.change password            |\n");
    printf("|                                                                         |\n");
    printf("|         3.change power level               4.change books               |\n");
    printf("|                                                                         |\n");
	printf("|         5.change name                      0.back                       |\n");
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
			if(Man_ManageAccount(M,root)!=SUCCESS)
				printf("管理账号失败!\n");
			break;
		}
		case 2://上架书籍
		{
			if(Man_Grounding(M,root)!=SUCCESS)
				printf("上架书籍失败!\n");
			break;
		}
		case 3://下架书籍
		{
			if(Man_OffShelf(M,root)!=SUCCESS)
				printf("下架书籍失败!\n");
			break;
		}
		case 4://查找书籍
		{
			if(Man_SearchBook(M,root)!=SUCCESS)
				printf("查找书籍失败!\n");
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
    //读取学生文件
	FILE *fp = NULL;
    char stu_ID[11];
    Stu stu = NULL;
    Stu_Init(stu);

    //输入学生账号
	printf("Please enter the ID of the student you want to manage:\n");
    scanf("%s",&stu_ID);

    //打开文件
    fp = fopen("Students.dat", "rb");
    
    //在数据文件中查找账号
    while(fread(stu, sizeof(student), 1, fp)){
        if(strcmp(stu_ID, stu->ID) == 0)
            //账号相同找到对应学生
			fclose(fp);
    }
    fclose(fp);

	int choice=-1;
    do {
		Man_AccountMenu();
		//打印测试
		recessedPrintRBTree(root->node, 0);
		printRBTree(root);
        choice = InputInteger();
		switch (choice) {
		case 1://获取信息
		{
			//打印学生信息
			printf("\tID: %s ", stu->ID);
			printf("\tName: %s ", stu->name);
			printf("\tPower: %d ", stu->power);
    		printf("\t\tAccount: %s \n", stu->account);
    		Print_Book(stu->mybook);
			break;
		}
		case 2://修改密码
		{
			char new_password[10];
			printf("Please enter the new password:\n");
			scanf("%s",&new_password);
            if(stu!=NULL) {
				strcpy(stu->password,new_password);
				Updata_StuInfo(stu);
				printf("Change password successfully!");
			}else{
				printf("Change password faile!");
			}
			break;
		}
		case 3://修改权力
		{
			int power;
			printf("Please enter the new power:\n");
			scanf("%d",&power);
            if(stu!=NULL) {
				stu->power=power;
				Updata_StuInfo(stu);
				printf("Change power successfully!");	
			}else{
				printf("Change power faile!");
			}
			break;
		}
		case 4://修改已借的书
		{

            return SUCCESS;
			break;
		}
		case 5://修改姓名
		{
            char new_name[10];
			printf("Please enter the new name:\n");
			scanf("%s",&new_name);
            if(stu!=NULL) {
				strcpy(stu->name,new_name);
				Updata_StuInfo(stu);
				printf("Change name successfully!");
			}else{
				printf("Change name faile!");
			}
			break;
		}
		case 0://退出
		{
            return SUCCESS;
			break;
		}
		default:printf("输入有误，请重新输入!（0-5）");
		}
	} while (choice!=0);
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
                // PrintBookInfo(targe->data);
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



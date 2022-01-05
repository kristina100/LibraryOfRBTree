/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 17:37:27
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-05 17:14:26
 */

#include"Manager.h"
#include"Login.h"
#include"Utils.h"
#include"EscapeRote.h"

/**
 * @brief 初始化Manager
 */
Status Man_Init(Manager &M){
    M = (Manager)malloc(sizeof(manager));
    if(M == NULL) return OVERFLOW;
    M->power = 0;
    return SUCCESS;
}

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
    printf("|           1.manager                     2.put book                      |\n");
    printf("|                                                                         |\n");
    printf("|           3.get off book                4.search book                   |\n");
    printf("|                                                                         |\n");
    printf("|           5.Show escape rote            0.back                          |\n");
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
    printf("|       3.Search By the author of book   4.Fuzzy search by the name       |\n");
    printf("|                                                                         |\n");
    printf("|                 0.Return to the previous level                          |\n");
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
    printf("|         3.change power level               4.Set book return            |\n");
    printf("|                                                                         |\n");
	printf("|         5.change name                      6.Set borrowing              |\n");
    printf("|                                                                         |\n");
	printf("|                    0.Return to the previous level                       |\n");
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);//黄色
	//创建空树
	RBRoot *root = NULL;
	root = createRBTree();
    //初始化书本树
	Man_GetBookTree(root);
	int choice;
    do {
		Man_ChoiceMenu();
		//打印测试
		//recessedPrintRBTree(root->node, 0);
		//printRBTree(root);
        choice = InputInteger();
		switch (choice) {
		case 1://管理账号
		{
			if(Man_ManageAccount(M,root)==ERROR)
				printf("Account does not exist!\n");
			break;
		}
		case 2://上架书籍
		{
			if(Man_Grounding(M,root)!=SUCCESS)
				printf("Failed to put the book on the shelf!\n");
			break;
		}
		case 3://下架书籍
		{
			if(Man_OffShelf(M,root)!=SUCCESS)
				printf("Book off shelf failed!\n");
			break;
		}
		case 4://查找书籍
		{
			if(Man_SearchBook(M,root)!=SUCCESS)
				printf("Failed to query books!\n");
			break;
		}
		case 5://逃生路线
		{
            if(getEscapeRote()!=SUCCESS)
				printf("Failed to show escape rote!\n");
			break;
		}
		case 0://退出 返回上一级
		{
			//返回上一级后保存图书信息--把树存到文件里面
	        FILE_WriteRBT(*root);
            printf("\n");
	        //保存后删除树
	        destroyRBTree(root);
            return SUCCESS;
			break;
		}
		default:printf("输入有误，请重新输入!（0-10）");
		}
		Pause();
		Clean();
	} while (choice!=0);
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
	int flag=0;
    char stu_ID[11];
    Stu stu = NULL,allstu=NULL;
    Stu_Init(stu);

    //输入学生账号
	printf("Please enter the ID of the student you want to manage:\n");
    scanf("%s",&stu_ID);
    
	allstu = Stu_ReadData();

	stu=allstu;
    //在数据文件中查找学号
    while(stu){
        if(strcmp(stu_ID,stu->ID) == 0){
			//账号相同找到对应学生
			flag =1;
			break;
		}else stu=stu->next; 
    }

	if(!flag){//判断是否找到
		stu =NULL;
		return ERROR;
	}

	int choice=-1;
    do {
		Man_AccountMenu();
		//打印测试
		//recessedPrintRBTree(root->node, 0);
		//printRBTree(root);
        choice = InputInteger();
		switch (choice) {
		case 1://获取信息
		{
			if(!stu) break;
			//打印学生信息
			printf("\tID: %s ", stu->ID);
			printf("\tName: %s ", stu->name);
			printf("\t\tAccount: %s ", stu->account);
			printf("\tPower: %d\n ", stu->power);
			if(!stu->mybook) printf("Have no books!\n");
    		else Print_Book(stu->mybook);
			break;
		}
		case 2://修改密码
		{
			char new_password[10] ="";
			printf("Please enter the new password:\n");
			scanf("%s",new_password);
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
		case 4://设置新增还书
		{
			if(Stu_return(stu, root) == SUCCESS){
                printf("Return the book successfully!\n");
            }else{
				printf("Failed to return book!\n");
			}
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
		case 6://设置新增借书
		{
			Stu_Borrow(stu, root);	
			break;
		}
		case 0://退出
		{
            return SUCCESS;
			break;
		}
		default:printf("输入有误，请重新输入!（0-5）");
		}
		Pause();
		Clean();
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
    //printf("Please enter the ISBN of the book you want to input:");
    //insert_x->elem = InputInteger();
    insert_status = insertRBTree(root, insert_x);
    if (insert_status == SUCCESS) {
        printf("Input book successfully!\n");
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
	RBTreeElemType e1 = (RBTreeElemType)malloc(sizeof(RBTElem));
	RBTreeElemType e2 = (RBTreeElemType)malloc(sizeof(RBTElem));
	int choice=-1;
    do {
		Man_SearchMenu();
		//打印测试
		//recessedPrintRBTree(root->node, 0);
		//printRBTree(root);
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
			search_x = NULL;
			free(search_x);
		}
		case 2://按书名搜索
		{
			e1 = SearchByName(root);
			e1 = NULL;
			break;
		}
		case 3://按作者搜索
		{
			e2 = SearchBookByAuthor(root);
			e2 = NULL;
			break;
		}
		case 4://按书名模糊搜索
		{
			MyBook books,p=NULL;
			books=FuzzySearchByName(root);
			p = books;
			while (p)
			{
				books=p->next;
				free(p);
				p = books;
			}
			break;
		}
		case 0://退出 返回上一级
		{
			free(e1);
			free(e2);
            return SUCCESS;
			break;
		}
		default:printf("输入有误，请重新输入!（1-4）");
		}
		Pause();
		Clean();
	} while (choice!=0);
	free(e1);
	free(e2);
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

/**
 * @name SearchByName
 * @brief 根据书名准确搜索
 * @param  root
 * @param  name
 * @return  RBTreeElemType
 */
RBTreeElemType SearchByName(RBRoot *root){
	RBTreeElemType e =(RBTreeElemType)malloc(sizeof(RBTElem));
	char str[20] = "";
	printf("Please enter the title of the book you want to search:");
	scanf("%s", str);
	e = RBT_SearchByName(root->node,str);
	if(e){
		PrintBookInfo(e);
		return e;
	}else{
        printf("No book exists!Try again!\n");
		return NULL;
	}
}

/**
 * @name SearchBookByAuthor
 * @brief 根据作者准确搜索
 * @param  root
 * @param  author
 * @return  RBTreeElemType
 */
RBTreeElemType SearchBookByAuthor(RBRoot *root){
	RBTreeElemType e =(RBTreeElemType)malloc(sizeof(RBTElem));
	char str[20] = "";
	printf("Please enter the author of the book you want to search:");
	scanf("%s", str);
	e = RBT_SearchBookByAuthor(root->node,str);
	if(e){
		PrintBookInfo(e);
		return e;
	}else{
        printf("No book exists!Try again!\n");
		return NULL;
	}
	e=NULL;
	free(e);
}

/**
 * @name FuzzySearchByName
 * @brief 按书名模糊搜索
 * @param  root
 * @return  status
 */
MyBook FuzzySearchByName(RBRoot *root){
	MyBook books=(MyBook)malloc(sizeof(mybook));
	books->book=NULL;
	books->next=NULL;
	char str[20] = "";
	printf("Please enter the title of the book you want to search:");
	scanf("%s", str);
	RBT_FuzzySearchByName(root->node,str,books);
	if(books){
		Print_Book(books);
		return books;
	}else{
        printf("No book exists!Try again!\n");
		return ERROR;
	}
}

/**
 * @name RBT_FuzzySearchByName
 * @brief 根据书名模糊搜索
 * @param  root
 * @param  name
 * @return  status
 */
Status RBT_FuzzySearchByName(RBTree node,char *name,MyBook &books){
    if(node == NULL) return ERROR;
    if (strpbrk(name,node->data->Title)!=NULL) {
        MyBook newBook = (MyBook)malloc(sizeof(mybook));
        if(newBook == NULL)
            return OVERFLOW;
        
        if(books->book==NULL) {
            //have no book
            books->book = node->data;
        }else{
            //have
			newBook->book = node->data;
            newBook->next =NULL;
            newBook->next = books;
            books = newBook;
        }
    }
    RBT_FuzzySearchByName(node->left,name,books);
    RBT_FuzzySearchByName(node->right,name,books);
    return OVERFLOW;
}

/**
 * @name printBookInfo
 * @brief Print information about a Book
 * @param e  
 * @return Status 
 */
Status PrintBookInfo(RBTreeElemType e){
	if(NULL==e) return ERROR;
	printf("*------------------------------------------------------------------------*\n");
    printf("                          <Book Infomation>                               \n\n");
    printf("     ISBN     |    Title    |    Author   |   Press   |   Score   \n\n");

    //打印ISBN
    printf("%-15lld",e->elem);
    //打印书名
    printf("%-15s",e->Title);
    //打印作者
    printf("%-15s",e->Author);
    //打印出版社
    printf("%-15s",e->press);
	//打印评分
	printf("%-10s",e->score);
	return SUCCESS;
}
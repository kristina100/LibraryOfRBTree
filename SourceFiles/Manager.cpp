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
 * @brief ��ʼ��Manager
 */
Status Man_Init(Manager &M){
    M = (Manager)malloc(sizeof(manager));
    if(M == NULL) return OVERFLOW;
    M->power = 0;
    return SUCCESS;
}

/**
 * @name Man_ChoiceMenu
 * @brief ��ӡ����Ա�˵�
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
 * @brief ����Ա���ҹ���
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
 * @brief �˺Ź���˵�
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
 * @brief ��¼�ɹ���������Աҳ��
 * @param  M
 * @return Status 
 * 
 */
Status Man_Fuction(Manager &M){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);//��ɫ
	//��������
	RBRoot *root = NULL;
	root = createRBTree();
    //��ʼ���鱾��
	Man_GetBookTree(root);
	int choice;
    do {
		Man_ChoiceMenu();
		//��ӡ����
		//recessedPrintRBTree(root->node, 0);
		//printRBTree(root);
        choice = InputInteger();
		switch (choice) {
		case 1://�����˺�
		{
			if(Man_ManageAccount(M,root)==ERROR)
				printf("Account does not exist!\n");
			break;
		}
		case 2://�ϼ��鼮
		{
			if(Man_Grounding(M,root)!=SUCCESS)
				printf("Failed to put the book on the shelf!\n");
			break;
		}
		case 3://�¼��鼮
		{
			if(Man_OffShelf(M,root)!=SUCCESS)
				printf("Book off shelf failed!\n");
			break;
		}
		case 4://�����鼮
		{
			if(Man_SearchBook(M,root)!=SUCCESS)
				printf("Failed to query books!\n");
			break;
		}
		case 5://����·��
		{
            if(getEscapeRote()!=SUCCESS)
				printf("Failed to show escape rote!\n");
			break;
		}
		case 0://�˳� ������һ��
		{
			//������һ���󱣴�ͼ����Ϣ--�����浽�ļ�����
	        FILE_WriteRBT(*root);
            printf("\n");
	        //�����ɾ����
	        destroyRBTree(root);
            return SUCCESS;
			break;
		}
		default:printf("������������������!��0-10��");
		}
		Pause();
		Clean();
	} while (choice!=0);
	//������һ���󱣴�ͼ����Ϣ--�����浽�ļ�����
	FILE_WriteRBT(*root);
    printf("\n");
	//�����ɾ����
	destroyRBTree(root);
    return SUCCESS;   
}

/**
 * @name Man_ManageAccount
 * @brief �����˺Ź���
 * @param   M root
 * @return  Status
 */
Status Man_ManageAccount(Manager M,RBRoot *root){
    //��ȡѧ���ļ�
	int flag=0;
    char stu_ID[11];
    Stu stu = NULL,allstu=NULL;
    Stu_Init(stu);

    //����ѧ���˺�
	printf("Please enter the ID of the student you want to manage:\n");
    scanf("%s",&stu_ID);
    
	allstu = Stu_ReadData();

	stu=allstu;
    //�������ļ��в���ѧ��
    while(stu){
        if(strcmp(stu_ID,stu->ID) == 0){
			//�˺���ͬ�ҵ���Ӧѧ��
			flag =1;
			break;
		}else stu=stu->next; 
    }

	if(!flag){//�ж��Ƿ��ҵ�
		stu =NULL;
		return ERROR;
	}

	int choice=-1;
    do {
		Man_AccountMenu();
		//��ӡ����
		//recessedPrintRBTree(root->node, 0);
		//printRBTree(root);
        choice = InputInteger();
		switch (choice) {
		case 1://��ȡ��Ϣ
		{
			if(!stu) break;
			//��ӡѧ����Ϣ
			printf("\tID: %s ", stu->ID);
			printf("\tName: %s ", stu->name);
			printf("\t\tAccount: %s ", stu->account);
			printf("\tPower: %d\n ", stu->power);
			if(!stu->mybook) printf("Have no books!\n");
    		else Print_Book(stu->mybook);
			break;
		}
		case 2://�޸�����
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
		case 3://�޸�Ȩ��
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
		case 4://������������
		{
			if(Stu_return(stu, root) == SUCCESS){
                printf("Return the book successfully!\n");
            }else{
				printf("Failed to return book!\n");
			}
			break;
		}
		case 5://�޸�����
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
		case 6://������������
		{
			Stu_Borrow(stu, root);	
			break;
		}
		case 0://�˳�
		{
            return SUCCESS;
			break;
		}
		default:printf("������������������!��0-5��");
		}
		Pause();
		Clean();
	} while (choice!=0);
	
	return SUCCESS;
}

/**
 * @name Man_Grounding
 * @brief  �ϼ��鼮
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
 * @brief �¼��鼮
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
 * @brief  �����鼮
 * @param   M root
 * @return  status
 */
Status Man_SearchBook(Manager M,RBRoot *root){
	RBTreeElemType e1 = (RBTreeElemType)malloc(sizeof(RBTElem));
	RBTreeElemType e2 = (RBTreeElemType)malloc(sizeof(RBTElem));
	int choice=-1;
    do {
		Man_SearchMenu();
		//��ӡ����
		//recessedPrintRBTree(root->node, 0);
		//printRBTree(root);
        choice = InputInteger();
		switch (choice) {
		case 1://��ISBN����
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
		case 2://����������
		{
			e1 = SearchByName(root);
			e1 = NULL;
			break;
		}
		case 3://����������
		{
			e2 = SearchBookByAuthor(root);
			e2 = NULL;
			break;
		}
		case 4://������ģ������
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
		case 0://�˳� ������һ��
		{
			free(e1);
			free(e2);
            return SUCCESS;
			break;
		}
		default:printf("������������������!��1-4��");
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
 * @brief ��ȡ�鼮(���ļ���ȡ��)
 * @param  root
 * @return  Status
 */
Status Man_GetBookTree(RBRoot *root){
	return FILE_ReadRBT(root);
}

/**
 * @name SearchByName
 * @brief ��������׼ȷ����
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
 * @brief ��������׼ȷ����
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
 * @brief ������ģ������
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
 * @brief ��������ģ������
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

    //��ӡISBN
    printf("%-15lld",e->elem);
    //��ӡ����
    printf("%-15s",e->Title);
    //��ӡ����
    printf("%-15s",e->Author);
    //��ӡ������
    printf("%-15s",e->press);
	//��ӡ����
	printf("%-10s",e->score);
	return SUCCESS;
}
/*
 * @Description: æµ‹è¯•ç®¡ç†åŠŸèƒ½æ¨¡å—
 * @Author: SuzyMo
 * @date: 2021-12-25 19:37:48
 */
#include"Common.h"
#include"HeaderFiles/RedBlackTree.h"
#include"HeaderFiles/RedBlackTreeUtils.h"
#include"HeaderFiles/BinarySearchTree.h"
#include"HeaderFiles/Utils.h"
//#include"HeaderFiles/Manager.h"
#include"HeaderFiles/Login.h"

int main(){
    RBRoot *root;
    Manager M;
    Stu stu = NULL;
    Stu_Init(stu);
    
    strcpy(stu->account, "121212");
    strcpy(stu->ID, "3220005002");
    strcpy(stu->name, "suzy");
    strcpy(stu->password, "123456");
    stu->power = 0;
    stu->next = NULL;
    stu->mybook = NULL;

    RBTreeElemType e1 = NULL;
    RBTreeElemType e2 = NULL;
    InitRBTElem(e1);
    InitRBTElem(e2);
    char str[20] = "";

    strcpy(str,"TheGivingTree");
    e1->Title = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e1->Title, str);

    strcpy(str, "ShelSilverstein");
    e1->Author = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e1->Author, str);

    strcpy(str, "¶¹°ê9.5·Ö");
    e1->score = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e1->score, str);

    strcpy(str, "Harper&Row");
    e1->press = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e1->press, str);
    e1->elem = 123434567543;
    
    
    strcpy(str,"Charlotte'sWeb");
    e2->Title = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e2->Title, str);

    strcpy(str, "None");
    e2->Author = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e2->Author, str);

    strcpy(str, "¶¹°ê8.5·Ö");
    e2->score = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e2->score, str);

    strcpy(str, "HarperCollins");
    e2->press = (char*)malloc(sizeof(char) * strlen(str));
    strcpy(e2->press, str);
    e2->elem = 254622366234;

    Stu_AddBook(stu, e1);
    Stu_AddBook(stu, e2);
    Updata_StuInfo(stu);
        
    Man_Fuction(M);
    system("pause");
    return 1;
}
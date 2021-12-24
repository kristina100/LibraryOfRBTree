#include"Common.h"
// #include "HeaderFiles/RedBlackTree.h"
// #include "HeaderFiles/RedBlackTreeUtils.h"
// #include "HeaderFiles/BinarySearchTree.h"
//#include "HeaderFiles/FileDo.h"

LARGE_INTEGER freq, begin, end;
void beginRecord();
double endRecord();
void menu(RBRoot *root);
int InputInteger();
void Quit();



int main()
{
//    FileRead();
    RBRoot *root = NULL;
    menu(root);
    return 0;
}

void FileReadAndBuiltTree(RBRoot *root)
{
    int a;
    FILE *fp=fopen("data.txt","r");
    if(NULL==fp)
    {
        printf ("Failed to open the file!\n");
        exit (0);
    }
    fscanf (fp,"%d",&a) ; //从fp所指文件中读取一个整数保存到变量a中
    while(!feof(fp))//如果位置指针不在文件末尾,即没有读到文件末尾
    {
        fscanf(fp,"%d",&a);//读入下一条记录
        printf("%d\n",a);
        RBTreeElemType temp;
        temp.elem = a;
        insertRBTree(root, temp);
    }
    fclose(fp);
}


void Quit(RBRoot *root)
{
    system("cls");
    int temp;
    printf("\t\t\t------------------------------\n");
    printf("\t\t\t|    Are you sure to quit    |\n");
    printf("\t\t\t|    1.YES      2.NO         |\n");
    printf("\t\t\t-----------------------------\n");
    printf("\t\t\tPlease enter your choice:\n");
    while(1)
    {
        temp = InputInteger();
        if(temp==1)
        {
            system("cls");
            printf("\t\t\tExiting safely....\n");
            system("cls");
            printf("\t\t\tSafely exited the system\n");
            printf("\t\t\tThank you for using!  <_>\n");
            exit(0);//Terminate the program

        }
        else if(temp==2)
        {
            menu(root);
            return;
        }
        else
            printf("The input is illegal, please re-enter.Thanks.--:");
    }
}

/**
 * 用户操作菜单
 *
 * @param[in]  root: the root of the red-black tree
 * @return  none
 */
void menu(RBRoot *root)
{
    int exist_flag = 0, saveFile = 0;  /* 标记红黑树是否存在  标记是否将修改保存到文件 */
    while (1) {
        system("cls");
        printf("\n\n\n\n*-------------------------------------------------------------------------*\n");
        printf("|  Welcome to Tomato's big work ~  Some operations on trees ~             |\n");
        printf("|                                                                         |\n");
        printf("|                                                                         |\n");
        printf("|    1. Init RedBlack Tree           7. Destroy the Tree                  |\n");
        printf("|                                                                         |\n");
        printf("|    2. Read Data & Built Tree       8. FileWrite                         |\n");
        printf("|                                                                         |\n");
        printf("|    3. Shape of tree                9. Display Tree Detail Information   |\n");
        printf("|                                                                         |\n");
        printf("|    4. Delete Operation             10. Post-Traverse                    |\n");
        printf("|                                                                         |\n");
        printf("|    5. Insert Operation             11. Find Max and Min Node            |\n");
        printf("|                                                                         |\n");
        printf("|    6. Search Operation             12. Quit System                      |\n");
        printf("|                                                                         |\n");
        printf("*-------------------------------------------------------------------------*\n");
        printf("*-------------------------------------------------------------------------*\n");

        if(exist_flag)
        {
            /* 以凹入法的方式实时打印红黑树 */
            printf("The current red-black tree ~ \n");
            recessedPrintRBTree(root->node, 0);
            if (!root->node) printf("The tree is empty ~ \n");
        }
        else
            printf("Do not exist tree!\n");

        printf("*--------------------------------------------------------------------*\n");
        printf("\n\t\t\nPlease enter your choice(1 to 12) :\n");
        switch (InputInteger())
        {
            case 1:  /* 初始化 */
                system("cls");
                root = createRBTree();
                exist_flag = 1;
                printf("Init successfully ~ \n");
                break;
            case 2:  /* 随机插入指定数量的结点 */
                system("cls");
                if (exist_flag) {
                    FileReadAndBuiltTree(root);
                    printf("Read initial data successfully ~ \n");
//                    /* 设置随机数种子 */
//                    srand((unsigned int) time(NULL));
//                    printf("Please enter information you want to insert:");
//                    int i, length_of_array;
//                    length_of_array = InputInteger();
//                    /* 以变量表示数组长度 */
//                    int *const array = (int *) malloc(sizeof(int) * length_of_array);
//                    /* 生成元素位于1-2020的数组 */
//                    for (i = 0; i < length_of_array; i++) array[i] = rand() % 2000;
//                    printf("The inserted nodes are : ");
//                    for (i = 0; i < length_of_array; i++)
//                    {
//                        printf("%d ", array[i]);
//                        RBTreeElemType temp;
//                        temp.elem = array[i];
//                        insertRBTree(root, temp);
//                }
//                    printf("\nInsert successfully ~ \n");
                }
                else
                    printf("No red-black tree exists, please initialize first!\n");
                break;

            case 3:  /* 打印 */
                system("cls");
                if (exist_flag)
                    printRBTree(root);
                else
                    printf("No red-black tree exists, please initialize first!\n");
                break;

            case 4:  /* 删除 */
                system("cls");
                if (exist_flag)
                {
                    RBTreeElemType delete_x;
                    Status delete_status;
                    double cost;
                    printf("Please enter the node you want to delete:");
                    delete_x.elem = InputInteger();
                    beginRecord();
                    delete_status = deleteRBTree(root, delete_x);
                    cost = endRecord();
                    if (delete_status == SUCCESS){
                        printf("Delete node successfully ~ \nTime consuming: %lf ms.\n", cost);
                        // 文件尚未存盘
                        saveFile = 1;
                    }
                    else
                        printf("Failed to delete node, no node exists!\n");
                }
                else
                    printf("No red-black tree exists, please initialize first!\n");
                break;

            case 5:  /* 插入 */
                system("cls");
                if (exist_flag)
                {
                    RBTreeElemType insert_x;
                    Status insert_status;
                    double cost;
                    printf("Please enter the node you want to insert:");
                    insert_x.elem = InputInteger();
                    beginRecord();
                    insert_status = insertRBTree(root, insert_x);
                    cost = endRecord();
                    if (insert_status == SUCCESS) {
                        printf("Insert node successfully!\nDelete time consuming: %lf ms.\n", cost);
                        // 文件尚未存盘
                        saveFile = 1;
                    }
                    else
                        printf("Insert node failed, the node already exists!\n");
                }
                else
                    printf("No red-black tree exists, please initialize first!\n");
                break;

            case 6:  /* 查找功能还需完善 模糊查找  */
                system("cls");
                if (exist_flag)
                {
                    RBTreeElemType search_x;
                    printf("Please enter the node you want to find:");
                    search_x.elem = InputInteger();
                    if ((recursiveSearchRBTree(root, search_x)) == SUCCESS)
                        printf("The search was successful, and the node exists ~\n");
                    else
                        printf("Failed to find, no node exists!\n");
                }
                else
                    printf("No red-black tree exists, please initialize first!\n");
                break;

            case 7:  /* 销毁 */
                system("cls");
                if (exist_flag)
                {
                    destroyRBTree(root);
                    exist_flag = 0;
                    printf("Destroy successfully ~ \n");
                    // 文件尚未存盘
                    saveFile = 1;
                }
                else
                    printf("No red-black tree exists, please initialize first!\n");
                break;

            case 8:  /* 把树的的data部分写入文件 */
                system("cls");
                if (exist_flag)
                {

//                    FileWrite(root);
                    printf("\n");

                }
                else
                    printf("No red-black tree exists, please initialize first!\n");
                break;
//            case 9:  /* 中序遍历 */
//                system("cls");
//                if (exist_flag)
//                {
//                    inorderRBTree(root);
//                    printf("\n");
//                }
//                else
//                    printf("No red-black tree exists, please initialize first!\n");
//                break;
//            case 10:  /* 后序遍历 */
//                system("cls");
//                if (exist_flag)
//                {
//                    postorderRBTree(root);
//                    printf("\n");
//                }
//                else
//                    printf("No red-black tree exists, please initialize first!\n");
//                break;
            case 11:  /* 查找最大和最小结点 */
                system("cls");
                if (exist_flag && root->node)
                {
                    RBTreeElemType *max = (RBTreeElemType *)malloc(sizeof(int));
                    RBTreeElemType *min = (RBTreeElemType *)malloc(sizeof(int));
                    maxRBTreeNode(root, max);
                    minRBTreeNode(root, min);
                    printf("The maximum node of the red-black tree is [%d], The minimum node is [%d]!\n", *max, *min);
                }
                else if (!root->node)
                    printf("The red-black tree is empty!\n");
                else
                    printf("No red-black tree exists, please initialize first!\n");
                break;
            case 12:  /* 退出程序 */
                system("cls");
                Quit(root);
                exit(0);
            default:
                printf("This option does not exist, please re-enter!\n");
                break;
        }
        system("pause");
    }
}

/**
 * 检测用户整数输入
 *
 * @param[in]  none
 * @return  legal integer
 */
int InputInteger()
{
    /* store converted numbers */
    int integer;
    /* flag status */
    int  status;
    /* receive string */
    char str[100];

    do {
        scanf("%s", str);
        status = TRUE;
        int i;
        for (i = 0; str[i] != '\0'; i++) {
            /* check for illegal characters */
            if (i == 0) {
                if (str[i] == '-' || str[i] == '+') continue;
            } else {
                if (str[i] < '0' || str[i] > '9') status = FALSE;
            }
        }
        if (status == FALSE) {
            printf("Input illegally, please re-enter:");
            continue;
        } else {
            /* Convert string to number */
            for (i = 0, integer = 0; str[i] != '\0'; i++) {
                if (i == 0) {
                    if (str[i] == '-' || str[i] == '+') continue;
                    else {
                        integer *= 10;
                        integer += (str[i] - 48);
                    }
                } else {
                    integer *= 10;
                    integer += (str[i] - 48);
                }
            }
            if (str[0] == '-') integer = -integer;

            /* check if the number entered is out of bounds */
            if (i >= 10) {
                printf("Overflow, please re-enter:");
                status = FALSE;
            }
        }
    } while (status == FALSE);

    return integer;
}

/**
 * 开始记录
 *
 * @param[in]  none
 * @return  none
 */
void beginRecord()
{
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&begin);
}

/**
 * 停止记录
 *
 * @param[in]  none
 * @return  execution time of the program
 */
double endRecord()
{
    QueryPerformanceCounter(&end);

    return (double )(end.QuadPart - begin.QuadPart) / (double)freq.QuadPart * 1000.0f;
}




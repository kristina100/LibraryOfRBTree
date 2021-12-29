/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 15:56:56
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-29 11:44:15
 */
#include"../HeaderFiles/Login.h"
#include"../HeaderFiles/Utils.h"

//存储学生数据的文件
char Data_Stu[] = "Students.dat";

//存储管理员数据的文件
char Data_Man[] = "Managers.dat";

/**
 * @brief 打印登录界面
 */
void Print_Login_Options(){

    Clean();
    printf("\n\n\n\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("|                            <Login Interface>                            |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|           1.Student Login                  2.Manager Login              |\n");
    printf("|                                                                         |\n");
    printf("|           3.Register                       0.System Return              |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("\n\t\t");
    printf("Please Choose: ");     
}

/**
 * @brief 登录选项
 */
void Login_Operation(){
    
    //选择
    int choose;
    
    while (true){
        Print_Login_Options();
        scanf("%d", &choose);
        
        switch (choose){
            
            //返回上一级
            case 0:{
                return;
            }break;

            //学生登录
            case 1:{
                Stu stu = NULL;
                stu = Login_Stu();
                if(stu == NULL){
                    printf("\tLogin failed! Account or password error.\n");
                }else{
                    printf("\tLogin succeeded.\n");
                    Sleep(1);
                    Stu_Operation(stu);
                }
                Pause();
            }break;

            //管理员登录
            case 2:{
                Manager manager = NULL;
                manager = Login_Man();
                if(manager == NULL){
                    printf("\tLogin failed! Account or password error.\n");
                }else{
                    printf("\tLogin succeeded.\n");
                    Sleep(1);
                    Man_Fuction(manager);
                }
                Pause();
            }break;

            //注册
            case 3:{
                Status status = Register_Spilt();
                if(status == SUCCESS){
                    printf("\tRegister was successful.\n");
                }else if(status == Exist){
                    printf("\tError! Account already exists.\n");
                }
                Pause();
            }break;
        
            default:{
                printf("\nOperation does not exist\n");
                Pause();
            }break;
        }
    Clean();
    }
}

/**
 * @brief 学生登录
 */
Stu Login_Stu(){
    Clean();
    printf("\n\n\n\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("                              <Student Login>                              \n");
    printf("                                                                           \n");
    printf("                                                                           \n");

    FILE *fp = NULL;
    char account[11];
    char password[6];
    Stu stu = NULL;
    Stu_Init(stu);

    //输入账号密码
    printf("\t\tPlease input account:");
    scanf("%s", account);

    printf("\t\tPlease input password:");
    scanf("%s", password);

    //打开文件
    fp = fopen(Data_Stu, "rb");
    
    //在数据文件中查找账号
    while(fread(stu, sizeof(student), 1, fp)){
        
        if(strcmp(account, stu->account) == 0){
            //密码相同
            if(strcmp(password, stu->password) == 0){
                fclose(fp);
                return stu;
            }
            else
                break;
            
        }
    }
    fclose(fp);
    
    return NULL;
}

/**
 * @name Login_Man
 * @brief 管理员登录
 * @param   
 * @return Status 
 */
Manager Login_Man(){
    Clean();
    printf("\n\n\n\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("                              <Manager Login>                              \n");
    printf("                                                                           \n");
    printf("                                                                           \n");

    FILE *fp = NULL;
    char account[11];
    char password[6];
    Manager man = NULL;
    Man_Init(man);
    
    //输入账号密码
    printf("请输入账号:");
    scanf("%s", account);

    printf("请输入密码:");
    scanf("%s", password);

    //打开文件
    fp = fopen(Data_Man, "rb");
    
    //在数据文件中查找账号
    while(fread(man, sizeof(manager), 1, fp)){
        
        if(strcmp(account, man->account) == 0){
            //密码相同
            if(strcmp(password, man->password) == 0){
                fclose(fp);
                return man;
            }
            else
                break;
            
        }
    }
    fclose(fp);
    
    return NULL;
}

/**
 * @brief 打印注册选项
 * 
 */
void Print_Register_Option(){
    Clean();
    printf("\n\n\n\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("|                            <Register Interface>                         |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|           1.Student Register               2.Manager Register           |\n");
    printf("|                                                                         |\n");
    printf("|           0.System Return                                               |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("\n\t\t");
    printf("Please Choose: "); 
}

/**
 * @brief 分流学生和管理员
 * 
 */
Status Register_Spilt(){

    int choose;

    while (true){
        Print_Register_Option();
        scanf("%d", &choose);

        switch (choose){
            
            //返回
            case 0:{
                return Cancel;
            }break;

            //学生注册
            case 1:{
                Status status = Register_Operation(0);
                if(status == SUCCESS)
                    return SUCCESS;
                else
                    return Exist;
            }break;

            //管理员注册
            case 2:{
                Status status = Register_Operation(1);
                if(status == SUCCESS)
                    return SUCCESS;
                else if(status == ERROR){
                    printf("\tThe administrator registration permission is invalid\n");
                    return ERROR;
                }else   
                    return Exist;
                    
            }break;

            default:{
                printf("\nOperation does not exist\n");
                Pause();
            }break;
        }
    Clean();
    }
    
}

/**
 * @brief 注册
 */
Status Register_Operation(int mode){

    //初始化
    FILE *fp = NULL;

    switch (mode){

        //学生注册
        case 0:{     
            Stu stu = NULL, temp = NULL;
            Stu_Init(stu);
            Stu_Init(temp);

            printf("\tPlease input your account: ");
            scanf("%s", stu->account);

            //=================检查账号是否存在=================

            //打开文件
            fp = fopen(Data_Stu, "rb");

            while(fread(temp, sizeof(student), 1, fp)){

                if(strcmp(temp->account, stu->account) == 0){
                    fclose(fp);
                    return Exist;
                }
            }
            fclose(fp);
            
            printf("\t\tPlease input your ID: ");
            scanf("%s", stu->ID);

            printf("\t\tPlease input your password: ");
            scanf("%s", stu->password);

            printf("\t\tPlease input your name: ");
            scanf("%s", stu->name);

            stu->power = 0;

            //写入文件
            fp = fopen(Data_Stu, "ab+");
            fwrite(stu, sizeof(student), 1, fp);
            
        }break;
        //管理员注册
        case 1:{
            Manager M = NULL, temp = NULL;
            Man_Init(M);
            Man_Init(temp);
            
            //检测管理员注册密钥
            int Mancode = 0;
            printf("\tPlease input the administrator registration key:");
            scanf("%d", &Mancode);
            //注册密钥错误
            if(Mancode != 1234) return FALSE;

            printf("Please input your account: ");
            scanf("%s", M->account);
            
            
            //=================检查账号是否存在=================

            //打开文件
            fp = fopen(Data_Man, "rb");

            while(fread(temp, sizeof(manager), 1, fp)){

                if(strcmp(temp->account, M->account) == 0){
                    fclose(fp);
                    return Exist;
                }
            }
            fclose(fp);
            
            printf("\t\tPlease input your password: ");
            scanf("%s", M->password);

            printf("\t\tPlease input your name: ");
            scanf("%s", M->name);

            M->power = 1;

            //写入文件
            fp = fopen(Data_Man, "ab");
            fwrite(M, sizeof(manager), 1, fp);
        }break;
    }
    fclose(fp);
    return SUCCESS;
}

/**
 * @brief 更新学生文件中的信息
 */
Status Updata_StuInfo(Stu &stu){
    
    FILE *fp = NULL;
    Stu t = NULL, p = NULL, head = NULL;

    //以二进制只读"rb"打开学生数据文件
    fp = fopen(Data_Stu, "rb");
    if(fp == NULL){
        printf("Error! Student data does not exist!\n");
        return ERROR;
    }
    //初始化
    Stu_Init(t);

    //读出学生数据的数量
    int num = 0;
    //将学生信息全部从文件中读出
    while(fread(t, sizeof(student), 1, fp)){
        num++;
        if(num == 1){
            p = head = t;
        }
        //将学生数据建成链表
        else{
            p->next = t;
            //p一直指向尾部
            p = p->next;
        }
    }
    //关闭文件
    fclose(fp);
    
    //找到对应学生，修改对应学生的数据
    for(p = head; p->next != NULL && p->next->account != stu->account; p = p->next);

    //将新数据替换旧数据
    t = p->next;
    stu->next = t->next;
    p->next = stu;
    
    //以二进制写"w"打开文件，覆盖输入
    fp = fopen(Data_Stu, "wb");
    for(p = head; p != NULL; p = p->next){
        fwrite(p, sizeof(student), 1, fp);
    }
    //关闭文件
    fclose(fp);
    
    //释放空间
    p = head;
    while(p != NULL){
        p = p->next;
        free(head);
        head = p;
    }
    free(t);
    return SUCCESS;
}
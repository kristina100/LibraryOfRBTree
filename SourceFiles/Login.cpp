/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 15:56:56
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-03 13:48:35
 */
#include"../HeaderFiles/Login.h"
#include"../HeaderFiles/Utils.h"
#include"EscapeRote.h"

//存储学生数据的文件
char Data_Stu[] = "Students.dat";

//存储管理员数据的文件
char Data_Man[] = "Managers.dat";

/**
 * @brief 打印登录界面
 */
void Print_Login_Options(){

    Clean();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//白色
    printf("\n\n\n\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("|                           <Login Interface>                             |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|           1.Student Login                  2.Manager Login              |\n");
    printf("|                                                                         |\n");
    printf("|           3.Register                       4.Escape Rote                |\n");
    printf("|                                                                         |\n");
    printf("|                            0.System Return                              |\n");
    printf("|                                                                         |\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("\n\t\t");
    printf("Please Choose: ");     
}

/**
 * @brief 登录选项
 */
void Login_Operation(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//白色
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
                    printf("\t\tLogin failed! Account or password error.\n");
                    Pause();
                }else{
                    printf("\t\tLogin succeeded.\n");
                    Sleep(1);
                    Stu_Operation(stu);
                }
            }break;

            //管理员登录
            case 2:{
                Manager manager = NULL;
                manager = Login_Man();
                if(manager == NULL){
                    printf("\tLogin failed! Account or password error.\n");
                    Pause();
                }else{
                    printf("\tLogin succeeded.\n");
                    Sleep(1);
                    Man_Fuction(manager);
                }
            }break;

            //注册
            case 3:{
                Status status = Register_Spilt();
                if(status == SUCCESS){
                    printf("\t\tRegister was successful.\n");
                }else if(status == Exist){
                    printf("\t\tError! Account already exists.\n");
                }
                Pause();
            }break;
            case 4://逃生路线
		   {
                if(getEscapeRote()!=SUCCESS)
				    printf("Failed to show escape rote!\n");
			    break;
		    }
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
    Stu stu = NULL;
    char password[6] = "";
    char account[20] = "";

    //输入账号
    printf("\t\t\tAccount: ");
    scanf("%s", account);

    //输入密码
    printf("\t\t\tPassword: ");
    scanf("%s", password);

    //读出学生信息数据
    stu = Stu_ReadData();
    
    //检查数据是否存在且对应
    while(stu != NULL){
        //账号相同
        if(strcmp(account, stu->account) == 0){
            //密码相同
            if(strcmp(password, stu->password) == 0)
                return stu;  
            else
                break;
        }
        //指向下一个
        stu = stu->next;
    }

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
    Manager Man = NULL;
    Man_Init(Man);
    char password[6] = "";
    char account[20] = "";

    //输入账号
    printf("\t\t\tAccount: ");
    scanf("%s", account);

    //输入密码
    printf("\t\t\tPassword: ");
    scanf("%s", password);

    //打开文件
    fp = fopen(Data_Man, "rb");
    
    //在数据文件中查找账号
    while(fread(Man, sizeof(manager), 1, fp)){
        
        if(strcmp(account, Man->account) == 0){
            //密码相同
            if(strcmp(password, Man->password) == 0){
                fclose(fp);
                return Man;
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

            printf("\t\tPlease input your account: ");
            scanf("%s", stu->account);

            //=================检查账号是否存在=================
            
            //读出学生信息数据
            temp = Stu_ReadData();
            //检查数据是否存在
            while(temp != NULL){
                if(strcmp(temp->account, stu->account) == 0)
                    return Exist;
                
                temp = temp->next;
            }

            printf("\t\tPlease input your ID: ");
            scanf("%s", stu->ID);

            printf("\t\tPlease input your password: ");
            scanf("%s", stu->password);

            printf("\t\tPlease input your name: ");
            scanf("%s", stu->name);
            
            //写入文件
            fp = fopen(Data_Stu, "ab");
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

    //读取学生信息数据
    head = Stu_ReadData();

    //head空
    if(head == NULL)
        return ERROR;
    
    //找到学生
    for(p = t = head; t != NULL; t = t->next){
    
        //找到对应学生
        if(strcmp(t->account, stu->account) == 0) 
            break;

        //p指向对应学生的上一位
        p = t;
    }

    //将新数据替换旧数据
    //对应学生为第一位
    if(p == t){
        stu->next = head->next;
        head = stu;
    }
    //对应学生不为第一位
    else{     
        stu->next = t->next;
        p->next = stu;
    }
    t->next = NULL;
    
    //格式化写入数据
    Stu_WriteData(head);
    
    return SUCCESS;
}
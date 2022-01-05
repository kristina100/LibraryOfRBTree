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

//�洢ѧ�����ݵ��ļ�
char Data_Stu[] = "Students.dat";

//�洢����Ա���ݵ��ļ�
char Data_Man[] = "Managers.dat";

/**
 * @brief ��ӡ��¼����
 */
void Print_Login_Options(){

    Clean();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//��ɫ
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
 * @brief ��¼ѡ��
 */
void Login_Operation(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//��ɫ
    //ѡ��
    int choose;
    
    while (true){
        Print_Login_Options();
        scanf("%d", &choose);
        
        switch (choose){
            
            //������һ��
            case 0:{
                return;
            }break;

            //ѧ����¼
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

            //����Ա��¼
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

            //ע��
            case 3:{
                Status status = Register_Spilt();
                if(status == SUCCESS){
                    printf("\t\tRegister was successful.\n");
                }else if(status == Exist){
                    printf("\t\tError! Account already exists.\n");
                }
                Pause();
            }break;
            case 4://����·��
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
 * @brief ѧ����¼
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

    //�����˺�
    printf("\t\t\tAccount: ");
    scanf("%s", account);

    //��������
    printf("\t\t\tPassword: ");
    scanf("%s", password);

    //����ѧ����Ϣ����
    stu = Stu_ReadData();
    
    //��������Ƿ�����Ҷ�Ӧ
    while(stu != NULL){
        //�˺���ͬ
        if(strcmp(account, stu->account) == 0){
            //������ͬ
            if(strcmp(password, stu->password) == 0)
                return stu;  
            else
                break;
        }
        //ָ����һ��
        stu = stu->next;
    }

    return NULL;
}

/**
 * @name Login_Man
 * @brief ����Ա��¼
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

    //�����˺�
    printf("\t\t\tAccount: ");
    scanf("%s", account);

    //��������
    printf("\t\t\tPassword: ");
    scanf("%s", password);

    //���ļ�
    fp = fopen(Data_Man, "rb");
    
    //�������ļ��в����˺�
    while(fread(Man, sizeof(manager), 1, fp)){
        
        if(strcmp(account, Man->account) == 0){
            //������ͬ
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
 * @brief ��ӡע��ѡ��
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
 * @brief ����ѧ���͹���Ա
 * 
 */
Status Register_Spilt(){

    int choose;

    while (true){
        Print_Register_Option();
        scanf("%d", &choose);

        switch (choose){
            
            //����
            case 0:{
                return Cancel;
            }break;

            //ѧ��ע��
            case 1:{
                Status status = Register_Operation(0);
                if(status == SUCCESS)
                    return SUCCESS;
                else
                    return Exist;
            }break;

            //����Աע��
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
 * @brief ע��
 */
Status Register_Operation(int mode){

    //��ʼ��
    FILE *fp = NULL;

    switch (mode){

        //ѧ��ע��
        case 0:{     
            Stu stu = NULL, temp = NULL;
            Stu_Init(stu);

            printf("\t\tPlease input your account: ");
            scanf("%s", stu->account);

            //=================����˺��Ƿ����=================
            
            //����ѧ����Ϣ����
            temp = Stu_ReadData();
            //��������Ƿ����
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
            
            //д���ļ�
            fp = fopen(Data_Stu, "ab");
            fwrite(stu, sizeof(student), 1, fp);
            
        }break;
        //����Աע��
        case 1:{
            Manager M = NULL, temp = NULL;
            Man_Init(M);
            Man_Init(temp);
            
            //������Աע����Կ
            int Mancode = 0;
            printf("\tPlease input the administrator registration key:");
            scanf("%d", &Mancode);
            //ע����Կ����
            if(Mancode != 1234) return FALSE;

            printf("Please input your account: ");
            scanf("%s", M->account);      
            
            
            //=================����˺��Ƿ����=================

            //���ļ�
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

            //д���ļ�
            fp = fopen(Data_Man, "ab");
            fwrite(M, sizeof(manager), 1, fp);
        }break;
    }
    fclose(fp);
    return SUCCESS;
}

/**
 * @brief ����ѧ���ļ��е���Ϣ
 */
Status Updata_StuInfo(Stu &stu){
    
    FILE *fp = NULL;
    Stu t = NULL, p = NULL, head = NULL;

    //��ȡѧ����Ϣ����
    head = Stu_ReadData();

    //head��
    if(head == NULL)
        return ERROR;
    
    //�ҵ�ѧ��
    for(p = t = head; t != NULL; t = t->next){
    
        //�ҵ���Ӧѧ��
        if(strcmp(t->account, stu->account) == 0) 
            break;

        //pָ���Ӧѧ������һλ
        p = t;
    }

    //���������滻������
    //��Ӧѧ��Ϊ��һλ
    if(p == t){
        stu->next = head->next;
        head = stu;
    }
    //��Ӧѧ����Ϊ��һλ
    else{     
        stu->next = t->next;
        p->next = stu;
    }
    t->next = NULL;
    
    //��ʽ��д������
    Stu_WriteData(head);
    
    return SUCCESS;
}
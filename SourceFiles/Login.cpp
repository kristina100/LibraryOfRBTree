/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 15:56:56
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-29 11:44:15
 */
#include"../HeaderFiles/Login.h"
#include"../HeaderFiles/Utils.h"

//�洢ѧ�����ݵ��ļ�
char Data_Stu[] = "Students.dat";

//�洢����Ա���ݵ��ļ�
char Data_Man[] = "Managers.dat";

/**
 * @brief ��ӡ��¼����
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
 * @brief ��¼ѡ��
 */
void Login_Operation(){
    
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
                    printf("\tLogin failed! Account or password error.\n");
                }else{
                    printf("\tLogin succeeded.\n");
                    Sleep(1);
                    Stu_Operation(stu);
                }
                Pause();
            }break;

            //����Ա��¼
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

            //ע��
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
    char account[11];
    char password[6];
    Stu stu = NULL;
    Stu_Init(stu);

    //�����˺�����
    printf("\t\tPlease input account:");
    scanf("%s", account);

    printf("\t\tPlease input password:");
    scanf("%s", password);

    //���ļ�
    fp = fopen(Data_Stu, "rb");
    
    //�������ļ��в����˺�
    while(fread(stu, sizeof(student), 1, fp)){
        
        if(strcmp(account, stu->account) == 0){
            //������ͬ
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
    char account[11];
    char password[6];
    Manager man = NULL;
    Man_Init(man);
    
    //�����˺�����
    printf("�������˺�:");
    scanf("%s", account);

    printf("����������:");
    scanf("%s", password);

    //���ļ�
    fp = fopen(Data_Man, "rb");
    
    //�������ļ��в����˺�
    while(fread(man, sizeof(manager), 1, fp)){
        
        if(strcmp(account, man->account) == 0){
            //������ͬ
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
            Stu_Init(temp);

            printf("\tPlease input your account: ");
            scanf("%s", stu->account);

            //=================����˺��Ƿ����=================

            //���ļ�
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

            //д���ļ�
            fp = fopen(Data_Stu, "ab+");
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

    //�Զ�����ֻ��"rb"��ѧ�������ļ�
    fp = fopen(Data_Stu, "rb");
    if(fp == NULL){
        printf("Error! Student data does not exist!\n");
        return ERROR;
    }
    //��ʼ��
    Stu_Init(t);

    //����ѧ�����ݵ�����
    int num = 0;
    //��ѧ����Ϣȫ�����ļ��ж���
    while(fread(t, sizeof(student), 1, fp)){
        num++;
        if(num == 1){
            p = head = t;
        }
        //��ѧ�����ݽ�������
        else{
            p->next = t;
            //pһֱָ��β��
            p = p->next;
        }
    }
    //�ر��ļ�
    fclose(fp);
    
    //�ҵ���Ӧѧ�����޸Ķ�Ӧѧ��������
    for(p = head; p->next != NULL && p->next->account != stu->account; p = p->next);

    //���������滻������
    t = p->next;
    stu->next = t->next;
    p->next = stu;
    
    //�Զ�����д"w"���ļ�����������
    fp = fopen(Data_Stu, "wb");
    for(p = head; p != NULL; p = p->next){
        fwrite(p, sizeof(student), 1, fp);
    }
    //�ر��ļ�
    fclose(fp);
    
    //�ͷſռ�
    p = head;
    while(p != NULL){
        p = p->next;
        free(head);
        head = p;
    }
    free(t);
    return SUCCESS;
}
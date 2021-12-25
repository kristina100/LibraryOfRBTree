/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 15:56:56
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-25 21:19:30
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
    printf("\n\n\n\n*-----------------------------------------------------------------*\n");
    printf("|                            <��¼����>                                    |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|           1.ѧ����¼                       2��Ա��¼                      |\n");
    printf("|                                                                         |\n");
    printf("|           3.ע��                           0.����                        |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("*-------------------------------------------------------------------------*\n");
    printf("*-------------------------------------------------------------------------*\n");
    
    printf("\n\t\t");
    printf("��ѡ��: ");     
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
                    printf("��¼ʧ�ܣ��˺Ż��������\n");
                }else{
                    printf("��¼�ɹ�\n");
                    Sleep(1);
                    Stu_Operation(stu);
                }
                Pause();
            }break;

            //����Ա��¼
            case 2:{
                Manager manager = NULL;
                manager =Login_Man();
                if(manager == NULL){
                    printf("��¼ʧ�ܣ��˺Ż��������\n");
                }else{
                    printf("��¼�ɹ�\n");
                    Sleep(1);
                    Man_Fuction(manager);
                }
                Pause();
            }break;

            //ע��
            case 3:{
                Status status = Register_Spilt();
                if(status == SUCCESS){
                    printf("ע��ɹ�\n");
                }else if(status == Exist){
                    printf("�˺��Ѵ���\n");
                }
                Pause();
            }break;
        
            default:{
                printf("\n����������\n");
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
    for (int i = 0; i < 10; i++){
        if(i == 5)
            printf("��¼");
        printf("__");
    }
    printf("\n");
    FILE *fp = NULL;
    char account[11];
    char password[6];
    Stu stu = NULL;
    Stu_Init(stu);

    //�����˺�����
    printf("�������˺�:");
    scanf("%s", account);

    printf("����������:");
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
    for (int i = 0; i < 10; i++){
        if(i == 5)
            printf("��¼");
        printf("__");
    }
    printf("\n");
    FILE *fp = NULL;
    char account[11];
    char password[6];
    Manager manager = NULL;
    Man_Init(manager);
    
    //�����˺�����
    printf("�������˺�:");
    scanf("%s", account);

    printf("����������:");
    scanf("%s", password);

    //���ļ�
    fp = fopen(Data_Man, "rb");
    
    //�������ļ��в����˺�
    while(fread(manager, sizeof(manager), 1, fp)){
        
        if(strcmp(account, manager->account) == 0){
            //������ͬ
            if(strcmp(password, manager->password) == 0){
                fclose(fp);
                return manager;
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
    for (int i = 0; i < 10; i++){
        if(i == 5)
            printf("��¼����");
        printf("__");
    }
    printf("\n\n");
    printf("1.ѧ��ע��\n");
    printf("2,����Աע��\n");
    printf("0.����\n\n");

    for (int i = 0; i < 15; i++){
        printf("__");
    }
    printf("\n");
    printf("��ѡ�����: "); 
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
                    printf("����Աע��Ȩ����Ч\n");
                    return ERROR;
                }else   
                    return Exist;
                    
            }break;

            default:{
                printf("\n����������\n");
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

            printf("�������˺�:");
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
            
            printf("������ѧ��:");
            scanf("%s", stu->ID);

            printf("����������(6λ):");
            scanf("%s", stu->password);

            printf("����������:");
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
            printf("���������Աע����Կ:");
            scanf("%d", &Mancode);
            //ע����Կ����
            if(Mancode != 1234) return FALSE;

            printf("�������˺�:");
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
            
            printf("����������(6λ):");
            scanf("%s", M->password);

            printf("����������:");
            scanf("%s", M->name);

            M->power = 1;

            //д���ļ�
            fp = fopen(Data_Man, "ab+");
            fwrite(M, sizeof(student), 1, fp);
        }break;
    }
    fclose(fp);
    return SUCCESS;
}
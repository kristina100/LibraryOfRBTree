/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-23 15:51:52
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-02 00:11:54
 */
#include"Common.h"
#include"Student.h"
#include"Manager.h"

/**
 * @brief ��ӡ��¼����
 * 
 */
void Print_Login_Options();

/**
 * @brief ��¼����
 */
void Login_Operation();

/**
 * @brief ѧ����¼
 * 
 * @return Stu 
 */
Stu Login_Stu();

/**
 * @brief  ����Ա��¼
 */
Manager Login_Man();

/**
 * @brief ע�����,mode == 0 Ϊѧ��ע��, 1Ϊ����Աע��
 * 
 * @param mode 
 * @return Status 
 */
Status Register_Operation(int mode);

/**
 * @brief ����ѧ���͹���Ա
 * 
 */
Status Register_Spilt();

/**
 * @brief ��ӡע��ѡ��
 * 
 */
void Print_Register_Option();

/**
 * @brief ����ѧ���ļ��е���Ϣ
 * 
 * @param stu 
 */
Status Updata_StuInfo(Stu &stu);

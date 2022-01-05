/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-22 12:54:00
 * @LastEditors: Hx
 * @LastEditTime: 2022-01-06 01:57:37
 */
#ifndef UTILS_H_INCLUDE
#define UTILS_H_INCLUDE
#include"Common.h"
#include"RedBlackTree.h"
#include"Student.h"
#include"Manager.h"

/**
 * @brief ��ͣ
 */
void Pause();

/**
 * @brief �����Ļ
 */
void Clean();

/**
 * @brief ��ӡ�鱾��Ϣ
 * 
 * @param e 
 */
void Print_BookInfo(RBTreeElemType e);

/*
 * ����û���������
 *
 * @param[in]  none
 * @return  legal integer
 */
long long int InputInteger();

/**
 * @name  Quit()
 * @brief �˳�
 * @param   
 * @return  
 */
void Quit();

#endif  
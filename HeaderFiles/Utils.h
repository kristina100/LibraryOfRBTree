/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-22 12:54:00
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-26 21:33:48
 */
#ifndef UTILS_H_INCLUDE
#define UTILS_H_INCLUDE
#include"Common.h"
#include"RedBlackTree.h"
#include"Student.h"
#include"Manager.h"

/**
 * @brief 暂停
 */
void Pause();

/**
 * @brief 清空屏幕
 */
void Clean();

/**
 * @brief 打印书本信息
 * 
 * @param e 
 */
void Print_BookInfo(RBTreeElemType e);

/*
 * 检测用户整数输入
 *
 * @param[in]  none
 * @return  legal integer
 */
int InputInteger();

/**
 * @name  Quit()
 * @brief 退出判断
 * @param   
 * @return  
 */
void Quit();

#endif  
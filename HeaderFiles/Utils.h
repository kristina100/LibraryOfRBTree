/*
 * @Descripttion: 
 * @Author: Hx
 * @Date: 2021-12-22 12:54:00
 * @LastEditors: Hx
 * @LastEditTime: 2021-12-28 16:48:44
 */
#ifndef UTILS_H_INCLUDE
#define UTILS_H_INCLUDE
#include"Common.h"
#include"RedBlackTree.h"
#include"Student.h"
#include"Manager.h"

/**
 * @brief 鏆傚仠
 */
void Pause();

/**
 * @brief 娓呯┖灞忓箷
 */
void Clean();

/**
 * @brief 鎵撳嵃涔︽湰淇℃伅
 * 
 * @param e 
 */
void Print_BookInfo(RBTreeElemType e);

/*
 * 妫€娴嬬敤鎴锋暣鏁拌緭鍏�
 *
 * @param[in]  none
 * @return  legal integer
 */
long long int InputInteger();

/**
 * @name  Quit()
 * @brief 閫€鍑哄垽鏂�
 * @param   
 * @return  
 */
void Quit();

#endif  
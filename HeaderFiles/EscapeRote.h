/*
* @Description: 逃生系统的接口 
* @Author: SuzyMo
* @date: 2022-01-02 13:34:35
*/
#include"Graph.h"

/**
 * @name InitGroup
 * @brief 初始化地图，创建图书馆地图
 * @param  G 
 */ 
void InitGroup(ALGraph &G);

/**
 * @name SOSFuction
 * @brief 根据地点查询逃生路径
 * @param  G
 * @param  position 
 */
void SOSFuction(ALGraph &G, int position);

/**
 * @name getEscapeRote
 * @brief 显示逃生路径的函数
 * @param   
 * @return Status  
 */
Status getEscapeRote();

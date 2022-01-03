/*
* @Description: 逃生路径接口实现
* @Author: SuzyMo
* @date: 2022-01-02 13:46:50
*/

#include "EscapeRote.h"
#include"Utils.h"

#define GATE_E 101//东西南北门
#define GATE_W 102
#define GATE_S 103
#define GATE_N 104


/**
 * @name InitGroup
 * @brief 初始化地图，创建图书馆地图
 * @param  G 
 */ 
void InitGroup(ALGraph &G) {
	
    //顶点数组初始化
	VexType Vex0 = { GATE_E,"东门" };
	VexType Vex1 = { GATE_W,"西门" };
	VexType Vex2 = { GATE_S,"南门" };
	VexType Vex3 = { GATE_N,"北门" };
	VexType computer = { 1,"计算机区" };
	VexType history = { 2,"历史区" };
	VexType science = { 3,"科学区" };
	VexType children = { 4,"儿童区" };
	VexType humatity = { 5,"人文区" };
	VexType vexs[9] = {computer,history, science ,children , humatity,Vex0,Vex1 ,Vex2, Vex3};

    //边数组初始化 带权值
	ArcInfo arcs1 = { humatity ,Vex3 ,5}; //5 9
	ArcInfo arcs2 = { humatity ,Vex1 ,7}; //5 7
	ArcInfo arcs3 = { humatity ,computer,3};//5 1
	ArcInfo arcs4 = { computer,history,1 };//1 2
	ArcInfo arcs5 = { computer,humatity,3 };//1 5
	ArcInfo arcs6 = { science ,Vex2 ,6}; //3 8
	ArcInfo arcs7 = { science,children ,1}; //3 4
	ArcInfo arcs8 = { science,history,3 };//3 2
	ArcInfo arcs9 = { history ,Vex0 ,2};//2 6
	ArcInfo arcs10 = { history ,Vex2 ,8 }; //2 8
	ArcInfo arcs11 = { children ,Vex1 ,4 }; //4 7
	ArcInfo arcs12 = { history ,computer ,1 }; //2 1
	ArcInfo arcs13= { science,humatity,3 };//3 5
	ArcInfo arcs14 = { children ,science,1}; //4 3
	ArcInfo arcs15= { humatity,science,3 };//5 3
	ArcInfo arcs[15]{ arcs1,arcs2,arcs3,arcs4,arcs5,arcs6,arcs7,arcs8,arcs9,arcs10,arcs11,arcs12,arcs13,arcs14,arcs15 };

	createDG_AL(G, vexs, 9, arcs, 15);
}
/**
 * @name PositionMenu
 * @brief 位置菜单，对应结点数组
 */
void PositionMenu(){
    printf("\n*-------------------------------------------------------------------------*\n");
    printf("|         Welcome to EscapeRoteFuction !  Choose the position !           |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
    printf("|             1.computer                     2.history                    |\n");
    printf("|                                                                         |\n");
    printf("|             3.science                      4.children                   |\n");
    printf("|                                                                         |\n");
	printf("|             5.humatity                     6.back                       |\n");
    printf("|                                                                         |\n");
    printf("|                                                                         |\n");
	printf("*-------------------------------------------------------------------------*\n");
    printf("请输入您当前所在区域:");
}

/**
 * @name SOSFuction
 * @brief 根据地点查询逃生路径
 * @param  G
 * @param  position 
 */
void SOSFuction(ALGraph &G, int position) {
	if (position<0) return;
	Dist dist;
    Dijkstra(G, LocateVex_AL(G,position), dist);
	printf("到东门: ");
    if(ERROR==Outputpath(G, dist, LocateVex_AL(G, GATE_E))) printf("无此路径!");
	printf("\n到西门: ");
    if(ERROR==Outputpath(G, dist, LocateVex_AL(G, GATE_W))) printf("无此路径!");
	printf("\n到南门: ");
    if(ERROR==Outputpath(G, dist, LocateVex_AL(G, GATE_S))) printf("无此路径!");
	printf("\n到北门: ");
    if(ERROR==Outputpath(G, dist, LocateVex_AL(G, GATE_N))) printf("无此路径!");
	printf("\n\n");
}

/**
 * @name getEscapeRote
 * @brief 显示逃生路径的函数
 * @param   
 * @return Status  
 */
Status getEscapeRote(){
    ALGraph G;
    InitGroup(G);
    int position;
    do {
		PositionMenu();
        position = InputInteger();
        if(position==0){
            break;
        }else if (position<6&&position>0){
            SOSFuction(G,position);
        }else{
            printf("输出有误!请重新输入!\n");
        }
        Pause();
        Clean();
	} while (position!=0);
	//if (SUCCESS != DeatroyDG_AL(G)) printf("销毁失败!");
    return SUCCESS;
}

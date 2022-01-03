/*
* @Description: 图的接口
* @Author: SuzyMo
* @date: 2022-01-02 13:36:58
*/

#include"Common.h"

#define UNVISITED 0
#define VISITED 1
#define UNSELECTED 0
#define SELECTED 1
#define INFINITY 32567 //计算机允许的整数最大值
#define NAMESIZE 20



//图的4种类型：有向图，有向带权图，无向图，无向带权图。
typedef enum { DG, DN, UDG, UDN } GraphKind;

typedef struct {
	int num;
	char name[NAMESIZE];
}VexType;

//图结构
typedef struct {
	VexType v, w;
	int info;
}ArcInfo;

typedef struct AdjVexNode {
	int adjvex; //邻接顶点在顶点数组中的位序     
	struct AdjVexNode *nextArc; //指向下一个邻接顶点(下一条边或弧)
	int info;   //存储边(弧)相关信息，对于非带权图可不用
}AdjVexNode, *AdjVexNodePtr;

typedef struct VexNode {
	VexType data;   //顶点值，VexType是顶点类型，由用户定义
	struct AdjVexNode *firstArc;    //邻接链表的头指针
}VexNode;   //顶点数组的元素类型

typedef struct {
	VexNode *vexs;
	int n, e;
	GraphKind kind;
	int *tags;
}ALGraph;

typedef struct {
	int prev;//当前最短路径上改顶点的前驱顶点的位序
	int lowcost;//当前最短路径的长度
}DistInfo,*Dist; //V-U中顶点的当前最短路径信息


/**
 * @brief 创建含n个顶点和e条弧的有向图G
 *
 * @param G
 * @param vexs
 * @param n
 * @param arcs
 * @param e
 * @return Status
 */
Status createDG_AL(ALGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e);

/**
 * @brief 查找顶点v在图G中的位序
 *
 * @param G
 * @param v
 * @return int
 */
int LocateVex_AL(ALGraph G, int num);

/**
 * @brief 查找图G中k顶点对应邻接链表中的第一个节点，若存在，返回其位序，
 *        并令指针p指向该节点，否则，返回-1，并令指针p为NULL。
 *
 * @param G
 * @param k
 * @param p
 * @return int
 */
int FirstAdjVex_AL(ALGraph G, VexType e);

/**
 * @brief 查找图G中k顶点对应邻接链表中的下一个节点，若存在，返回其位序，
 *        并令指针p指向该节点，否则，返回-1，并令指针p为NULL。
 *
 * @param G
 * @param k
 * @param p
 * @return int
 */
int NextAdjVex_AL(ALGraph G, int k, AdjVexNodePtr &p);

/**
 * @brief 销毁
 *
 * @param G
 * @return Status
 */
Status DeatroyDG_AL(ALGraph &G);

/**
 * @brief 在图G中删除k顶点到m顶点的边
 *
 * @param G
 * @param k
 * @param m
 * @return Status
 */
Status Delarc_AL(ALGraph& G, int k, int m);

/**
 * @brief 迪杰斯特拉算法求最短路径
 *
 * @param G Dist
 * @return Status
 */
Status Dijkstra(ALGraph G, int i, Dist &Dist);

/**
 * @brief 输出源点的到k顶点的最短路径
 *
 * @param G Dist k
 */
Status Outputpath(ALGraph G, DistInfo *Dist, int k);
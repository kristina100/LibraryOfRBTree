/*
* @Description: ͼ�Ľӿ�
* @Author: SuzyMo
* @date: 2022-01-02 13:36:58
*/

#include"Common.h"

#define UNVISITED 0
#define VISITED 1
#define UNSELECTED 0
#define SELECTED 1
#define INFINITY 32567 //�����������������ֵ
#define NAMESIZE 20



//ͼ��4�����ͣ�����ͼ�������Ȩͼ������ͼ�������Ȩͼ��
typedef enum { DG, DN, UDG, UDN } GraphKind;

typedef struct {
	int num;
	char name[NAMESIZE];
}VexType;

//ͼ�ṹ
typedef struct {
	VexType v, w;
	int info;
}ArcInfo;

typedef struct AdjVexNode {
	int adjvex; //�ڽӶ����ڶ��������е�λ��     
	struct AdjVexNode *nextArc; //ָ����һ���ڽӶ���(��һ���߻�)
	int info;   //�洢��(��)�����Ϣ�����ڷǴ�Ȩͼ�ɲ���
}AdjVexNode, *AdjVexNodePtr;

typedef struct VexNode {
	VexType data;   //����ֵ��VexType�Ƕ������ͣ����û�����
	struct AdjVexNode *firstArc;    //�ڽ������ͷָ��
}VexNode;   //���������Ԫ������

typedef struct {
	VexNode *vexs;
	int n, e;
	GraphKind kind;
	int *tags;
}ALGraph;

typedef struct {
	int prev;//��ǰ���·���ϸĶ����ǰ�������λ��
	int lowcost;//��ǰ���·���ĳ���
}DistInfo,*Dist; //V-U�ж���ĵ�ǰ���·����Ϣ


/**
 * @brief ������n�������e����������ͼG
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
 * @brief ���Ҷ���v��ͼG�е�λ��
 *
 * @param G
 * @param v
 * @return int
 */
int LocateVex_AL(ALGraph G, int num);

/**
 * @brief ����ͼG��k�����Ӧ�ڽ������еĵ�һ���ڵ㣬�����ڣ�������λ��
 *        ����ָ��pָ��ýڵ㣬���򣬷���-1������ָ��pΪNULL��
 *
 * @param G
 * @param k
 * @param p
 * @return int
 */
int FirstAdjVex_AL(ALGraph G, VexType e);

/**
 * @brief ����ͼG��k�����Ӧ�ڽ������е���һ���ڵ㣬�����ڣ�������λ��
 *        ����ָ��pָ��ýڵ㣬���򣬷���-1������ָ��pΪNULL��
 *
 * @param G
 * @param k
 * @param p
 * @return int
 */
int NextAdjVex_AL(ALGraph G, int k, AdjVexNodePtr &p);

/**
 * @brief ����
 *
 * @param G
 * @return Status
 */
Status DeatroyDG_AL(ALGraph &G);

/**
 * @brief ��ͼG��ɾ��k���㵽m����ı�
 *
 * @param G
 * @param k
 * @param m
 * @return Status
 */
Status Delarc_AL(ALGraph& G, int k, int m);

/**
 * @brief �Ͻ�˹�����㷨�����·��
 *
 * @param G Dist
 * @return Status
 */
Status Dijkstra(ALGraph G, int i, Dist &Dist);

/**
 * @brief ���Դ��ĵ�k��������·��
 *
 * @param G Dist k
 */
Status Outputpath(ALGraph G, DistInfo *Dist, int k);
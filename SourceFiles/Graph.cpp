/*
* @Description: 图的相关操作接口的实现
* @Author: SuzyMo
* @date: 2022-01-02 13:41:56
*/

#include"Graph.h"

/**
 * @brief 创建含n个顶点和e条弧的有向图G
 */
Status createDG_AL(ALGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e) {

	int i, j, k;
	VexType v, w;
	AdjVexNodePtr p;

	//读入定点数和弧数
	G.n = n; G.e = e;
	G.vexs = (VexNode*)malloc(n * sizeof(VexNode));
	G.tags = (int*)malloc(n * sizeof(int));

	//初始化标志数组和建立顶点数组
	for (i = 0; i < G.n; i++) {
		G.tags[i] = UNVISITED;
		G.vexs[i].data = vexs[i];
		G.vexs[i].firstArc = NULL;
	}
	//建立邻接链表
	for (k = 0; k < G.e; k++) {
		v = arcs[k].v; w = arcs[k].w;
		//确定v和w的位序i和j
		i = LocateVex_AL(G, v.num);
		j = LocateVex_AL(G, w.num);

		//顶点v或w不存在
		if (i < 0 || j < 0) return ERROR;
		//为顶点w分配p结点
		p = (AdjVexNodePtr)malloc(sizeof(AdjVexNode));
		if (p == NULL) return OVERFLOW;
		p->adjvex = j;
		p->info = arcs[k].info;
		//在i顶点的邻接链表表头插入p结点
		p->nextArc = G.vexs[i].firstArc;
		G.vexs[i].firstArc = p;
	}

	return SUCCESS;
}

/**
 * @brief 查找顶点v在图G中的位序
 */
int LocateVex_AL(ALGraph G, int num) {

	int i;
	for (i = 0; i < G.n; i++)
		if (num == G.vexs[i].data.num) return i;

	return -1;
}

/**
 * @brief 查找图G中k顶点对应邻接链表中的第一个节点，若存在，返回其位序，
 *        并令指针p指向该节点，否则，返回-1，并令指针p为NULL。
 */
int FirstAdjVex_AL_OLD(ALGraph G, int k, AdjVexNodePtr &p) {

	//k顶点不存在
	if (k < 0 || k >= G.n) return -1;

	p = G.vexs[k].firstArc;

	//返回第一个结点存储的顶点位序
	if (p != NULL) return p->adjvex;
	else return -1;
}

int FirstAdjVex_AL(ALGraph G, VexType e) {


	int k = LocateVex_AL(G,e.num);

	if (k < 0 || k >= G.n) return -1;

	AdjVexNodePtr p = G.vexs[k].firstArc;

	//返回第一个结点存储的顶点位序
	if (p != NULL) return p->adjvex;
	else return -1;
}

/**
 * @brief 查找图G中k顶点对应邻接链表中的下一个节点，若存在，返回其位序，
 *        并令指针p指向该节点，否则，返回-1，并令指针p为NULL。
 */
int NextAdjVex_AL(ALGraph G, int k, AdjVexNodePtr &p) {

	//k顶点不存在
	if (k < 0 || k >= G.n) return -1;
	if (p == NULL) return -1;

	p = p->nextArc;

	if (p != NULL) return p->adjvex;
	else return -1;
}

int NextAdjVex_ALM(ALGraph G, int k, int m) {
	//k顶点不存在
	if (k < 0 || k >= G.n) return -1;
	if (m < 0 || m >= G.n) return -1;
	AdjVexNodePtr p = G.vexs[m].firstArc;
	for (int i = 0; i < m; i++) {
		p = p->nextArc;
	}
	if (p != NULL) return p->nextArc->adjvex;
	else return -1;
}
/**
 * @brief 销毁
 *
 * @param G
 * @return Status
 */
Status DeatroyDG_AL(ALGraph &G) {
	AdjVexNode* p, *temp;
	for (int i = 0; i < G.n; i++) {
		p = G.vexs[i].firstArc;
		for (int j = 0; p != NULL; j++) {
			temp = p;
            if(NULL!=p->nextArc)
			    p = p->nextArc;
            temp->nextArc=NULL;
			free(temp);
            temp = NULL;
            
		}
		printf("\n");
	}
	free(G.vexs);
	free(G.tags);
	return SUCCESS;
}

int Degree_AL(ALGraph G, int k) {//无权图
	if (k < 0 || k >= G.n) return -1;
	AdjVexNode* p, *q;
	q = G.vexs[k].firstArc;
	int dep = 0;
	if (G.kind == UDG) {
		while (q) {
			dep++;
			q = q->nextArc;
		}
	}
	else {
		for (int i = 0; i < G.n; i++) {
			p = G.vexs[i].firstArc;
			if (i == k) {
				for (int j = 0; p != NULL; j++) {
					dep++;
					p = p->nextArc;
				}
			}
			else {
				for (int j = 0; p != NULL; j++) {
					if (p->adjvex == k)dep++;
					p = p->nextArc;
				}
			}
		}
	}

	return dep;
}

Status Delarc_AL(ALGraph& G, int k, int m)//在图G中删除k顶点到m顶点的边
{
	AdjVexNodePtr p = G.vexs[k].firstArc;
	if (p == NULL)
		return ERROR;
	if (p->adjvex == m)
	{
		G.vexs[k].firstArc = p->nextArc;
		free(p);
	}
	else {
		while (p != NULL)
		{
			if (p->nextArc->adjvex == m)
			{
				p->nextArc = p->nextArc->nextArc;
			}
			p = p->nextArc;
		}
	}
	if (G.kind == DG)
		return SUCCESS;
	else if (G.kind == UDG)
	{
		AdjVexNodePtr q = G.vexs[m].firstArc;
		if (q->adjvex == k)
		{
			G.vexs[m].firstArc = q->nextArc;
			free(q);
		}
		else {
			while (q != NULL)
			{
				if (q->nextArc->adjvex == k)
				{
					q->nextArc = q->nextArc->nextArc;
				}
				q = q->nextArc;
			}
		}

	}

	return SUCCESS;


}

Status Dijkstra(ALGraph G, int i, Dist &Dist) {
	//求图G中从i顶点到其他顶点所有顶点的最短路径，并由Dist返回
	int j, m, k, min;
	AdjVexNodePtr p;
	Dist = (DistInfo*)malloc(G.n * sizeof(DistInfo));
	for (j = 0; j < G.n; j++) {//初始化
		Dist[j].lowcost = INFINITY;
		G.tags[j] = UNSELECTED;//所有顶点均不在集合U中
	}
	for (p = G.vexs[i].firstArc; p != NULL; p = p->nextArc) {
		//源点i引出的所有弧的信息出入Dist
		Dist[p->adjvex].prev = i;
		Dist[p->adjvex].lowcost = p->info;
	}
	Dist[i].prev = -1;
	Dist[i].lowcost = 0;//将源点信息存入Dist
	G.tags[i] = SELECTED;//初始集合仅含源点i
	for (m = 1; m < G.n; m++) {
		min = INFINITY;
		k = 0;
		for (j = 0; j < G.n; j++) 
			if (0 == G.tags[j] && Dist[j].lowcost < min) {
				k = j;
				min = Dist[k].lowcost;
			}
		G.tags[k] = SELECTED;//将k顶点加入集合U
		for (p = G.vexs[k].firstArc; p != NULL; p = p->nextArc) {
			//更新Dist数组
			j = p->adjvex;
			if (UNSELECTED == G.tags[j] && (Dist[k].lowcost + p->info )< Dist[j].lowcost) {
				Dist[j].lowcost = Dist[k].lowcost + p->info;
				Dist[j].prev = k;
			}
		}
	}
	return SUCCESS;
}

Status Outputpath(ALGraph G, DistInfo *Dist, int k) {
	//沿Dist数组的prev域，可递归得到源点到k顶点的最短路径
	if (-1 == k) return SUCCESS ;
	if (k < 0) return OVERFLOW;
	if(OVERFLOW == Outputpath(G, Dist, Dist[k].prev)) return ERROR ;//逆向递归获取路径上的顶点
	if (0 == Dist[k].lowcost) 
		printf("%s", G.vexs[k].data.name);//正向输出
	else
	    printf("---(%dm)--->%s",  Dist[k].lowcost, G.vexs[k].data.name);//正向输出
	return SUCCESS;
}
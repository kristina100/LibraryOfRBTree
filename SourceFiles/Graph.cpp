/*
* @Description: ͼ����ز����ӿڵ�ʵ��
* @Author: SuzyMo
* @date: 2022-01-02 13:41:56
*/

#include"Graph.h"

/**
 * @brief ������n�������e����������ͼG
 */
Status createDG_AL(ALGraph &G, VexType *vexs, int n, ArcInfo *arcs, int e) {

	int i, j, k;
	VexType v, w;
	AdjVexNodePtr p;

	//���붨�����ͻ���
	G.n = n; G.e = e;
	G.vexs = (VexNode*)malloc(n * sizeof(VexNode));
	G.tags = (int*)malloc(n * sizeof(int));

	//��ʼ����־����ͽ�����������
	for (i = 0; i < G.n; i++) {
		G.tags[i] = UNVISITED;
		G.vexs[i].data = vexs[i];
		G.vexs[i].firstArc = NULL;
	}
	//�����ڽ�����
	for (k = 0; k < G.e; k++) {
		v = arcs[k].v; w = arcs[k].w;
		//ȷ��v��w��λ��i��j
		i = LocateVex_AL(G, v.num);
		j = LocateVex_AL(G, w.num);

		//����v��w������
		if (i < 0 || j < 0) return ERROR;
		//Ϊ����w����p���
		p = (AdjVexNodePtr)malloc(sizeof(AdjVexNode));
		if (p == NULL) return OVERFLOW;
		p->adjvex = j;
		p->info = arcs[k].info;
		//��i������ڽ������ͷ����p���
		p->nextArc = G.vexs[i].firstArc;
		G.vexs[i].firstArc = p;
	}

	return SUCCESS;
}

/**
 * @brief ���Ҷ���v��ͼG�е�λ��
 */
int LocateVex_AL(ALGraph G, int num) {

	int i;
	for (i = 0; i < G.n; i++)
		if (num == G.vexs[i].data.num) return i;

	return -1;
}


/**
 * @brief ����
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


Status Delarc_AL(ALGraph& G, int k, int m)//��ͼG��ɾ��k���㵽m����ı�
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
	//��ͼG�д�i���㵽�����������ж�������·��������Dist����
	int j, m, k, min;
	AdjVexNodePtr p;
	Dist = (DistInfo*)malloc(G.n * sizeof(DistInfo));
	for (j = 0; j < G.n; j++) {//��ʼ��
		Dist[j].lowcost = INFINITY;
		G.tags[j] = UNSELECTED;//���ж�������ڼ���U��
	}
	for (p = G.vexs[i].firstArc; p != NULL; p = p->nextArc) {
		//Դ��i���������л�����Ϣ����Dist
		Dist[p->adjvex].prev = i;
		Dist[p->adjvex].lowcost = p->info;
	}
	Dist[i].prev = -1;
	Dist[i].lowcost = 0;//��Դ����Ϣ����Dist
	G.tags[i] = SELECTED;//��ʼ���Ͻ���Դ��i
	for (m = 1; m < G.n; m++) {
		min = INFINITY;
		k = 0;
		for (j = 0; j < G.n; j++) 
			if (0 == G.tags[j] && Dist[j].lowcost < min) {
				k = j;
				min = Dist[k].lowcost;
			}
		G.tags[k] = SELECTED;//��k������뼯��U
		for (p = G.vexs[k].firstArc; p != NULL; p = p->nextArc) {
			//����Dist����
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
	//��Dist�����prev�򣬿ɵݹ�õ�Դ�㵽k��������·��
	if (-1 == k) return SUCCESS ;
	if (k < 0) return OVERFLOW;
	if(OVERFLOW == Outputpath(G, Dist, Dist[k].prev)) return ERROR ;//����ݹ��ȡ·���ϵĶ���
	if (0 == Dist[k].lowcost) 
		printf("%s", G.vexs[k].data.name);//�������
	else
	    printf("---(%dm)--->%s",  Dist[k].lowcost, G.vexs[k].data.name);//�������
	return SUCCESS;
}
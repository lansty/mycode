#include<iostream>
using namespace std;
#define MAXVEX 100
bool visited[MAXVEX];
int que[MAXVEX];	
int rear,front;
typedef struct EdgeNode
{
	int adjvex;
	int weight;
	struct EdgeNode *next;
} EdgeNode;

typedef struct VexNode
{
	int data;
	EdgeNode *firstedge;
} VertexNode,Adjlist[MAXVEX];

typedef struct
{
	Adjlist adjlist;
	int numVexs,numEdges;
}Graph;
void GreatGraph(Graph *G)
{
	
	cout<<"请输入顶点个数和边的条数：";
	cin>>G->numVexs>>G->numEdges;
	for(int i = 0;i < G->numVexs;i++)
	{
		G->adjlist[i].data = i+1;
		G->adjlist[i].firstedge = NULL;
	}
	
	for(int k = 0;k < G->numEdges;k++)
	{
		int i ,j;
		cout<<"请输入（vi,vj)对应的下标号：";
		cin>>i>>j;
		EdgeNode *p  = new EdgeNode;
		p->adjvex = j;
		p->next = G->adjlist[i].firstedge;
		G->adjlist[i].firstedge = p;
		
		p  = new EdgeNode;
		p->adjvex = i;
		p->next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = p;	
	} 
	
}
void DFS(Graph *G,int i)
{
	EdgeNode *p;
	visited[i] = true;
	cout<<G->adjlist[i].data<<" ";
	p = G->adjlist[i].firstedge;
	while(p!=NULL)
	{
		if(!visited[p->adjvex])
			DFS(G,p->adjvex);
		p = p->next;	
	}
}

void create_dfs(Graph *G)
{
	for(int i = 0;i < G->numVexs;i++)
		visited[i] = false;
		
	for(int i = 0;i < G->numVexs;i++)
	{
		if(!visited[i])
		    DFS(G,i);	
		
	}		
}



void BFS(Graph *G,int i)
{
	if(!visited[i])
	{
		visited[i] = true;
		rear = (rear + 1)%MAXVEX;
		que[rear]  = i;
		cout<<G->adjlist[i].data<<" ";
		while(rear != front)
		{
			front = (front + 1) % MAXVEX;
			EdgeNode *p = G->adjlist[que[front]].firstedge;
			while(p)
			{
				if(!visited[p->adjvex])
				{
					visited[p->adjvex] = true;
					cout<<G->adjlist[p->adjvex].data<<" ";
					rear = (rear + 1)%MAXVEX;
					que[rear]  = p->adjvex;
				}
				p = p->next;	
			}			
		}	
	}		
}

void BFSTraverse(Graph *G)
{
	for(int i = 0;i < G->numVexs;i++)
	{
		visited[i] = false;
		
	}
	for(int i = 0;i < G->numVexs;i++)
		if(!visited[i])
			BFS(G,i);
}
int main()
{
	Graph G;
	GreatGraph(&G);
	create_dfs(&G);//根据输入顺序的不同，遍历的结果也不一样！ 
	cout<<endl<<"---------------------------------------------"<<endl; 
	BFSTraverse(&G);
	return 0;	
} 
/*     
9 15
0 1
1 2
2 3
3 4
4 5
5 0
6 5
6 7 
6 1
6 3
7 3
7 4
8 1
8 2
8 3

*/

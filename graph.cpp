#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define INFINITY 65536
#define MAXVEX 100
typedef struct 
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertex,numEdge; 
}MGraph;
bool visited[MAXVEX];
void createMGraph(MGraph *G)//���ڽӾ���洢���ڵ�����+��ά�����ߵĹ�ϵ�� 
{
	cout<<"�����붥�����ͱ����� "<<endl;
	cin>>G->numVertex>>G->numEdge;
		cout<<"�����������ֵ ��"<<endl; 
	for(int i = 0;i < G->numVertex;i++)
		cin>>G->vexs[i];
	for(int i = 0;i < G->numVertex;i++)
		for(int j = 0;j < G->numVertex;j++)
			G->arc[i][j] = 0;
			
	for(int k = 0;k < G->numEdge;k++)
	{
		int i,j,w;
		cout<<"������ߣ�vi,vj)�����±�i,j��Ȩw :"<<endl;;
		cin>>i>>j>>w;
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];	
	}	
	for(int i = 0;i < G->numVertex;i++)
	{
		for(int j = 0;j < G->numVertex;j++)
			cout<<G->arc[i][j]<<" ";
			cout<<endl;
	}
			 		
} 


void DFS_Graph(MGraph *G,int i)//ͼ��ȱ������ݹ飩 
{
	visited[i] = true;
	cout<<G->vexs[i]<<" ";
	for(int j = 0;j < G->numVertex;j++)
		if(visited[j]==false && G->arc[i][j]==1)
			DFS_Graph(G,j);
}
 
void DFSTraverse(MGraph *G) 	
{
	for(int i = 0;i < G->numVertex;i++)
		visited[i] = false;
		
	for(int i = 0;i < G->numVertex;i++)
	{
		//cout<<"i"<<i<<endl;
		if(!visited[i]) 
		 	DFS_Graph(G,i);	
	}
		 
}

void BFSTraverse(MGraph *G)//��ȱ����� 
{
	int front,rear;
	bool visited[MAXVEX];
	int  que[MAXVEX];
	memset(que,0,sizeof(que));
	front = rear = 0;
	for(int i = 0;i < G->numVertex;i++)
		visited[i] = false;
  
	for(int i = 0;i < G->numVertex;i++)//������ͨͼֻ�Ǵ�ĳһ������������� 
	{
	 	  if(!visited[i]) 
	 	  {
	 	  		visited[i] = true;
	 	  		rear = (rear + 1)%MAXVEX;
				que[rear] =i;//���ַ���±꣩ 
				while(rear != front)
				{
					front = (front + 1)%MAXVEX;
					//cout<<endl<<"------------------------------------"<<endl;
				    int temp_cur = que[front];
					cout<<G->vexs[temp_cur]<<" ";
					//cout<<"temp_cur = :"<<temp_cur<<" ";	
					for(int j = 0;j < G->numVertex;j++)
					{
						
						if(G->arc[temp_cur][j] == 1 && !visited[j])
						{
							 visited[j] = true;
							  //cout<<endl<<"j = "<<j<<" ";
							 //cout<<G->vexs[j]<<" ";	 
							 rear = (rear + 1)%MAXVEX;//����� 
							 que[rear] = j;	
						}
						
					 } 			
				}
		   }
	}
	//cout<<"------------------------------------------"<<endl;
	//for(int i = 0;i < 10;i++)
	//	cout<<endl<<que[i]<<" ";	
}
int main()
{
	MGraph G;
	createMGraph(&G); 
	cout<<"DFS_Traverse: "<<endl;
	DFSTraverse(&G); 
	cout<<endl<<" BFS_Traverse:"<<endl;
	BFSTraverse(&G);	
	return 0;
}
/*                                                 
//�ڽӾ��� 
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
//�ڵ����� i��j,w: 
0 1 1
0 2 1
0 3 1
1 2 1
2 3 1
//�����ݽṹp242
���룺
9 15
1 2 3 4  5 6 7 8  9
0 1 1
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 7 1
4 7 1
3 7 1
3 6 1
3 8 1
1 6 1
1 8 1
2 8 1 
0 5 1
 */ 

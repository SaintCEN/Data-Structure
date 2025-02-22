#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int a[101][101];
int n, m;
int flag[101] = {0};
vector<int> bfs(int u) {
    vector<int> path;
    queue<pair<int, vector<int>>> q;
    path.push_back(u);
    q.push({u, path});
    flag[u] = 1;
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int node = front.first;
        vector<int> currentPath = front.second;
        if (node == n) {
            return currentPath; 
        }
        for (int i = 1; i <= n; i++) {
            if (a[node][i] == 1 && !flag[i]) {
                flag[i] = 1; 
                vector<int> newPath = currentPath; 
                newPath.push_back(i);
                path = newPath;
                q.push({i, newPath});
            }
        }
    }
    return path; 
}
int main() {
    cin >> n >> m;
    int p, q;

    for (int i = 0; i < m; i++) {
        cin >> p >> q;
        a[p][q] = 1;
        a[q][p] = 1;
    }
    vector<int> path = bfs(1);
    if (!path.empty() && path.back() == n) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    for (int i = 0; i < path.size(); i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
 
typedef struct Graph{
	int vexs[101];
	int arcs[101][101];
	int vexnum,arcnum;
}Graph;
 
typedef struct Queue{
	int data[101];
	int front;
	int rear;
}Queue;
 
void InitGraph(Graph *G,int vexnum,int arcnum){
	int i,j,prior,next;
	G->vexnum=vexnum;
	G->arcnum=arcnum;
	for(i=1;i<=vexnum;i++){
		G->vexs[i]=i;
	}
	for(i=1;i<=vexnum;i++){
		for(j=0;j<vexnum;j++){
			G->arcs[i][j]=0;
		}
	}
	for(i=1;i<=arcnum;i++){
		scanf("%d %d",&prior,&next);
		G->arcs[prior][next]=1;
		G->arcs[next][prior]=1; 
	}
}
 
void InitQueue(Queue *Q){ 
	Q->front=Q->rear=0;
}
 
void EnQueue(Queue *Q,int elem){ 
	Q->data[Q->rear]=elem;
	Q->rear++;
}
 
void OutQueue(Queue *Q,int *elem){  
	*elem=Q->data[Q->front];
	Q->front++;
}
 
int IsEmpty(Queue *Q){
    if(Q->rear==Q->front){
    	return 1;
	}else{
		return 0;
	}
}
 
void BFS(Graph *G,Queue *Q,int vexnum,int visited[],int v,int path[],int *pathindex){
	int i,j,flag=1,temp=1; 
	EnQueue(Q,v);
	visited[v]=1;
	while(!IsEmpty(Q)){
		OutQueue(Q,&temp);
		path[*(pathindex)]=temp;
		(*pathindex)++; 
		for(i=1;i<=G->vexnum;i++){
			if(G->arcs[temp][i]==1&&visited[i]==0){
				EnQueue(Q,i);
				visited[i]=1;
			}
		}
	} 
}
 
void Check(int path[],int pathindex,int vexnum){
	int i,flag=0;
	for(i=1;i<pathindex;i++){
		if(path[i]==vexnum){
			flag=1;
		}
	}
	if(flag==1){
		printf("YES\n");
		for(i=1;i<pathindex;i++){
			printf("%d ",path[i]);
			if(path[i]==vexnum){
				break;
			}
		}
	}else{
		printf("NO\n");
		for(i=1;i<pathindex;i++){
			printf("%d ",path[i]);
		}
	}
}
 
int main(){
    Graph G;
	Queue Q;
	int vexnum,arcnum,path[101],pathindex=1,i;
	scanf("%d %d",&vexnum,&arcnum);
	InitGraph(&G,vexnum,arcnum);
	InitQueue(&Q);
	int visited[vexnum+1];
	for(i=1;i<=vexnum;i++){
		visited[i]=0;
	} 
	BFS(&G,&Q,vexnum,visited,1,path,&pathindex);
	Check(path,pathindex,vexnum);
	return 0;
}
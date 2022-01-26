#include<stdio.h>
#include<stdlib.h>
#include <limits.h> //for INT_MAX and INT_MIN
char vertices[]={'A','B','C','D','E','F'};
int find_min(int dist[], int vis[],int n)
{
    int min=INT_MAX, min_index;
    for (int v=0; v<n; v++)
    if (vis[v] == 0 && dist[v] <= min) {
        min=dist[v];
        min_index=v;
    }
    return min_index;
}
void print(int *dist,int *previous,int st,int n)
{
    printf("Network ID \t Cost \t Next Hop\n");
    for (int i=0; i<n; i++) {
        if(i!=st) {
            printf("%c \t \t%d\t\t ", vertices[i], dist[i]);
            int *stack;
            stack= (int*)malloc(n*sizeof(int));
            int top=-1;
            top=0;
            stack[top]=i;
            while(stack[top]!=st) {
                stack[top+1]=previous[stack[top]];
                top++;
            }
            if(top>=2)printf("%c\n",vertices[stack[top-1]]);
            else printf("--  \n");
        }
    }
}

void dijkstra(int **adj, int st,int *dist,int *previous,int n)
{
    int *vis;
    vis =(int *)malloc(n*sizeof(int));
    for (int i=0;i<n;i++) vis[i]=0;
    dist[st]=0;
    previous[st]=st;
    for (int i=0; i<n-1; i++) {
        int u=find_min(dist,vis,n);
            vis[u]=1;
            for (int j=0; j<n; j++) {
                if (vis[j]==0 && adj[u][j]!=0 && dist[u]+adj[u][j]<dist[j]) {
                dist[j]=dist[u] + adj[u][j];
                previous[j]=u;
            }
        }
    }
    for (int i=0;i<n;i++) printf("%d ",previous[i]);
}

int main() {
    int n;
    int **adj,*dist,*previous;
    printf("enter the number of vertices : ");
    scanf("%d",&n);
    previous=(int*)malloc(n*sizeof(int));
    dist=(int*)malloc(n*sizeof(int));
    adj=(int**)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++) {
        adj[i]=(int *)malloc(n*sizeof(int));
    }
    printf("0 is considered as there is no edge between the vertices\nEdges : \n");
    int d;
    for (int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) d=0;
            else {
                printf("%d->%d : ",i,j);
                scanf("%d",&d);
                adj[i][j]=d;
            }
        }
    }
    for(int i=0;i<n;i++) {
        for (int j=0; j<n; j++) dist[j]=INT_MAX;
        printf("\n");
        dijkstra(adj,i,dist,previous,n);
        printf("\n");
        printf(" NODE %c \n",vertices[i]);
        print(dist,previous,i,n);
    }
}

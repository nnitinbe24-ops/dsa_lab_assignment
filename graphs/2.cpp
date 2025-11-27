#include <iostream>
using namespace std;

class Graph {
    int n;
    int adj[50][50];
public:
    Graph(int v){
        n=v;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                adj[i][j]=0;
    }
    void addEdge(int u,int v){
        adj[u][v]=1;
        adj[v][u]=1;
    }
    void BFS(int s){
        int q[50],front=0,rear=0;
        int vis[50];
        for(int i=0;i<n;i++) vis[i]=0;
        q[rear++]=s;
        vis[s]=1;
        while(front<rear){
            int u=q[front++];
            cout<<u<<" ";
            for(int v=0;v<n;v++){
                if(adj[u][v] && !vis[v]){
                    vis[v]=1;
                    q[rear++]=v;
                }
            }
        }
    }
};

int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.BFS(0);
}
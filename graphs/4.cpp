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
    void addEdge(int u,int v,int w){
        adj[u][v]=w;
    }
    void Dijkstra(int src){
        int dist[50],vis[50];
        for(int i=0;i<n;i++){
            dist[i]=9999;
            vis[i]=0;
        }
        dist[src]=0;
        for(int c=0;c<n;c++){
            int u=-1,minV=9999;
            for(int i=0;i<n;i++)
                if(!vis[i] && dist[i]<minV){
                    minV=dist[i];
                    u=i;
                }
            vis[u]=1;
            for(int v=0;v<n;v++){
                if(adj[u][v] && dist[u]+adj[u][v] < dist[v])
                    dist[v] = dist[u] + adj[u][v];
            }
        }
        for(int i=0;i<n;i++)
            cout<<i<<" "<<dist[i]<<endl;
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1,10);
    g.addEdge(0,4,5);
    g.addEdge(1,2,1);
    g.addEdge(4,1,3);
    g.addEdge(4,2,9);
    g.addEdge(2,3,4);
    g.addEdge(3,0,7);
    g.Dijkstra(0);
}
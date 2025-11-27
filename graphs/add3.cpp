#include <iostream>
using namespace std;

class Graph {
    int n;
    int adj[50][50];
    int dist[50];
    int vis[50];
public:
    Graph(int v){
        n=v;
        for(int i=0;i<n;i++){
            dist[i]=999999;
            vis[i]=0;
            for(int j=0;j<n;j++)
                adj[i][j]=0;
        }
    }
    void addEdge(int u,int v,int w){
        adj[u][v]=w;
    }
    int Dijkstra(int src){
        dist[src]=0;
        for(int k=0;k<n;k++){
            int u=-1,minV=999999;
            for(int i=0;i<n;i++){
                if(!vis[i] && dist[i]<minV){
                    minV=dist[i];
                    u=i;
                }
            }
            if(u==-1) break;
            vis[u]=1;
            for(int v=0;v<n;v++){
                if(adj[u][v] && dist[u]+adj[u][v] < dist[v])
                    dist[v] = dist[u] + adj[u][v];
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            if(dist[i]==999999) return -1;
            if(dist[i]>mx) mx=dist[i];
        }
        return mx;
    }
};

int main(){
    int N,E,K;
    cin>>N>>E>>K;
    Graph g(N);
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u-1,v-1,w);
    }
    cout<<g.Dijkstra(K-1);
}
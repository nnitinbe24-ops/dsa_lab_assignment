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
    void dfsUtil(int u,int vis[]){
        vis[u]=1;
        for(int v=0;v<n;v++)
            if(adj[u][v] && !vis[v])
                dfsUtil(v,vis);
    }
    int countComponents(){
        int vis[50];
        for(int i=0;i<n;i++) vis[i]=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfsUtil(i,vis);
            }
        }
        return count;
    }
};

int main(){
    int V,E;
    cin>>V>>E;
    Graph g(V);
    for(int i=0;i< E;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    cout<<g.countComponents();
}
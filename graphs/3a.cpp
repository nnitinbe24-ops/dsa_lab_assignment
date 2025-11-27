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
        adj[v][u]=w;
    }
    int findSet(int parent[],int i){
        while(parent[i]!=i) i=parent[i];
        return i;
    }
    void Kruskal(){
        int parent[50];
        for(int i=0;i<n;i++) parent[i]=i;
        int edges=0;
        while(edges<n-1){
            int minW=9999,a=-1,b=-1;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][j] && adj[i][j]<minW){
                        minW=adj[i][j];
                        a=i; b=j;
                    }
                }
            }
            int s1=findSet(parent,a);
            int s2=findSet(parent,b);
            if(s1!=s2){
                cout<<a<<" "<<b<<" "<<minW<<endl;
                parent[s2]=s1;
                edges++;
            }
            adj[a][b]=adj[b][a]=0;
        }
    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(0,2,6);
    g.addEdge(0,3,5);
    g.addEdge(1,3,15);
    g.addEdge(2,3,4);
    g.Kruskal();
}
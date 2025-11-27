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
    void Prim(){
        int selected[50];
        for(int i=0;i<n;i++) selected[i]=0;
        selected[0]=1;
        int edges=0;
        while(edges<n-1){
            int minW=9999,x=-1,y=-1;
            for(int i=0;i<n;i++){
                if(selected[i]){
                    for(int j=0;j<n;j++){
                        if(!selected[j] && adj[i][j] && adj[i][j]<minW){
                            minW=adj[i][j];
                            x=i; y=j;
                        }
                    }
                }
            }
            selected[y]=1;
            cout<<x<<" "<<y<<" "<<minW<<endl;
            edges++;
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1,2);
    g.addEdge(0,3,6);
    g.addEdge(1,2,3);
    g.addEdge(1,3,8);
    g.addEdge(1,4,5);
    g.addEdge(2,4,7);
    g.Prim();
}
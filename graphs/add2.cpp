#include <iostream>
using namespace std;

class Grid {
    int m,n;
    int cost[50][50];
    int dist[50][50];
    int vis[50][50];
public:
    Grid(int r,int c){
        m=r; n=c;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                dist[i][j]=999999;
                vis[i][j]=0;
            }
    }
    void setCost(int i,int j,int val){
        cost[i][j]=val;
    }
    int Dijkstra(){
        dist[0][0]=cost[0][0];
        for(int k=0;k<m*n;k++){
            int x=-1,y=-1,minV=999999;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(!vis[i][j] && dist[i][j]<minV){
                        minV=dist[i][j];
                        x=i; y=j;
                    }
                }
            }
            vis[x][y]=1;
            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};
            for(int t=0;t<4;t++){
                int nx=x+dx[t];
                int ny=y+dy[t];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    if(dist[x][y] + cost[nx][ny] < dist[nx][ny])
                        dist[nx][ny] = dist[x][y] + cost[nx][ny];
                }
            }
        }
        return dist[m-1][n-1];
    }
};

int main(){
    int m,n;
    cin>>m>>n;
    Grid g(m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int v;
            cin>>v;
            g.setCost(i,j,v);
        }
    }
    cout<<g.Dijkstra();
}
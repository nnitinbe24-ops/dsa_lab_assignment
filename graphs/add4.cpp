#include <iostream>
using namespace std;

class Grid {
    int m,n;
    char g[50][50];
    int vis[50][50];
public:
    Grid(int r,int c){
        m=r; n=c;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                vis[i][j]=0;
    }
    void setVal(int i,int j,char v){
        g[i][j]=v;
    }
    void dfs(int x,int y){
        vis[x][y]=1;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=0 && nx<m && ny>=0 && ny<n){
                if(g[nx][ny]=='1' && !vis[nx][ny])
                    dfs(nx,ny);
            }
        }
    }
    int countIslands(){
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        return cnt;
    }
};

int main(){
    int m,n;
    cin>>m>>n;
    Grid obj(m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            obj.setVal(i,j,c);
        }
    }
    cout<<obj.countIslands();
}
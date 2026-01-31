#include<bits/stdc++.h>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<string>grid(N);
    for(int i=0;i<N;i++) cin>>grid[i];
    int sx,sy,ex,ey;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            if(grid[i][j]=='A'){
                sx=i;sy=j;
            }
            if(grid[i][j]=='B'){
                ex=i;ey=j;
            }
    }
    vector<vector<int>>vis(N,vector<int>(M,0));
    queue<pair<int,int>>q;
    q.push({sx,sy});
    vis[sx][sy]=1;
    while(!q.empty()){
        pair<int,int>p=q.front();
        q.pop();
        int x=p.first,y=p.second;
        if(x==ex&&y==ey){
            cout<<"YES\n";
            return 0;
        }
        for(int d=0;d<4;d++){
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=0&&nx<N&&ny>=0&&ny<M){
                if(!vis[nx][ny]&&grid[nx][ny]!='#'){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout<<"NO\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MX=1005;
int N,M;
string gd[MX];
bool vis[MX][MX];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int dfs(int x, int y){
    vis[x][y]=true;
    int cnt=1;
    for(int d=0; d<4; d++){
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(nx>=0 && nx<N && ny>=0 && ny<M){
            if(!vis[nx][ny] && gd[nx][ny]=='.'){
                cnt += dfs(nx,ny);
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>gd[i];
    }
    vector<int>ans;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(gd[i][j]=='.' && !vis[i][j]){
                int x=dfs(i, j);
                ans.push_back(x);
            }
        }
    }

    if(ans.size()>0){
        sort(ans.begin(),ans.end());
        for(auto u:ans){
            cout<<u<<' ';
        }
        cout<<endl;
    }
    else cout<<0<<endl;
    return 0;
}

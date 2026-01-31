#include <bits/stdc++.h>
using namespace std;

int adj[1005][1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,E;
    cin>>N>>E;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            adj[i][j]=0;
        }
    }
    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    int Q;
    cin >> Q;

    while(Q--){
        int X;
        cin>>X;

        bool found=0;

        for(int i=N-1; i>=0; i--){
            if(adj[X][i]){
                if(found) cout<<" ";
                cout<<i;
                found=true;
            }
        }

        if(!found) cout << -1;
        cout<<"\n";
    }
    
    return 0;
}

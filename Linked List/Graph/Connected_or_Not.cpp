#include <bits/stdc++.h>
using namespace std;

int adj[1005][1005];

int main(){
    int N,E;
    cin>>N>>E;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            adj[i][j]=0;
            adj[i][i]=0;
            adj[j][j]=0;
        }
    }
    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;   
        adj[u][u]=1;   
        adj[v][v]=1;   
    }

    int Q; cin>>Q;

    while(Q--){
        int A,B;
        cin>>A>>B;
        if(adj[A][B]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}

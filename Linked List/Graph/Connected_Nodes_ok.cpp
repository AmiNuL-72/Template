#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,E;
    cin>>N>>E;

    vector<vector<int>>adj(N);

    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);   
    }

    for(int i=0; i<N; i++){
        sort(adj[i].begin(),adj[i].end(),greater<int>());
    }

    int Q; cin>>Q;

    while(Q--){
        int X;
        cin>>X;
        if(adj[X].empty()){
            cout<<-1<<"\n";
        }
        else{
            for(int i=0; i<adj[X].size(); i++){
                if(i) cout<<" ";
                cout<<adj[X][i];
            }
            cout<<"\n";
        }
    }

    return 0;
}

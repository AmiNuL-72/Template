#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin>>N>>M;

    stack<int>st;
    queue<int>q;

    for(int i=0; i<N; i++){
        int x; cin>>x;
        st.push(x);
    }
    for(int i=0; i<M; i++){
        int x; cin>>x;
        q.push(x);
    }
    if(N!=M){
        cout<<"NO\n"; return 0;
    }
    while(!st.empty() && !q.empty()){
        if(st.top() != q.front()){
            cout<<"NO\n"; return 0;
        }
        st.pop();
        q.pop();
    }

    cout<<"YES\n";

    return 0;
}

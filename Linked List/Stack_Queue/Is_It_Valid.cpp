#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;

    while(T--){
        string S; cin>>S;
        stack<char>st;
        for(auto c : S){
            if(!st.empty() && st.top()!= c){
                st.pop();
            }
            else st.push(c);
        }

        if(st.empty()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

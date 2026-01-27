#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    list<ll>l; 
    int Q; cin>>Q;

    while(Q--){
        ll X,V;
        cin>>X>>V;

        if(X == 0){
            l.push_front(V);
        }
        else if(X == 1){
            l.push_back(V);
        }

        else if(X == 2){
            if(V<0 || V>=l.size()){
                // invalid index -> nothing
            }
            else{
                auto it = l.begin();
                for(ll i=0; i<V; i++) it++;
                l.erase(it);
            }
        }

        cout<<"L ->";
        for(auto u:l) cout<<' '<<u;
        cout<<endl;

        cout<<"R ->";
        for(auto it = l.rbegin(); it != l.rend(); it++){
            cout<<' '<<*it;
        }
        cout<<endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll   long long

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll vis[200005];

ll fun(ll i,vector<ll>v){
    if(vis[i] != -1){
        return vis[i];
    }
    ll x=0;
    for(ll j=i+1; j<v.size(); j++){
       if(v[j]>v[i]) x=max(x,fun(j,v));
    }
    vis[i]=x+1;
    return vis[i];
}

void lis(ll n, vector<ll>v){
    for(ll i=0; i<n; i++) vis[i]=-1;
    ll len_of_lis=0;
    for(ll i=0; i<n; i++){
        len_of_lis=max(len_of_lis,fun(i,v));
    }
    cout<<len_of_lis<<endl;
}

void solve(){
    ll n; cin>>n;
    vector<ll>v(n);
    // map<ll,ll>mp;
    for(ll i=0; i<n; i++){
        cin>>v[i];
       // mp[v[i]]++;
    }

    lis(n,v);
    
    // ll x=0,y=0; 
    // for(auto u:mp){
    //     if(u.second>1) x++;
    //     else y++;
    // }
    // ll r=(y+1)/2;
    // cout<<x+r<<endl;
}

int main()
{
    optimize();
    ll t=1;
    cin>>t;
    while(t--) solve();
}

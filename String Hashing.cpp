#include<bits/stdc++.h>
using namespace std;
#define ll   long long
#define pb   push_back
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
#define all(x) (x).begin(), (x).end()
#define    gcd(a,b)      __gcd(a,b)
#define    lcm(a,b)  (a*b)/__gcd(a,b)
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define mod 1000000007

void solve(){
   string s,t;
   cin>>s>>t;
   ll n=s.size();
   ll m=t.size();

   ll arr[n+5];
   arr[0]=0; 
   // hash values of s string
   ll prime=31; // use large prime value to avoid collisions;
   for(ll i=0; i<n; i++){
    arr[i+1]=(((arr[i]*prime)%mod)+s[i])%mod;
   }
    // hash value of t string
   ll val=0;
   for(ll i=0; i<m; i++){
     val=(((val*prime)%mod)+t[i])%mod;
   }

   ll pw=1;
   for(ll i=1; i<=m; i++){
     pw=(prime*pw)%mod;
   }

   ll cnt=0;
   for(ll i=m; i<=n; i++){
     ll ans=arr[i];
     ll ans1=arr[i-m];
     ans1=(ans1*pw)%mod;
     ans=ans-ans1;
     if(ans<0) ans+=mod;
     if(ans==val) cnt++;
   }

   cout<<cnt<<endl;
}

int main()
{
    optimize();
    ll t = 1;
    cin >> t;
    for(ll i=1; i<=t; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
}

               Explaination
***************************************************
s="abcde";  a[i+1]=(a[i]*p+s[i])%mod;
a[0]=0;
a[1]=0*p^0 + 'a';
a[2] = 'a'*p^1 + 'b';
a[3] = 'a'*p^2 + 'b'*p^1 + 'c';
a[4] = 'a'*p^3 + 'b'*p^2 + 'c'*p^1 + 'd';
a[5] = 'a'*p^4 + 'b'*p^3 + 'c'*p^2 + 'd'*p^1 + 'e';

hash(cd) = a[4]-(a[2]*p^ln); 
//ln(cd)=2
hash(cde) = a[e]-(a[2]*p^ln); 
//ln(cde)=3

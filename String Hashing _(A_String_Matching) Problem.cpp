#include<bits/stdc++.h>
using namespace std;
#define ll   long long
#define pb   push_back
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
#define all(x) (x).begin(), (x).end()
#define gcd(a,b)      __gcd(a,b)
#define lcm(a,b)  (a*b)/__gcd(a,b)
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define mod1 1000000007
#define mod2 1000000009

void solve(){
   string s, t;
   cin >> s >> t;
   ll n = s.size();
   ll m = t.size();

   ll prime1 = 37, prime2 = 41; 
   ll arr1[n+5], arr2[n+5];
   arr1[0] = 0; 
   arr2[0] = 0;

   for (ll i = 0; i < n; i++) {
      arr1[i+1] = (((arr1[i] * prime1) % mod1) + s[i]) % mod1;
      arr2[i+1] = (((arr2[i] * prime2) % mod2) + s[i]) % mod2;
   }

   ll val1 = 0, val2 = 0;
   for (ll i = 0; i < m; i++) {
      val1 = (((val1 * prime1) % mod1) + t[i]) % mod1;
      val2 = (((val2 * prime2) % mod2) + t[i]) % mod2;
   }

   ll pw1 = 1, pw2 = 1;
   for (ll i = 1; i <= m; i++) {
      pw1 = (pw1 * prime1) % mod1;
      pw2 = (pw2 * prime2) % mod2;
   }

   ll cnt = 0;
   for (ll i = m; i <= n; i++) {
      ll ans1 = arr1[i];
      ll ans2 = arr2[i];
      ll sub1 = arr1[i-m];
      ll sub2 = arr2[i-m];
      
      sub1 = (sub1 * pw1) % mod1;
      sub2 = (sub2 * pw2) % mod2;
      ans1 = (ans1 - sub1 + mod1) % mod1;
      ans2 = (ans2 - sub2 + mod2) % mod2;

      if (ans1 == val1 && ans2 == val2) cnt++;
   }

   cout << cnt << endl;
}

int main()
{
    optimize();
    ll t = 1;
    //cin >> t;
    while (t--) solve();
}

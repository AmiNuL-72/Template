#include<bits/stdc++.h>
using namespace std;
#define ll   long long
#define pb   push_back
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
#define all(x) (x).begin(), (x).end()
#define gcd(a,b)      __gcd(a,b)
#define lcm(a,b)      (a*b)/__gcd(a,b)
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll a[200005], seg[4 * 200005];


void segmentTree(ll ind, ll low, ll high) {
    if (low == high) {  // Leaf node
        seg[ind] = a[low];
        return;
    }
    ll mid = (low + high) / 2;
    segmentTree(2 * ind + 1, low, mid);
    segmentTree(2 * ind + 2, mid + 1, high);
    //seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);  
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);  
    //seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);  
}


ll query(ll ind, ll low, ll high, ll l, ll r) {
    if (low >= l && high <= r) {  // Completely within range
        return seg[ind];
    }
    if (high < l || low > r) {   // Completely outside range
        //return LLONG_MIN;
        return LLONG_MAX;
        //return 0;
    }
    ll mid = (low + high) / 2;
    ll left = query(2 * ind + 1, low, mid, l, r);
    ll right = query(2 * ind + 2, mid + 1, high, l, r);
    //return max(left, right);  
    return min(left, right);  
    //return (left + right);  
}

void update(ll ind, ll low, ll high, ll pos, ll val) {
    if (low == high) {  // Leaf node
        seg[ind] = val;
        a[pos] = val;
        return;
    }
    ll mid = (low + high) / 2;
    if (pos <= mid) {
        update(2 * ind + 1, low, mid, pos, val);
    } else {
        update(2 * ind + 2, mid + 1, high, pos, val);
    }
    //seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);  
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);  
    //seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);  
}

int main() {
    optimize();
    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    segmentTree(0, 0, n - 1);

    while (q--) {
        ll k, l, r;
        cin >> k >> l >> r;
        
        if (k == 1) { 
            l--; 
            update(0, 0, n - 1, l, r);  
        } else {  
            l--, r--;  
            cout << query(0, 0, n - 1, l, r) << endl;
        }
    }

    return 0;
}

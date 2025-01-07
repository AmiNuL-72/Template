#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node {
    ll sum, max, min, gcd; 
};

const ll N = 2e5 + 7;
ll arr[N]; 
node tree[N * 4]; 

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum; 
    ans.max = max(a.max, b.max); 
    ans.min = min(a.min, b.min); 
    ans.gcd = __gcd(a.gcd, b.gcd); 
    return ans;
}

void segmentTree(ll currNode, ll left, ll right) {
    tree[currNode] = {0, 0, (ll)1e18, 0};
    if (left == right) {
        tree[currNode].sum = tree[currNode].max = tree[currNode].min = tree[currNode].gcd = arr[left];
        return;
    }
    ll leftNode = currNode * 2; 
    ll rightNode = currNode * 2 + 1; 
    ll mid = left + (right - left) / 2;     
    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid + 1, right);

    tree[currNode] = merge(tree[leftNode], tree[rightNode]);
}

node query(ll currNode, ll left, ll right, ll i, ll j) {
    if (i > right || j < left) 
        return {0, 0, (ll)1e18, 0};

    if (left >= i && right <= j) 
        return tree[currNode];

    ll leftNode = currNode * 2; 
    ll rightNode = currNode * 2 + 1;
    ll mid = left + (right - left) / 2;

    node leftCalc = query(leftNode, left, mid, i, j);
    node rightCalc = query(rightNode, mid + 1, right, i, j);

    return merge(leftCalc, rightCalc);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t = 1; 
    cin >> t;

    while (t--) {
        ll n, q; 
        cin >> n >> q;

        ll v[n + 1]; // Array of size n (1-based indexing)
        for (ll i = 1; i <= n; i++) 
            cin >> v[i]; 
        for (ll i = 1; i < n; i++) 
            arr[i] = abs(v[i] - v[i + 1]);

        if (n > 1) 
            segmentTree(1, 1, n - 1);

        while (q--) {
            ll l, r; // Query range [l, r]
            cin >> l >> r;

            if (n == 1) 
                // If the array has only one element, the GCD of differences is 0
                cout << "0 ";
            else 
                // Query the GCD of the range [l, r-1] in the `arr` array
                cout << query(1, 1, n - 1, l, r - 1).gcd << " ";
        }
        cout << "\n"; 
    }

    return 0;
}

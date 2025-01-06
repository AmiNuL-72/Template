#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll MAX = 200005;
ll arr[MAX], seg[4 * MAX], lazy[4 * MAX];

void build(ll ind, ll low, ll high) {
    if (low == high) {
        seg[ind] = arr[low];
        return;
    }
    ll mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

void propagate(ll ind, ll low, ll high) {
    if (lazy[ind] != 0) {
        seg[ind] += (high - low + 1) * lazy[ind];  // Apply the pending updates to the node
        
        if (low != high) {  // If not a leaf node, propagate the laziness to children
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;  // Clear the lazy value for the current node
    }
}

void update(ll ind, ll low, ll high, ll l, ll r, ll u) {
    propagate(ind, low, high);  // Ensure all previous updates are applied
    
    if (low > r || high < l) {
        return;  // Out of range
    }

    if (low >= l && high <= r) {
        // Completely within range
        lazy[ind] += u;  // Mark this node as needing an update
        propagate(ind, low, high);  // Apply the lazy update
        return;
    }

    ll mid = (low + high) / 2;
    update(2 * ind + 1, low, mid, l, r, u);  // Update the left child
    update(2 * ind + 2, mid + 1, high, l, r, u);  // Update the right child
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];  // Recalculate the sum for the current node
}

ll query(ll ind, ll low, ll high, ll idx) {
    propagate(ind, low, high);  // Ensure all previous updates are applied
    
    if (low == high) {
        return seg[ind];  // Return the value at the leaf node
    }

    ll mid = (low + high) / 2;
    if (idx <= mid) {
        return query(2 * ind + 1, low, mid, idx);
    } else {
        return query(2 * ind + 2, mid + 1, high, idx);
    }
}

int main() {
    optimize();
    
    ll n, q;
    cin >> n >> q;
    
    // Read initial values
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build the segment tree
    build(0, 0, n - 1);
    
    while (q--) {
        ll type;
        cin >> type;
        
        if (type == 1) {
            // Update query: increase range [a, b] by u
            ll a, b, u;
            cin >> a >> b >> u;
            a--; b--;  // Convert to 0-indexed
            update(0, 0, n - 1, a, b, u);
        } else {
            // Point query: get the value at position k
            ll k;
            cin >> k;
            k--;  // Convert to 0-indexed
            cout << query(0, 0, n - 1, k) << endl;
        }
    }

    return 0;
}

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
        seg[ind] += (high - low + 1) * lazy[ind];  // Apply the pending update to the segment
        
        if (low != high) {  // If not a leaf node, propagate the laziness to children
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;  // Clear the lazy value for this node
    }
}

void update(ll ind, ll low, ll high, ll l, ll r, ll u) {
    propagate(ind, low, high);  // Apply any pending updates
    
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

ll query(ll ind, ll low, ll high, ll l, ll r) {
    propagate(ind, low, high);  // Apply any pending updates
    
    if (low > r || high < l) {
        return 0;  // Out of range
    }
    
    if (low >= l && high <= r) {
        return seg[ind];  // Completely within range
    }
    
    ll mid = (low + high) / 2;
    ll leftSum = query(2 * ind + 1, low, mid, l, r);
    ll rightSum = query(2 * ind + 2, mid + 1, high, l, r);
    return leftSum + rightSum;
}

int main() {
    optimize();
    
    ll n, q;
    cin >> n >> q;
    
    // Read the initial array
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Build the segment tree
    build(0, 0, n - 1);
    
    while (q--) {
        ll type;
        cin >> type;
        
        if (type == 1) {
            // Update query: add `u` to all elements in range [l, r]
            ll l, r, u;
            cin >> l >> r >> u;
            l--; r--;  // Convert to 0-indexed
            update(0, 0, n - 1, l, r, u);
        } else if (type == 2) {
            // Range sum query: get the sum of elements in range [l, r]
            ll l, r;
            cin >> l >> r;
            l--; r--;  // Convert to 0-indexed
            cout << query(0, 0, n - 1, l, r) << endl;
        }
    }
    
    return 0;
}

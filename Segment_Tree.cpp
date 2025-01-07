#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll MAX = 100005;
ll arr[MAX], seg[4 * MAX];

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

void update(ll ind, ll low, ll high, ll pos, ll val) {
    if (low == high) {
        seg[ind] = val;
        return;
    }
    ll mid = (low + high) / 2;
    if (pos <= mid) {
        update(2 * ind + 1, low, mid, pos, val);
    } else {
        update(2 * ind + 2, mid + 1, high, pos, val);
    }
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

ll query(ll ind, ll low, ll high, ll l, ll r) {
    if (low > r || high < l) return 0;  // Out of range
    if (low >= l && high <= r) return seg[ind];  // Completely within range
    ll mid = (low + high) / 2;
    return query(2 * ind + 1, low, mid, l, r) + query(2 * ind + 2, mid + 1, high, l, r);
}

int main() {
    optimize();
    ll T;
    cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll n, q;
        cin >> n >> q;

        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }

        build(0, 0, n - 1);

        cout << "Case " << t << ":\n";

        while (q--) {
            ll type, i, j, v;
            cin >> type;

            if (type == 1) {
                // Query type 1: give all money from the ith sack
                cin >> i;
                cout << arr[i] << "\n";
                arr[i] = 0;
                update(0, 0, n - 1, i, 0);

            } else if (type == 2) {
                // Query type 2: add money v to the ith sack
                cin >> i >> v;
                arr[i] += v;
                update(0, 0, n - 1, i, arr[i]);

            } else if (type == 3) {
                // Query type 3: find total money in range [i, j]
                cin >> i >> j;
                cout << query(0, 0, n - 1, i, j) << "\n";
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node {
    ll sum, max, min, PreSum; 
};

const ll N = 2e5 + 7;
ll arr[N]; 
node tree[N * 4]; 

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum + b.sum; 
    ans.max = max(a.max, b.max); 
    ans.min = min(a.min, b.min); 
    ans.PreSum = max(a.PreSum, a.sum + b.PreSum);
    return ans;
}

void segmentTree(ll currNode, ll left, ll right) {
    tree[currNode] = {0, 0, (ll)1e18, 0};
    if (left == right) {
        tree[currNode].sum = tree[currNode].max = tree[currNode].min = tree[currNode].PreSum = arr[left];
        tree[currNode].PreSum = max(0LL, arr[left]); 
        return;
    }
    ll leftNode = currNode * 2; 
    ll rightNode = currNode * 2 + 1; 
    ll mid = left + (right - left) / 2;     
    segmentTree(leftNode, left, mid);
    segmentTree(rightNode, mid + 1, right);

    tree[currNode] = merge(tree[leftNode], tree[rightNode]);
}

void update(int currNode, int start, int end, int k, ll u) {
    if (start == end) {
        arr[k] = u;
        tree[currNode].sum = u;
        tree[currNode].max = u;
        tree[currNode].min = u;
        tree[currNode].PreSum = max(0LL, u); 
        return;
    }
    ll mid = (start + end) / 2;
    if (k <= mid) {
        update(2 * currNode, start, mid, k, u);
    } else {
        update(2 * currNode + 1, mid + 1, end, k, u);
    }
    tree[currNode] = merge(tree[2 * currNode], tree[2 * currNode + 1]);
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

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    segmentTree(1, 0, n - 1);  

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            ll k,u;
            cin >> k >> u;
            k--; 
            update(1, 0, n - 1, k, u);
        }
        else {
            ll a, b;
            cin >> a >> b;
            a--; b--;  // 0-based index
            node result = query(1, 0, n - 1, a, b);
            cout << result.PreSum << "\n";
        }
    }

    return 0;
}
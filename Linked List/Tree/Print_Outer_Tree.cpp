#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree() {
    int val;
    if (!(cin >> val) || val == -1) return NULL;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        int l, r;
        if (cin >> l) {
            if (l != -1) {
                cur->left = new Node(l);
                q.push(cur->left);
            }
        }
        if (cin >> r) {
            if (r != -1) {
                cur->right = new Node(r);
                q.push(cur->right);
            }
        }
    }
    return root;
}

void solve() {
    Node* root = buildTree();
    if (!root) return;

    vector<int> leftV, rootV, rightV;
    set<Node*> vis;

    rootV.push_back(root->data);
    vis.insert(root);

    Node* cur = root->left;
    while (cur) {
        leftV.push_back(cur->data);
        vis.insert(cur);
        if (cur->left) cur = cur->left;
        else if (cur->right) cur = cur->right;
        else break;
    }
    reverse(leftV.begin(), leftV.end());

    cur = root->right;
    while (cur) {
        if (vis.find(cur) == vis.end()) {
            rightV.push_back(cur->data);
        }
        if (cur->right) cur = cur->right;
        else if (cur->left) cur = cur->left;
        else break;
    }

    bool ck = true;
    for (int val : leftV) {
        if (!ck) cout << " ";
        cout << val;
        ck = false;
    }
    for (int val : rootV) {
        if (!ck) cout << " ";
        cout << val;
        ck = false;
    }
    for (int val : rightV) {
        if (!ck) cout << " ";
        cout << val;
        ck = false;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
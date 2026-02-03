#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = right = NULL;
    }
};

Node* buildTree(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1)
        return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        Node* cur = q.front();
        q.pop();
        if (i < arr.size() && arr[i] != -1) {
            cur->left = new Node(arr[i]);
            q.push(cur->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1) {
            cur->right = new Node(arr[i]);
            q.push(cur->right);
        }
        i++;
    }

    return root;
}

void gotoLeaf(Node* root, vector<int>& leaf) {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        leaf.push_back(root->val);
        return;
    }
    gotoLeaf(root->left, leaf);
    gotoLeaf(root->right, leaf);
}

int main() {

    vector<int> arr;
    int x;
    while (cin >> x) {
        arr.push_back(x);
    }

    Node* root = buildTree(arr);

    vector<int> leaf;
    gotoLeaf(root, leaf);

    sort(leaf.begin(), leaf.end(), greater<int>());

    for (int i = 0; i < leaf.size(); i++) {
        cout << leaf[i];
        if (i + 1 < leaf.size()) cout << " ";
    }

    cout << endl;

    return 0;
}

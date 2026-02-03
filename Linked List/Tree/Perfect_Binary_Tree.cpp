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

int deep(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + max(deep(root->left), deep(root->right));
}

int cntNode(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + cntNode(root->left) + cntNode(root->right);
}

int main() {

    vector<int> arr;
    int x;

    while (cin >> x) {
        arr.push_back(x);
    }

    Node* root = buildTree(arr);

    int d = deep(root);
    int total = cntNode(root);

    int formullla = (1 << d) - 1;   // 2^d - 1

    if (total == formullla)  cout << "YES" << endl;
    else  cout << "NO" << endl;

    return 0;
}

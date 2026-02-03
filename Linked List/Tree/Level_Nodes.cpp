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

int main() {

    vector<int> arr;
    int x;

    while (cin >> x) {
        arr.push_back(x);
    }

    int X = arr.back();
    arr.pop_back();

    Node* root = buildTree(arr);

    if (root == NULL) {
        cout << "Invalid" << endl;
        return 0;
    }

    queue<Node*> q;
    q.push(root);

    int level = 0;
    bool found = false;

    while (!q.empty()) {

        int sz = q.size();

        for (int i = 0; i < sz; i++) {
            Node* cur = q.front();
            q.pop();

            if (level == X) {
                found = true;
                cout << cur->val;
                if (i + 1 < sz) cout << " ";
            }

            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }

        if (level == X) {
            cout << endl;
            break;
        }

        level++;
    }

    if (!found) {
        cout << "Invalid" << endl;
    }

    return 0;
}

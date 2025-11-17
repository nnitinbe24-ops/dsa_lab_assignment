#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
    Node(int x) {
        val = x;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() { root = nullptr; }

    Node* insert(Node* cur, int x) {
        if (!cur) return new Node(x);
        if (x < cur->val)
            cur->left = insert(cur->left, x);
        else
            cur->right = insert(cur->right, x);
        return cur;
    }

    bool isBSTUtil(Node* node, long long minVal, long long maxVal) {
        if (!node) return true;
        if (node->val <= minVal || node->val >= maxVal)
            return false;
        return isBSTUtil(node->left, minVal, node->val) &&
               isBSTUtil(node->right, node->val, maxVal);
    }

    bool isBST(Node* root) {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }
};

int main() {
    BinaryTree tree;
    tree.root = tree.insert(tree.root, 15);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 8);
    tree.root = tree.insert(tree.root, 12);
    tree.root = tree.insert(tree.root, 17);
    tree.root = tree.insert(tree.root, 25);

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    if (tree.isBST(tree.root))
        cout << "The given binary tree is a BST." << endl;
    else
        cout << "The given binary tree is NOT a BST." << endl;

    return 0;
}
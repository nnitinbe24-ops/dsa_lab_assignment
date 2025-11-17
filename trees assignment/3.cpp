#include <iostream>
#include <algorithm>
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

class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insertNode(Node* cur, int x) {
        if (!cur) return new Node(x);
        if (x < cur->val)
            cur->left = insertNode(cur->left, x);
        else if (x > cur->val)
            cur->right = insertNode(cur->right, x);
        return cur;
    }

    Node* getMin(Node* cur) {
        while (cur && cur->left)
            cur = cur->left;
        return cur;
    }

    Node* deleteNode(Node* cur, int key) {
        if (!cur) return cur;
        if (key < cur->val)
            cur->left = deleteNode(cur->left, key);
        else if (key > cur->val)
            cur->right = deleteNode(cur->right, key);
        else {
            if (!cur->left) {
                Node* tmp = cur->right;
                delete cur;
                return tmp;
            } else if (!cur->right) {
                Node* tmp = cur->left;
                delete cur;
                return tmp;
            }
            Node* minNode = getMin(cur->right);
            cur->val = minNode->val;
            cur->right = deleteNode(cur->right, minNode->val);
        }
        return cur;
    }

    int maxDepth(Node* node) {
        if (!node) return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }

    int minDepth(Node* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        if (!node->left) return 1 + minDepth(node->right);
        if (!node->right) return 1 + minDepth(node->left);
        return 1 + min(minDepth(node->left), minDepth(node->right));
    }

    void inorder(Node* cur) {
        if (!cur) return;
        inorder(cur->left);
        cout << cur->val << " ";
        inorder(cur->right);
    }
};

int main() {
    BST tree;
    int arr[] = {15, 10, 20, 8, 12, 17, 25};
    for (int x : arr)
        tree.root = tree.insertNode(tree.root, x);

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Deleting 10...\n";
    tree.root = tree.deleteNode(tree.root, 10);
    cout << "After Deletion: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Maximum Depth: " << tree.maxDepth(tree.root) << endl;
    cout << "Minimum Depth: " << tree.minDepth(tree.root) << endl;

    return 0;
}
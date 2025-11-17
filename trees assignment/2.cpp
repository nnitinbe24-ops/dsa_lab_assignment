#include <iostream>
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

    Node* searchRec(Node* cur, int key) {
        if (!cur || cur->val == key) return cur;
        if (key < cur->val) return searchRec(cur->left, key);
        return searchRec(cur->right, key);
    }

    Node* searchIter(Node* cur, int key) {
        while (cur) {
            if (key == cur->val) return cur;
            cur = (key < cur->val) ? cur->left : cur->right;
        }
        return nullptr;
    }

    Node* getMin(Node* cur) {
        while (cur && cur->left)
            cur = cur->left;
        return cur;
    }

    Node* getMax(Node* cur) {
        while (cur && cur->right)
            cur = cur->right;
        return cur;
    }

    Node* findSuccessor(Node* root, Node* target) {
        if (target->right) return getMin(target->right);
        Node* succ = nullptr;
        while (root) {
            if (target->val < root->val) {
                succ = root;
                root = root->left;
            } else if (target->val > root->val)
                root = root->right;
            else break;
        }
        return succ;
    }

    Node* findPredecessor(Node* root, Node* target) {
        if (target->left) return getMax(target->left);
        Node* pred = nullptr;
        while (root) {
            if (target->val > root->val) {
                pred = root;
                root = root->right;
            } else if (target->val < root->val)
                root = root->left;
            else break;
        }
        return pred;
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
    int arr[] = {20, 8, 22, 4, 12, 10, 14};
    for (int x : arr)
        tree.root = tree.insertNode(tree.root, x);

    cout << "Inorder: ";
    tree.inorder(tree.root);
    cout << endl;

    int key = 10;
    Node* r1 = tree.searchRec(tree.root, key);
    Node* r2 = tree.searchIter(tree.root, key);
    cout << "Recursive Search: " << (r1 ? "Found" : "Not Found") << endl;
    cout << "Iterative Search: " << (r2 ? "Found" : "Not Found") << endl;

    cout << "Minimum: " << tree.getMin(tree.root)->val << endl;
    cout << "Maximum: " << tree.getMax(tree.root)->val << endl;

    Node* node = tree.searchIter(tree.root, 10);
    Node* succ = tree.findSuccessor(tree.root, node);
    Node* pred = tree.findPredecessor(tree.root, node);

    cout << "Successor of 10: " << (succ ? to_string(succ->val) : "None") << endl;
    cout << "Predecessor of 10: " << (pred ? to_string(pred->val) : "None") << endl;

    return 0;
}
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    Node* createSampleTree() {
        Node* root = new Node(3);
        root->left = new Node(9);
        root->right = new Node(20);
        root->right->left = new Node(15);
        root->right->right = new Node(7);
        return root;
    }

    int sumOfLeftLeaves(Node* root) {
        if (!root)
            return 0;

        int sum = 0;
        if (root->left) {
            if (!root->left->left && !root->left->right)
                sum += root->left->val;
            else
                sum += sumOfLeftLeaves(root->left);
        }
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};

int main() {
    BinaryTree tree;
    Node* root = tree.createSampleTree();
    cout << "Sum of all left leaves: " << tree.sumOfLeftLeaves(root);
    return 0;
}
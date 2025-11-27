#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    int postIndex;

    BinaryTree() {
        postIndex = 0;
    }


    int search(int inorder[], int start, int end, int key) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == key)
                return i;
        }
        return -1;
    }

    
    Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd) {
        if (inStart > inEnd)
            return NULL;

        int rootVal = postorder[postIndex--];
        Node* root = new Node(rootVal);

        if (inStart == inEnd)
            return root;

        int pos = search(inorder, inStart, inEnd, rootVal);

        
        root->right = buildTree(inorder, postorder, pos + 1, inEnd);
        root->left  = buildTree(inorder, postorder, inStart, pos - 1);

        return root;
    }
};

void printPreorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int n;
    cin >> n;

    int* inorder = new int[n];
    int* postorder = new int[n];

    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    BinaryTree bt;
    bt.postIndex = n - 1;

    Node* root = bt.buildTree(inorder, postorder, 0, n - 1);

 

    delete[] inorder;
    delete[] postorder;

    return 0;
}
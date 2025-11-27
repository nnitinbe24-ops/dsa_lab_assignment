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
    int preIndex;  

    BinaryTree() {
        preIndex = 0;
    }

   
    int search(int inorder[], int start, int end, int value) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == value)
                return i;
        }
        return -1;
    }

    
    Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd) {
        if (inStart > inEnd)
            return NULL;

        int rootVal = preorder[preIndex++];
        Node* root = new Node(rootVal);

        if (inStart == inEnd)
            return root;

        int pos = search(inorder, inStart, inEnd, rootVal);

        root->left = buildTree(preorder, inorder, inStart, pos - 1);
        root->right = buildTree(preorder, inorder, pos + 1, inEnd);

        return root;
    }
};

void printInorder(Node* root) {  
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int n;
    cin >> n;

    int* preorder = new int[n];
    int* inorder = new int[n];

    for (int i = 0; i < n; i++)
        cin >> preorder[i];

    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    BinaryTree bt;
    Node* root = bt.buildTree(preorder, inorder, 0, n - 1);

  
    delete[] preorder;
    delete[] inorder;

    return 0;
}
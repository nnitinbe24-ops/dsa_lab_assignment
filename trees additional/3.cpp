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
    Node* root;

    BinaryTree() {
        root = NULL;
    }


    Node* insertLevelOrder(int arr[], int i, int n) {
        if (i >= n || arr[i] == -1) return NULL;

        Node* temp = new Node(arr[i]);
        temp->left  = insertLevelOrder(arr, 2*i + 1, n);
        temp->right = insertLevelOrder(arr, 2*i + 2, n);

        return temp;
    }

    int maxDepth(Node* node) {
        if (node == NULL) return 0;

        int lh = maxDepth(node->left);
        int rh = maxDepth(node->right);

        return 1 + (lh > rh ? lh : rh);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int *arr = new int[n];
        for (int i = 0; i < n; i++) cin >> arr[i];

        BinaryTree bt;
        bt.root = bt.insertLevelOrder(arr, 0, n);

        cout << bt.maxDepth(bt.root) << endl;

        delete[] arr;
    }

    return 0;
}
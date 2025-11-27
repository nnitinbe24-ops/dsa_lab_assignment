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

// Doubly Linked List Node
class DLLNode {
public:
    int data;
    DLLNode* prev;
    DLLNode* next;

    DLLNode(int val) {
        data = val;
        prev = next = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int val) {
        if (node == NULL)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);

        return node;
    }

    void inorder(Node* root, int arr[], int &idx) {
        if (root == NULL) return;
        inorder(root->left, arr, idx);
        arr[idx++] = root->data;
        inorder(root->right, arr, idx);
    }
};

class Solution {
public:
    DLLNode* mergeSortedArrays(int a[], int n1, int b[], int n2) {
        int i = 0, j = 0;
        DLLNode* head = NULL;
        DLLNode* tail = NULL;

        while (i < n1 && j < n2) {
            int val = (a[i] < b[j]) ? a[i++] : b[j++];
            DLLNode* newNode = new DLLNode(val);

            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        while (i < n1) {
            DLLNode* newNode = new DLLNode(a[i++]);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        while (j < n2) {
            DLLNode* newNode = new DLLNode(b[j++]);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        return head;
    }
};

void printDLL(DLLNode* head) {
    DLLNode* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << " <-> NULL\n";
}

int main() {
    int n1, n2;
    cin >> n1;

    BST tree1, tree2;

    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        tree1.root = tree1.insert(tree1.root, x);
    }

    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        tree2.root = tree2.insert(tree2.root, x);
    }

    int *arr1 = new int[n1];
    int *arr2 = new int[n2];

    int idx1 = 0, idx2 = 0;

    tree1.inorder(tree1.root, arr1, idx1);
    tree2.inorder(tree2.root, arr2, idx2);

    Solution s;
    DLLNode* head = s.mergeSortedArrays(arr1, idx1, arr2, idx2);

    printDLL(head);

    delete[] arr1;
    delete[] arr2;

    return 0;
}
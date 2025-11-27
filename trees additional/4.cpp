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

class Queue {
public:
    Node* arr[10000];
    int front, rear;

    Queue() {
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear;
    }

    void push(Node* x) {
        arr[rear++] = x;
    }

    Node* pop() {
        return arr[front++];
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() { root = NULL; }

  
    Node* insertLevelOrder(int arr[], int i, int n) {
        if (i >= n || arr[i] == -1) return NULL;

        Node* temp = new Node(arr[i]);
        temp->left  = insertLevelOrder(arr, 2*i + 1, n);
        temp->right = insertLevelOrder(arr, 2*i + 2, n);
        return temp;
    }

    void rightView(Node* root) {
        if (root == NULL) return;

        Queue q;
        q.push(root);

        while (!q.isEmpty()) {
            int size = q.rear - q.front;

            Node* node;
            for (int i = 0; i < size; i++) {
                node = q.pop();

               
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

          
            cout << node->data << " ";
        }
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

        bt.rightView(bt.root);
        cout << endl;

        delete[] arr;
    }

    return 0;
}
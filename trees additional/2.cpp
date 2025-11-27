#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTGenerator {
public:
    Node** generateTrees(int n, int &total) {
        if (n == 0) {
            total = 0;
            return NULL;
        }
        return buildTrees(1, n, total);
    }

    void preorder(Node* root) {
        if (!root) {
            cout << "null ";
            return;
        }
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

private:
    Node** buildTrees(int start, int end, int &count) {
        if (start > end) {
            count = 1;
            Node** arr = new Node*[1];
            arr[0] = NULL;
            return arr;
        }

        Node** result = new Node*[1000];
        count = 0;

        for (int i = start; i <= end; i++) {
            int leftCount = 0, rightCount = 0;
            Node** leftTrees = buildTrees(start, i - 1, leftCount);
            Node** rightTrees = buildTrees(i + 1, end, rightCount);

            for (int l = 0; l < leftCount; l++) {
                for (int r = 0; r < rightCount; r++) {
                    Node* root = new Node(i);
                    root->left = leftTrees[l];
                    root->right = rightTrees[r];
                    result[count++] = root;
                }
            }
            delete[] leftTrees;
            delete[] rightTrees;
        }
        return result;
    }
};

int main() {
    BSTGenerator bst;
    int n = 3, total = 0;
    Node** trees = bst.generateTrees(n, total);
    cout << "Total Unique BSTs: " << total << endl;

    for (int i = 0; i < total; i++) {
        cout << "Tree " << i + 1 << ": ";
        bst.preorder(trees[i]);
        cout << endl;
    }

    delete[] trees;
    return 0;
}
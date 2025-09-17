#include <iostream>
using namespace std;

#define MAX 5

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = x;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
        } else {
            cout << arr[top--] << endl;
        }
    }

    void peek() {
        if (top == -1) cout << "Stack Empty\n";
        else cout << arr[top] << endl;
    }

    bool isEmpty() { return (top == -1); }

    bool isFull() { return (top == MAX - 1); }

    void display() {
        if (top == -1) cout << "Stack Empty\n";
        else {
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "1.Push 2.Pop 3.Peek 4.isEmpty 5.isFull 6.Display 7.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            cout << (s.isEmpty() ? "Yes\n" : "No\n");
            break;
        case 5:
            cout << (s.isFull() ? "Yes\n" : "No\n");
            break;
        case 6:
            s.display();
            break;
        case 7:
            break;
        default:
            cout << "Invalid\n";
        }
    } while (choice != 7);

    return 0;
}
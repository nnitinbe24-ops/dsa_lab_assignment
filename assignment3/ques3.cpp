#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {

    stack<char> s;


    for (int i = 0; i < expr.length(); i++) {

        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);

        } else if (ch == ')' || ch == '}' || ch == ']') {

            if (s.empty()) return false;
            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {

                return false;
            }

        }
    }
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced Expression" << endl;

    else
        cout << "Not Balanced Expression" << endl;
        
    return 0;
}
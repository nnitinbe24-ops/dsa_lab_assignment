#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }
    string rev = "";
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }
    return rev;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string reversed = reverseString(input);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
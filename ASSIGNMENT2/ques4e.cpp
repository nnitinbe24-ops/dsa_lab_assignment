/*
ques-->4e
e) Write a program to convert a character from uppercase to lowercase.

*/
#include <iostream>
using namespace std;

void toLower(char &ch) {
    if (ch >= 'A' && ch <= 'Z') ch = ch + 32;
    cout << ch;
}

int main() {
    char ch;
    cin >> ch;
    toLower(ch);
}
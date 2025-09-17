/*
ques -->4b
(b) Write a program to reverse a string
*/

#include <iostream>
using namespace std;

void reverseString(char s[]) {
    int n = 0;
    while (s[n] != '\0') n++;
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    cout << s;
}

int main() {
    char str[200];
    cin.getline(str, 200);
    reverseString(str);
}
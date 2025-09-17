/*
ques--> 4c
(c) Write a program to delete all the vowels from the string.
*/
#include <iostream>
using namespace std;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

void removeVowels(char s[]) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (!isVowel(s[i])) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
    cout << s;
}

int main() {
    char str[200];
    cin.getline(str, 200);
    removeVowels(str);
}
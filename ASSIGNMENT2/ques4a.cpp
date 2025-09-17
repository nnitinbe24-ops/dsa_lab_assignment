/*
ques-->4a
tring Related Programs
(a) Write a program to concatenate one string to another string.
*/

#include <iostream>
using namespace std;

void concatStrings(char s1[], char s2[]) {
    int i = 0, j = 0;
    while (s1[i] != '\0') i++;
    while (s2[j] != '\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    cout << s1;
}

int main() {
    char str1[200], str2[100];
    cin.getline(str1, 200);
    cin.getline(str2, 100);
    concatStrings(str1, str2);
}
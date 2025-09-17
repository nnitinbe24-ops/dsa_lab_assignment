/*
ques-->4d
(d) Write a program to sort the strings in alphabetical order.
*/

#include <iostream>
using namespace std;

void sortString(char s[]) {

    for (int i = 0; s[i] != '\0'; i++) {

        for (int j = i + 1; s[j] != '\0'; j++) {


            if (s[i] > s[j]) {
                
                char t = s[i];
                s[i] = s[j];
                s[j] = t;

       }
 }
}
}
    


int main() {
    char str[100];
    cin.getline(str, 100);

    sortString(str);

    cout << str;
}
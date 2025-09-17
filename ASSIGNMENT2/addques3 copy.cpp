#include <iostream>
using namespace std;

bool isAnagram(string str1, string str2) {
    
    int n1 = 0, n2 = 0;
    while (str1[n1] != '\0') n1++;
    while (str2[n2] != '\0') n2++;

    if (n1 != n2) return false;

   
    int count[256] = {0};

    
    for (int i = 0; i < n1; i++) {
        count[(int)str1[i]]++;
    }

   
    for (int i = 0; i < n2; i++) {
        count[(int)str2[i]]--;
    }

    
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0)
            return false;
    }

    return true;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    if (isAnagram(str1, str2))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
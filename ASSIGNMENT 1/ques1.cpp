/* QUES 1

Develop a Menu driven program to demonstrate the following operations of Arrays
1) ——MENU——-
1.CREATE
2. DISPLAY
3. INSERT
4. DELETE
5. LINEAR SEARCH
6. EXIT

*/

#include <iostream>

using namespace std;

int arr[100], n = 0;

void createArray() {

    cout << "Enter number of elements: ";
    cin >> n;


    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
}



void displayArray() {

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

}



void insertElement() {
    int pos, val;

    cout << "Enter position and value: ";

    cin >> pos >> val;


    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

void deleteElement() {
    int pos;
    cout << "Enter position to delete: ";

    cin >> pos;


    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}

void linearSearch() {
    int key, found = 0;
    cout << "Enter value to search: ";


    cin >> key;
    for (int i = 0; i < n; i++) {

        if (arr[i] == key) {


            cout << "Found at position " << i << "\n";
            found = 1;
            break;


        }
    }
    if (!found) cout << "Not found\n";
}

int main() {
    int option;


    while (true) {


        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";

        cin >> option;

        switch (option) {

            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: return 0;
        }
    }
}
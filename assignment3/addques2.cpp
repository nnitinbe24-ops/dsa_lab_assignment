#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int currentMin;


void pushElement(int x) {
    if (s.empty()) {
        s.push(x);
        currentMin = x;
    }
    else if (x >= currentMin) {
        s.push(x);
    }
    else {
      
        s.push(2*x - currentMin);
        currentMin = x;
    }
}


int popElement() {
    if (s.empty()) {
        return -1;
    }

    int t = s.top();
    s.pop();

    if (t >= currentMin) {
        return t;
    }
    else {
        int actual = currentMin;
        currentMin = 2*currentMin - t; 
        return actual;
    }
}


int getTop() {
    if (s.empty()) {
        return -1;
    }

    int t = s.top();
    if (t >= currentMin) {
        return t;
    }
    else {
        return currentMin;
    }
}


int getMin() {
    if (s.empty()) {
        return -1;
    }
    return currentMin;
}

int main() {
    pushElement(5);
    pushElement(3);
    pushElement(7);

    cout << getMin() << endl;   
    cout << popElement() << endl; 
    cout << getMin() << endl;   
    cout << popElement() << endl; 
    cout << getMin() << endl;   
    cout << getTop() << endl;   

    return 0;
}
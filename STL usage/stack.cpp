#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void print(stack<int> s) {
    stack<int> copy = s;
    while(!copy.empty()) {
        cout << copy.top() << ", ";
        copy.pop();
    }
    cout << "\n";
}

int main() {
    // Initialize heap
    stack<int> s;

    // Add elements
    int size = 10;
    for (int i = 0; i < size; i++) {
        s.push(i);
    }

    // Get top element
    int top = s.top();

    // Add
    s.push(10);

    // Remove from top
    s.pop();

    print(s);
    return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void print(queue<int> s) {
    queue<int> copy = s;
    while(!copy.empty()) {
        cout << copy.front() << ", ";
        copy.pop();
    }
    cout << "\n";
}

int main() {
    // Initialize queue
    queue<int> s;

    // Add elements
    int size = 10;
    for (int i = 0; i < size; i++) {
        s.push(i);
    }

    // Get element
    int first = s.front();
    int last = s.back();

    // Add to back
    s.push(10);

    // Remove from front
    s.pop();

    print(s);
    return 0;
}
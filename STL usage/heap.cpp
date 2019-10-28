#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void print(priority_queue<int> s) {
    priority_queue<int> copy = s;
    while(!copy.empty()) {
        cout << copy.top() << ", ";
        copy.pop();
    }
    cout << "\n";
}

// Workst for comparing objects as well
struct min_compare {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};

int main() {
    // Initialize heap
    priority_queue<int> s;

    // Initialize min heap
    priority_queue<int, vector<int>, min_compare> min;

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
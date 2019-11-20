#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct PAIR {
    int priority;
    string value;

    bool operator<(const PAIR & rhs) const {
        return priority < rhs.priority;
    }
};

void print(priority_queue<PAIR> s) {
    priority_queue<PAIR> copy = s;
    while(!copy.empty()) {
        cout << copy.top().value << ", ";
        copy.pop();
    }
    cout << "\n";
}

int main() {
    // Initialize heap of PAIR with priority-value
    priority_queue<PAIR> s;

    // Add elements
    s.push({1, "I leave low priority"});
    s.push({100, "I have high priority"});
    s.push({10, "I have middle priority"});

    // Get top element
    PAIR top = s.top();

    print(s);
    return 0;
}
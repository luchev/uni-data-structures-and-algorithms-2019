#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

void print(list<int> s) {
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << ", ";
    }
    cout << "\n";
}

int main() {
    // Initialize doubly linked list
    list<int> s;

    // Add elements
    int size = 10;
    for (int i = 0; i < size; i++) {
        s.push_back(i);
    }

    // Get element
    int first = s.front();
    int last = s.back();

    // Add to front
    s.push_front(-1);

    // Add to back
    s.push_back(10);

    // Remove from back
    s.pop_back();

    // Remove from front
    s.pop_front();

    // Insert element at position
    auto insertIndex = s.begin();
    int insertAt = 0;
    advance(insertIndex, insertAt);
    s.insert(insertIndex, -1);

    // Erase element at position
    auto removeIndex = s.begin();
    int removeAt = 0;
    advance(removeIndex, insertAt);
    s.erase(removeIndex);

    // Reverse
    s.reverse();

    // Sort
    s.sort();

    // Count elements
    int countFives = count(s.begin(), s.end(), 5);

    // Find if an element exists (returns iterator)
    auto five = find(s.begin(), s.end(), 5);
    if (five == s.end()) {
        cout << "5 is not in the array\n";
    } else {
        cout << "Found 5 -> " << *five << "\n";
    }

    print(s);
    return 0;
}
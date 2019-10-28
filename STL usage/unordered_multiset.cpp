#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

void print(unordered_multiset<int> s) {
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << ", ";
    }
    cout << "\n";
}

int main() {
    // Initialize hash table with repeating values
    unordered_multiset<int> s;

    int size = 10;
    // Add values
    for (int i = 0; i < size; i++) {
        s.insert(i);
        s.insert(i);
    }

    // Insert element
    s.insert(-1);

    // Erase by key
    s.erase(-1);

    // Count elements by key
    int countFives = s.count(5);

    // Find if an element exists by key (returns iterator)
    auto five = s.find(5);
    if (five == s.end()) {
        cout << "5 is not in the array\n";
    } else {
        cout << "Found 5 -> " << *five << "\n";
    }

    print(s);
    return 0;
}
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void print(map<int, int> s) {
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << i->first << ": " << i->second << ", ";
    }
    cout << "\n";
}

int main() {
    // Initialize map
    map<int, int> s;

    int size = 10;
    // Add values
    for (int i = 0; i < size; i++) {
        s.insert(pair<int, int>(i, i * i));
    }

    // Insert element
    s.insert(pair<int, int>(-1, -100));

    // Insert or change element by key
    s[12] = 144;

    // Erase by key
    s.erase(-1);
    s.erase(12);

    // Count elements by key
    int countFives = s.count(5);

    // Find if an element exists by key (returns iterator)
    auto five = s.find(5);
    if (five == s.end()) {
        cout << "5 is not in the array\n";
    } else {
        cout << "Found 5 -> " << five->first << ": " << five->second << "\n";
    }

    print(s);
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<int> s) {
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << ", ";
    }
    cout << "\n";
}

int main() {
    int size = 10;
    // Initialize vector
    vector<int> s;

    // Preallocate memory (the size is changed)
    s.resize(size);
    // Initialize elements after resize()
    for (int i = 0; i < s.size(); i++) {
        s[i] = i;
    }

    size = 20;
    // Preallocate memory (the capacity is changed)
    s.reserve(size);
    // Initialize elements after reserve()
    for (int i = s.size(); i < s.capacity(); i++) {
        s.push_back(i);
    }

    // Get element
    int middle = s[10];
    int middle2 = s.at(10);
    int first = s.front();
    int last = s.back();

    // Get pointer to the first element
    int* ptr = s.data();

    // Add to back
    s.push_back(20);

    // Remove from back
    s.pop_back();

    // Insert element at position
    int insertAtIndex = 0;
    s.insert(s.begin() + insertAtIndex, -1);

    // Erase element at position
    int removeAtIndex = 0;
    s.erase(s.begin() + removeAtIndex);

    // Reverse
    reverse(s.begin(), s.end());

    // Shuffle
    random_shuffle(s.begin(), s.end());

    // Sort
    sort(s.begin(), s.end());

    // Count elements
    int countFives = count(s.begin(), s.end(), 5);

    // Find if an element exists (returns iterator)
    auto five = find(s.begin(), s.end(), 5);
    if (five >= s.end()) {
        cout << "5 is not in the array\n";
    } else {
        cout << "Index of 5 is " << five - s.begin() << "\n";
    }

    print(s);
    return 0;
}
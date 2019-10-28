#include <iostream>
#include <algorithm>
using namespace std;

void print(int* s, int size) {
    for (int i = 0; i < size; i++) {
        cout << s[i] << ", ";
    }
    cout << "\n";
}

int main() {

    // Declare s
    int size = 10;
    int* s = new int[size];
    for (int i = 0; i < size; i++) {
        s[i] = i;
    }

    // Reverse
    reverse(s, s + size);

    // Shuffle
    random_shuffle(s, s + size);

    // Sort
    sort(s, s + size);

    // Binary search
    bool fiveExistsBinary = binary_search(s, s + size, 5);

    // Count elements
    int countFives = count(s, s + size, 5);

    // Find if an element exists
    int* five = find(s, s + size, 5);
    if (five > s + size) {
        cout << "5 is not in the array\n";
    } else {
        cout << "Index of 5 is " << five - s << "\n";
    }

    print(s, size);
    return 0;
}
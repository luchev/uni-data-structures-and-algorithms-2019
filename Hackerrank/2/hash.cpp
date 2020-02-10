#include <iostream>
#include <unordered_set>
using namespace std;

bool check(char * a, char * b, int length) {
    unordered_multiset<char> A;
    unordered_multiset<char> B;
    for (int i = 0; i < length; i++) {
        A.insert(a[i]);
        B.insert(b[i]);
    }
    return A == B;
}

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int length = 0;
    cin >> length;
    char * a = new char[length + 1];
    char * b = new char[length + 1];

    cin >> a;
    cin >> b;

    if (check(a , b, length)) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }

    delete[] a;
    delete[] b;
}
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool check(char * a, char * b, int length) {
    sort(a, a + length);
    sort(b, b + length);
    for (int i = 0; i < length; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
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
#include <iostream>

using namespace std;

bool check(char * a, char * b, int length) {
for (int i = 0; i < length; i++) {
        bool found = false;
        for (int k = 0; k < length; k++) {
            if (b[k] == a[i]) {
                b[k] = ' ';
                found = true;
                break;
            }
        }
        if (!found) {
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
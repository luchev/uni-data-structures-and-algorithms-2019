#include <iostream>
#include <cstring>
using namespace std;

void check(char * a, char * b) {
    cout << strlen(a) << "\n" << strlen(b) << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int length = 0;
    cin >> length;
    char * a = new char[length + 10000];
    char * b = new char[length + 10000];

    cin >> a;
    cin >> b;

    check(a, b);

    delete[] a;
    delete[] b;
}
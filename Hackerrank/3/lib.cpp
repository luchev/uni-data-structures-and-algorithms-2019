#include <math.h>
#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int number;
        int root;

        cin >> number;
        cin >> root;
        cout << pow(number, 1.0/root) << "\n";
    }
}
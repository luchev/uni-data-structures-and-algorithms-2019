#include <iostream>
using namespace std;
const int ALPHABET_SIZE = 200;

int main() {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

    int length = 0;
    cin >> length;

    char input;
    int alphabet[ALPHABET_SIZE] { 0 };
    for (int i = 0; i < length; i++) {
        cin >> input;
        alphabet[input]++;
    }
    cin >> input;
    
    for (int i = 0; i < length; i++) {
        cin >> input;
        alphabet[input]--;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (alphabet[i] != 0) {
            cout << "no\n";
            return 0;
        }
    }
    cout << "yes\n";
}
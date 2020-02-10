#include <random>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>

using namespace std;

char generateRandom(char from, char to) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from,to);

    return dist6(rng);
}

int main() {
    int length = 220000000;
    
    cout << length << "\n";
    for (int i = 0; i < length / 26; i++) {
        for (char k = 'a'; k <= 'z'; k++) {
            cout << k;
        }
    }
    cout << "\n";
    for (int i = 0; i < length / 26; i++) {
        for (char k = 'a'; k <= 'z'; k++) {
            cout << 'b';
        }
    }
    cout << "\n";

}
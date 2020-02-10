#include <random>
#include <iostream>
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
    string str;
    int length = 30;
    for (int i = 0; i < length; i++) {
        
        str.push_back(generateRandom('a', 'z'));
    }
    cout << length << "\n";
    cout << str << "\n";
    random_shuffle(str.begin(), str.end());
    cout << str << "\n";
}
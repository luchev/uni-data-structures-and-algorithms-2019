#include <random>
#include <iostream>

using namespace std;

int generateRandomNumber(int from, int to) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from,to);

    return dist6(rng);
}

int main() {
    for (int i = 0; i < 1000; i++) {
        cout << generateRandomNumber(10, 10000) << " ";
    }
}
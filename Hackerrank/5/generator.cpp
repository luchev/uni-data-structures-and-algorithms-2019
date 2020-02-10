#include <random>
#include <iostream>

using namespace std;

#define LOW 1
#define HIGH 10000
#define TREE 10000
#define QUERY 10000

int generateRandomNumber(int from, int to) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from,to);

    return dist6(rng);
}

int main() {
    int N = TREE;
    int K = QUERY;

    cout << N << " " << K << "\n";

    for (int i = 0; i < N; i++) {
        cout << generateRandomNumber(LOW, HIGH) << " ";
    }

    cout << "\n";

    for (int i = 0; i < K; i++) {
        cout << generateRandomNumber(LOW, HIGH) << " ";
    }
    cout << "\n";
}
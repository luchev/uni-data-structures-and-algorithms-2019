#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
#include <random>
using namespace std;

int generate(int from, int to) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from,to);

    return dist6(rng);
}

int main() {
    int N = 20000;
    int M = 20000;
    int maxWeight = 1000;
    cout << N << " " << M << "\n";

    for (int i = 0; i < M; i++) {
        int weight = generate(0, maxWeight);
        int from = generate(0, N - 1);
        int to = from;
        while (from == to) {
            to = generate(0, N - 1);
        }
        cout << from << " " << to << " " << weight << "\n";
    }
}
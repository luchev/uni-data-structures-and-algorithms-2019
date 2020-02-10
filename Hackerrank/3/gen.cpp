#include <random>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>

using namespace std;

int generateRandom(int from, int to) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from,to);

    return dist6(rng);
}

int main() {
    int minTrucks = 0;
    int maxTrucks = 50000;
    int minTruck = -10000;
    int maxTruck = 10000;
    int minMonster = 0;
    int maxMonster = 5000;

    // int length = generateRandom(0, 20);
    int length = maxTrucks;
    
    cout << length << "\n";
    for (int i = 0; i < length; i++) {
        // Truck
        cout << generateRandom(minTruck, maxTruck) << " ";
        // Monsters
        cout << generateRandom(minMonster, maxMonster);
        cout << "\n";
    }
}
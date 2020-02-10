#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

size_t GenerateUnsignedInt(size_t From, size_t To) {
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<mt19937::result_type> generate(From, To);
    return generate(rng);
}

vector<size_t> GenerateUnsignedInts(size_t Amount, size_t From, size_t To) {
    vector<size_t> vect;
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<mt19937::result_type> generate(From, To);
    for (size_t i = 0; i < Amount; i++) {
        vect.push_back(generate(rng));
    }
    return vect;
}

vector<long long> GenerateInts(size_t Amount, size_t From, size_t To) {
    vector<long long> vect;
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<mt19937::result_type> generate(From, To);
    uniform_int_distribution<mt19937::result_type> sign(0, 1);
    for (size_t i = 0; i < Amount; i++) {
        vect.push_back((int)generate(rng) * (sign(rng) == 1 ? -1 : 1));
    }
    return vect;
}

template<typename T>
void PrintVector(vector<T> Vector) {
    for (size_t i = 0; i < Vector.size(); i++) {
        cout << Vector[i] << ", ";
    }
    cout << endl;
}

void PrintDuration(high_resolution_clock::time_point t1, high_resolution_clock::time_point t2) {
    long long duration = duration_cast<nanoseconds>(t2 - t1).count();
    //cout << "Nanoseconds: " << duration << endl;
    //cout << "Microseconds: " << duration / 1000 << endl;
    //cout << "Miliseconds: " << duration / 1000000 << endl;
    cout << "Seconds: " << duration / 1000000000.0 << endl;
}

//
// End of generators
//

struct Building {
    int height = 0;
    int price = 0;
};

bool CompareHeight(Building& lhs, Building& rhs) {
    return (lhs.height < rhs.height); // || (lhs.height == rhs.height && lhs.price < rhs.price));
}
bool ComparePrice(Building& lhs, Building& rhs) {
    return (lhs.price < rhs.price); // || (lhs.price == rhs.price && lhs.height < rhs.height));
}

long long Price(Building* buildings, int arrSize, int height) {
    long long price = 0;
    for (int i = 0; i < arrSize; i++) {
        price += abs(buildings[i].height - height) * buildings[i].price;
    }
    return price;
}

bool BuildingEqual(const Building& a, const Building& b) {
    return (a.height == b.height && a.price == b.price);
}

const int TESTSIZE = 10;

int Min(int a, int b) {
    return a < b ? a : b;
}

int MinPriceTernaryNaive(Building* buildings, int size, int left, int right) {
    if (right - left < 3) {
        int currentMin = Price(buildings, size, left);
        for (int i = left + 1; i < right + 1; i++) {
            currentMin = Min(currentMin, Price(buildings, size, i));
        }
        return currentMin;
    }
    else if (left < right) {
        int leftThird = left + (right - left) / 3;
        int rightThird = right - (right - left) / 3;

        int leftPrice = Price(buildings, size, leftThird);
        int rightPrice = Price(buildings, size, rightThird);

        if (leftPrice < rightPrice) {
            return MinPriceTernaryNaive(buildings, size, left, rightThird);
        }
        else if (leftPrice > rightPrice) {
            return MinPriceTernaryNaive(buildings, size, leftThird, right);
        }
        else {
            return Min(Min(MinPriceTernaryNaive(buildings, size, left, leftThird), MinPriceTernaryNaive(buildings, size, leftThird, rightThird)),
                MinPriceTernaryNaive(buildings, size, rightThird, right));
        }
    }
    return -1;
}

int MinPriceTernary(Building* buildings, int size, Building* unique, int uniqueSize, int left, int right) {
    if (right - left < 3) {
        int currentMin = Price(buildings, size, buildings[left].height);
        for (int i = left + 1; i < right + 1; i++) {
            currentMin = Min(currentMin, Price(buildings, size, buildings[i].height));
        }
        return currentMin;
    } else if (left < right) {
        int leftThird = left + (right - left) / 3;
        int rightThird = right - (right - left) / 3;
        
        int leftPrice = Price(buildings, size, buildings[leftThird].height);
        int rightPrice = Price(buildings, size, buildings[rightThird].height);
        
        if (leftPrice < rightPrice) {
            return MinPriceTernary(buildings, size, unique, uniqueSize, left, rightThird);
        }
        else if (leftPrice > rightPrice) {
            return MinPriceTernary(buildings, size, unique, uniqueSize, leftThird, right);
        }
        else { // Should never enter this but just in case
            return Min(Min(MinPriceTernary(buildings, size, unique, uniqueSize, left, leftThird), MinPriceTernary(buildings, size, unique, uniqueSize, leftThird, rightThird)),
                MinPriceTernary(buildings, size, unique, uniqueSize, rightThird, right));
        }
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    Building* buildings = new Building[N];
    for (size_t i = 0; i < N; i++) {
        cin >> buildings[i].height;
    }
    for (size_t i = 0; i < N; i++) {
        cin >> buildings[i].price;
    }
    sort(buildings, buildings + N, CompareHeight);
    if (N > 1) {
        cout << MinPriceTernaryNaive(buildings, N, buildings[0].height, buildings[N-1].height);
    }
}

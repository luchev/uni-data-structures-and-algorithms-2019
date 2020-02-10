#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>
#include <random>
using namespace std;

int gen(int from, int to) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from,to);

    return dist6(rng);
}

string generateName(const vector<string>& names) {
    int len = gen(1, 3);
    string out;
    for (int i = 0; i < len; i++) {
        if (i > 0) {
            out.append("_");
        }
        int randName = gen(0, names.size() - 1);
        out.append(names[randName]);
    }
    return out;
}

int main() {
    const int MOODLE_CHECK_CHANCE = 10;
    const int COUNT = 2;
    const int SIZE = 10;
    const int INVALID_NAME_CHANCE = 3;
    const int COUNT_CHANCE = SIZE / COUNT;

    string input;
    ifstream names_file("names_uniq");
    vector<string> names;
    while (names_file >> input) {
        names.push_back(input);
    }

    unordered_map<string, bool> moodle;

    cout << "++moodle\n";
    bool addMoodle = true;

    for (int i = 0; i < SIZE; i++) {
        // generate input
        // BROKEN
        
        int chance = gen(0, MOODLE_CHECK_CHANCE);
        if (chance == MOODLE_CHECK_CHANCE) {
            if (addMoodle) {
                input = "++check";
            } else {
                input = "++moodle";
            }
        } else {
            if (chance < COUNT_CHANCE && !addMoodle) {
                input = "++count";
            } else {
                if (addMoodle) {
                    do {
                        input = generateName(names);
                    } while (moodle.count(input) > 0);
                } else {
                    bool validName = gen(0, INVALID_NAME_CHANCE) == 0;
                    if (validName && moodle.size() > 0) {
                        int randName = gen(0, moodle.size() - 1);
                        auto nameFromMoodle = moodle.begin();
                        advance(nameFromMoodle, randName);
                        input = nameFromMoodle->first;
                    } else {
                        input = generateName(names);
                    }
                }
            }
        }



        if (input == "++moodle") {
            cout << input << "\n";
            addMoodle = true;
            moodle.clear();
        } else if (input == "++check") {
            cout << input << "\n";
            addMoodle = false;
        } else if (input == "++count") {
            cout << input << "\n";
        } else {
            if (addMoodle) {
                moodle.insert({input, false});
                cout << input << "\n";
            }
        }
    }

    cout << "++end\n";
    return 0;
}

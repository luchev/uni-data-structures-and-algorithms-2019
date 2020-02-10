#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input;
    unordered_map<string, bool> moodle;
    int countIntersection = 0;
    bool addMoodle = false;

    while(true) {
        cin >> input;
        if (input == "++moodle") {
            addMoodle = true;
            moodle.clear();
        } else if (input == "++check") {
            addMoodle = false;
            countIntersection = 0;
        } else if (input == "++count") {
            cout << countIntersection << "\n";
        } else if (input == "++end") {
            return 0;
        } else {
            if (addMoodle) {
                moodle.insert({input, false});
            } else {
                auto potential = moodle.find(input);
                if (potential != moodle.end()) {
                    if (potential->second == false) {
                        cout << "Yes\n";
                        countIntersection++;
                        moodle[input] = true;
                    }
                } else {
                    cout << "No\n";
                }
            }
        }
    }
    return 0;
}

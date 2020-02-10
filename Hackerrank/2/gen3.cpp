#include <random>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>
#include <cstring>  
using namespace std;

int main() {
    int length = 150000000;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    char * str = new char[length + 1];
    str[length] = 0;
    
    for (int i = 0; i < length / 26; i++) {
        strcpy(&str[i * 26], alpha.c_str());
    }
    
    cout << length << "\n";
    cout << str << "\n";
    random_shuffle(alpha.begin(), alpha.end());
    for (int i = 0; i < length / 26; i++) {
        strcpy(&str[i * 26], alpha.c_str());
    }
    cout << str << "\n";
}
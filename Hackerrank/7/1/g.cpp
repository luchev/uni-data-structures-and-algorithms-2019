#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

struct Node {
	string name;
	vector<Node*> sub;
	Node* parent = nullptr;

	Node(const string& name, Node* parent = nullptr) : name(name), parent(parent) { }

	bool hasSub(string dir) {
		for (Node* i : sub) {
			if (i->name == dir) {
				return true;
			}
		}
		return false;
	}

	void mkdir(const string& dir) {
		if (hasSub(dir)) {
			cout << "Directory already exists\n";
		} else {
			sub.push_back(new Node(dir, this));
		}
	}

	void ls() {
		sort(sub.begin(), sub.end(), [](const auto& lhs, const auto& rhs) {
			return lhs->name < rhs->name; });

		for (auto i : sub) {
			// cout << i->name << " ";
		}
		
		// cout << "\n";
	}

	Node* cd(const string& dir) {
		if (dir == "..") {
			if (parent) {
				return parent;
			}
		} else {
			for (Node* i : sub) {
				if (i->name == dir) {
					return i;
				}
			}
		}

		// cout << "No such directory\n";
		return this;
	}

	void pwd() const {
		stack<string> dirs;
		const Node* current = this;
		while (current != nullptr) {
			dirs.push(current->name);
			current = current->parent;
		}

		while (!dirs.empty()) {
			// cout << dirs.top() << "/";
			dirs.pop();
		}
		// cout << "\n";
	}
};

#include <random>
#include <string>
int generate(int from, int to) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from,to);

    return dist6(rng);
}

string generateString(int length) {
    string result;
    for (int i = 0; i < length; i++) {
        result.push_back(generate('a', 'z'));
    }
    return result;
}

int main() {
	int N = 1;
    int strLen = 0;
	string in;
    cin >> N >> strLen;
	Node* current = new Node("");

    cout << N << "\n";
	for (int i = 0; i < N; i++) {
		int now = generate(0, 3);

		if (now == 0) {
            cout << "mkdir ";
            in = generateString(generate(3, strLen));
			current->mkdir(in);
            cout << in << "\n";
		} else if (now == 1) {
            cout << "ls\n";
			current->ls();
		} else if (now == 2) {
            cout << "cd ";
            if (current->sub.size() == 0) {
                in = "..";
            } else {
                int goParent = generate(0, 2);
                if (goParent == 0) {
                    in = "..";
                } else {
                    int next = generate(0, current->sub.size() - 1);
                    in = current->sub[next]->name;
                }
            }

			current = current->cd(in);
            cout << in << "\n";
		} else if (now == 3) {
            cout << "pwd\n";
			current->pwd();
		}
	}
}
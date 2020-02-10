#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Request {
	int cash;
	string company;

	Request(int cash, string company) {
		this->cash = cash;
		this->company = company;
	}

	bool operator<(const Request& rhs) const {
		return cash < rhs.cash;
	}
};

int main() {
	int queries;
	cin >> queries;

	priority_queue<Request> que;

	for (int i = 0; i < queries; i++) {
		char instruction;
		cin >> instruction;
		if (instruction == 'a') {
			string company;
			int cash;
			cin >> company >> cash;
			que.push(Request(cash, company));
		} else if (instruction == 'g') {
			Request top = que.top();
			que.pop();
			cout << top.company << " ";
		}
	}
}
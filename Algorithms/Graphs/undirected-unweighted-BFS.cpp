#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct Node {
	list<int> neighbours;

	bool hasNeighbour(int index) {
		for (auto i : neighbours) {
			if (i == index) {
				return true;
			}
		}
		return false;
	}

	void addNeighbour(int index) {
		neighbours.push_back(index);
	}
};

class Graph {
private:
	vector<Node> nodes;

	void _BFS(int start, vector<bool> & visited) {
		queue<int> nextToProcess;
		nextToProcess.push(start);
		visited[start] = true;

		while(!nextToProcess.empty()) {
			int current = nextToProcess.front();
			nextToProcess.pop();

			cout << current << ", ";

			for (auto neighbour : nodes[current].neighbours) {
				if (!visited[neighbour]) {
					nextToProcess.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}

public:
	Graph(int nodeCount = 0) {
		nodes.resize(nodeCount);
	}

	void print() const {
		for (int node = 0; node < nodes.size(); node++) {
			cout << node << ": ";
			for (auto neighbour : nodes[node].neighbours) {
				cout << neighbour << ", ";
			}
			cout << "\n";
		}
	}

	void connect(int from, int to) {
		if (!nodes[from].hasNeighbour(to)) { // remove this check to make it multigraph
			nodes[from].addNeighbour(to);
			nodes[to].addNeighbour(from); // remove this to make the graph directed
		}
	}

	void BFSAll() { // For disjoint union of graphs
		vector<bool> visited;
		visited.resize(nodes.size(), false);

		for (int start = 0; start < nodes.size(); start++) {
			if (!visited[start]) {
				_BFS(start, visited);
			}
		}
	}

	void BFS(int start) { // Traverse the component this node belongs to
		vector<bool> visited;
		visited.resize(nodes.size(), false);
		
		_BFS(start, visited);
	}
};

int main() {
	Graph g(4);
	g.connect(0, 1);
	g.connect(1, 0);
	g.connect(1, 2);
	g.connect(1, 3);
	g.connect(2, 1);
	g.connect(3, 1);
	g.connect(3, 2);

	g.BFS(3);
}

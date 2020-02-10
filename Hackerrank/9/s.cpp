
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct Pair {
	int index;
	int weight;
};

struct Node {
	list<Pair> neighbours;

	bool hasNeighbour(int index) {
		for (auto neighbour : neighbours) {
			if (neighbour.index == index) {
				return true;
			}
		}
		return false;
	}

	void addNeighbour(int index, int weight) {
		neighbours.push_back(Pair{ index, weight });
	}
};

struct Edge {
	int from;
	int to;
	int weight;

	bool operator<(const Edge& rhs) const {
		return weight < rhs.weight;
	}
};

class Graph {
private:
	vector<Node> nodes;

public:
	Graph(int nodeCount = 0) {
		nodes.resize(nodeCount);
	}

	void print() const {
		for (int node = 0; node < nodes.size(); node++) {
			cout << node << ": ";
			for (auto neighbour : nodes[node].neighbours) {
				cout << neighbour.index << "(" << neighbour.weight << "), ";
			}
			cout << "\n";
		}
	}

	void connect(int from, int to, int weight) {
		nodes[from].addNeighbour(to, weight);
		nodes[to].addNeighbour(from, weight);
	}

	vector<Edge> getAllEdges() const {
		vector<Edge> edges;

		for (int from = 0; from < nodes.size(); from++) {
			for (auto neighbour : nodes[from].neighbours) {
				int to = neighbour.index;
				int weight = neighbour.weight;
				if (from < to) {
					edges.push_back(Edge{ from, to, weight });
				}
			}
		}

		return edges;
	}

	int kruskal() const {
		if (nodes.size() < 1) {
			return 0;
		}
		
		vector<Edge> allEdges = getAllEdges();
		// for (auto i : allEdges) {
		// 	cout << i.from << " " << i.to << " " << i.weight << "\n";
		// }
		sort(allEdges.begin(), allEdges.end());

		vector<int> components;
		components.resize(nodes.size());

		for (int i = 0; i < nodes.size(); i++) {
			components[i] = i;
		}

		int totalWeight = 0;
		for (Edge edge : allEdges) {
			if (components[edge.from] != components[edge.to]) {
				totalWeight += edge.weight;
				int oldComponent = components[edge.from];
				int newComponent = components[edge.to];
				for (int i = 0; i < components.size(); i++) {
					if (components[i] == oldComponent)
						components[i] = newComponent;
				}
			}
		}

		return totalWeight;
	}
};

int main() {
	int n;
	int m;
	cin >> n;
	cin >> m;
	Graph g(n);
	int from, to, weight;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> weight;
		g.connect(from, to, weight);
	}

	int s = g.kruskal();
	cout << s;
}

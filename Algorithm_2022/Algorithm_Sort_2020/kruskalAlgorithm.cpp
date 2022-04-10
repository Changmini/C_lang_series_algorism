#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int getParent(int parent[], int n) {
	if (parent[n] == n) return n;
	return getParent(parent, parent[n]);
}

void unionParent(int* parent, int a, int b) {
	int na = getParent(parent, a);
	int nb = getParent(parent, b);
	if (na < nb) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int parent[], int a, int b) {
	int na = getParent(parent, a);
	int nb = getParent(parent, b);
	// not connect
	if (na != nb) return false;
	// connect
	else return true;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this-> node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator < (Edge& edge) {
		return this->distance < edge.distance;
	}
};

int main() {
	int n = 7;
	int m = 11;

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(7, 4, 13));
	v.push_back(Edge(7, 5, 73));
	v.push_back(Edge(4, 2, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(5, 3, 20));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(6, 3, 37));

	sort(v.begin(), v.end());

	int* parent = new int[n];
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < (int)v.size(); i++)
	{
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	cout << sum << endl;
}
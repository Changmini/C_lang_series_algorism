#include<iostream>
#include<vector>

using namespace std;

int getParent(vector<int> parent, int n) {
	if (parent[n] == n) return n;
	return getParent(parent, parent[n]);
}

void unionParent(vector<int> &parent, int a, int b) {
	int na = getParent(parent, a);
	int nb = getParent(parent, b);
	if (na < nb) parent[b] = a;
	else parent[a] = b;
}

void findParent(vector<int> parent, int a, int b) {
	int na = getParent(parent, a);
	int nb = getParent(parent, b);
	if (na != nb) cout << "연결되어 있지 않습니다." << endl;
	else cout << "연결되어 있습니다." << endl;
}

int main() {
	vector<int> parent;
	parent.push_back(0);

	// 데이터의 수
	int length = 10;

	for (int i = 1; i <= length; i++)
	{
		parent.push_back(i);
	}

	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 4, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	findParent(parent, 4, 5);

	unionParent(parent, 4, 5);
	findParent(parent, 4, 5);
}
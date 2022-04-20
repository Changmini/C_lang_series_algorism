#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define length 8
bool c[length];
vector<int> a[length];

void dfs(int x) {
	if (c[x]) return;
	c[x] = true;
	cout << x << ' ';
	for (vector<int>::iterator it = a[x].begin(); it < a[x].end(); it++)
	{
		int y = *it;
		dfs(y); 
	}
}

int main(void) {

	// root 1
	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	// 2 <-> 4, 2 <-> 5
	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);


	// 3 <-> 6, 3 <-> 7
	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);


	// 4 <-> 5, 6 <-> 7
	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);

	dfs(1);

	return 0;
}
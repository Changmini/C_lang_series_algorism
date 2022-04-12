#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define length 8
bool c[length];
vector<int> a[length];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);

		// root 값(x)을 기준으로 주변 노드검사
		for (vector<int>::iterator it = a[x].begin(); it != a[x].end(); it++)
		{
			// root(x)의 자식노드 데이터 추출
			int y = *it;

			// 한번 이상 다녀간 노드인지 검사
			if (!c[y]) {
				// 한번도 접근하지 않았으면 queue에 넣어주고 
				// 다녀갔다는 표시하기
				q.push(y);
				c[y] = true;
			}
		}
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
	
	bfs(1);

	return 0;
}
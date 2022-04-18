#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	// 문제 구성원소가 (1, 2, 3, 2, 5) 일 경우
	// 예) 연속된 원소들의 합이 5가 나올 수 있는 집합의 수
	// 2+3, 3+2, 5 까지 3가지 존재

	// 원소의 개수는 5(num), 연속된 원소들의 합 조건 5(sum)
	int num = 5, sum = 5;
	// 구성데이터
	int data[] = { 1,2,3,2,5 };

	int result = 0, summary = 0, end = 0;
	
	/* 데이터 수 만큼 반복*/
	// 앞 포인터
	for (int start = 0; start < num; start++)
	{
		// 뒤 포인터
		while (summary < sum && end < num) {
			/*뒤 포인터가 이동하면서 해당 인덱스 위치의 데이터 덧셈*/
			// 데이터 덧셈
			summary += data[end];
			// 포인터 이동
			end += 1;
		}
		// 합의 조건(sum)을 만족하면 result값 증가
		if (summary == sum) {
			result += 1;
		}
		// 합의 조건(sum)을 초과했을 경우 앞 포인터의 데이터를 삭제하여
		// 조건을 맞추어간다.
		summary -= data[start];
	}

	cout << result << endl;

	return 0;
}
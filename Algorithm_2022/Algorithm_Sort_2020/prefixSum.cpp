#include<iostream>
#include<algorithm>
#include <list>

using namespace std;

int main() {
	int data[] = { 10, 20, 30, 40, 50 };
	int length = sizeof(data) / sizeof(int);

	int summary = 0;
	
	int * prefix_sum = new int[length];
	
	for (int i = 0; i < length; i++)
	{
		summary += data[i];
		prefix_sum[i] = summary;
	}
	int left = 3;
	int right = 4;
	
	cout << prefix_sum[right] - prefix_sum[left - 1];

	return 0;
}
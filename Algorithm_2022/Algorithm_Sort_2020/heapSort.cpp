#include<stdio.h>

int heap[] = { 7, 6, 5, 8, 3, 5, 9, 1, 6, 10 };
int length = sizeof(heap) / sizeof(int);

int main(void) {
	// 최대 힙 구조로 만들기
	for (int i = 1; i < length; i++)
	{
		int pos = i;
		do {
			int root = (pos - 1) / 2;
			if (heap[root] < heap[pos]) {
				int temp = heap[root];
				heap[root] = heap[pos];
				heap[pos] = temp;
			}
			pos = root;
		} while (pos != 0);
	}

	for (int i = length - 1; i >= 0; i--)
	{
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;

		int root = 0;
		int pos = 1;
		do {
			if (heap[pos] < heap[pos + 1] && pos + 1 < i) {
				pos++;
			}
			if (heap[root] < heap[pos] && pos < i) {
				int temp = heap[root];
				heap[root] = heap[pos];
				heap[pos] = temp;
			}
			root = pos;
			pos = root * 2 + 1;
		} while (pos < i);
	}
	for (int i = 0; i < length; i++)
	{
		printf("%d ", heap[i]);
	}



	return 0;
}
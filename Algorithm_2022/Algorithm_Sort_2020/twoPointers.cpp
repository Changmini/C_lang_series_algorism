#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	// ���� �������Ұ� (1, 2, 3, 2, 5) �� ���
	// ��) ���ӵ� ���ҵ��� ���� 5�� ���� �� �ִ� ������ ��
	// 2+3, 3+2, 5 ���� 3���� ����

	// ������ ������ 5(num), ���ӵ� ���ҵ��� �� ���� 5(sum)
	int num = 5, sum = 5;
	// ����������
	int data[] = { 1,2,3,2,5 };

	int result = 0, summary = 0, end = 0;
	
	/* ������ �� ��ŭ �ݺ�*/
	// �� ������
	for (int start = 0; start < num; start++)
	{
		// �� ������
		while (summary < sum && end < num) {
			/*�� �����Ͱ� �̵��ϸ鼭 �ش� �ε��� ��ġ�� ������ ����*/
			// ������ ����
			summary += data[end];
			// ������ �̵�
			end += 1;
		}
		// ���� ����(sum)�� �����ϸ� result�� ����
		if (summary == sum) {
			result += 1;
		}
		// ���� ����(sum)�� �ʰ����� ��� �� �������� �����͸� �����Ͽ�
		// ������ ���߾��.
		summary -= data[start];
	}

	cout << result << endl;

	return 0;
}
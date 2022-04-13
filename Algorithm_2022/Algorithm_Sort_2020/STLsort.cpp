#include<iostream>
#include<algorithm>

using namespace std;

// �������� sort�Լ� ��� ����
bool compare(int a, int b) {
	return a > b;
}

// ��ü�� ����� sort�Լ� ��� ����
class Student
{
	string name;
	int score;
public:
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	string getname() { return this->name; }

	bool operator < (Student &student) {
		return this->score > student.score;
	}
	~Student() {}
};


int main() {
	int a[10] = { 9, 3, 5, 4, 1, 10, 8, 6, 7, 2 };

	// �������� sort�Լ� ��� ���
	sort(a, a + 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << ' ';
	}
	cout << "\n\n";

	sort(a, a + 10, compare);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << ' ';
	}
	cout << "\n\n";

	// ��ü�� ���� sort�Լ� ��� ���
	Student students[] = {
		Student("�̰���",100),
		Student("����ǥ",90),
		Student("����",89),
		Student("��û��",75),
		Student("��ο�",95)
	};

	sort(students, students + 5);

	for (int i = 0; i < 5; i++)
	{
		cout << students[i].getname() << " ";
	}
	cout << "\n\n";
}
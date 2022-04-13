#include<iostream>
#include<algorithm>

using namespace std;

// 기초적인 sort함수 사용 예시
bool compare(int a, int b) {
	return a > b;
}

// 객체를 사용한 sort함수 사용 예시
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

	// 직관적인 sort함수 사용 방법
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

	// 객체를 통한 sort함수 사용 방법
	Student students[] = {
		Student("이건쫌",100),
		Student("물음표",90),
		Student("주작",89),
		Student("멍청이",75),
		Student("헬로우",95)
	};

	sort(students, students + 5);

	for (int i = 0; i < 5; i++)
	{
		cout << students[i].getname() << " ";
	}
	cout << "\n\n";
}
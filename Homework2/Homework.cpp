#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

struct Student {
	string name;
	int points;

	bool operator<(Student& st2) {
		if (this->points == st2.points) 
			return this->name > st2.name;
		else if (this->points < st2.points) 
			return true;
		else 
			return false;
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	size_t studentsCount;
	cin >> studentsCount;
	vector<int> points;
	vector<string> names;
	vector<Student> students(studentsCount);

	for (size_t i = 0; i < studentsCount; ++i) {
		string name;
		cin >> name;
		names.push_back(name);
		students[i].name = name;
	}
	for (size_t i = 0; i < studentsCount; ++i) {
		int point;
		cin >> point;
		points.push_back(point);
		students[i].points = point;
	}
	
	sort(students.begin(), students.end());
	reverse(students.begin(), students.end());
	for (size_t i = 0; i < students.size(); ++i) {
		cout << students[i].name << " " << students[i].points << "\n";
	}
}



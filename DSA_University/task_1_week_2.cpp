// За група от N (0 <= N <= 30) студенти се пази информация за К оценки.
//  Да се напише програма, която извежда списък
// на студентите, подредени по успех в низходящ ред


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
	string name;
	int faculty_number;
	int marks[10];
	int count_marks;
	double average;
};

int main()
{
	Student students[30];
	int n;
	cout << "Number of students: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "Student name: ";
		getline(cin, students[i].name);

		cout << "Faculty number: ";
		cin >> students[i].faculty_number;

		cout << "How many marks has " << students[i].name <<"?"<< endl;
		cin >> students[i].count_marks;
		int sum_marks = 0;

		for (int j = 0; j < students[i].count_marks; j++)
		{
			cout << "Write mark " << j + 1 << endl;
			cin >> students[i].marks[j];
			sum_marks += students[i].marks[j];
		}
		students[i].average = (double)sum_marks / students[i].count_marks;
	}

	// descending order
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (students[i].average < students[j].average)
			{
				Student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
	cout << "Students sotred in descending order by marks: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << students[i].name
			<< " | Faculty number: " << students[i].faculty_number
			<< " | Average: " << fixed << setprecision(2) << students[i].average
			<< endl;
	}
}

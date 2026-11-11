// A list of numbers is given.
// Write a program that calculates
// the average of the positive nums


#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cout << "How many numbers you want to write: ";
	cin >> n;

	vector<int> array(n);

	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i + 1 << "] = ";
		cin >> array[i];
	}

	double sum = 0;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (array[i] > 0)
		{
			sum += array[i];
			count++;
		}
	}

	if (count > 0)
	{
		double average = sum / count;
		cout << "Number of positive elements: " << count << endl;
		cout << "Average of positive numbers: " << average << endl;
	}
	else
	{
		cout << "No positive numbers were entered." << endl;
	}
	return 0;
}

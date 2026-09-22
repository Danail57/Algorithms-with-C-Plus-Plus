// Даден е масив от цели числа 
// (въведен от потребителя). Намери 
// първото число в масива, което се 
// среща само веднъж (не се повтаря никъде
// другаде).


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	int n;
	cout << "Size of the array: ";
	cin >> n;

	vector <int> numbers(n);
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	unordered_map<int, int> counts;
	for (int num : numbers)
	{
		counts[num]++;
	}

	bool found = false;
	for (int num : numbers)
	{
		if (counts[num] == 1)
		{
			cout << "First unique number: " << num << endl;
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "No unique numbers found" << endl;
	}
}

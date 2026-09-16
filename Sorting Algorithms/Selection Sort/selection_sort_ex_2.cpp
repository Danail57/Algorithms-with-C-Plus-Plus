
// selection sort - Exercise 1 - 
// програма, която сортира масив с помощта на
// Selection Sort и извежда колко
// на брой размени (swap)
// са били извършени по време на целия процес.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void selection_sort(vector<int>& arr)
{
	int n = arr.size();
	if (n == 0)
	{
		cout << "No elements in the array.";
		return;
	}

	int swap_count = 0; // извън цикъла, за да пази
	// общия брой размени

	for (int i = 0; i < n - 1; i++)
	{
		int min_idx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			swap(arr[i], arr[min_idx]);
			swap_count++;
		}
	}
	cout << "Total swap count: " << swap_count << endl;
}

void print_array(vector<int>& arr)
{
	for (auto value : arr)
	{
		cout << value << " ";
	}
	cout << endl;
}

int main()
{
	vector <int> arr = { 36, 72, 74, 3, -89 };
	cout << "Unsorted array: ";
	print_array(arr);

	selection_sort(arr);
	cout << "Sorted array: ";
	print_array(arr);
}

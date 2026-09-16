
// selection sort - Lesson

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void selection_sort(vector<int>& arr)
{
	int n = arr.size();
	if (n == 0)
	{
		cout << "No elements in the array" << endl;
		return;
	}

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
		swap(arr[i], arr[min_idx]);
	}
}

void print_array(vector<int>& arr)
{
	for (auto& value : arr)
	{
		cout << value << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> arr = { 28, 12, 3, -2, 76, 98 };
	cout << "Original array: ";
	print_array(arr);

	selection_sort(arr);
	cout << "Sorted array: ";
	print_array(arr);
}

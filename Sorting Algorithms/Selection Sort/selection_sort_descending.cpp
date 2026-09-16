
// selection sort - Exercise 1 - 
// Сортиране в низходящ ред (Descending Order)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void selection_sort_descending(vector<int>& arr)
{
	int n = arr.size();
	if (n == 0)
	{
		cout << "No elements in the array";
		return;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int max_idx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] > arr[max_idx])
			{
				max_idx = j;
			}
		}
		swap(arr[i], arr[max_idx]);
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
	vector<int> arr = {12, 9, -87, -54, 100, 23, 42};
	cout << "Unsorted descending array: ";
	print_array(arr);
	
	selection_sort_descending(arr);
	cout << "Sorted descending array: ";
	print_array(arr);
}

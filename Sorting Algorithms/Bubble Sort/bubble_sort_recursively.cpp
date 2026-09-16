
// bubble sort - Lesson 2
// Recursive implementation


#include <iostream>
#include <string>
#include <vector>
using namespace std;

void bubble_sort_recursively(vector<int>& arr, int n)
{
	//base case -> the array is sorted
	if (n == 1) 
		return;

	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
			count++;
		}
	}
	if (count == 0)return; 
	//checking if
	//any swapping occured

	bubble_sort_recursively(arr, n - 1);
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
	vector<int>arr = { 64, 34, 25, 12, 22, 11, 90 };
	cout << "Unsorted array: ";
	print_array(arr);

	cout << "Sorted Recursively Bubble Array: ";
	bubble_sort_recursively(arr, arr.size());
	print_array(arr);
}

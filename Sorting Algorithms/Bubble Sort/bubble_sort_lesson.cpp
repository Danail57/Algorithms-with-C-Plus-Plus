
// bubble sort - Lesson 2
// Bubble Sort is the simplest sorting algorithm
// that works by
// repeatedly swapping the adjacent elements 
// if they are in the wrong order. 
// This algorithm is not efficient for large
// data sets as its average and worst-case time 
// complexity are quite high.


#include <iostream>
#include <string>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& arr)
{
	int n = arr.size();
	bool swapped;

	for (int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}

void print_vector(vector<int>& arr)
{
	for (auto value : arr)
	{
		cout << " " << value;
	}
	cout << endl;
}

int main()
{
	vector<int> arr = { 64, 34, 21, -9, 5, 11, -34, 94 };
	bubble_sort(arr);
	cout << "Sorted array (Bubble sort): " << endl;
	print_vector(arr);

}

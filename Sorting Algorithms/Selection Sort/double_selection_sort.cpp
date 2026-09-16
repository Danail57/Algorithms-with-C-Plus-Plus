
// selection sort - Optimization 
// При тази оптимизация обхождаме масива от
// двете страни едновременно: 
// намираме най-малкия и най-големия елемент
// в несортираната част с едно минаване 
// и ги поставяме съответно в началото и в края.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void double_selection_sort(vector<int>& arr)
{
	int left = 0;
	int right = arr.size() - 1;

	while (left < right)
	{
		int min_idx = left;
		int max_idx = left;
		for (int i = left; i <= right; i++)
		{
			if (arr[i] < arr[min_idx])
			{
				min_idx = i;
			}
			if (arr[i] > arr[max_idx])
			{
				max_idx = i;
			}
		}

		swap(arr[left], arr[min_idx]);
		if (max_idx == left)
		{ 
			max_idx = min_idx; 
		}

		swap(arr[right], arr[max_idx]);
		left++;
		right--;
	}
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
	vector<int> arr = { 1, -3, 0, 8, -45, 12, 3 };
	cout << "Original array: ";
	print_array(arr);

	double_selection_sort(arr);
	cout << "Sorted array: ";
	print_array(arr);
}

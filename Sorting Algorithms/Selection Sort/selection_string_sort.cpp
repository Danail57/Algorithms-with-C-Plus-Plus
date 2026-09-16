
// selection sort - Exercise 1
// Напиши програма, която използва Selection Sort,
// за да подреди вектор от текстове (думи)
// по азбучен ред (лексикографски).

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void selection_string_sort(vector<string>& arr)
{
	int n = arr.size();
	if (n == 0)
	{
		cout << "No elements";
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
		if (min_idx != i)
		{
			swap(arr[i], arr[min_idx]);
		}
	}
}

void print_array(vector <string>& arr)
{
	for (auto value : arr)
	{
		cout << value << ", ";
	}
	cout << endl;
}

int main()
{
	vector<string> words = { "banana", "apple", "cherry", "orange", "grape", "pineapple", "lemon" };
	cout << "Unsorted: ";
	print_array(words);

	selection_string_sort(words);
	cout << "Sorted words alphabetically: ";
	print_array(words);
}

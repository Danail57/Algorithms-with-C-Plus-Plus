// Напишете програма, която приема масив/вектор 
// от цели числа и извежда колко пъти се среща 
// всяко число.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


unordered_map<int, int> repeating_nums(vector<int>numbers_array)
{
	int n = numbers_array.size();
	if (n == 0)
	{
		cout << "No numbers written" << endl;
		return {};
	}

	// creating an array for putting nums in it
	unordered_map<int, int> repeating_numbers;

	for (auto num : numbers_array)
	{
		repeating_numbers[num]++;
	}
	return repeating_numbers;
}

void print_array(unordered_map<int, int> repeating_numbers)
{
	for (auto num : repeating_numbers)
	{
		cout << num.first << " is repeated -> " << num.second << " time(s)" << endl;
	}
	cout << endl;
}

int main()
{
	int n;
	cout << "Size of the array: ";
	cin >> n;

	vector <int> numbers(n);
	cout << "Write " << n << " numbers: ";
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	unordered_map<int, int> result = repeating_nums(numbers);
	cout << "\nResults: " << endl;
	print_array(result);
}

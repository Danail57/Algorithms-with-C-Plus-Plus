//  Напишете функция 
// vector<int> twoSum(vector<int>& nums, int target),
// която намира индексите на две числа от масива, 
// чиято сума е равна на target и извежда индекстие и самите 
// числа, даващи сумата на target -a.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector <int> two_sum(vector<int>nums, int target)
{
	if (nums.empty())
	{
		cout << "No numbers in the array";
		return {};
	}

	unordered_map<int, int> seen_numbers;
	bool found = false;
	for (int i = 0; i < nums.size(); i++)
	{
		int complement = target - nums[i];
		if (seen_numbers.find(complement) != seen_numbers.end())
		{
			int idx1 = seen_numbers[complement];
			int idx2 = i;
			cout << "Found pair: Indexes " << idx1 << " and " << idx2
				<< " (" << nums[idx1] << " + " << nums[idx2] << " = " << target << ")" << endl;
			found = true;
		}
		// if we did not find it, we record the num and its index
		seen_numbers[nums[i]] = i;
	}
	if (!found)
	{
		cout << "No nums sum up to " << target << endl;
	}
	return {};
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

	int target;
	cout << "Target number: ";
	cin >> target;

	vector <int> result = two_sum(numbers, target);
}

#include <iostream>
#include <vector>
using namespace std;

void find_subset_sum(vector <long long>& numbers, long long target, vector <long long>& current_subset, int index)
{
	long long current_sum = 0;
	for (auto a : current_subset)
		current_sum += a;
	if (current_sum == target)
	{
		cout << "Found subset: ";
		for (long long n : current_subset) cout << n << " ";
		cout << endl;
	}
	if (index >= numbers.size())
	{
		return;
	}
	current_subset.push_back(numbers[index]);
	find_subset_sum(numbers, target, current_subset, index + 1);
	current_subset.pop_back();
	find_subset_sum(numbers, target, current_subset, index + 1);
}

int main()
{
	vector<long long> nums;
	int n;
	long long target;
	cout << "How many numbers you will write? "; cin >> n;
	cout << "Enter target sum: "; cin >> target;
	for (int i = 0; i < n; i++)
	{
		long long temp;
		cout << "Enter number " << i + 1 << ": ";
		cin >> temp;
		nums.push_back(temp);
	}
	vector <long long> current;
	find_subset_sum(nums, target, current, 0);
}

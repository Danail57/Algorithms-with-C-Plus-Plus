// There are two lists in which elements
// are whole nums / strings. Write a program which 
// shows the elements value which are in the two arrays


#include <iostream>
#include <vector>
using namespace std;

// Function to write the array elements
vector<int> input_list(int size, const string list_name)
{
	vector<int> list(size);
	for (int i = 0; i < size; i++)
	{
		cout << "Element " << i + 1 << ": ";
		cin >> list[i];
	}
	return list;
}

// Function to find the same values
void print_common_values(vector<int> list1, vector<int> list2)
{
	cout << "\nCommon elements in both lists: ";
	bool found_common = false;
	for (size_t i = 0; i < list1.size(); i++)
	{
		for (size_t j = 0; j < list1.size(); j++)
		{
			if (list1[i] == list2[j])
			{
				cout << list1[i] << " ";
				found_common = true;
				break;
			}
		}
	}
	if (!found_common) {
		cout << "None";
	}
	cout << endl;
}

int main()
{
	int n1, n2;
	cout << "Enter size of the first list: ";
	cin >> n1;
	vector<int> list1 = input_list(n1, "first");

	cout << "\nEnter size of the second list: ";
	cin >> n2;
	vector<int> list2 = input_list(n2, "second");

	print_common_values(list1, list2);
}

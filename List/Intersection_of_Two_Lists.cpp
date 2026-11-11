// There are two lists in which elements
// are whole nums / strings. Write a program which 
// creates an array of the elements value which are in the two arrays


#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

vector<int> input_list(int size, const string list_name)
{
	vector<int> list(size);
	cout << "Enter elements of the " << list_name << " list:\n";
	for (int i = 0; i < size; i++)
	{
		cout << "Element " << i + 1 << ": ";
		cin >> list[i];
	}
	return list;
}

vector<int> get_common_values(vector<int> list1, vector<int> list2)
{
	vector<int> common_list;

	for (size_t i = 0; i < list1.size(); i++)
	{
		for (size_t j = 0; j < list2.size(); j++) 
		{
			if (list1[i] == list2[j])
			{
				bool already_added = false;
				for (size_t k = 0; k < common_list.size(); k++) {
					if (common_list[k] == list1[i]) {
						already_added = true;
						break;
					}
				}

				if (!already_added) {
					common_list.push_back(list1[i]);
				}
				break;
			}
		}
	}
	return common_list;
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

	vector<int> common_elements = get_common_values(list1, list2);

	cout << "\nCommon elements array: ";
	if (common_elements.empty()) {
		cout << "None";
	}
	else {
		for (size_t i = 0; i < common_elements.size(); i++) {
			cout << common_elements[i] << " ";
		}
	}
	cout << endl;

	return 0;
}

// Program to delete empty strings

#include <iostream>
#include <string>
using namespace std;

class StringList {
private:
	string* array_words; // dynamic array of strings
	int size; // current elements count
	int capacity; // total capacity of the array

public:
	// constructor
	StringList()
	{
		size = 0;
		capacity = 2; // starting with a small capacity
		array_words = new string[capacity];
	}

	// destructor
	~StringList()
	{
		delete[] array_words;
	}

	void add_word(const string& word)
	{
		if (size >= capacity)
		{
			capacity *= 2;
			string* temp = new string[capacity];

			// copying older words in the new array
			for (int i = 0; i < size; i++)
			{
				temp[i] = array_words[i];
			}

			delete[] array_words;
			array_words = temp;
		}
		array_words[size] = word;
		size++;
	}

	int remove_empty()
	{
		int initial_size = size; // Запомняме размера преди изчистването
		int write_index = 0;

		for (int i = 0; i < size; i++)
		{
			if (!array_words[i].empty())
			{
				array_words[write_index] = array_words[i];
				write_index++;
			}
		}
		size = write_index;
		return initial_size - size;
	}

	void print() const
	{
		if (size == 0)
		{
			cout << "Empty list" << endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			cout << "Word " << i + 1 << " - " << array_words[i] << endl;
		}
	}
};

int main()
{
	StringList words;
	string input;
	cout << "Write strings (stop - ending the program; TIP: use Enter to separate the words):\n";

	while (true)
	{
		getline(cin, input);
		if (input == "stop" || input == "Stop" || input == "STOP")
		{
			break;
		}

		words.add_word(input);
	}

	int deleted_count = words.remove_empty();
	cout << "\nDeleted empty strings: " << deleted_count << endl;

	cout << "Written words: " << endl;
	words.print();

	return 0;
}

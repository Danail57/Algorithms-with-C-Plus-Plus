// програма, в която потребителят 
// въвежда списък от думи. Програмата трябва 
// да преброи колко пъти се среща 
// всяка една дума и да изведе резултата.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<string, int> count_words(vector<string> words_arr)
{
	int n = words_arr.size();
	if (n == 0)
	{
		cout << "No words written" << endl;
		return {}; // returns empty map
	}

	unordered_map<string, int> word_counts;
	for (string word : words_arr)
	{
		word_counts[word]++;
	}
	return word_counts;
}



void print_array(unordered_map<string, int> word_counts)
{
	for (auto element : word_counts)
	{
		cout << element.first << " - " << element.second << endl;
	}
	cout << endl;
}

int main()
{
	cout << "Write words separated by space: ";
	string input_line;
	getline(cin, input_line);

	// input using intervals between the words	
	stringstream ss(input_line);
	string word;
	vector<string> words_arr;

	while (ss >> word)
	{
		words_arr.push_back(word);
	}

	unordered_map<string, int> counts = count_words(words_arr);
	print_array(counts);
}

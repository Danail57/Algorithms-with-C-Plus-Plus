//  Дадени са два низа (думи). Напишете 
// функция bool isAnagram(string s, string t),
// която проверява дали двете думи съдържат 
// абсолютно същите букви с еднакъв брой 
// повторения.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


bool is_anagram(string first_string, string second_string)
{
	if (first_string.length() != second_string.length())
		return false;

	unordered_map<char, int> char_counts;
	for (auto symbol : first_string)
	{
		char_counts[symbol]++;
	}

	for (auto symbol : second_string)
	{
		char_counts[symbol]--;
	}

	for (auto pair : char_counts)
	{
		if (pair.second != 0)
			return false;
	}
	return true;
}


int main()
{
	string word1, word2;
	cout << "Write the first word: ";
	getline(cin, word1);

	cout << "Write the second word: ";
	getline(cin, word2);

	if (is_anagram(word1, word2))
	{
		cout << "The words " << word1 << " and " << word2 << " are anagrams" << endl;
	}
	else
	{
		cout << "The words " << word1 << " and " << word2 << " are not anagrams" << endl;
	}
}

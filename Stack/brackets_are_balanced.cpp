// Да се напише програма, която с помощта на стек определя
// дали във входен низ, състоящ се от отварящи и затварящи скоби,
// броят на '(' е равен на ')' 

#include <iostream>
#include <string>
#include <stack>
using namespace std;


// function to check if brackets are balanced
bool brackets_are_balanced(string expression)
{
	stack<char> brackets; // storing the open brackets ([{
	
	// iterating throuhg expression
	for (int i = 0; i < expression.length(); i++)
	{

		//check if the current symbol is an opening bracket
		if (expression[i] == '(' ||
			expression[i] == '[' ||
			expression[i] == '{')
		{
			// if it is an open
			// bracket we add it to the stack
			brackets.push(expression[i]);
			continue; // go to the other iteration
		}


		if (brackets.empty())
			return false;


		// checking if the closing bracket
		// corresponds to the open
		if (expression[i] == ')' ||
			expression[i] == ']' ||
			expression[i] == '}')
		{
			if (brackets.empty())
				return false;

			// taking the last opening bracket from the top stack
			char top_element = brackets.top();
			
			
			// checking if the closing bracket
			// corresponds to the open bracket
			if ((expression[i] == ')' && top_element != '(' ||
				expression[i] == ']' && top_element != '[' ||
				expression[i] == '}' && top_element != '{'))
			{
				return false; // does not match
			}
			brackets.pop();
		}
	}
	return brackets.empty();
}


int main()
{
	string expression;
	cout << "Write a bracket expression: ";
	cin >> expression;

	if (brackets_are_balanced(expression))
	{
		cout << "Balanced" << endl;
	}
	else
	{
		cout << "Not balanced" << endl;
	}
	return 0;
}

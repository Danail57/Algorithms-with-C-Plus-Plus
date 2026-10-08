// Да се напише програма, която преобразува 
// аритметичен израз, представен в инфиксна
// форма в постфиксна форма

# include <iostream>
# include <string>
# include <stack>
using namespace std;

int precedence(char operand)
{
	if (operand == '+' || operand == '-') return 1;
	if (operand == '*' || operand == '/') return 2;
	return 0;
}


string infix_to_postfix(string infix)
{
	stack<char> operators;
	string postfix = "";

	for (auto symbol : infix)
	{
		if ((symbol >= 'a' && symbol <= 'z') ||
			(symbol >= 'A' && symbol <= 'Z') ||
			(symbol >= '0' && symbol <= '9'))
		{
			postfix += symbol;
		}

		if (symbol == '(')
		{
			operators.push(symbol);
		}
		else if (symbol == ')')
		{
			while (!operators.empty() && operators.top() != '(')
			{
				postfix += operators.top();
				operators.pop();
			}
			if (!operators.empty())
			{
				operators.pop();
			}
		}

		else
		{
			while (!operators.empty() && precedence(operators.top()) >= precedence(symbol))
			{
				postfix += operators.top();
				operators.pop();
			}
			operators.push(symbol);
		}
	}
	return postfix;
}

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n, x, y, m = 0;
	stack<int> a, b;

	cin >> n;
	cin >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> y;
		a.push(y);
		if (y > x) b.push(y);
	}
	b.push(x);
	a.push(x);

	while (!b.empty())
	{
		x = b.top();
		b.pop();
		cout << x << " ";
		m++;
	}
	cout << m << endl;

	while (!a.empty())
	{
		x = a.top();
		a.pop();
		cout << x << " ";
		m++;
	}
	cout << m << endl;

	return 0;
}

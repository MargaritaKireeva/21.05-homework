#include <iostream>
#include <stack>
#include <queue>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("input.txt");
	queue <int> q1, q2;
	stack <int> st1, st2;
	int x;
	while (in >> x)
	{
		if (x % 3 == 0)
			q1.push(x);
		else if (x % 3 == 1)
			st1.push(x);
		else
		{
			q2.push(x);
			st2.push(x);
		}
	}
	while (!q1.empty())
	{
		cout << q1.front() << ' ';
		q1.pop();
	}
	while (!st1.empty())
	{
		cout << st1.top() << ' ';
		st1.pop();
	}
	while (!q2.empty() || !st2.empty())
	{
		if (!q2.empty())
		{
			cout << q2.front() << ' ';
			if (q2.front() == st2.top())
				break;
			q2.pop();
		}
		if (!st2.empty())
		{
			cout << st2.top() << ' ';
			if (q2.front() == st2.top())
				break;
			st2.pop();
		}
	}
	return 0;
}

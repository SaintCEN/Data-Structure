#include <cstdio>
#include <set>
#include <iostream>
#include <map>
using namespace std;
int main()
{
	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(5);

	set<int>::iterator ite;
	ite = s.find(1);
	s.erase(3);

	for (ite = s.begin(); ite != s.end(); ite++)
	{
		cout << *ite;
	}

	map<int, const char *> m;
	m.insert(make_pair(1, "ONE"));
	m[100] = "HUNDRED";
	map<int, const char *>::iterator mite;
	mite = m.find(1);
	if (mite != m.end())
	{
		puts(mite->second);
	}
	m.erase(10);
	for (auto ite = m.begin(); ite != m.end(); ++ite)
	{
		cout << ite->first << " " << ite->second << endl;
	}
	return 0;
}

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


int hesh(string str)
{
	int a = 127, h = 0;
	for (int i = 0;i < str.size();i++)
	{
		h += (str[i] * a);
	}
	if( h < 0)
	{
		h = h * (-1);
	}
	cout << h << endl;
	return h;
}

int main()
{
	string str;
	for (int i = 0;i < 5;i++)
	{
		cin >> str;
		hesh(str);
	}

	system("PAUSE");
	return 0;
}
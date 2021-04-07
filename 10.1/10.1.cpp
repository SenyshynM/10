#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;
bool search(const char* s);

int main()
{
	char str[101];

	ifstream f("t.txt");
	f >> str;
	if (search(str))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	f.close();

	cin.get();
	return 0;
}

bool search(const char* s)
{

	for (int j = 0; s[j] != '\0'; j++)
		if ((s[j] == 'a' && s[j + 1] == 'a') || (s[j] == 'b' && s[j + 1] == 'b') || (s[j] == 'c' && s[j + 1] == 'c'))
			return true;
	return false;
}
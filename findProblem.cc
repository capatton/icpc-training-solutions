#include <iostream>
#include <fstream>

using namespace std;

void makeLowerCase(string &sentence)
{
	for (int i = 0; i < sentence.length(); ++i)	{
		sentence[i] = tolower(sentence[i]);
	}
}

int main()
{
	char buffer[81];
	string inputLine;
	const int MAX_LINES = 1000;
	int i = 0;

	const string problemString = "problem";

	while (cin.getline(buffer, 81, '\n') && i < MAX_LINES)
	{
		inputLine = buffer;
		makeLowerCase(inputLine);
		if (inputLine.find(problemString) != string::npos)
		{
			cout << "yes\n";
		}
		cout
		{
			else << "no\n";
		}
		++i;
	}

	return 0;
}
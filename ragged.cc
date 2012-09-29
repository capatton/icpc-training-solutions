#include <iostream>
#include <vector>
using namespace std;

const int MAX_LINE_LENGTH = 81;

int nMinusMSquared(int n, int m)
{
	return ((n - m) * (n - m));
}

void outputRaggedScore(int maxLength, vector<int> lineLengths)
{
	int score = 0;
	for (int i = 0; i < lineLengths.size() - 1; ++i)
	{
		score += nMinusMSquared(maxLength, lineLengths[i]);
	}

	cout << score;

}
int main()
{
	string currentLine;
	char buffer[MAX_LINE_LENGTH];
	vector<int> lineLengths;
	
	if (!cin.getline(buffer, MAX_LINE_LENGTH, '\n')) //if file has no lines, end here
	{
		return 0;
	}
	currentLine = buffer;
	int maxLength = currentLine.length();
	lineLengths.push_back(currentLine.length());

	int i = 0;
	while (cin.getline(buffer, MAX_LINE_LENGTH, '\n') && i < 100)
	{
		currentLine = buffer;
		if (currentLine.length() > maxLength)
		{
			maxLength = currentLine.length();
		}

		lineLengths.push_back(currentLine.length());
		++i;
	}

	outputRaggedScore(maxLength, lineLengths);

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

struct Point{
	int x;
	int y;
};

struct Rectangle{
	Point lowerLeft;
	Point upperRight;
};

struct Circle{
	Point center;
	int radius;
};

bool inRectangle(Rectangle rectangle, Point shot)
{
	if (shot.x > 1000 || shot.x < -1000 || shot.y > 1000 || shot.y < -1000)
	{
		return false;
	}

	if (shot.x >= rectangle.lowerLeft.x && shot.x <= rectangle.upperRight.x 
		&& shot.y >= rectangle.lowerLeft.y && shot.y <= rectangle.upperRight.y)
	{
		return true;
	}

	return false;
}

bool inCircle(Circle circle, Point shot)
{
	if (shot.x > 1000 || shot.x < -1000 || shot.y > 1000 || shot.y < -1000)
	{
		return false;
	}

	if ((shot.x - circle.center.x) * (shot.x - circle.center.x) + (shot.y - circle.center.y) * (shot.y - circle.center.y) 
		<= (circle.radius * circle.radius)) 
	{
		return true;
	}

	return false;
}

void makeLowerCase(string &sentence)
{
	for (int i = 0; i < sentence.length(); ++i)	{
		sentence[i] = tolower(sentence[i]);
	}
}

void storeTargets(vector<Rectangle> &rectangleTargets, vector<Circle> &circleTargets)
{
	int numTargets = 0;
	cin >> numTargets;

	string currentType;
	for (int i = 0; i < numTargets; ++i)
	{
		cin >> currentType;
		makeLowerCase(currentType);
		if (currentType == "rectangle")
		{
			Rectangle newRect;
			cin >> newRect.lowerLeft.x;
			cin >> newRect.lowerLeft.y;
			cin >> newRect.upperRight.x;
			cin >> newRect.upperRight.y;
			rectangleTargets.push_back(newRect);
		}
		else if (currentType == "circle")
		{
			Circle newCircle;
			cin >> newCircle.center.x;
			cin >> newCircle.center.y;
			cin >> newCircle.radius;
			circleTargets.push_back(newCircle);
		}
		else //error
		{
		}
	}
}

void outputNumTargetsHit(vector<Rectangle> rectangleTargets, vector<Circle> circleTargets, Point shot)
{
	int targetsHit = 0;
	for (int i = 0; i < rectangleTargets.size(); ++i)
	{
		if (inRectangle(rectangleTargets[i], shot))
		{
			++targetsHit;
		}
	}

	for (int i = 0; i < circleTargets.size(); ++i)
	{
		if (inCircle(circleTargets[i], shot))
		{
			++targetsHit;
		}
	}

	cout << targetsHit << endl;
}

void handleShots(vector<Rectangle> rectangleTargets, vector<Circle> circleTargets)
{
	int numShots = 0;
	cin >> numShots;

	for (int i = 0; i < numShots; ++i)
	{
		Point shot;
		cin >> shot.x;
		cin >> shot.y;
		outputNumTargetsHit(rectangleTargets, circleTargets, shot);
	}
}

int main()
{
	vector<Rectangle> rectangleTargets;
	vector<Circle> circleTargets;

	storeTargets(rectangleTargets, circleTargets);
	handleShots(rectangleTargets, circleTargets);
	
	return 0;
}
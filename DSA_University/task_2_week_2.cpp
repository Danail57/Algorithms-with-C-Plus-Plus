// Дадени са К окръжности (0 <= K <= 30) и (0 <= N <= 30) N точки.
// Да се изведат номерата на окръжностите, подредени в нарастващ ред
// според броя на точките в тях


#include <iostream>
#include <vector> // for points and circles
#include <string>
#include <algorithm> // for sort
#include <utility> // for vector of pair
using namespace std;


struct Point {
	int x;
	int y;
};

struct Circle {
	Point center;
	double radius;
};

int points_in_circle(vector<Point>points, Circle circle)
{
	int count = 0;
	for (Point p : points)
	{
		double dx = p.x - circle.center.x;
		double dy = p.y - circle.center.y;
		if (dx * dx + dy * dy <= circle.radius * circle.radius)
			count++;
	}
	return count;
}

int main()
{
	int k_circles;
	cout << "Number of circles: ";
	cin >> k_circles;

	int n_points;
	cout << "Number of points: ";
	cin >> n_points;

	vector<Circle> circles(k_circles);
	cout << "Enter circles (format: center_x center_y radius):\n";
	for (int i = 0; i < k_circles; i++)
	{
		cout << "Circle " << i + 1 << ": " << endl;
		cin >> circles[i].center.x >> circles[i].center.y >> circles[i].radius;
	}

	vector <Point> points(n_points);
	cout << "Enter points (format: x y):\n";
	for (int i = 0; i < n_points; i++)
	{
		cout << "Point " << i + 1 << endl;
		cin >> points[i].x >> points[i].y;
	}

	vector <pair<int, int>> results;
	for (int i = 0; i < k_circles; i++)
	{
		int count = points_in_circle(points, circles[i]);
		results.push_back({ count, i });
	}

	sort(results.begin(), results.end());
	
	cout << "Circles sorted by number of points: ";
	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i].second << " ";
	}
	cout << endl;
}

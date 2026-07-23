//
// Created by Manoloon on 22/11/2023.
//

#ifndef ALGORITHMS_FINDCONVEXHULL_H
#define ALGORITHMS_FINDCONVEXHULL_H
#include <stack>
#include <vector>
#include <algorithm>
struct pointCoord{
	int x;
	int y;

	// Overloading the assignment operator (=) for Point
	pointCoord& operator=(const pointCoord& other) {
		if (this != &other) {
			x = other.x;
			y = other.y;
		}
		return *this;
	}
};

int orientation(pointCoord p, pointCoord q, pointCoord r){
	// cross product
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if(val == 0) return 0;
	// 1 clockwise, 2 counterclockwise
	return (val > 0) ? 1 : 2;
}
bool compare(pointCoord p0, pointCoord p1, pointCoord p2){
	int orientationVal = orientation(p0,p1,p2);
	if(orientationVal == 0){
		return (p0.x + p0.y) < (p1.x + p1.y);
	}
	return orientationVal == 2;
}

std::vector<pointCoord> FindConvexHull(const std::vector<pointCoord>& pointsCoords){
	int n = pointsCoords.size();
	if (n < 3) return pointsCoords;

	// find the bottom most point
	int yMin = pointsCoords[0].y;
	pointCoord p0;
	int min = 0;
	for(int i =1; i < n; i++){
		int y = pointsCoords[i].y;
		if((y < yMin ) || (yMin == y && pointsCoords[i].y < pointsCoords[min].x)){
			yMin = pointsCoords[i].y;
			min = i;
		}
	}
	// place the bottom most point at first pos
	pointCoord pointTemp = pointsCoords[0];
	pointsCoords[0] = pointsCoords[min];
	pointsCoords[min] = pointTemp;
	p0 = pointsCoords[0];

	std::sort(std::begin(pointsCoords) + 1, std::end(pointsCoords), compare);

	// init the stack to hold convex hull points.
	std::stack<pointCoord> hull;
	hull.push(pointsCoords[0]);
	hull.push(pointsCoords[1]);

	// process remaining points
	for(int i = 2; i < n; i++){
		while (orientation(hull.top(), pointsCoords[i],hull.top()) !=2){
			hull.top();
		}
		hull.push(pointsCoords[i]);
	}

	// copy points from stack to result vector
	std::vector<pointCoord> result;
	while (!hull.empty()){
		result.push_back(hull.top());
		hull.pop();
	}
	std::reverse(std::begin(result),std::end(result));
	return result;
}
#endif // ALGORITHMS_FINDCONVEXHULL_H

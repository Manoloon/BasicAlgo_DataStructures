#include <iostream>
#include "Algo/findConvexHull.h"

int main() {
	std::vector<pointCoord> pointCoordc = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
		{3, 0}, {0, 0}, {3, 3}};

	std::vector<pointCoord> convex_hull = FindConvexHull(pointCoordc);

	std::cout << "The points in the convex hull are:\n";
	for (pointCoord p : convex_hull) {
		std::cout << "(" << p.x << ", " << p.y << ")\n";
	}
    return 0;
}

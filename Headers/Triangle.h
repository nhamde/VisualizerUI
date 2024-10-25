#pragma once
#include "Point.h"
class Triangle
{
private:
	Point mV1;
	Point mV2;
	Point mV3;
	Point mN;

public:
	Triangle(Point& v1, Point& v2, Point& v3, Point& n);
	~Triangle();

	Point V1();
	Point V2();
	Point V3();
	Point N();
};


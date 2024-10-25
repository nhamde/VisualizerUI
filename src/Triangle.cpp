#include "Triangle.h"

Triangle::Triangle(Point& v1, Point& v2, Point& v3, Point& n)
	: mV1(v1), mV2(v2), mV3(v3), mN(n)
{
}

Triangle::~Triangle()
{
}

Point Triangle::V1()
{
	return mV1;
}

Point Triangle::V2()
{
	return mV2;
}

Point Triangle::V3()
{
	return mV3;
}

Point Triangle::N()
{
	return mN;
}
//#pragma once
//#include "Triangle.h"
//#include<vector>
//
//class Triangulation
//{
//public:
//    Triangulation();
//    ~Triangulation();
//
//    std::vector<double> UniqueNumbers;
//    std::vector<Triangle> Triangles;
//};

#pragma once
#include"Triangle.h"
#include <vector>
using namespace std;
class Triangulation
{
public:
	vector<Triangle> triangles;
	vector<double> uniqueValues;

	Triangulation();
	~Triangulation();
};
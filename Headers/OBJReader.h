//#pragma once
//#include <string> 
//#include "Triangulation.h"
//#include "Reader.h"
//
//class ObjReader : public Reader
//{
//public:
//	ObjReader();
//	~ObjReader();
//
//	void read(const std::string& fileName, Triangulation& triangulation);
//
//	bool operator()(double a, double b) const;
//};

#pragma once
#include <string>
#include"Triangulation.h"
using namespace std;
class OBJReader
{
public:
	void read(const string& fileName, Triangulation& tri);
};
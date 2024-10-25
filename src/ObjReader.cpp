#include "ObjReader.h"
//#include "Point.h"
//#include "Reader.h"
//
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <map>
//
//#define TOLERANCE 0.0000001
//
//ObjReader::ObjReader()
//{
//}
//
//ObjReader::~ObjReader()
//{
//}
//
//bool ObjReader::operator()(double a, double b) const
//{
//	return fabs(a - b) > TOLERANCE ? a < b : false;
//}
//
//void ObjReader::read(const std::string& fileName, Triangulation& triangulation)
//{
//    std::map<double, int, ObjReader> uniqueMap;
//    double xyz[3];
//    std::vector<int> pointIndices;
//    std::vector<double> normal;
//
//    std::ifstream infile(fileName);
//
//    if (infile.is_open()) {
//        std::string line;
//        while (getline(infile, line)) {
//            std::stringstream ss(line);
//            std::string word;
//
//            if (line.empty() || line[0] == '#') {
//                continue; 
//            }
//
//            ss >> word;
//            if (word == "v") {
//                ss >> xyz[0] >> xyz[1] >> xyz[2];
//                triangulation.UniqueNumbers.push_back(xyz[0]);
//                triangulation.UniqueNumbers.push_back(xyz[1]);
//                triangulation.UniqueNumbers.push_back(xyz[2]);
//            }
//            else if (word == "vn") {
//                std::vector<double> normal(3);
//                ss >> normal[0] >> normal[1] >> normal[2];
//                normals.push_back(normal);
//            }
//            else if (word == "f") {
//                pointIndices.clear();
//                std::string vertexData;
//                while (ss >> vertexData) {
//                    std::string vertexIndexStr = vertexData.substr(0, vertexData.find('/'));
//                    int vertexIndex = std::stoi(vertexIndexStr) - 1;
//
//                    pointIndices.push_back(vertexIndex * 3); 
//                }
//
//                if (pointIndices.size() == 6) {
//                    for (int i = 0; i < 3; ++i) {
//                        Point p1 = Point(pointIndices[i * 3], pointIndices[i * 3 + 1], pointIndices[i * 3 + 2]);
//                        Point p2 = Point(pointIndices[(i + 1) % 3 * 3], pointIndices[(i + 1) % 3 * 3 + 1], pointIndices[(i + 1) % 3 * 3 + 2]);
//                        Point p3 = Point(pointIndices[3], pointIndices[4], pointIndices[5]);
//
//                        // Assuming the first normal is associated with this triangle
//                        Triangle t(p1, p2, p3, normals[0]); // You may need to adjust which normal is used
//                        triangulation.Triangles.push_back(t);
//                    }
//                }
//            }
//        }
//    }
//}

#include "OBJReader.h"
#include "Triangulation.h"
#include "Point.h"
#include "Triangle.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

void OBJReader::read(const string& fileName, Triangulation& triangulation)
{
    map<double, int> uniqueMap;
    double xyz[3];
    double normalXYZ[3];
    string str1;
    string str2;
    string str3;
    //vector<int> pointIndices;
    vector<Point> vertices;
    vector<Point> normals;


    ifstream infile(fileName);
    if (!infile.is_open()) {
        cerr << "Error: Could not open file " << fileName << endl;
        return;
    }
    if (infile.is_open())
    {

        string line;

        while (getline(infile, line))
        {
            stringstream ss(line);
            string word;
            while (ss >> word)
            {
                if (word == "v")
                {
                    ss >> xyz[0] >> xyz[1] >> xyz[2];

                    int pt[3];

                    for (int i = 0; i < 3; i++)
                    {
                        auto pair = uniqueMap.find(xyz[i]);
                        if (pair == uniqueMap.end())
                        {
                            triangulation.uniqueValues.push_back(xyz[i]);
                            uniqueMap[xyz[i]] = triangulation.uniqueValues.size() - 1;
                            pt[i] = triangulation.uniqueValues.size() - 1;

                        }
                        else
                        {
                            pt[i] = pair->second;

                        }

                    }
                    vertices.push_back(Point(pt[0], pt[1], pt[2]));
                }

                if (word == "vn")
                {
                    ss >> normalXYZ[0] >> normalXYZ[1] >> normalXYZ[2];

                    int pt[3];

                    for (int i = 0; i < 3; i++)
                    {
                        auto pair = uniqueMap.find(normalXYZ[i]);
                        if (pair == uniqueMap.end())
                        {
                            triangulation.uniqueValues.push_back(normalXYZ[i]);
                            uniqueMap[normalXYZ[i]] = triangulation.uniqueValues.size() - 1;
                            pt[i] = triangulation.uniqueValues.size() - 1;

                        }
                        else
                        {
                            pt[i] = pair->second;

                        }

                    }
                    normals.push_back(Point(pt[0], pt[1], pt[2]));
                }

                if (word == "f")
                {
                    ss >> str1 >> str2 >> str3;
                    int FirstPointIndex = stoi(str1.substr(0, 1)) - 1;
                    int SecondPointIndex = stoi(str2.substr(0, 1)) - 1;
                    int ThirdPointIndex = stoi(str3.substr(0, 1)) - 1;
                    int normalIndex = stoi(str3.substr(4, 1)) - 1;
                    cout << FirstPointIndex << SecondPointIndex << ThirdPointIndex << normalIndex << endl;
                    triangulation.triangles.push_back(Triangle(vertices[FirstPointIndex], vertices[SecondPointIndex], vertices[ThirdPointIndex], normals[normalIndex]));
                }
            }
        }
        cout << triangulation.triangles.size();
    }
}
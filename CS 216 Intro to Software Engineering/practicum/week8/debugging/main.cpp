// (C) 2011 Dr.-Ing. Jens Hannemann j.hannemann@ieee.org
// For use outside of the University of Kentucky CS216 class, please contact
// the author

#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdlib>

#include "point.h"
#include "polygon.h"
#include "triangle.h"
#include "rectangle.h"
#include "square.h"

int main(){
  
  // number of elements in the mesh
  const unsigned int SIZE = 1000000;  //compares to unsigned int in loop
  
  // number of available polygon types
  const int NUM_OF_TYPES = 3;  //only has 3 types, not 4 

  std::cout << "Setting up vectors..." << std::flush;
  
  // the cast keeps the compiler from complaining about the irrelevant
  // loss of precision on some platforms
  srand(static_cast<unsigned int>(time(NULL)));
  
  std::vector<Polygon*> polygons;
  std::vector<Triangle> triangles;
  
  // preallocate the vector
  polygons.reserve(SIZE);
  triangles.reserve(SIZE);
  
  int triangle_count  = 0;
  int square_count    = 0;
  int rectangle_count = 0;
  
  // fill the vectors with a random collection of objects
  for(unsigned i=0; i<SIZE; ++i){
    int type = rand()%NUM_OF_TYPES;
    switch (type) {
      case 0:
      {
        const Point p0(static_cast<double>(rand()),
                       static_cast<double>(rand()));
        const Point p1(static_cast<double>(rand()),
                       static_cast<double>(rand()));
        const Point p2(static_cast<double>(rand()),
                       static_cast<double>(rand()));
        polygons.push_back(new Triangle(p0, p1, p2));
        //triangles[i] = Triangle(p0, p1, p2); //skips i's, use push_back
	triangles.push_back(Triangle(p0, p1, p2));
        ++triangle_count;
      }
        break;
      case 1:
      {
        const Point p0(static_cast<double>(rand()),
                       static_cast<double>(rand()));
        const Point p1(static_cast<double>(rand()),
                       static_cast<double>(rand()));
        polygons.push_back(new Rectangle(p0, p1));
        ++rectangle_count;
      }
        break;
      case 2:
      {
        const Point p0(static_cast<double>(rand()),
                       static_cast<double>(rand()));
        const double width(static_cast<double>(rand()));
        polygons.push_back(new Square(p0, width));
        ++square_count;
      }
        break;  //no break; falls through to default
      default:
        std::cerr << "Unexpected type!\n";
        exit(EXIT_FAILURE);
        break;
    }
  }
  
  std::cout << " done" << std::endl;
  std::cout << triangle_count  << " triangles\n"
            << rectangle_count << " rectangles\n"
            << square_count    << " squares" << std::endl;

  // compute total mesh edge length using polymorphism and dynamic binding
  double edge_length = 0.0;
  for(unsigned i=0; i<polygons.size(); ++i){
    edge_length += polygons[i]->circumference();
    }
  
  std::cout << "    edge length: " << edge_length << std::endl;
  
  // compute triangles only
  double triangle_length = 0.0;
  for(unsigned i=0; i<triangles.size(); ++i){
    triangle_length += triangles[i].circumference();
    }
  std::cout << "triangle length: " << triangle_length << std::endl;
  
  // delete pointers
  for(unsigned i=0; i<polygons.size(); ++i)
    delete polygons[i];

return 0;
}

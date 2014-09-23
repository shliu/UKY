#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "mesh.h"

int main(){
  
  try {
    
    Mesh mesh("/u/zon-d2/ugrad/shliu2/cs216/practicum/factories/abstract_factory/build/mesh.xml");
    mesh.process();
    
  } catch (std::exception&e) {
    
    std::cerr << "Exception caught: " << e.what() << '\n';
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}

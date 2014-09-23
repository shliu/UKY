#include "address.h"
#include "addressprocessor.h"
#include <iostream>

int main(){
  try{
    AddressProcessor addressbook("addresses.xml");
    addressbook.print();
  }
  catch(AddressProcessor::Exception& e){
    std::cerr << "Address Exception caught: " << e.what() << '\n';
    return 1;
  }
  catch(std::exception& e){
    std::cerr << "Standard library exception caught: " << e.what() << '\n';
    return 2;
  }
  catch(...){
    std::cerr << "Unknown exception caught\n";
    return 3; 
  }
  return 0;
  }

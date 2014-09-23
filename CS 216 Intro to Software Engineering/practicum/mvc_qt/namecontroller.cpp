#include "namecontroller.h"


NameController::NameController(NameModel * model) : m_model(model){}

void NameController::getData(){
  std::string f, l;
  std::cout << "Enter first name (:end to quit): ";
  std::cin >> f;
  if(f.compare(":end") == 0)
    emit quit();
  else{
    std::cout << "Enter last name: ";
    std::cin >> l;
    m_model->setName(f,l);
  }
}

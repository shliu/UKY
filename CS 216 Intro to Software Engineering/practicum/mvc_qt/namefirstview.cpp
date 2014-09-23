#include "namefirstview.h"
#include <iostream>

FirstView::FirstView(NameModel * model) : View(model){}

void FirstView::print(){
  std::cout << "Name (1): " << m_model->first() << " " << m_model->last() 
    << std::endl;
}

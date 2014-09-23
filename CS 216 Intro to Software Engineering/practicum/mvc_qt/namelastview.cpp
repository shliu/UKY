#include "namelastview.h"
#include <iostream>

LastView::LastView(NameModel * model) : View(model){}


void LastView::print(){
  std::cout << "Name (2): " << m_model->last() << ", " << m_model->first() 
    << std::endl;
}

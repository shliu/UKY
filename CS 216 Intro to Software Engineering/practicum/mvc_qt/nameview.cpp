#include "nameview.h"


View::View(NameModel * model) : m_model(model){}

void View::updateView(){
  print();
}

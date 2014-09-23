#include <iostream>
#include <QCoreApplication>
#include <QTimer>
#include "namecontroller.h"
#include "namemodel.h"
#include "namefirstview.h"
#include "namelastview.h"


int main(int argc, char *argv[]){
  QTimer timer;
  QCoreApplication app(argc, argv);
  NameModel model;
  NameController controller(&model);
  FirstView fview(&model);
  LastView lview(&model);

  QObject::connect(&timer, SIGNAL(timeout()), &controller, SLOT(getData())); 
  QObject::connect(&model, SIGNAL(nameChanged()), &fview, SLOT(updateView()));
  QObject::connect(&model, SIGNAL(nameChanged()), &lview, SLOT(updateView()));
  QObject::connect(&controller, SIGNAL(quit()), &app, SLOT(quit()));

  timer.start(0);
  std::cerr << "starting event loop..." << std::endl;
  app.exec();
  std::cerr << "done processing event loop." << std::endl;
  return 0;
  }

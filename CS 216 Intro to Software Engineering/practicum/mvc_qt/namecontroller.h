#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <iostream>
#include "namemodel.h"

class NameController : public QObject{
  Q_OBJECT

public:
  NameController(NameModel * model);

public slots:
  void getData();

signals:
  void quit();

private:
  NameModel * m_model;
};

#endif

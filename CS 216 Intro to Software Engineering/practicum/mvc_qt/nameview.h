#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include "namemodel.h"


class View : public QObject{
  Q_OBJECT

public:
  View(NameModel * model);
  virtual void print() = 0;
  
public slots:
  void updateView(); 

protected:
  NameModel * m_model;
};


#endif

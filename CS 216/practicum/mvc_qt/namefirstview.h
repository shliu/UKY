#ifndef FIRSTVIEW_H
#define FIRSTVIEW_H

#include "nameview.h"
#include <QObject>

class FirstView : public View{
  Q_OBJECT
public:
  FirstView(NameModel * model);
  void print();
};

#endif

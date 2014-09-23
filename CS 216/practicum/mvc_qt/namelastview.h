#ifndef LASTVIEW_H
#define LASTVIEW_H

#include "nameview.h"
#include <QObject>

class LastView : public View{
  Q_OBJECT
public:
  LastView(NameModel * model);
  void print();
};

#endif

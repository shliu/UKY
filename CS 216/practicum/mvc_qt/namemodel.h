#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <string>


class NameModel : public QObject{
  Q_OBJECT

public:
  //NameModel( QObject* o );
  std::string first() const;	//returns first name
  std::string last() const;	//returns last name

public slots:
  void setName(const std::string f, const std::string l);

signals:
  void nameChanged();

private:
  std::string m_f;
  std::string m_l;
};


#endif

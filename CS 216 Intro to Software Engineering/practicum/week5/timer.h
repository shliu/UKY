#ifndef TIMER_H
#define TIMER_H

class Timer{
public:
  Timer();
  void start();
  void stop();
  double elapsed() const;
  void reset();
private:
  bool started;
  double m_start;
  double m_stop;
};

#endif

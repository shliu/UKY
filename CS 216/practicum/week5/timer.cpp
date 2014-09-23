#include "timer.h"

#include <cassert>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

Timer::Timer() : started(false), m_start(0.0), m_stop(0.0){}

void Timer::start() {
  assert(started==false);
  started = true;
  
#ifdef _WIN32
  DWORD start = GetTickCount();
  m_start = static_cast<double>(start);
#else
  timeval start;
  gettimeofday(&start, 0);
  m_start = 1.e6*static_cast<double>(start.tv_sec)
          + static_cast<double>(start.tv_usec);
#endif
}

void Timer::stop() {
  assert(started==true);
  started = false;
  
#ifdef _WIN32
  DWORD stop = GetTickCount();
  m_stop = static_cast<double>(stop);
#else
  timeval stop;
  gettimeofday(&stop, 0);
  m_stop = 1.e6*static_cast<double>(stop.tv_sec)
         + static_cast<double>(stop.tv_usec);
#endif
}

double Timer::elapsed() const {
  assert(started==false);
  return (m_stop-m_start);
}

void Timer::reset() {
  assert(started==false);
  m_start=0.0;
  m_stop=0.0;
}
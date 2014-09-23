#ifndef VOICEFACTORY_H
#define VOICEFACTORY_H

#include "planfactory.h"
#include "voice.h"

class VoiceFactory : public PlanFactory {
public:
  static Voice* createShape(const QDomElement& element);
};

#endif
#include "voicefactory.h"

#include <cassert>

Voice* VoiceFactory::createShape(const QDomElement& element){
  assert(!element.isNull());
  assert(element.tagName()=="voice");
  
  Voice* voice = new Voice(element);
  
  return voice;
}
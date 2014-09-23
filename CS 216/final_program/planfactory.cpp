#include "planfactory.h"
#include "voicefactory.h"
#include "textfactory.h"
#include "datafactory.h"

#include <cassert>


Plan* PlanFactory::createPlan(const QDomElement& element){
  assert(!element.isNull());
  
  Plan* plan = 0;
  
  // get the tag name for the current DOM element
  const QString tagName = element.tagName();
  
  // create a new object on the heap depending on the type specified by the tag
  if(tagName=="voice")
    plan = VoiceFactory::createShape(element);
  
  if(tagName=="text")
    plan = TextFactory::createShape(element);
  
  if(tagName=="data")
    plan = DataFactory::createShape(element);
  
  // if the schema definition and the and the type list above are in sync,
  // plan should never be null
  assert(plan!=0);
  
  return plan;
}
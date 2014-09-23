#include "addressprocessor.h"
#include <iostream>
#include <QFile>
#include <QXmlSchema>
#include <QXmlSchemaValidator>

AddressProcessor::AddressProcessor(const QString& infile){
  //validate xsd file
  QFile schema_file(":/xsd/addresslist.xsd");
  if(!schema_file.open(QIODevice::ReadOnly))
    throw Exception("Could not open addresslist schema file");
  QXmlSchema schema;
  schema.load(&schema_file, QUrl::fromLocalFile(schema_file.fileName()));
  if(!schema.isValid())
    throw Exception("addresses XML schema definition is invalid");

  //validate xml using schema 
  QFile file(infile);
  if(!file.open(QIODevice::ReadOnly))
    throw Exception("Could not open addresses.xml file");
  QXmlSchemaValidator validator(schema);
  if(!validator.validate(&file, QUrl::fromLocalFile(file.fileName()))){
    file.close();
    throw Exception("XML file is invalid according to schema");
  }

  //create dom using xml file
  file.reset();
  QDomDocument doc("addresses");
  if(!doc.setContent(&file)){
    file.close();
    throw Exception("Error parsing addresses.xml file");
  }
  file.close();

  //get nodes and store them into the vector
  QDomNodeList addresses = doc.elementsByTagName("address");
  for(int i=0; i<addresses.size(); i++){
    nodes.push_back(Address(addresses.item(i))); 
  }
}


void AddressProcessor::print() const{
  std::cout << std::endl << std::endl;
  for(unsigned int i=0; i<nodes.size(); i++){
    nodes[i].print();
    std::cout << std::endl << std::endl;
  }
}

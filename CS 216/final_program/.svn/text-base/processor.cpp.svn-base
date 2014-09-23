#include "processor.h"
#include "planfactory.h"

#include <cassert>
#include <iostream>
#include <iomanip>

#include <QFile>
#include <QXmlSchema>
#include <QXmlSchemaValidator>


Processor::Processor(const QString& aFile, const QString& pFile){
  //validate xsd file
  QFile a_schema_file(":/xsd/accounts.xsd");
  QFile p_schema_file(":/xsd/plans.xsd");
  if(!a_schema_file.open(QIODevice::ReadOnly))
    throw Exception("Could not open Accounts schema file");
  if(!p_schema_file.open(QIODevice::ReadOnly))
    throw Exception("Could not open Plans schema file");
  QXmlSchema a_schema;
  QXmlSchema p_schema;
  a_schema.load(&a_schema_file, QUrl::fromLocalFile(a_schema_file.fileName()));
  p_schema.load(&p_schema_file, QUrl::fromLocalFile(p_schema_file.fileName()));
  if(!a_schema.isValid())
    throw Exception("Accounts XML schema definition is invalid");
  if(!p_schema.isValid())
    throw Exception("Plans XML schema definition is invalid");
  
  //validate xml using schema 
  QFile a_file(aFile);
  QFile p_file(pFile);
  if(!a_file.open(QIODevice::ReadOnly))
    throw Exception("Could not open Accounts XML file");
  if(!p_file.open(QIODevice::ReadOnly))
    throw Exception("Could not open Plans XML file");
  QXmlSchemaValidator a_validator(a_schema);
  if(!a_validator.validate(&a_file, QUrl::fromLocalFile(a_file.fileName()))){
    a_file.close();
    throw Exception("Accounts XML file is invalid according to schema");
  }
  QXmlSchemaValidator p_validator(p_schema);
  if(!p_validator.validate(&p_file, QUrl::fromLocalFile(p_file.fileName()))){
    p_file.close();
    throw Exception("Plans XML file is invalid according to schema");
  }
  
  //create dom using xml file
  a_file.reset();
  p_file.reset();
  QDomDocument a_doc("accounts"), p_doc("plans");
  if(!a_doc.setContent(&a_file)){
    a_file.close();
    throw Exception("Error parsing Accounts XML file");
  }
  a_file.close();
  if(!p_doc.setContent(&p_file)){
    p_file.close();
    throw Exception("Error parsing Plans XML file");
  }
  p_file.close();

  //get nodes and store them into the vector
  QDomNodeList accounts = a_doc.elementsByTagName("account");
  for(int i=0; i<accounts.size(); i++){
    m_accounts.push_back(Account(accounts.item(i)));
  }

  // document has been read successfully - instantiate factory
  PlanFactory factory;
  
  // get list of all plans
  QDomElement docElem = p_doc.documentElement();
  
  // iterate over all first-level elements (i.e. plans) in the DOM tree
  QDomNode n = docElem.firstChild();
  while(!n.isNull()) {
    // convert the node to an element
    QDomElement e = n.toElement(); 
    assert(!e.isNull());

    // the element now holds a DOM subtree representing a plan
    // create plan object from subtree
    Plan* plan = factory.createPlan(e);

    assert(plan!=0);

    const unsigned int account_num = plan->account();
    m_plans.insert(std::pair<unsigned int, Plan*>(account_num, plan));
    
    n = n.nextSibling();
  }
}



Processor::~Processor(){
  std::multimap<unsigned int, Plan*>::iterator it;
  for(it=m_plans.begin(); it!=m_plans.end(); it++)
    delete it->second;
}



void Processor::printBills() const{
  std::cout << std::endl << "Printing Bills..." << std::endl << std::endl;
  unsigned int total;
  std::vector<Account>::const_iterator it_acc;
  for(it_acc=m_accounts.begin(); it_acc!=m_accounts.end(); it_acc++){
    total = 0;
    it_acc->print();
    //finds the plans with matching account #
    std::pair<std::multimap<unsigned int, Plan*>::const_iterator,
      std::multimap<unsigned int, Plan*>::const_iterator> range;
    range = m_plans.equal_range(it_acc->number());  //returns range of matches
    //prints plans of matching account #'s
    std::multimap<unsigned int, Plan*>::const_iterator it_plan;
    for(it_plan=range.first; it_plan!=range.second; it_plan++){
      it_plan->second->print();
      total += it_plan->second->subtotal();
    }
    std::cout << "Total amount due: " << total << std::endl << std::endl;
  }
  std::cout << "Printed " << m_accounts.size() 
    << " accounts in this billing cycle" << std::endl << std::endl;
}



void Processor::printReports() const{
  std::cout << std::endl << "Printing Reports..." << std::endl << std::endl;

  //calculate each plan's total usage, total revenue
  //store type usage into a map<typename, totalusage>
  unsigned int revenue = 0;
  std::multimap<unsigned int, Plan*>::const_iterator it_plan;
  std::map<std::string, unsigned int> usages;
  std::map<std::string, unsigned int>::const_iterator it_use;
  std::string type;
  for(it_plan=m_plans.begin(); it_plan!=m_plans.end(); it_plan++){
    revenue += it_plan->second->subtotal();
    type = it_plan->second->type();
    it_use = usages.find(type);  //returns map.end() if nothing's found
    //if can't find type, it should be the first value
    if(it_use==usages.end())
      usages[type] = it_plan->second->usage();
    else
      usages[type] += it_plan->second->usage();
  }
  
  const unsigned int num_accs = m_accounts.size();
    
  std::cout << "Total # of accounts:     " << num_accs << std::endl
    << "Total revenue:           " << revenue << std::endl;
  
  //print each plan's total usage
  std::cout << "Total usage for..." << std::endl;
  for(it_use=usages.begin(); it_use!=usages.end(); it_use++)
    std::cout << "  " << it_use->first
      << ": " << std::setw(6-(it_use->first).length())
      << it_use->second << std::endl;

  //print each plan's average uage
  std::cout << "Average usage/account for..." << std::endl;
  for(it_use=usages.begin(); it_use!=usages.end(); it_use++)
    std::cout << "  " << it_use->first
      << ": " << std::setw(6-(it_use->first).length())
      << it_use->second/num_accs << std::endl;
	
  std::cout << "Average revenue/account: " << revenue/num_accs
    << std::endl << std::endl;
}



void Processor::printAccount(const int& accountNum) const{
  assert(accountNum>0);
  const unsigned int acc_num = static_cast<unsigned int>(accountNum);
  bool found = false;
  std::vector<Account>::const_iterator it_acc;
  for(it_acc=m_accounts.begin(); it_acc!=m_accounts.end(); it_acc++){
    if(it_acc->number() == acc_num){
      std::cout << std::endl << "Account found: " << std::endl;
      it_acc->print();
      //find plans of matching account #
      std::pair<std::multimap<unsigned int, Plan*>::const_iterator,
        std::multimap<unsigned int, Plan*>::const_iterator> range;
      range = m_plans.equal_range(it_acc->number());
      //print plans of matching account #'s
      std::multimap<unsigned int, Plan*>::const_iterator it_plan;
      for(it_plan=range.first; it_plan!=range.second; it_plan++){
        it_plan->second->print();
      }
      found = true;
      break;
    }
  }
  if(!found)
    std::cout << "Sorry, no account of #" << acc_num << " found" << std::endl;
}

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <getopt.h>
#include <stdlib.h>

class InputException{
public:
  InputException(const std::string& msg) : m_msg(msg){};
  const std::string& what() const {return m_msg;}
private:
  const std::string m_msg;
};

int main(int argc, char* argv[]) {
  try {

    // initialize option values to defaults
    std::string aFile;  //accounts file
    std::string pFile;  //plans file
    int accountNum;
    bool printBilling = false;
    bool printReport = false;
    bool printAccount = false;

    // process options
    const char* optstring = "a:bhp:r";
    const struct option longOpts[] = {
      {"accounts",       required_argument, 0, 'a'},
      {"billing",        no_argument,       0, 'b'},
      {"help",           no_argument,       0, 'h'},
      {"plans",          required_argument, 0, 'p'},
      {"print-account",  required_argument, 0, '0'},
      {"report",         no_argument,       0, 'r'}
    };

    int c;
    int longIndex;
    while((c = getopt_long(argc, argv, optstring, longOpts, &longIndex)) != -1){
      switch(c){
      case 'a':
        {
          std::istringstream is(optarg);
          char leftoverChar;
          if(!(is >> aFile) || is.get(leftoverChar))
            throw(InputException("Invalid argument for accounts file name"));
        }
        break;
      case 'b':
        {
          printBilling = true;
        }
        break;
      case 'p':
        {
          std::istringstream is(optarg);
          char leftoverChar;
          if(!(is >> pFile) || is.get(leftoverChar))
            throw(InputException("Invalid argument for plans file name"));
        }
        break;
      case 'r':
        {
          printReport = true;
        }
        break;
      case '0':
        { // long option without corresponding short option
		  std::istringstream is(optarg);
		  char leftoverChar;
		  if(!(is >> accountNum) || is.get(leftoverChar))
            throw(InputException("Invalid argument for account #"));
		  printAccount = true;
        }
		break; 
      case 'h':
      default:
        {
          std::cerr << "Usage: " << argv[0] 
		    << " -a afile -p pfile [-b|-r|--print-account #]\n";
          std::cerr << "Options:\n"
            << "-a, --accounts afile     Specify accounts file\n"
            << "-b, --billing            Run a billing cycle and print bills\n"
            << "-h, --help               Shows this message\n"
            << "-p, --plans pfile        Specify plans file\n"
            << "    --print-account #    Print financial and usage report\n"
            << "-r, --report             Print financial and usage report\n";
          exit(-1);
        }
      }
    }

    // check options for semantic correctness
    if(aFile.empty() || pFile.empty())
      throw InputException
	("Both Accounts and Plans files must be provided");
	
    if(!printAccount && !printReport && !printBilling)
      throw InputException
        ("You must choose at least one -b, -r, --print-account option(s)");
	
    if(printAccount && (printReport || printBilling))
      throw InputException
        ("Sorry, cannot print Account at the same time as Report/Billing");
		
    if(accountNum<1)
      throw InputException
        ("Sorry, the account # must be > 0");
		
	


    // start working, using the options and arguments
    std::cout << "Options OK" << std::endl;
	
    if(printReport)
      std::cout << "Generating report..." << std::endl;
	
    if(printBilling)
      std::cout << "Running billing cycle..." << std::endl;
	  
    if(printAccount)
      std::cout << "Printing account info for "
      << accountNum << "..." << std::endl;
  }
  catch(InputException& e){
    std::cerr << "Invalid input: " << e.what() << '\n';
    std::cerr << "Use the --help option for usage information\n";
    exit(2);
  }
  catch(...){
    std::cerr << "Unknown exception caught\n";
    exit(3);
  }

  return 0;
}


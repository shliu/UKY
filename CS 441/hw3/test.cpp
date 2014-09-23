#include <iostream>
#include <regex>
using namespace std;

int main()
{
    regex e("[0-9]+");
    if(regex_match("32910", e))
    {
        cout << "Is number" << endl;
    }
}
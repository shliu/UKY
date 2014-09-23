/*
  This program implements a simple Reverse Polish Notation calculator
  This program was successfully compiled on the multi-lab servers 
  with the following command:
    "g++ -Wall calc1.cpp"
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <stdio.h>

using namespace std;

const float PI = 3.14159;

vector<string> tokenize(string);	//splits the string into tokens, saved as elements in string vector
void RPNcalc(vector<string>);		//calculates the result of a properly tokenized string vector


int main()
{
	string input;		//user input
	vector<string> tokens;	//string vector used to store user input split into tokens
	
	cout << "Please enter your post-fix (Reverse Polish Notation) function:" << endl;
	getline(cin, input);
	
	tokens = tokenize(input);
	RPNcalc(tokens);
}


vector<string> tokenize(string input)
{
	vector<string> tokens;
	size_t current = 0;
	size_t next = 0;
	
	while(next!=string::npos)
	{
		next = input.find_first_of(" ", current);
		tokens.push_back(input.substr(current, next-current));
		current = next + 1;
	}
	
	return tokens;
}


void RPNcalc(vector<string> tokens)
{
	stack<float> stack;

	for(vector<string>::iterator it=tokens.begin();
		it!=tokens.end();
		it++)
	{
		string field = *it;
		float number, left, right;
		
		int isNumber = sscanf(field.c_str(), "%f", &number);
		if(isNumber>0)
		{
			stack.push(number);
		}
		else if(field==("pi"))
		{
			stack.push(PI);	
		}
		else if(stack.size()>1 
			&& (field=="+" || field=="-" || field=="*" || field=="/" || field=="^"))
		{
			right = stack.top();
			stack.pop();
			left = stack.top();
			stack.pop();
			
			if(field=="+")
			{
				stack.push(left+right);
			}
			else if(field=="-")
			{
				stack.push(left-right);	
			}
			else if(field=="*")
			{
				stack.push(left*right);
			}
			else if(field=="/")
			{
				stack.push(left/right);	
			}
			else //field=="^"
			{
				stack.push(pow(left, right));	
			}
		}
		else
		{
			//unknown input, do nothing and maybe throw error
			cerr << "error: cannot evaluate \"" << field << "\"" << endl;
		}
	}
	

	if(stack.size()==1)
	{
		cout << "Result: " << stack.top() << endl;
	}
	else if(stack.size()>1)
	{
		cerr << "error: too many operands" << endl;
	}
}

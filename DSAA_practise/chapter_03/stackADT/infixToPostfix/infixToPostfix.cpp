#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

#define LARGER   1
#define EQUAL    0
#define SMALLER -1
#define ERROR   -2
int compare(char i, char j)
{
    if(j == '(')
	return LARGER;
    switch(i)
    {
	case '*': case '/':
	    if(j == '+' || j == '-')
		return LARGER;
	    else
		return EQUAL;
	case '+': case '-':
	    if(j == '*' || j == '/')
		return SMALLER;
	    else
		return EQUAL;
	default:
	    return ERROR;
    }
}

void infixToPostfix(const vector<char> &infix, vector<char> &postfix)
{
    stack<char> operatorStack;

    for(char i: infix)
    {
	if(isdigit(i) || i == ' ')
	    postfix.push_back(i);
	else if(i == '(')
	    operatorStack.push(i);
	else if(i == ')')
	{
	    for(char j = operatorStack.top(); j != '('; j = operatorStack.top())
	    {
		postfix.push_back(' ');
		postfix.push_back(j);
		operatorStack.pop();
	    }
	    operatorStack.pop();
	}
	else
	{
	    while(!operatorStack.empty() && compare(i, operatorStack.top()) != LARGER)
	    {
		postfix.push_back(' ');
		postfix.push_back(operatorStack.top());
		operatorStack.pop();
	    }
	    operatorStack.push(i);
	}
    }
    while(!operatorStack.empty())
    {
	postfix.push_back(' ');
	postfix.push_back(operatorStack.top());
	operatorStack.pop();
    }
}

int main(int argc, char **argv)
{
    vector<char> infix, postfix;

    for(int i = 1; i < argc; ++i)
    {
	string temp = argv[i];
	for(auto c: temp)
	    infix.push_back(c);
	infix.push_back(' ');
    }
    infixToPostfix(infix, postfix);
    for(auto c: postfix)
	cout << c;
    cout << endl;
    return 0;
}




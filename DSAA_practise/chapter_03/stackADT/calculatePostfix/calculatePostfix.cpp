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
    bool isNewNum = true;

    for(char i: infix)
    {
	if(isdigit(i))
	{
	    if(isNewNum)
		postfix.push_back(' ');
	    isNewNum = false;
	    postfix.push_back(i);
	}
	else
	{
	    isNewNum = true;
	    if(i == '(')
	    {
		operatorStack.push(i);
	    }
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
	    else if(i != ' ')
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
    }
    while(!operatorStack.empty())
    {
	postfix.push_back(' ');
	postfix.push_back(operatorStack.top());
	operatorStack.pop();
    }
}

int calculate(int a, int b, char op)
{
    switch(op)
    {
	case '+':
	    return a + b;
	case '-':
	    return a - b;
	case '*':
	    return a * b;
	case '/':
	    if(b != 0)
		return a / b;
	    else
		return 0;
	default:
	    return 0;
    }
}

int calculatePostfix(const vector<char> &infix)
{
    vector<char> postfix;
    infixToPostfix(infix, postfix);
    stack<int> numStack;
    string numStr = "";
    for(auto i = postfix.cbegin(); i < postfix.cend(); ++i)
    {
	if(*i == ' ' && numStr != "")
	{
	    int num = stoi(numStr);
	    numStack.push(num);
	    numStr = "";
	}
	else if(isdigit(*i))
	    numStr += *i;
	else if(*i != ' ')
	{
	    int b = numStack.top();
	    numStack.pop();
	    int a = numStack.top();
	    numStack.pop();
	    numStack.push(calculate(a, b, *i));
	}
    }
    return numStack.top();
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
    int result = calculatePostfix(infix);
    cout << result << endl;
    return 0;
}




#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define LEFT      0
#define RIGHT     1
#define NOTSYMBOL 2
#define ERROR     3
#define OK        4

int symbolJudge(const char s1, const char s2 = 0)
{
    switch(s1)
    {
	case '(': case '[': case '{':
	    if(s2 == 0)
	    	return LEFT;
	    else if(s1 == '(' && s2 != ')')
		return ERROR;
	    else if(s1 == '[' && s2 != ']')
		return ERROR;
	    else if(s1 == '{' && s2 != '}')
		return ERROR;
	    else 
		return OK;
	case ')': case ']': case '}':
	    if(s2 == 0)
	    	return RIGHT;
	    else
		return ERROR;
	default:
	    return NOTSYMBOL;
    }
}

string symbolBalanceJudge(const string symbolString)
{
    stack<char> symbolStack;
    string resultInfo = "";

    for(auto i: symbolString)
    {
	if(symbolJudge(i) == LEFT)
	    symbolStack.push(i);
	else if(symbolJudge(i) == RIGHT)
	{
	    if(symbolStack.empty())
		resultInfo = resultInfo + "?" + i + " ";
	    else if(symbolJudge(symbolStack.top(), i) == ERROR)
	    {
		resultInfo = resultInfo + symbolStack.top() + i + " ";
		symbolStack.pop();
	    }
	    else if(symbolJudge(symbolStack.top(), i) == OK)
		symbolStack.pop();
	}
    }
    while(!symbolStack.empty())
    {
	resultInfo = resultInfo + symbolStack.top() + "? ";
	symbolStack.pop();
    }
    return resultInfo;
}

int main(int argc, char **argv)
{
    string result = symbolBalanceJudge(argv[1]);
    if(result.empty())
	cout << "No symbol error." << endl;
    else 
	cout << "Symbol error! can not match:\n" << result << endl;
    return 0;
}




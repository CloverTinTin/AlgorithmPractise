#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

struct binaryTree;
typedef struct binaryTree *bNodePtr;

struct binaryTree
{
    int        num;
    char       op;
    bNodePtr   left;
    bNodePtr   right;
};

int compare(char a, char b)
{
    switch(a)
    {
	case '+': case '-':
	    if(b == '+' || b== '-')
		return 0;
	    else
		return -1;
	case '*': case '/':
	    if(b == '*' || b == '/')
		return 0;
	    else
		return 1;
	default:
	    break;
    }
}

string infixToPostfix(const string &infix)
{
    string postfix = "";
    stack<char> opStack;

    for(auto c: infix)
    {
	if(isdigit(c))
	    postfix += c;
	else if(!isblank(c))
	{
	    if(isdigit(*(postfix.end() - 1)))
		postfix += " ";
	    if(c == '(')
		opStack.push(c);
	    else if(c == ')')
	    {
		while(opStack.top() != '(')
		{
		    postfix += opStack.top();
		    opStack.pop();
		}
		opStack.pop();
	    }
	    else
	    {
		while(!opStack.empty() && opStack.top() != '(' && compare(c, opStack.top()) <= 0)
		{
		    postfix += opStack.top();
		    opStack.pop();
		}
		opStack.push(c);
	    }
	}
    }
    while(!opStack.empty())
    {
	postfix += opStack.top();
	opStack.pop();
    }
    return postfix;
}

bNodePtr postfixToExpressionTree(const string &postfix)
{
    stack<bNodePtr> bNodeStack;
    string num = "";
    for(auto c: postfix)
    {
	if(isdigit(c))
	    num += c;
	else
	{
	    if(num != "")
	    {
		bNodePtr node = new struct binaryTree;
		node->num = stoi(num);
		node->op = 0;
		num = "";
		node->left = node->right = nullptr;
		bNodeStack.push(node);
	    }
	    if(c != ' ')
	    {
		bNodePtr node = new struct binaryTree;
		node->op = c;
		node->right = bNodeStack.top();
		bNodeStack.pop();
		node->left = bNodeStack.top();
		bNodeStack.pop();
		bNodeStack.push(node);
	    }
	}
    }
    return bNodeStack.top();
}

int calculateExpressionTree(bNodePtr tree)
{
    int leftValue, rightValue, result;

    if(tree->left == nullptr )
	result =  tree->num;
    else
    {
	leftValue = calculateExpressionTree(tree->left);
	rightValue = calculateExpressionTree(tree->right);
	switch(tree->op)
	{
	    case '+':
		result = leftValue + rightValue;
		break;
	    case '-':
		result = leftValue - rightValue;
		break;
	    case '*':
		result = leftValue * rightValue;
		break;
	    case '/':
		result = leftValue / rightValue;
		break;
	    default:
		break;
	}
    }
    delete tree;
    return result;
}

int main(int argc, char **argv)
{
    string infix = "";
    for(int i = 1; i < argc; ++i)
    {
	infix += argv[i];
	infix += " ";
    }
    string postfix = infixToPostfix(infix);
    int result = calculateExpressionTree(postfixToExpressionTree(postfix));
    cout << result << endl;
    //cout << postfix << endl;
    return 0;
}




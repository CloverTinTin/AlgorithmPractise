#include <iostream>
#include <list>
#include <iterator>
#include <string>
using namespace std;

typedef struct PolynomialNode
{
    int coefficient;
    int exponent;
}polynomialNode;

void polyMultiply(const list<polynomialNode> &poly1, const list<polynomialNode> &poly2, list<polynomialNode> &resultPoly)
{
    for(auto i: poly1)
	for(auto j: poly2)
	{
	    polynomialNode tempNode;
	    tempNode.coefficient = i.coefficient * j.coefficient;
	    tempNode.exponent = i.exponent + j.exponent;
	    auto iter = resultPoly.end();
	    if(!resultPoly.empty())
		for(iter = resultPoly.begin(); iter != resultPoly.end() && tempNode.exponent < iter->exponent; ++iter);
	    if(iter != resultPoly.end() && iter->exponent == tempNode.exponent)
		iter->coefficient += tempNode.coefficient;
	    else
		resultPoly.insert(iter, tempNode);
	}
}

int main(int argc, char **argv)
{
    list<polynomialNode> poly1, poly2, resultPoly;

    list<polynomialNode> *polyPtr = &poly1;
    for(int i = 1; i < argc; i += 2)
    {
	if(stoi(argv[i]) == 0)
	{
	    polyPtr = &poly2;
	    continue;
	}
	polynomialNode node = {stoi(argv[i]), stoi(argv[i + 1])};
	//node.coefficient = stoi(argv[i]);
	//node.exponent = stoi(argv[i + 1]);
	polyPtr->push_back(node);
    } 
    polyMultiply(poly1, poly2, resultPoly);
    for(auto i: resultPoly)
	cout << i.coefficient << " " << i.exponent << " | ";
    cout << endl;
    return 0;
}




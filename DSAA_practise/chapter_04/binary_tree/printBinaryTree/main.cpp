#include "searchTree.h"
#include "printBinaryTree.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    searchTreePtr tree = nullptr;
    vector<int> data;
    for(int i = 1; i < argc; ++i)
	data.push_back(stoi(argv[i]));
    for(int i = 0; i < data.size(); ++i)
	tree = insertElement(tree, data[i]);
    printBinaryTree(tree);
    return 0;
}

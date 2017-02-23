#include "searchTree.h"
#include "printBinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
    searchTreePtr tree = nullptr;
//    int data[] = {5, 4, 1, 2, 3, 9, 10, 7, 6, 8};
    int data[] = {7, 4, 3, 5, 9, 8};

    for(int i = 0; i < end(data) - begin(data); ++i)
	tree = insertElement(tree, data[i]);
    printBinaryTree(tree);
    return 0;
}

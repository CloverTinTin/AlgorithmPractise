#include "searchTree.h"
#include <iostream>
using std::endl;
using std::cout;

void traverseTree(searchTreePtr tree)
{
    if(tree == nullptr)
	return;
    traverseTree(tree->left);
    cout << tree->element << " " << tree->amount << endl;
    traverseTree(tree->right);
}

int main()
{
    int a[] = {6, 4, 7, 3, 5, 9, 10, 8, 3, 1, 1, 1, 2};
    searchTreePtr tree = nullptr;

    int size = std::end(a) - std::begin(a);
    for(int i = 0; i < size; ++i)
	tree = insertElement(tree, a[i]);
    traverseTree(tree);
    cout << endl;
    tree = deleteElement(tree, 6);
    traverseTree(tree);
    return 0;
}

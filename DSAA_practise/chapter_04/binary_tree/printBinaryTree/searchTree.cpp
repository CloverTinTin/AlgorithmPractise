#include <iostream>
#include "searchTree.h"

nodePtr findElement(searchTreePtr tree, int keyword)
{
    if(tree == nullptr)
	return nullptr;
    if(tree->element == keyword)
	return tree;
    else if(tree->element > keyword)
	return findElement(tree->left, keyword);
    else
	return findElement(tree->right, keyword);
}

nodePtr insertElement(searchTreePtr tree, int keyword)
{
    if(tree == nullptr)
    {
	tree = new struct treeNode;
	tree->element = keyword;
	tree->amount = 1;
	tree->left = tree->right = nullptr;
    }
    else if(tree->element > keyword)
	tree->left = insertElement(tree->left, keyword);
    else if(tree->element == keyword)
	++(tree->amount);
    else
	tree->right = insertElement(tree->right, keyword);
    return tree;
}

nodePtr deleteElement(searchTreePtr tree, int keyword)
{
    if(tree->element == keyword)
    {
	if(tree->left == nullptr || tree->left == nullptr)
	{
	    if(tree->left == tree->right)
	    {
		delete tree;
		tree = nullptr;
	    }
	    else 
	    {
		nodePtr temp = tree;
		if(tree->left != nullptr)
		    tree = tree->left;
		else
		    tree = tree->right;
		delete temp;
	    }
	}
	else
	{
	    nodePtr temp = tree->right;
	    while(temp->left != nullptr)
		temp = temp->left;
	    tree->element = temp->element;
	    tree->amount = temp->amount;
	    tree->right = deleteElement(tree->right, tree->element);
	}
    }
    else if(tree->element > keyword)
	tree->left = deleteElement(tree->left, keyword);
    else
	tree->right = deleteElement(tree->right, keyword);
    return tree;
}


















#include <iostream>
#include "AVL_Tree.h"
#include "printBinaryTree.h"

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

nodePtr singleRotate(searchTreePtr tree)
{
    nodePtr rootPtr = tree;
    if(getBinaryTreeHeight(tree->left) >  
       getBinaryTreeHeight(tree->right))
    {
	tree = tree->left;
	rootPtr->left = tree->right;
	tree->right = rootPtr;
    }	
    else
    {
	tree = tree->right;
	rootPtr->right = tree->left;
	tree->left = rootPtr;
    }
    rootPtr->height = getBinaryTreeHeight(rootPtr);
    tree->height = getBinaryTreeHeight(tree);
    return tree;
}

nodePtr doubleRotate(searchTreePtr tree)
{
    if(getBinaryTreeHeight(tree->left) >  
       getBinaryTreeHeight(tree->right))
	tree->left = singleRotate(tree->left);
    else
	tree->right = singleRotate(tree->right);
    tree = singleRotate(tree);
    return tree;
}

nodePtr insertElement_AVL(searchTreePtr tree, int keyword)
{
    if(tree == nullptr)
    {
	tree = new struct treeNode;
	tree->element = keyword;
	tree->amount = 1;
	tree->left = tree->right = nullptr;
    }
    else if(tree->element > keyword)
    {
	tree->left = insertElement_AVL(tree->left, keyword);
	if(getBinaryTreeHeight(tree->left) -  
	   getBinaryTreeHeight(tree->right) > 1)
	    if(keyword < tree->left->element)
		tree = singleRotate(tree);
	    else 
		tree = doubleRotate(tree);
    }
    else if(tree->element == keyword)
	++(tree->amount);
    else
    {
	tree->right = insertElement_AVL(tree->right, keyword);
	if(getBinaryTreeHeight(tree->right) - 
	   getBinaryTreeHeight(tree->left) > 1)
	    if(keyword > tree->right->element)
		tree = singleRotate(tree);
	    else
		tree = doubleRotate(tree);
    }
    tree->height = getBinaryTreeHeight(tree);
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




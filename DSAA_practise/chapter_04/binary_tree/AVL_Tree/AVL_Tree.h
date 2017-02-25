#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

struct treeNode;
typedef struct treeNode *searchTreePtr;
typedef struct treeNode *nodePtr;

nodePtr findElement(searchTreePtr tree, int keyword);
nodePtr deleteElement(searchTreePtr tree, int keyword);
nodePtr insertElement_AVL(searchTreePtr tree, int keyword);
nodePtr singleRotate(searchTreePtr tree);
nodePtr doubleRotate(searchTreePtr tree);

struct treeNode
{
    int element;
    int amount;
    int height;
    nodePtr left;
    nodePtr right;
};

#endif

#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

struct treeNode;
typedef struct treeNode *searchTreePtr;
typedef struct treeNode *nodePtr;

nodePtr findElement(searchTreePtr tree, int keyword);
nodePtr deleteElement(searchTreePtr tree, int keyword);
nodePtr insertElement(searchTreePtr tree, int keyword);

struct treeNode
{
    int element;
    int amount;
    nodePtr left;
    nodePtr right;
};

#endif

#include "printBinaryTree.h"
#include "searchTree.h"
#include <iostream>
#include <vector>
using std::cout;
using std::vector;

#define LEFT   -1 
#define ROOT    0
#define RIGHT   1
#define L_SLASH -100000 
#define R_SLASH -200000

int getBinaryTreeDepth(searchTreePtr tree)
{
    if(tree == nullptr)
	return -1;
    else
    {
	int leftDepth = getBinaryTreeDepth(tree->left);
	int rightDepth = getBinaryTreeDepth(tree->right);
	int result = leftDepth > rightDepth? leftDepth: rightDepth;
	return result + 1;
    }
}

using intVec = vector<int>;

void creatPrintSheet(searchTreePtr tree, vector<intVec> &printSheet, int rows, int rowNum, int columNum, int leftOrRight)
{
    if(tree == nullptr)
	return;
    printSheet[rowNum][columNum] = tree->element;
    if(leftOrRight == LEFT)
	for(int i = 0; i < rows - 1 - rowNum; ++i)
	    printSheet[rowNum - i][columNum + i] = L_SLASH;
    else if(leftOrRight == RIGHT)
	for(int i = 0; i < rows - 1 - rowNum; ++i)
	    printSheet[rowNum - i][columNum - i] = R_SLASH;
    int step = (rows - 1 - rowNum) / 2 + 1;
    creatPrintSheet(tree->left, printSheet, rows, rowNum + step, columNum - step, LEFT);
    creatPrintSheet(tree->right, printSheet, rows, rowNum + step, columNum + step, RIGHT);
}

void printBinaryTree(searchTreePtr tree)
{
    int treeDepth = getBinaryTreeDepth(tree);
    vector<intVec> printSheet;
    //int rows = treeDepth * 2 + 1;
    int colums = 1;
    for(int i = 0; i < treeDepth; ++i)
	colums *= 2;
    colums = colums / 2 * 6;
    int rows = colums / 2;
    for(int i = 0; i < rows; ++i)
    {
	intVec row(colums, 0);
	printSheet.push_back(row);
    }
    creatPrintSheet(tree, printSheet, rows, 0, colums / 2 - 1, ROOT);
    for(int i = 0; i < rows; ++i)
	for(int j = 0; j < colums; ++j)
	{
	    int num;
	    if((num = printSheet[i][j]) == 0)
		cout << " ";
	    else if(num == L_SLASH)
		cout << "/";
	    else if(num == R_SLASH)
		cout << "\\";
	    else 
		cout << num;
	    if(j == colums - 1)
		cout << std::endl;
	}
}




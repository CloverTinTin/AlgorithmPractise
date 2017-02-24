#include "printBinaryTree.h"
#include "searchTree.h"
#include <iostream>
#include <iomanip>
#include <vector>
using std::cout;
using std::vector;

#define LEFT   -1 
#define ROOT    0
#define RIGHT   1
#define L_SLASH  -100000 
#define R_SLASH  -200000
#define NOOUTPUT -300000
#define BLANK    -400000

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

void creatPrintSheet(searchTreePtr tree, vector<intVec> &printSheet, int rows, int colums, int rowNum, int columNum, int leftOrRight)
{
    if(tree == nullptr)
	return;
    printSheet[rowNum][columNum] = tree->element;
    int numWidth = 1;
    int temp = tree->element / 10;
    while(temp != 0)
    {
	++numWidth;
	temp = temp / 10;
    }
    if(rowNum != rows)
	for(int i = 1; columNum + i <= colums && i < numWidth; ++i)
	    printSheet[rowNum][columNum + i] = NOOUTPUT;
    if(leftOrRight == LEFT)
    {
	if(rowNum == rows)
	    printSheet[rowNum - 1][columNum + 1] = L_SLASH;
	else
	    for(int i = 1; i <= rows - rowNum; ++i)
		printSheet[rowNum - i][columNum + i] = L_SLASH;
    }
    else if(leftOrRight == RIGHT)
    {
	if(rowNum == rows)
	    printSheet[rowNum - 1][columNum - 1] = R_SLASH;
	else
	    for(int i = 1; i <= rows - rowNum; ++i)
		printSheet[rowNum - i][columNum - i] = R_SLASH;
    }
    int step = (rows - rowNum) / 2 + 1;
    creatPrintSheet(tree->left, printSheet, rows, colums, rowNum + step, columNum - step, LEFT);
    creatPrintSheet(tree->right, printSheet, rows, colums, rowNum + step, columNum + step, RIGHT);
}

void printBinaryTree(searchTreePtr tree)
{
    int treeDepth = getBinaryTreeDepth(tree);
    if(treeDepth == 0)
    {
	cout << tree->element << std::endl;
	return;
    }
    vector<intVec> printSheet;
    int colums = 1;
    for(int i = 0; i < treeDepth; ++i)
	colums *= 2;
    colums = colums / 2 * 6;
    int rows = colums / 2;
    for(int i = 0; i < rows; ++i)
    {
	intVec row(colums, BLANK);
	printSheet.push_back(row);
    }
    creatPrintSheet(tree, printSheet, rows - 1, colums - 1, 0, colums / 2 - 1, ROOT);
    for(int i = 0; i < rows; ++i)
	for(int j = 0; j < colums; ++j)
	{
	    int num;
	    if((num = printSheet[i][j]) == BLANK)
		cout << " ";
	    else if(num == L_SLASH)
		cout << "/";
	    else if(num == R_SLASH)
		cout << "\\";
	    else if(num != NOOUTPUT)
		cout << std::setiosflags(std::ios::left) << num;
	    if(j == colums - 1)
		cout << std::endl;
	}
}




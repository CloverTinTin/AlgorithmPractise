#include <iostream>
using namespace std;

void eightQueens(int queenAmount, int *counter, int rowNum, int solution[])
{
    if(rowNum >= queenAmount)
    {
	++(*counter);
	return;
    }

   for(int column = 0; column < queenAmount; ++column)	   
   {
       int row;
       for(row = 0; row < rowNum; ++row)
	   if(solution[row] == column || (row- rowNum == solution[row] - column) || (row - rowNum == column - solution[row]))
	       break;
       if(row == rowNum)
       {
	   solution[rowNum] = column;
	   eightQueens(queenAmount, counter, rowNum + 1, solution);
       } 
   }
}

int main()
{
    int counter = 0;
    int solution[100];

    eightQueens(8, &counter, 0, solution);
    cout << counter << endl;
    return 0;
}

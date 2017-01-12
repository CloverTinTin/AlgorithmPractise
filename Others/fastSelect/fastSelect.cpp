#include <iostream>
using namespace std;

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int fastSelect(int* const left, int* const right, int k)
{
    int j = 0;
    int result;
    for(int i = 1; i <= right - left; ++i)
	if(*(left + i) < *left)
	{
	    ++j;
	    swap(left + i, left +j); 
	}
    swap(left, left +j);
    ++j;
    if(j < k)
	result = fastSelect(left + j, right, k - j);
    else if(j > k)
	result = fastSelect(left, left + j - 2, k);
    else
	result = *(left + j - 1);
    return result;
}

int main()
{
    int array[] = {2, 1};
    cout << fastSelect(begin(array), end(array) - 1, 1) << endl;
}

#include <iostream>
using namespace std;

int maxSubserial(int array[], int (&subScript)[2], size_t size) //O(N)
{
    int max = 0, sum = -1;

    for(int i = 0; i < size; ++i)
    {
	if(sum < 0)
	{
	    subScript[0] = i;
	    sum = array[i];
	}
	else
	    sum += array[i];
	if(max < sum)
	{
	    max = sum;
	    subScript[1] = i;
	}
    }
    return max;
}

int maxSub_divideAndConquer(int array[], int begin, int end) //O(NlogN)
{
    if(begin == end)
	return array[begin];
    int middle = (begin + end) / 2;
    int leftMax = maxSub_divideAndConquer(array, begin, middle);
    int rightMax = maxSub_divideAndConquer(array, middle + 1, end);
    int middleMaxL = 0;
    for(int i = 1, temp = 0; middle - i >= begin; ++i)
    {
	temp += array[middle - i];
	if(temp > middleMaxL)
	    middleMaxL = temp;
    }
    int middleMaxR = 0;
    for(int i = 1, temp = 0; middle + i <= end; ++i)
    {
	temp += array[middle + i];
	if(temp > middleMaxR)
	    middleMaxR = temp;
    }
    int middleMax = middleMaxL + middleMaxR + array[middle];
    int max = leftMax > rightMax? leftMax: rightMax;
    max = max > middleMax? max: middleMax;
    return max;
}

int maxSub_divideAndConquer(const int *begin, const int *end)
{
    if(begin == end)
	return *begin;
    const int *middle = begin + (end - begin) / 2;
    int leftMax = maxSub_divideAndConquer(begin, middle);
    int rightMax = maxSub_divideAndConquer(middle + 1, end);
    int middleMaxL = *middle;
    for(int i = 1, temp = 0; middle - i >= begin && (temp = (middleMaxL + *(middle - i))) > middleMaxL; ++i)
	middleMaxL = temp;
    int middleMaxR = *(middle + 1);
    for(int i = 2, temp = 0; middle + i <= end && (temp = (middleMaxR + *(middle + i))) > middleMaxR; ++i)
	middleMaxR = temp;
    int middleMax = middleMaxL + middleMaxR;
    int max = leftMax > rightMax? leftMax: rightMax;
    max = max > middleMax? max: middleMax;
    return max;
}

int main()
{
    int array[] = {-2, 11, -4, 13, -5, -2}, subScript[2] = {0, 0};
    int maxSub = maxSubserial(array, subScript, end(array) - begin(array));
    cout << "In integer serial: ";
    for(auto i = begin(array); i < end(array); ++i)
	cout << *i << " ";
    cout << "\nThe max Subserial is:\n";
    for(int i = subScript[0]; i <= subScript[1]; ++i)
	cout << array[i] << " ";
    cout << "\nTheir sum is: " << maxSub << endl;

    cout << maxSub_divideAndConquer(array, 0, end(array) - begin(array) - 1) << endl;
    cout << maxSub_divideAndConquer(begin(array), end(array) - 1) << endl;
    return 0;
}













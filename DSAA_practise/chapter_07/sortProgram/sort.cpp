#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using std::vector;

void insertSort(vector<int> &nums)
{
    int size = nums.size();

    for(int i = 1; i < size; ++i)
    {
	int temp = nums[i], j;
	for(j = i - 1; j >= 0 && nums[j] > temp; --j)
	    nums[j + 1] = nums[j];
	nums[j + 1] = temp;
    }
}

void shellSort(vector<int> &nums)
{
    int size = nums.size();

    for(int step = size / 2; step >= 1; step /= 2)
	for(int i = step; i < size; i += step)
	{
	    int temp = nums[i], j;
	    for(j = i - step; j >= 0 && nums[j] > temp; j -= step)
		nums[j + step] = nums[j];
	    nums[j + step] = temp;
	}
}

void heapSort(vector<int> &nums)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    for(int i: nums)
	heap.push(i);
    for(int &i: nums)
    {
	i = heap.top();
	heap.pop();
    }
}

void merge(vector<int> &nums, vector<int> &temp, int begin, int mid, int end)
{
    int aptr = begin, bptr = mid + 1, cptr = begin;

    while(aptr <= mid && bptr <= end)
	if(nums[aptr] < nums[bptr])
	    temp[cptr++] = nums[aptr++];
	else
	    temp[cptr++] = nums[bptr++];
    while(aptr <= mid)
	temp[cptr++] = nums[aptr++];
    while(bptr <= end)
	temp[cptr++] = nums[bptr++];
    while(begin <= end)
    {
	nums[begin] = temp[begin];
	++begin;
    }
}

void mSort(vector<int> &nums, vector<int> &temp, int begin, int end)
{
    if(begin < end)
    {
	int mid = (begin + end) >> 1;
	mSort(nums, temp, begin, mid);
	mSort(nums, temp, mid + 1, end);
	merge(nums, temp, begin, mid, end);
    }
}

void mergeSort(vector<int> &nums)
{
    vector<int> temp(nums.size());
    mSort(nums, temp, 0, nums.size() - 1);
}

void quickSort(vector<int> &nums, int left, int right)
{
    if(left >= right)
	return;
    if(left + 1 == right)
    {
	if(nums[left] > nums[right])
	    std::swap(nums[left], nums[right]);
	return;
    }
    int mid = (left + right) / 2;
    //vector<int> pivotVec = {left, mid, right};
    int pivotVec[3] = {left, mid, right};
    for(int i = 1; i < 3; ++i)
    {
	int temp = pivotVec[i], j;
	for(j = i - 1; j >= 0 && nums[pivotVec[j]] > nums[temp]; --j)
	    pivotVec[j + 1] = pivotVec[j];
	pivotVec[j + 1] = temp;
    }
    mid = pivotVec[1];
    std::swap(nums[mid], nums[right]);
    int i = left, j = right - 1;
    while(i < j)
    {
	while(nums[i] < nums[right])
	    ++i;
	while(nums[j] > nums[right])
	    --j;
	if(i < j)
	{
	    std::swap(nums[i], nums[j]);
	    ++i; --j;
	}
    }
    std::swap(nums[i], nums[right]);
    quickSort(nums, left, i - 1);
    quickSort(nums, i + 1, right);
}

void quickSort(vector<int> &nums)
{
    quickSort(nums, 0, nums.size() - 1);
}

int main(int argc, char **argv)
{
    vector<int> nums;
    for(int i = 1; i < argc; ++i)
	nums.push_back(std::stoi(argv[i]));
    //insertSort(nums);
    //shellSort(nums);
    //heapSort(nums);
    //mergeSort(nums);
    quickSort(nums);
    for(int i: nums)
	std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}

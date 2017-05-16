#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using iter = std::vector<int>::iterator;

void swap(iter i, iter j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void swap(std::vector<int> &vec, int i, int j)
{
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

void printVec(const std::vector<int> &vec)
{
    for(auto i: vec)
	std::cout << i << " ";
    std::cout << std::endl;
}

void permutation(std::vector<int> &vec, iter i, iter j)
{
    if(i == j)
	printVec(vec);
    else
	for(iter k = i; k < j; ++k)
	{
	    swap(i, k);
	    permutation(vec, i + 1, j);
	    swap(i, k);
	}
}

void permutation(std::vector<int> &vec, int i, int j)
{
    if(i == j)
	printVec(vec);
    for(int k = i; k < j; ++k)
    {
	swap(vec, i, k);
	permutation(vec, i + 1, j);
	swap(vec, i, k);
    }
}

int main(int argc, char **argv)
{
    std::vector<int> vec;
    for(int i = 1; i < argc; ++i)
	vec.push_back(std::stoi(argv[i]));
    permutation(vec, vec.begin(), vec.end());
    return 0;
}

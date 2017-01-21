#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <list>
using namespace std;

void radixSort(vector<int> &vec, int maxOrder)
{
    list<int> buckets[2][10];
    for(auto i: vec)
	buckets[0][i % 10].push_back(i);
    int src = 1, dst = 0;
    for(int i = 1; i < maxOrder; ++i)
    {
	int temp = src;
	src = dst;
	dst = temp;
	int pow = 1;
	for(int k = 0; k <= i; ++k)
	    pow *= 10;
	for(int j = 0; j < 10; ++j)
	    for(auto itr = buckets[src][j].begin(); itr != buckets[src][j].end();)
	    {
		buckets[dst][*itr % pow / (pow / 10)].push_back(*itr);
		itr = buckets[src][j].erase(itr);
	    }
    }
    vector<int>::iterator vecIter = vec.begin();
    for(int j = 0; j < 10; ++j)
	for(auto value: buckets[dst][j])
	{
	    *vecIter = value;
	    ++vecIter;
	}
}

int main(int argc, char **argv)
{
    vector<int> vec;
    for(int i = 1; i < argc; ++i)
	vec.push_back(stoi(argv[i]));
    radixSort(vec, 3);
    for(auto i: vec)
	cout << i << " "; 
    cout << endl;
    return 0;
}




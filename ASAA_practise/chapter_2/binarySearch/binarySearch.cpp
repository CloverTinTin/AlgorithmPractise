#include <iostream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;

int binarySearch(vector<int> vec, int num)
{
    vector<int>::iterator left = vec.begin(), right = vec.end() - 1;
    while(left <= right)
    {
	auto mid = left + (right - left) / 2;
	if(*mid == num)
	    return mid - vec.begin();
	else if(*mid < num)
	    left = mid + 1;
	else
	    right = mid - 1;
    }
    return -1;
}

int main(int argc, char **argv)
{
    vector<int> vec;
    for(int i = 1; i < argc - 1; ++i)
	vec.push_back(stoi(argv[i]));
    int num = stoi(argv[argc - 1]);
    for(int i = 0; i < vec.size(); ++i)
	cout << vec[i] << " ";
    cout << "\n" << num << endl;
    int pos = binarySearch(vec, num);
    if(pos >= 0)
	cout << "Find " << num << " in position " << pos << endl;
    else
	cout << "Not in" << endl;
    return 0;
}

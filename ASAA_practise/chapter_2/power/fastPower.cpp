#include <iostream>
#include <string>
using namespace std;

int fastPower(int x, int N)
{
    if(N == 0)
	return 1;
    if(N % 2 == 0)
	return fastPower(x * x, N / 2);
    else
	return fastPower(x * x, N / 2) * x;
}

int main(int argc, char **argv)
{
    int x = stoi(argv[1]), N = stoi(argv[2]); 
    cout << fastPower(x, N) << endl;
    return 0;
}

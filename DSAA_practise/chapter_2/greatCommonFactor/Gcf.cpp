#include <iostream>
#include <string>
using namespace std;

int Gcf(int M, int N)
{
    while(N > 0)
    {
	int temp = M % N;
	M = N;
	N = temp;
    }
    return M;
}

int main(int argc, char **argv)
{
    int M = stoi(argv[1]), N = stoi(argv[2]);
    cout << "Greatest common factor is " << Gcf(M, N) << endl;
    return 0;
}

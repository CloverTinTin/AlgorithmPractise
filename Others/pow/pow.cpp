#include <iostream>

double pow(double x, int n)
{
    if(n == 0)
	return 1.0;
    if(n == 1)
	return x;
    if(n < 0)
	return 1 / pow(x, -n);
    if(n & 1 == 0)
	return pow(x * x, n >> 1);
    else
	return pow(x * x, n >> 1) * x;
}

int main()
{
    std::cout << pow(1, 2147483648) << std::endl;//2147483648==0x80000000, 会使程序陷入死循环
    //int i = 0x80000000;
    //int j = 2147483648;
    //std::cout << -i << " " << j << std::endl;
    return 0;
}

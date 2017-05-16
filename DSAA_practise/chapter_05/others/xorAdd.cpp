#include <iostream>
#include <string>

int xorAdd(int a, int b)
{
    if(b == 0)
	return a;
    int xorval = a ^ b;
    int carry = (a & b) << 1;
    xorAdd(xorval, carry);
}

int main(int argc, char **argv)
{
    int a = std::stoi(argv[1]);
    int b = std::stoi(argv[2]);
    std::cout << xorAdd(a, b) << std::endl;
    return 0;
}

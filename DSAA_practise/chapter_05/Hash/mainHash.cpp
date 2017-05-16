#include <iostream>
#include "hash.h"

int main()
{
    Hash hashTable;
    hashTable.insert("abc").insert("efg");
    Hash::position p = hashTable.find("efg");
    if(p != hashTable.notfind)
	std::cout << *p << std::endl;
    else
	std::cout << "can't find" << std::endl;
    return 0;
}

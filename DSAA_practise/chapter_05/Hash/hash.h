#ifndef HASH_H
#define HASH_H

#include <list>
#include <string>
#include <vector>
using std::list;
using std::string;
using std::vector;

class Hash
{
public:
    using position = list<string>::iterator;
    using size_type = vector<list<string> *>::size_type;

    Hash() = default;
    Hash(size_type s): size(s), table(s, nullptr){ };
    position find(const string &key) const;
    Hash &insert(const string &key);
    Hash &deleteElement(const string &key);
    list<string> noFindLabel;
    position notfind = noFindLabel.begin();

private:
    size_type size = 10007;
    vector<list<string> *> table = vector<list<string> *>(10007, nullptr);
    size_type hashFunction(const string &key) const;
};

Hash::position Hash::find(const string &key) const
{
    size_type hashVal = hashFunction(key);
    list<string> *listPtr = table[hashVal];
    if(listPtr != nullptr)
	for(position p = listPtr->begin(); p != listPtr->end(); ++p)
	    if(*p == key)
		return p;
    return notfind;
}

Hash &Hash::insert(const string &key)
{
    if(find(key) == notfind)
    {
	size_type hashVal = hashFunction(key);
	if(table[hashVal] == nullptr)
	    table[hashVal] = new list<string>;
	table[hashVal]->insert(table[hashVal]->begin(), key);
    }
    return *this;
}

Hash::size_type Hash::hashFunction(const string &key) const
{
    Hash::size_type amount = 0;
    for(char c: key)
    {
	Hash::size_type temp = static_cast<Hash::size_type>(c);
	amount = (amount + c) << 5;
    }
    return amount % size;
}



#endif

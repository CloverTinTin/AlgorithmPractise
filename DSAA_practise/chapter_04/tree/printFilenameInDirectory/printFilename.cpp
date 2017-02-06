#include <iostream>
#include <string>
#include <dirent.h> /*struct dirent; opendir; readdir*/ 
#include <unistd.h> /*getcwd*/ 
using namespace std;

void listDir(const string addr, const int depth)
{
    DIR *dir;
    struct dirent *dptr;

    dir = opendir(&addr[0]);
    while((dptr = readdir(dir)) != nullptr)
    {
	string name = dptr->d_name;
	if(name == "." || name == "..")
	    continue;
	else
	{
	    for(int i = 0; i < depth; ++i)
		cout << "\t";
	    cout << name << endl;
	    if(dptr->d_type == 4)
		listDir(addr + "/" + name, depth + 1);
	}
    }
    closedir(dir);
}

int main()
{
    char addr[500];

    getcwd(addr, end(addr) - begin(addr));
    cout << addr << endl;
    listDir(addr, 0);
    return 0;
}

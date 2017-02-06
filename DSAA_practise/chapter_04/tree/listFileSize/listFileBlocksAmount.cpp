#include <iostream>
#include <string>
#include <dirent.h> /*struct dirent; opendir; readdir*/ 
#include <unistd.h> /*getcwd*/ 
#include <sys/stat.h>
using namespace std;

void listDir(const string addr, const int depth)
{
    DIR *dir;
    struct dirent *dptr;
    struct stat statbuff;

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
	    string filePath = addr + "/" + name;
	    stat(&filePath[0], &statbuff);
	    cout << name << " " << statbuff.st_size << " " << statbuff.st_blksize << " " << statbuff.st_blocks << endl;
	    if(dptr->d_type == 4)
		listDir(filePath, depth + 1);
	}
    }
    closedir(dir);
}

int fileBlocks(const string addr)
{
    struct stat statbuff;
    stat(&addr[0], &statbuff);
    int blocks = statbuff.st_blocks;
    DIR *dir = opendir(&addr[0]);
    struct dirent *direntPtr;

    while((direntPtr = readdir(dir)) != NULL)
    {
	string filename = direntPtr->d_name;
	string filepath = addr + "/" + filename;
	if(filename == "." || filename == "..")
	    continue;
	else if(direntPtr->d_type == 4)
	    blocks += fileBlocks(filepath);
	else
	{
	    stat(&filepath[0], &statbuff);
	    blocks += statbuff.st_blocks;
	}
    }
    return blocks;
}

int main()
{
    char addr[500];

    getcwd(addr, end(addr) - begin(addr));
    cout << addr << " " << fileBlocks(addr) << endl;
    listDir(addr, 0);
    return 0;
}




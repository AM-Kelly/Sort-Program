//File operation
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main()
{
	ofstream thefile;
	thefile.open("example.txt");//INPUT THE FILE DIR
	thefile << "Writing to file test.\n";
	thefile.close();
	_getch();
	return 0;
}
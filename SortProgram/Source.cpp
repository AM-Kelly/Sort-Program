//File operation
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string>
using namespace std;

void readin();
void writeout();

void readin()
{

	int* a = NULL;   // Pointer to int, initialize to nothing.
	int n;           // Size needed for array
	cin >> n;        // Read in the size
	a = new int[n];  // Allocate n ints and save ptr in a.
	for (int i = 0; i<n; i++) {
		a[i] = 0;    // Initialize all elements to zero.
	}







	string line;
	ifstream thefile("numbers.txt");
	if (thefile.is_open())
	{
		while (getline(thefile, line))
		{
			cout << line << '\n';
		}
		thefile.close();
	}
	_getch();
}
void writeout()
{
	ofstream thefile;
	thefile.open("example.txt");//INPUT THE FILE DIR
	thefile << "Writing to file test.\n";
	thefile.close();
	_getch();
}
int main()
{
	int userchoice;
	cout << "Would you like to 1.) read in, or 2.) print out?\n";
	cin >> userchoice;
	switch (userchoice)
	{
	case 1 :
		readin();
		break;
	case 2 :
		writeout();
	default:
		break;
	}
	return 0;
}
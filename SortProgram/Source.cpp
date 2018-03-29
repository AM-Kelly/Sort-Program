//File operation
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <iterator>
using namespace std;

void readin();
void writeout();

void readin()
{
	//*******************Dynamic Array************************
	int* a = NULL;   // Pointer to int, initialize to nothing.
	int n;           // Size needed for array

	//cin >> n;        // Read in the size			//get number of lines

	//*******************Text File Declaration************************
	ifstream thefile("numbers.txt");
	thefile.unsetf(ios_base::skipws);
	unsigned line_count = count(istream_iterator<char>(thefile), istream_iterator<char>(), '\n');//Counts the number of lines in the file
	n = line_count;//sets the number of placeholders required
	//*******************Text File Declaration************************

	a = new int[n];  // Allocate n ints and save ptr in a.
	for (int i = 0; i<n; i++) {
		a[i] = 0;    // Initialize all elements to zero.
	}
	//*******************Dynamic Array************************

	string line;
	int i = 0;
	
	cout << "# of lines: " << line_count << '\n';
	if (thefile.is_open())
	{
		while (getline(thefile, line))
		{
			//a[i] = stoi(line);
			//cout << a[i] << '\n';
			//i++;
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
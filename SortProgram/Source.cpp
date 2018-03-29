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
	ifstream thefile1("numbers.txt");//Textfile declaration
	thefile1.unsetf(std::ios_base::skipws);//Skip new lines
	// count the newlines with an algorithm specialized for counting:
	unsigned line_count = std::count(
		std::istream_iterator<char>(thefile1),
		std::istream_iterator<char>(),
		'\n');
	cout << line_count << '\n';//Print out the number of lines starting from 0

	int* a = NULL;   // Pointer to int, initialize to nothing.
	int n;           // Size needed for array
	n = line_count;        // allocate the size of the array
	a = new int[n];  // Allocate n ints and save ptr in a.
	for (int i = 0; i<n; i++) {
		a[i] = 0;    // Initialize all elements to zero.
	}



	string line;//declare line 
	ifstream thefile("numbers.txt");//Declare the txt file to read in from
	if (thefile.is_open())//If the file is open do
	{
		int i = 0;//Counter set to zero
		while (getline(thefile, line))
		{
			a[i] = atoi(line.c_str());//put the conversion of line into --> a[i]
			cout << line << '\n';//Print out the line as a check
			i++;//increment the counter
		}
		thefile.close();//Close the file
	}
	_getch();//wait
	//TODO: For making this into a full read in function, it should return the array so the sort can process the data
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
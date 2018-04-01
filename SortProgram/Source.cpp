#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <iterator>
#include <vector>
using namespace std;

void writeoutfile();
//BubbleSort
class bubbleSort
{
public:
	void bubbleSortDriver(std::vector<int> arr3);

private:
	void swap(int *xp, int *yp);//This swaps ints around for the sort
	void sort(int arr[], int n);//This sorts the ints
	void printArray(int arr[], int size);//This prints the sorted array out
};

void bubbleSort::bubbleSortDriver(std::vector<int> arr3)//Driver
{
	//int arr[] = { 64, 34, 25, 12, 22, 11, 90 };//This needs to be changed to the array that has been loaded from the textfile
	
	//*****************SOMETHING WRONG IN HERE********************
	int* arr4 = NULL;   // Pointer to int, initialize to nothing.
	int z;           // Size needed for array
	z = arr3.size();        // allocate the size of the array
	arr4 = new int[z];  // Allocate n ints and save ptr in a.
	for (int i = 0; i<z; i++) {
		arr4[i] = 0;    // Initialize all elements to zero.
	}
	int i = 0;//Counter set to zero
	while (i < z)
	{
		arr4[i] = arr3[i];
		i++;//increment the counter
	}
	//*****************SOMETHING WRONG IN HERE********************
	//std:vector<int> arr4 = arr3;
	int n = sizeof(arr4) / sizeof(arr4[0]);
	sort(arr4, n);
	printf("Sorted array: \n");
	printArray(arr4, n);
	_getch();
}
void bubbleSort::swap(int *xp, int *yp)//Swaps ints around for the sort
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort::sort(int arr[], int n)// An optimized version of Bubble Sort
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break
		if (swapped == false)
			break;
	}
}

void bubbleSort::printArray(int arr[], int size)// Function to print an array
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

class textFileRead//Change the void --> Ints. Passing values back up through.
{
public:
	std::vector<int> textFileReadDriver();//Driver function declaration

private:
	std::vector<int> readIn();//Read in from file function declaration
};

std::vector<int> textFileRead::textFileReadDriver()//Driver function //To be called
{
	std::vector<int> arr1 =	readIn();//Start the readIn function (private)
	return arr1;
}

std::vector<int> textFileRead::readIn()
{
	ifstream thefile1("numbers.txt");//Textfile declaration
	thefile1.unsetf(std::ios_base::skipws);//Skip new lines
	// count the newlines with an algorithm specialized for counting:
	unsigned line_count = std::count(
		std::istream_iterator<char>(thefile1),
		std::istream_iterator<char>(),
		'\n');
	cout << line_count << '\n';//Print out the number of lines starting from 0


	std::vector<int> arr(line_count + 1);//+1 To get to the right number

	string line;//declare line 
	ifstream thefile("numbers.txt");//Declare the txt file to read in from
	if (thefile.is_open())//If the file is open do
	{
		int i = 0;//Counter set to zero
		while (getline(thefile, line))
		{
			//a[i] = atoi(line.c_str());//put the conversion of line into --> a[i]
			arr[i] = atoi(line.c_str());//put the conversion of line into --> a[i]
			cout << line << '\n';//Print out the line as a check
			cout << arr[i] << '\n';//Print out the vector as a check
			i++;//increment the counter
		}
		thefile.close();//Close the file
	}
	return arr;
}//read in from file function

void writeoutfile()
{
	ofstream thefile;
	thefile.open("example.txt");//INPUT THE FILE DIR
	thefile << "Writing to file test.\n";
	thefile.close();
	_getch();
}

int main()
{
	std::vector<int> arr2;
	int userchoice;
	cout << "How would you like to sort these numbers?\n1.) Bubble.\n2.) Selection.\n3.) Insertion\n4.) Hash\n5.) Binary\n";
	cin >> userchoice;
	switch (userchoice)
	{
	case 1 ://Bubble
		textFileRead read;//test
		arr2 = read.textFileReadDriver();//test
		_getch();
		bubbleSort sort;
		sort.bubbleSortDriver(arr2);
		_getch();
		break;
	case 2 ://Selection 

		break;
	case 3://Insertion
		
		break;
	case 4://Hash
		
		break;
	case 5://Binary
		
		break;
	default://Error Catch Here!
		break;
	}
	return 0;
}
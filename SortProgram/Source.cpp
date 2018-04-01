#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <iterator>
#include <vector>
#include <math.h>
using namespace std;

void writeoutfile();
//Print 
class print
{
public:
	void printDriver(std::vector<int>);

private:
	void printArray(std::vector<int>, int);//This prints the sorted array out
};

void print::printDriver(std::vector<int> sortedArr)
{
	int x = sortedArr.size();
	printf("Sorted array: \n");
	printArray(sortedArr, x);//Print the sorted vector array
}

void print::printArray(std::vector<int> sortedArr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", sortedArr[i]);
}
//Print End

class quickSort
{
public:
	std::vector<int> quickSortDriver(std::vector<int>);
	

private:
	void swap(int* a, int* b);
	int partition(std::vector<int>, int, int);
	std::vector<int> sort(std::vector<int>, int, int);
};

std::vector<int> quickSort::quickSortDriver(std::vector<int> arr)
{
	std::vector<int> sortedArr;
	int x = arr.size();
	sortedArr = sort(arr, x);
	return sortedArr;
}
void quickSort::swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int quickSort::partition(std::vector<int> arr, int low, int high)
{
	int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
std::vector<int> quickSort::sort(std::vector<int> arr, int low, int high)
{
	if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
	return arr;
}

//Insertion
class insertionSort
{
public:
	std::vector<int> insertionSortDriver(std::vector<int>);

private:
	std::vector<int> sort(std::vector<int>, int);
};

std::vector<int> insertionSort::insertionSortDriver(std::vector<int> arr)
{
	std::vector<int> sortedArr;
	int x = arr.size();
	sortedArr = sort(arr, x);
	return sortedArr;
}

std::vector<int> insertionSort::sort(std::vector<int> arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	return arr;
}
//Insertion End

//Selection 
class selectionSort
{
public:
	std::vector<int> selectionSortDriver(std::vector<int>);
private:
	std::vector<int> sort(std::vector<int>, int);
	void swap(int *xp, int *yp);
};

std::vector<int> selectionSort::selectionSortDriver(std::vector<int> arr)
{
	std::vector<int> sortedArr;
	int x = arr.size();
	sortedArr = sort(arr, x);
	return sortedArr;
}
void selectionSort::swap(int *xp, int *yp)//Swaps ints around for the sort
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
std::vector<int> selectionSort::sort(std::vector<int> arr, int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
	return arr;
}
//Selection End

//BubbleSort
class bubbleSort
{
public:
	std::vector<int> bubbleSortDriver(std::vector<int>);

private:
	void swap(int *xp, int *yp);//This swaps ints around for the sort
	std::vector<int> sort(std::vector<int>, int);//This sorts the ints
};

std::vector<int> bubbleSort::bubbleSortDriver(std::vector<int> arr)//Driver
{
std:vector<int> sortedArr;//Declare a new vector array for holding the sorted data
	int x = arr.size();//get the size of the passed vector array
	sortedArr = sort(arr, x);//Sort using the passed vector array
	return sortedArr;
	_getch();
}

void bubbleSort::swap(int *xp, int *yp)//Swaps ints around for the sort
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

std::vector<int> bubbleSort::sort(std::vector<int> arr, int n)// An optimized version of Bubble Sort
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
	return arr;
}
//BubbleSort End

//TextFileRead
class textFileRead//Change the void --> Ints. Passing values back up through.
{
public:
	std::vector<int> textFileReadDriver();//Driver function declaration

private:
	std::vector<int> readIn();//Read in from file function declaration
};

std::vector<int> textFileRead::textFileReadDriver()//Driver function //To be called
{
	std::vector<int> arr =	readIn();//Start the readIn function (private)
	return arr;//second vector array being returned (from the textfile --> main)
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
	cout << "There are " << line_count + 1 << " numbers to sort.\n";//Print out the number of lines starting from 0


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
			//cout << line << '\n';//Print out the line as a check
			//cout << arr[i] << '\n';//Print out the vector as a check
			i++;//increment the counter
		}
		thefile.close();//Close the file
	}
	//Put in a output saying the file has been read 
	return arr;//First vector array being returned (from the textfile)
}//read in from file function
//TextFileReadEnd

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
	std::vector<int> arr;//Unsorted
	std::vector<int> sortedArr;

	textFileRead read;//Could put an if statement around this to stop loading arr all the time?
	arr = read.textFileReadDriver();//Get the unsorted values from the textfile & assign them to the vector array

	int userchoice;
	cout << "How would you like to sort these numbers?\n1.) Bubble.\n2.) Selection.\n3.) Insertion\n4.) Hash\n5.) Binary\n";
	cin >> userchoice;
	switch (userchoice)
	{
	case 1 ://Bubble
		bubbleSort bSort;
		sortedArr = bSort.bubbleSortDriver(arr);//Start the bubble sort passing unsorted vector array
		print bPrint;
		bPrint.printDriver(sortedArr);//Start the print class passing the sorted vector array
		_getch();
		break;
	case 2 ://Selection 
		selectionSort sSort;
		sortedArr = sSort.selectionSortDriver(arr);
		print sPrint;
		sPrint.printDriver(sortedArr);
		_getch();
		break;
	case 3://Insertion
		insertionSort iSort;
		sortedArr = iSort.insertionSortDriver(arr);//Start the insertion sort passing unsorted vector array
		print iPrint;
		iPrint.printDriver(sortedArr);//Start the print class passing the sorted vector array
		_getch();
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
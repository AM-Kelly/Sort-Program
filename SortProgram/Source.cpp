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
	void printDriver(vector<int>);//Print driver declaration for controlling the class (also gives public access)

private:
	void printArray(vector<int>, int);//This prints the sorted array out
};
void print::printDriver(vector<int> sortedArr)//This function will control this class
{
	int x = sortedArr.size();
	printf("Sorted array: \n");
	printArray(sortedArr, x);//Print the sorted vector array
}
void print::printArray(vector<int> sortedArr, int size)
{
	int i;
	for (i = 0; i < size; i++)//Increments through the sorted array, to print each placeholder
		printf("%d ", sortedArr[i]);//Prints the sorted array to the screen
}
//Print End

//Heap Sort
class heapSort//This class will sort numbers through a heap sort method
{
public:
	vector<int> heapSortDriver(vector<int>);//public accessed driver function
	

private:
	vector<int> heapify(vector<int>, int,int);//Heap function
	vector<int> sort(vector<int>, int);//Sort function
};
vector<int> heapSort::heapSortDriver(vector<int> arr)
{
	vector<int> sortedArr;
	int x = arr.size();//getting the size of the passed vector
	sortedArr = sort(arr, x);//sorting the vector and assigning it to sortedArr
	return sortedArr;//Returning the sorted vector to the main function
}
vector<int> heapSort::heapify(vector<int> arr, int n, int i)
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1 - used to divide left 
	int r = 2 * i + 2;  // right = 2*i + 2 - used to divide right

						// If left side is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right side is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not equal to root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		arr = heapify(arr, n, largest);
	}
	return arr;
}
vector<int> heapSort::sort(vector<int> arr, int n)
{
	// Build the heap ( and rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		arr = heapify(arr, n, i);

	// Incrementally - One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to the end
		swap(arr[0], arr[i]);

		// call the max heapify on the reduced heap
		arr = heapify(arr, i, 0); 
	}
	return arr;
}
//Heap Sort End

//Comb Sort
class combSort
{
public:
	vector<int> combSortDriver(vector<int>);//publically accessible sort driver function
	

private:
	int getNextGap(int);
	vector<int> sort(vector<int>, int);
};
vector<int> combSort::combSortDriver(vector<int> arr)
{
	vector<int> sortedArr;
	int x = arr.size();//Getting the size of the vector
	sortedArr = sort(arr, x);//Starting the sort, passing the unsorted vector
	return sortedArr;//Returning the sorted vector back to the main function
}
int combSort::getNextGap(int gap)
{
	// shrink gap by the defined shrink factor
	gap = (gap * 10) / 13;

	if (gap < 1)
		return 1;
	return gap;
}
vector<int> combSort::sort(vector<int> arr, int n)
{
	// Initialize gap
	int gap = n;

	// Initialize the swapped as true to ensure the loop runs
	bool swapped = true;

	// Keep running while the gap is more greater than 1 and the last iteration caused a swap
	while (gap != 1 || swapped == true)
	{
		// Find next the gap
		gap = getNextGap(gap);

		// Initialize swapped as false so that the record of swap can be checked
		swapped = false;

		// Compare all elements in the array with current gap
		for (int i = 0; i<n - gap; i++)
		{
			if (arr[i] > arr[i + gap])
			{
				swap(arr[i], arr[i + gap]);
				swapped = true;
			}
		}
	}
	return arr;
}
//Comb Sort End
/*//Quick Sort
class quickSort
{
public:
	vector<int> quickSortDriver(vector<int>);
	

private:
	void swap(int* a, int* b);
	int partition(vector<int>, int, int);
	vector<int> sort(vector<int>, int, int);
};
vector<int> quickSort::quickSortDriver(vector<int> arr)
{
	vector<int> sortedArr;
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
int quickSort::partition(vector<int> arr, int low, int high)
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
vector<int> quickSort::sort(vector<int> arr, int low, int high)
{
	if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           //at right place
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
	return arr;
}
*/
//Insertion
class insertionSort
{
public:
	vector<int> insertionSortDriver(vector<int>);//Publically accessible driver function

private:
	vector<int> sort(vector<int>, int);
};
vector<int> insertionSort::insertionSortDriver(vector<int> arr)
{
	vector<int> sortedArr;
	int x = arr.size();//get the size of the vector
	sortedArr = sort(arr, x);//Starts the sort program, assigning the returned variable to sortedArr
	return sortedArr;//Returning the sorted vector to the main function
}
vector<int> insertionSort::sort(vector<int> arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		//Move numbers that are greater than the key +1 in the vector
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
	vector<int> selectionSortDriver(vector<int>);//Publically accessible function for initialising the selection sort
private:
	vector<int> sort(vector<int>, int);
	void swap(int *xp, int *yp);
};
vector<int> selectionSort::selectionSortDriver(vector<int> arr)
{
	vector<int> sortedArr;
	int x = arr.size();//Getting the size of the vector
	sortedArr = sort(arr, x);//Sorting the vector and assigning it back to sortedArr
	return sortedArr;//Returning to main function
}
void selectionSort::swap(int *xp, int *yp)//Swaps ints around for the sort
{
	//This will swap two numbers around
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
vector<int> selectionSort::sort(vector<int> arr, int n)
{
	int i, j, min_idx;

	// Incrementally move the boundary of the unsorted subarray to keep track of what has been sorted
	for (i = 0; i < n - 1; i++)
	{
		// Find the smallest element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the smallest found element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
	return arr;
}
//Selection End

//BubbleSort
class bubbleSort
{
public:
	vector<int> bubbleSortDriver(vector<int>);//Publically accesible function for sorting numbers (Bubble)

private:
	void swap(int *xp, int *yp);//This swaps ints around for the sort
	vector<int> sort(vector<int>, int);//This sorts the ints
};
vector<int> bubbleSort::bubbleSortDriver(vector<int> arr)//Driver
{
std:vector<int> sortedArr;//Declare a new vector array for holding the sorted data
	int x = arr.size();//get the size of the passed vector array
	sortedArr = sort(arr, x);//Sort using the passed vector array and return back to sortedArr
	return sortedArr;//Return the sortedArr to the main function
}
void bubbleSort::swap(int *xp, int *yp)//Swaps ints around for the sort
{
	//this will swap two numbers around
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
vector<int> bubbleSort::sort(vector<int> arr, int n)// An optimized version of Bubble Sort
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		//Start with swapped set to false
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			//Determine whether it should be swapped
			if (arr[j] > arr[j + 1])
			{
				//Swap
				swap(&arr[j], &arr[j + 1]);
				//Change swapped to true
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
	vector<int> textFileReadDriver();//Driver function declaration

private:
	vector<int> readIn();//Read in from file function declaration
};
vector<int> textFileRead::textFileReadDriver()//Driver function //To be called
{
	vector<int> arr =	readIn();//Start the readIn function (private)
	return arr;//second vector array being returned (from the textfile --> main)
}
vector<int> textFileRead::readIn()
{
	ifstream thefile1("numbers.txt");//Textfile declaration
	thefile1.unsetf(std::ios_base::skipws);//Skip new lines
	// count the newlines with an algorithm specialized for counting:
	unsigned line_count = std::count(
		std::istream_iterator<char>(thefile1),
		std::istream_iterator<char>(),
		'\n');
	cout << "There are " << line_count + 1 << " numbers to sort.\n";//Print out the number of lines starting from 0


	vector<int> arr(line_count + 1);//+1 To get to the right number

	string line;//declare line 
	ifstream thefile("numbers.txt");//Declare the txt file to read in from
	if (thefile.is_open())//If the file is open do
	{
		int i = 0;//Counter set to zero
		while (getline(thefile, line))
		{
			arr[i] = atoi(line.c_str());//put the conversion of line into --> a[i]
			//CHECKS 
			//cout << line << '\n';//Print out the line as a check
			//cout << arr[i] << '\n';//Print out the vector as a check
			//CHECKS
			i++;//increment the counter
		}
		thefile.close();//Close the file
	}
	//Put in a output saying the file has been read 
	return arr;//First vector array being returned (from the textfile)
}//read in from file function
//TextFileReadEnd

void writeoutfile()//This could be used to output the vector to a file
{
	ofstream thefile;
	thefile.open("example.txt");//INPUT THE FILE DIR
	thefile << "Writing to file test.\n";
	thefile.close();
	_getch();
}

int main()
{
	vector<int> arr;//Unsorted
	vector<int> sortedArr;//Sorted

	textFileRead read;//Could put an if statement around this to stop loading arr all the time?
	arr = read.textFileReadDriver();//Get the unsorted values from the textfile & assign them to the vector array

	int userchoice = 0;
	cout << "How would you like to sort these numbers?\n1.) Bubble.\n2.) Selection.\n3.) Insertion\n4.) Comb\n5.) Heap\n";
	
	while (!(cin >> userchoice) && userchoice < 1 || userchoice > 5)
	{
		cout << "Invalid selection (Choice must be between 1 - 5)\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	switch (userchoice)
	{
	case 1 ://Bubble
		bubbleSort bSort;
		sortedArr = bSort.bubbleSortDriver(arr);//Start the bubble sort passing unsorted vector array
		print bPrint;
		bPrint.printDriver(sortedArr);//Start the print class passing the sorted vector array
		_getch();
		cout << "\n";//New line
		main();
		break;
	case 2 ://Selection 
		selectionSort sSort;
		sortedArr = sSort.selectionSortDriver(arr);
		print sPrint;
		sPrint.printDriver(sortedArr);
		_getch();
		cout << "\n";//New line
		main();
		break;
	case 3://Insertion
		insertionSort iSort;
		sortedArr = iSort.insertionSortDriver(arr);//Start the insertion sort passing unsorted vector array
		print iPrint;
		iPrint.printDriver(sortedArr);//Start the print class passing the sorted vector array
		_getch();
		cout << "\n";//New line
		main();
		break;
	case 4://Comb Sort
		combSort cSort;
		sortedArr = cSort.combSortDriver(arr);
		print cPrint;
		cPrint.printDriver(sortedArr);
		_getch();
		cout << "\n";//New line
		main();
		break;
	case 5://Heap Sort
		heapSort hSort;
		sortedArr = hSort.heapSortDriver(arr);
		print hPrint;
		hPrint.printDriver(sortedArr);
		_getch();
		cout << "\n";//New line
		main();
		break;
	default://Error Catch Here!
		break;
	}
	return 0;
}
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <iterator>
#include <vector>
#include <math.h>
#include <ctime>
clock_t clockStart;
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
	int x = sortedArr.size();//get array size
	printf("Sorted array: \n");//output
	printArray(sortedArr, x);//Print the sorted vector array
}
void print::printArray(vector<int> sortedArr, int size)
{
	int i;//dec
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
	vector<int> sortedArr;//dec
	int x = arr.size();//getting the size of the passed vector
	sortedArr = sort(arr, x);//sorting the vector and assigning it to sortedArr
	return sortedArr;//Returning the sorted vector to the main function
}
vector<int> heapSort::heapify(vector<int> arr, int n, int i)
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1 - used to divide left 
	int r = 2 * i + 2;  // right = 2*i + 2 - used to divide right

	if (l < n && arr[l] > arr[largest])// If left side is larger than root
		largest = l;//assignment

	if (r < n && arr[r] > arr[largest])// If right side is larger than the largest in process
		largest = r;//assignment

	if (largest != i)// If largest is not equal to root
	{
		swap(arr[i], arr[largest]);//start swap around largest

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
	int getNextGap(int);//Finds next gap 
	vector<int> sort(vector<int>, int);//sort function
};
vector<int> combSort::combSortDriver(vector<int> arr)
{
	vector<int> sortedArr;//dec
	int x = arr.size();//Getting the size of the vector
	sortedArr = sort(arr, x);//Starting the sort, passing the unsorted vector
	return sortedArr;//Returning the sorted vector back to the main function
}
int combSort::getNextGap(int gap)
{
	gap = (gap * 10) / 13; // shrink gap by factor given

	if (gap < 1)
		return 1;
	return gap;
}
vector<int> combSort::sort(vector<int> arr, int n)
{
	int gap = n;//dec and initalisation
	bool swapped = true;// dec and initialise the variable as true to make sure the loop runs

	
	while (gap != 1 || swapped == true)//Keep running while the gap does not equal and 1 and/or swapped equals true
	{
		gap = getNextGap(gap);// location the next gap
		swapped = false;// Set swap to false so that swap can be tracked and checked against

		for (int i = 0; i<n - gap; i++)// Compare all elements in the array with gap
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

//Insertion
class insertionSort
{
public:
	vector<int> insertionSortDriver(vector<int>);//Publically accessible driver function

private:
	vector<int> sort(vector<int>, int);//sort function
};
vector<int> insertionSort::insertionSortDriver(vector<int> arr)
{
	vector<int> sortedArr;//dec
	int x = arr.size();//get the size of the vector
	sortedArr = sort(arr, x);//Starts the sort program, assigning the returned variable to sortedArr
	return sortedArr;//Returning the sorted vector to the main function
}
vector<int> insertionSort::sort(vector<int> arr, int n)
{
	int i, key, j;//dec
	for (i = 1; i < n; i++)//
	{
		key = arr[i];//assign arr to key
		j = i - 1;//decrement n assign to j

		while (j >= 0 && arr[j] > key)//swap around the numbers that are bigger than the key by 1 (in the vector)
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
	vector<int> sort(vector<int>, int);//sort function
	void swap(int *xp, int *yp);//swap function
};
vector<int> selectionSort::selectionSortDriver(vector<int> arr)
{
	vector<int> sortedArr;//dec
	int x = arr.size();//Getting the size of the vector
	sortedArr = sort(arr, x);//Sorting the vector and assigning it back to sortedArr
	return sortedArr;//Returning to main function
}
void selectionSort::swap(int *iz, int *jz)//Swaps ints around for the sort
{
	//This will swap two numbers around
	int temp = *iz;
	*iz = *jz;
	*jz = temp;
}
vector<int> selectionSort::sort(vector<int> arr, int n)
{
	int i, j, min_idx;//dec

	for (i = 0; i < n - 1; i++)// increment the boundary of the unsorted vector so tracking can be performed
	{
		min_idx = i;// Find the smallest number in unsorted vector
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		swap(&arr[min_idx], &arr[i]);// Swap the smallest found number with the first element
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
void bubbleSort::swap(int *iz, int *jz)//Swaps ints around for the sort
{
	int temp = *iz;	//this will swap two numbers around
	*iz = *jz;
	*jz = temp;
}
vector<int> bubbleSort::sort(vector<int> arr, int n)// An optimized version of Bubble Sort
{
	int i, j;//dec
	bool swapped;//tracking boolean for swap
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;//Start with swapped set to false
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])//Determine whether it should be swapped
			{
				swap(&arr[j], &arr[j + 1]);//Swap
				swapped = true;//Change swapped to true
			}
		}
		if (swapped == false)// IF no two elements were swapped by inner loop, then break
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

	int userchoice = 0;//dec and assignment
	cout << "How would you like to sort these numbers?\n1.) Bubble.\n2.) Selection.\n3.) Insertion\n4.) Comb\n5.) Heap\n";//output
	
	while (!(cin >> userchoice) || userchoice < 1 || userchoice > 5)//error check
	{
		cout << "Invalid selection (Choice must be between 1 - 5)\n";//output
		cin.clear();//clear
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//check
	}
	switch (userchoice)//switch about userchoice
	{
	case 1 ://Bubble
		bubbleSort bSort;//class dec
		clockStart = clock();//Start clock
		sortedArr = bSort.bubbleSortDriver(arr);//Start the bubble sort passing unsorted vector array
		print bPrint;//class dec
		bPrint.printDriver(sortedArr);//Start the print class passing the sorted vector array
		cout << "\nThis sort took " << ((clock() - clockStart) / (double)CLOCKS_PER_SEC) << " seconds\n";//output time
		_getch();
		cout << "\n";//New line
		main();
		break;
	case 2 ://Selection 
		selectionSort sSort;//class dec
		clockStart = clock();//Start clock
		sortedArr = sSort.selectionSortDriver(arr);//start class
		print sPrint;//class dec
		sPrint.printDriver(sortedArr);//start class
		cout << "\nThis sort took " << ((clock() - clockStart) / (double)CLOCKS_PER_SEC) << " seconds\n";//output time
		_getch();
		cout << "\n";//New line
		main();
		break;
	case 3://Insertion
		insertionSort iSort;//class dec
		clockStart = clock();//Start clock
		sortedArr = iSort.insertionSortDriver(arr);//Start the insertion sort passing unsorted vector array
		print iPrint;//class dec
		iPrint.printDriver(sortedArr);//Start the print class passing the sorted vector array
		cout << "\nThis sort took " << ((clock() - clockStart) / (double)CLOCKS_PER_SEC) << " seconds\n";//output time
		_getch();
		cout << "\n";//New line
		main();
		break;
	case 4://Comb Sort
		combSort cSort;//class dec
		clockStart = clock();//Start clock
		sortedArr = cSort.combSortDriver(arr);//class start
		print cPrint;//class dec
		cPrint.printDriver(sortedArr);//class start
		cout << "\nThis sort took " << ((clock() - clockStart) / (double)CLOCKS_PER_SEC) << " seconds\n";//time stop and output time
		_getch();
		cout << "\n";//New line
		main();
		break;
	case 5://Heap Sort
		heapSort hSort;//class dec
		clockStart = clock();//Start clock
		sortedArr = hSort.heapSortDriver(arr);//class start
		print hPrint;//class dec
		hPrint.printDriver(sortedArr);//class start
		cout << "\nThis sort took " << ((clock() - clockStart) / (double)CLOCKS_PER_SEC) << " seconds\n";//time stop and output time
		_getch();
		cout << "\n";//New line
		main();
		break;
	default:
		break;
	}
	return 0;
}
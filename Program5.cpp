/////////////////////////////////////////////////////////////////////////////////////////////////////
//Name: Eddie G. Pineda Castelan																   //
//Date: 12/01/2022																				   //
//Program Statement: Design a class AbstractSort to analyze the number of comparisons performed    //
//                   by a sorting algorithm. The class should have:                                //
//                      *Member function compare that compares two array elements                  //
//                      *A means of keeping track of the number of comparisons performed           //
//                      *Pure virtual member function void sort(int arr[], int size) which, when   //
//                       overriden, will sort the array by calling a compare function to determine //
//                       the relative order of pairs of numbers.                                   //
//                   Create a subclass that uses a similar sorting algorithm to implement the sort //
//                   function. Class should have a member function to retrieve the number of       //
//                   comparisons performed.                                                        //
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
using namespace std;

//Start of classes
class AbstractSort { //Start of class AbstractSort
	public:
		AbstractSort(); //Default Constructor
		bool compare(int, int); //Compare member function that compares two array elements
		int getCount(); //Retrieve number of comparisons
		virtual void sort(int*, int) = 0; //Pure virtual function sort(int arr[], int size)

	protected:
		int countTrack; //Means of keeping track of the number of comparisons performed
};

class SelectionSort : public AbstractSort //Subclass with sorting algorithm used to implement the sort function
{
	public:
		virtual void sort(int*, int); //virtual function sort(int arr[], int size)
};

//Start of function implementations
AbstractSort::AbstractSort() { //Default Cosntructor definition
	countTrack = 0; //Sets the count to 0
}

bool AbstractSort::compare(int intOne, int intTwo) { //Definition for compare function
	if (intOne > intTwo) { //If first value is greater than the second
		return true;
	}
	else {
		return false;
	}
}

int AbstractSort::getCount() { //Definition for getCount function
	return countTrack; //Function simply returns the stored value for countTrack
}

void SelectionSort::sort(int arr[], int size) { //Implementation of sort function using subclass SelectionSort
	int index, temp; //Integer variables used in the selection sorting algorithm

	for (int i = 0; i < size - 1; i++) { //First for loop of selection sort. Parses through every value minus the last one
		index = i; //Temporarily stores the current index
		temp = arr[i]; //Temporarily stores teh current value in the array

		for (int j = i + 1; j < size; j++) { //Second for loop of selection sort. Parses through every value minus the first one
			if (compare(temp, arr[j])) { //Uses the compare function previously defined to compare the temporary stored variable and the value of the current index in the array
				temp = arr[j]; //Temp stores the new value from the array
				index = j; //Index stores the new of the second for loop
				countTrack++; //countTrack is increased by 1 after successfuly using the compare function
			}
		}
		arr[index] = arr[i]; //Array values swap
		arr[i] = temp; //Array value stores the temporary value
	}
}
const int sizeArr = 10; //Size of the array in the program
int main() {
	AbstractSort* arrayProb = new SelectionSort; //Creates new class element used in the program
	int currArr[sizeArr]; //Creates the array of the desired size

	cout << "Enter the values in the array: " << endl; //Asks the user to enter the values in the array
	for (int i = 0; i < sizeArr; i++) { //For loop parses through every value in the array
		cin >> currArr[i]; //Stores value in current index
	}

	cout << "Sorted array:" << endl;
	arrayProb->sort(currArr, sizeArr); //Uses the pure virtual function sort(int*,int) to sort the array
	for (int i = 0; i < sizeArr; i++) { //For loop used to output the ordered array
		cout << currArr[i] << " " << flush; //Outputs the value of the current index in the array
	}
	cout << endl << "Number of Comparisons: " << arrayProb->getCount() << endl; //Uses the getCount() function to output the number of comparisons done by the sorting array

	return 0;
}
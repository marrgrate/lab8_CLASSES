#include "Vector.h"

int main()
{
	Vector<double> arr;
	int n = 10;
	cout << "DEFAULT CONSTRUCTOR: " << arr;		//using overloded operator <<
	arr.SetSize(n);							//set size of array = 10
	arr.InitVectorRandom();						//initialize array with random numbers
	cout << "RANDOM VECTOR: " << arr;
	n = 5;
	arr.SetSize(5);
	cout << "Enter " << n << " numbers:\n";
	cin >> arr;									//using overloded operator >>
	cout << "\nUSER VECTOR: " << arr;

//-----------------------------------------------------------------------------------//
//create an array from numbers once contained in a file
	cout << "\nTASK 7.1\n";
	const int size = 10000;
	Vector<bool> numbers(size, 0);
	cout << numbers.GetSize();		//testing GetSize() method

	fstream file("numbers.txt");
	int number;
	int cntr = 0;
	while (!file.eof() && cntr != 10000)
	{
		file >> number;
		if (!numbers[number])
		{
			numbers[number] = true;
			++cntr;
		}
	}
	Vector<int> new_array(cntr, 0);
	cout << endl;
	int i = 0;
	for (int j = 0; j < 10000; j++)
		if (numbers[j])
		{
			new_array[i] = j;
			++i;
		}
	cout << new_array;
	file.close();
	return 0;
}
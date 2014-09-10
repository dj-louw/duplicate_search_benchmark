
// C++ includes
#include <iostream> // for io related stuff
#include <sstream> // for stringstream


// External Library includs
#include "../danlib/danlib.h"







using namespace std;

// function that creates and populates an array of size @ArraySize with random numbers.
vector<int> GenerateArray(int _arraySize, float _fractionDuplicates = 0.5)
{

	if(_fractionDuplicates >= 1)
		_fractionDuplicates = 1;

	// Create an empty vector
	std::vector<int> ArrayOfNumbers;

	int i = 1;

	// fill the first bit with the amount of duplicates specified.
	for ( ; ArrayOfNumbers.size() < int(_arraySize * (_fractionDuplicates)) ; i++)
	{
		ArrayOfNumbers.push_back(i);
		ArrayOfNumbers.push_back(i);
	}

	// using the same counter, fill the second bit with duplicates.
	for ( ; ArrayOfNumbers.size() <= _arraySize - 1; i++)
	{
		if (ArrayOfNumbers.size() < _arraySize)
			ArrayOfNumbers.push_back(i);
		// if (ArrayOfNumbers.size() < _arraySize)
		// 	ArrayOfNumbers.push_back(i*2);
	}
	return ArrayOfNumbers;
}


void CreateFileAndPopulate(int x, int y, float p, int n)
{

	stringstream fileName;
	fileName << "bin/output/afile/A-File-" << x << "-" << y;
	DanLib::FileTool outFile;
	outFile.InitOFile(fileName.str());

	for (int i = 0; i < 10; i++)
	{
		
		cout << "Generating array with parameters " << "p = " << p << " and " << "n = " << n << endl;
		vector<int> randomArray = GenerateArray(n,p);
		//PrintArray(randomArray);

		stringstream stringifiedArray;
		for (int elem : randomArray)
		{
			stringifiedArray << elem << "|"; 
		}
		stringifiedArray << endl; 

		outFile.WriteToFile(stringifiedArray.str());
	}

	outFile.Close();

}


int main()
{
	cout << "AFile: Generates arrays according to the parameters and populates files with it." << endl;

	for(int x = 1; x <=11; x++)
	{

		 // p is the proportion of duplicates within the array. 0.0 is no duplicates, 1.0 is 100% duplicates.
		float p = ((x-1)/10.0);
		int y, n = 0;

		cout << endl << ">" << float(p) << "<" << endl;


		// 100 elems
		n = 100;
		y = 1;
		CreateFileAndPopulate(x, y, p, n);

		// 300 elems
		n = 300;
		y = 2;
		CreateFileAndPopulate(x, y, p, n);

		// 900 elems
		n = 900;
		y = 3;
		CreateFileAndPopulate(x, y, p, n);

		// 2700 elems
		n = 2700;
		y = 4;
		CreateFileAndPopulate(x, y, p, n);

		// 8100 elems
		n = 8100;
		y = 5;
		CreateFileAndPopulate(x, y, p, n);


	}














































	cout << "\nPress Return key to exit"; 
	cin.get();

	return 0;
}


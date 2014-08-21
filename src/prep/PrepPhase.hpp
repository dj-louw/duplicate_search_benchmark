#ifndef PREPPHASE
#define PREPPHASE

#include <sstream>
#include <math.h>
#include <iostream>

#include "../util/ArrayTools.hpp"
#include "../util/FilePrinter.hpp"

void CreateFileAndPopulate(int x, int y, float p, int n)
{

	stringstream fileName;
	fileName << "I-File-" << x << "-" << y;
	FilePrinter outFile (fileName.str());

	for (int i = 0; i < 10; i++)
	{
		
		cout << "Generating array with parameters " << "p = " << p << " and " << "n = " << n << endl;
		vector<int> randomArray = GenerateRandomArray(n,p);
		//PrintArray(randomArray);

		stringstream stringifiedArray;
		for (int elem : randomArray)
		{
			stringifiedArray << elem << "|"; 
		}
		stringifiedArray << endl; 

		outFile.WriteToFile(stringifiedArray.str());
	}

	outFile.CloseFile();

}

void PerformPrepPhase()
{
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



		// for (int y = 1; y < 6; y++)
		// {
		// 	// n is the size of the array of numbers to be generated.
		// 	// The array size increases exponentially according to the function n = (100/3)*3^y
		// 	int n = (100/3)*pow(3,y);

		// 	stringstream fileName;
		// 	fileName << "I-File-" << x << "-" << y;
		// 	FilePrinter outFile (fileName.str());

		// 	for (int i = 0; i < 10; i++)
		// 	{
				
		// 		cout << "Generating array with parameters " << "p = " << p << " and " << "n = " << n << endl;
		// 		vector<int> randomArray = GenerateRandomArray(n,p);
		// 		//PrintArray(randomArray);

		// 		stringstream stringifiedArray;
		// 		for (int elem : randomArray)
		// 		{
		// 			stringifiedArray << elem << "|"; 
		// 		}
		// 		stringifiedArray << endl; 

		// 		outFile.WriteToFile(stringifiedArray.str());
		// 	}

		// 	outFile.CloseFile();



		//}

	}
}









#endif
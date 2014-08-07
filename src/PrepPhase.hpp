#ifndef PREPPHASE
#define PREPPHASE

#include <sstream>
#include <math.h>
#include <iostream>

#include "FilePrinter.hpp"

void CreateFileAndPopulate(int x, int y, int p, int n)
{
	stringstream fileName;
	fileName << "I-File-" << x << "-" << y;
	FilePrinter outFile (fileName.str());

	for (int i = 0; i < 10; i++)
	{
		cout << "p = " << p << "| n = " << n << endl;
		outFile.WriteToFile("blah|\n");
	}

	outFile.CloseFile();
}

void PerformPrepPhase()
{
	for(int x = 0; x <11; x++)
	{

		float p = x/10;

		for (int y = 1; y < 6; y++)
		{
			int n = (100/3)*pow(3,y);

			CreateFileAndPopulate(x, 1, p, n);
		}

	}
}









#endif
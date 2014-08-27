// Gruner1.cpp : Defines the entry point for the console application.
//
#include <random>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <vector>
#include <sstream>
#include <string>

// #include <fstream>	

//#include "NaiveApproach.hpp"
//#include "FilePrinter.hpp"
#include "util/ArrayTools.hpp"
//#include "bench.hpp"
//#include "benchstream.hpp"
#include "prep/PrepPhase.hpp"
#include "algorithms/CombinedQuickSort.hpp"
#include "algorithms/BSTSearch.hpp"
//#include "prep/PrepPhase.hpp"


// include DanLib
#include "../danlib/danlib.h"

using namespace std;

int main()
{
	cout << "Duplicate Finding Algorithm Benchmark Tool" << endl;


/*
* Testing section
*

	for (float f = 0.0; f <= 1.1;)
	{

		cout << "p = " << float(f) << " > " ;

		int n = 10;
		// float p = 0.0;
		vector<int> testArray = GenerateRandomArray(n,f);
		PrintArray(testArray);	

		f = f + 0.1;
	}
	
*/

	DanLib::FileTool ft;
	ft.InitOFile("lel")	;


/**/


	// vector<int> ArrayOfRandomNumbers = GenerateRandomArray(1, 0.5);

	// //ImprovedQuickSort CurrentAlgorithm = ImprovedQuickSort(ArrayOfRandomNumbers);
	// BSTSearch CurrentAlgorithm = BSTSearch(ArrayOfRandomNumbers);

	// CurrentAlgorithm.Do();

	// cout << CurrentAlgorithm.GetDuplicateCounter() << endl;
	// cout << CurrentAlgorithm.GetStepCounter() << endl;







/******************************************************
* Preparatory Phase
*/
//PerformPrepPhase();


	// pause and require input before exit
	cout << "\nPress Return key to continue"; 
	cin.get();

	return 0;
}


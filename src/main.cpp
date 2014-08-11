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
//#include "util.hpp"
//#include "bench.hpp"
//#include "benchstream.hpp"
#include "prep/PrepPhase.hpp"
//#include "algorithms/CombinedQuickSort.hpp"
//#include "prep/PrepPhase.hpp"

using namespace std;

int main()
{
	cout << "Duplicate Finding Algorithm Benchmark Tool" << endl;



	// vector<int> ArrayOfRandomNumbers = GenerateRandomArray(50, 0);

	// ImprovedQuickSort CurrentAlgorithm = ImprovedQuickSort(ArrayOfRandomNumbers);

	// CurrentAlgorithm.Do();

	PerformPrepPhase();


	// pause and require input before exit
	cout << "\nPress Return key to continue"; 
	cin.get();

	return 0;
}


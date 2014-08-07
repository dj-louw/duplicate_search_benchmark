#ifndef STREAMBENCH
#define STREAMBENCH

#include <string>
#include <chrono>
#include <sstream>
#include <vector>
#include <random>



#include "CombinedQuickSort.hpp"
#include "NaiveApproach.hpp"
#include "AlteredNaive.hpp"
#include "BSTSearch.hpp"






void DoStreamBench()
{

	BSTSearch CurrentAlgorithm = BSTSearch();
  	std::default_random_engine generator;
  	std::uniform_int_distribution<int> distribution(0,5);
	
	while (true)
	{	
		CurrentAlgorithm.DoForAStream(distribution(generator));
		std::this_thread::sleep_for(std::chrono::seconds(1));
		
	}
}







// void DoBenchMark(int _arraySize, float _fractionOfDuplicates, string _testTitle, int _amountOfTests, int _amountOfRepetitions)
// {

// 	cout << _testTitle << endl;

// 	FilePrinter timingFile (_testTitle);

// 	// create a blank container for the numbers
// 	std::vector<int> ArrayOfRandomNumbers;

// 	// The actual Benchmark Loop
// 	for (int i = 1; i <= _amountOfTests; i++)
// 	{

// 		// user feedback
// 		cout << "\r" << "Running Test #" << i << " Of " << _amountOfTests << ".";
// 		std::cout.flush();

			
		
// 		// // sleep between runs to give the rangen some time to catch up. 
// 		// std::this_thread::sleep_for(std::chrono::seconds(1));

		

// 		// for (int kk = 0; kk <= ArrayOfRandomNumbers.size(); kk++)
// 		// 	cout << " | " << ArrayOfRandomNumbers[kk];

// 		// ImprovedQuickSort CurrentAlgorithm = ImprovedQuickSort(ArrayOfRandomNumbers);
// 		// CurrentAlgorithm.Do();




// 		ArrayOfRandomNumbers = GenerateRandomArray(_arraySize, _fractionOfDuplicates);

// 		// for (int kk = 0; kk <= ArrayOfRandomNumbers.size() -1 ; kk++)
// 		// 	cout << " | " << ArrayOfRandomNumbers[kk];
// 		// cout << endl;

// 		ImprovedQuickSort CurrentAlgorithm = ImprovedQuickSort(ArrayOfRandomNumbers);
// 		//NaiveApproach CurrentAlgorithm = NaiveApproach(ArrayOfRandomNumbers);
// 		//AlteredNaive CurrentAlgorithm = AlteredNaive(ArrayOfRandomNumbers);
// 		//BSTSearch CurrentAlgorithm = BSTSearch(ArrayOfRandomNumbers);

// 		// everything between the lines are benched.
// 		 auto start_time = chrono::high_resolution_clock::now();
// 		//==============================================================================================================
		
// 			// we repeat the run multiple times on the same random array to ensure that no anomalies in the time measurement creeps in.
// 			for (int j = 1; j <= _amountOfRepetitions; j++)
// 			{// The algorithm to benchmark comes in here.							
// 				CurrentAlgorithm.Do();				
// 			}

// 		//=============================================================================================================
// 		auto end_time = chrono::high_resolution_clock::now();

// 		cout << " Duplicates Found: " << CurrentAlgorithm.GetDuplicateCounter();

// 		// calculate duration and print to file
// 		auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
// 		stringstream durationString;
// 		durationString << duration << endl;		
// 		//cout << "Time: " << duration << endl << endl;
// 		timingFile.WriteToFile(durationString.str());


// 	};

	// close the current file
	//timingFile.CloseFile();

//}




















#endif
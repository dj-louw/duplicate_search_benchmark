#ifndef BENCH
#define BENCH

#include <string>
#include <chrono>
#include <sstream>
#include <vector>


unsigned TokenizeString(const string& i_source, const string& i_seperators, bool i_discard_empty_tokens, vector<string>& o_tokens)
{
	unsigned prev_pos = 0;
	int pos = 0;
	unsigned number_of_tokens = 0;
	o_tokens.clear();
	pos = i_source.find_first_of(i_seperators, pos);

	while (pos != string::npos)
	{
		string token = i_source.substr(prev_pos, pos - prev_pos);
		if (!i_discard_empty_tokens || token != "")
		{
			o_tokens.push_back(i_source.substr(prev_pos, pos - prev_pos));
			number_of_tokens++;
		}
		pos++;
		prev_pos = pos;
		pos = i_source.find_first_of(i_seperators, pos);
	}
	if (prev_pos < i_source.length())
	{
		o_tokens.push_back(i_source.substr(prev_pos));
		number_of_tokens++;
	}
	return number_of_tokens;
}






void DoBenchMark()
{

	DanLib::FileTool ft;

	for (int x = 1; x <= 11; x++) // x <= 11
	{
		for (int y = 1; y <= 5; y++) // x <= 5
		{
			// calculate the name of the file and open it
			stringstream iFileName, oFileName;
			
			iFileName << "../data/I-File-" << x << "-" << y;
			oFileName << "../data/output/O-File-" << x << "-" << y;
			//iFileName << "../data/TESTDATA";
				
			cout << "Opening " << iFileName.str() << " and " << oFileName.str() << endl;

			ft.InitIFile(iFileName.str());
			ft.InitOFile(oFileName.str());



			//read the lines into an array and do the magic!
			string CurrentLine; 

			// the program step counters
			float QuickSortCounter, BSTreeCounter = 0.0;

			// Line counter, used in average calculations
			int LineCounter = 0;

			// the size of the current array being worked on. (float for avg calculation)
			float ArraySize = 0;

			// the amount of duplicates found for each algorithm (float for avg calculation)
			float BSTDupsFound = 0.0;
			float QuickDupsFound = 0.0;

			while (ft.ReadLineFromFile(CurrentLine))
			{

				LineCounter++;

				vector<string> stringsFromLine;
				TokenizeString(CurrentLine, "|", true, stringsFromLine);

				vector<int> currentData;

				for (auto elem : stringsFromLine)
				{
					int temp = atoi(elem.c_str());
					currentData.push_back(temp);
				}

				ArraySize += currentData.size();

				/**********************************************************
					Now we have an array, currentData,
					containing the random numbers that must be processed
				*/





				// The Binary Tree based method
				vector<int> tempA(currentData); // we make a copy of the data just to be on the safe side.
				BSTSearch MethodA = BSTSearch(tempA);
				MethodA.Do();
				BSTreeCounter = BSTreeCounter + MethodA.GetStepCounter();
				BSTDupsFound = BSTDupsFound + MethodA.GetDuplicateCounter();

				
				// The QuickSort based method
				vector<int> tempB(currentData); // we make a copy of the data just to be on the safe side.
				ImprovedQuickSort MethodB = ImprovedQuickSort(tempB);
				MethodB.Do();
				QuickSortCounter = QuickSortCounter + MethodB.GetStepCounter();
				QuickDupsFound = QuickDupsFound + MethodB.GetDuplicateCounter();

				cout << "Binary took: " << BSTreeCounter << " steps to complete." << endl;
				cout << "Quick took:  " << QuickSortCounter << " steps to complete." << endl;

			};


			// File header (intended to be used as a sanity check)

			ArraySize = ArraySize / LineCounter; // this number should have no decimal
			float ProportionDups = ((x-1)/10.0); // calculate the proportion of duplicates that must be present
			// The actual duplicates found for each file
			
			BSTDupsFound = BSTDupsFound / LineCounter;
			QuickDupsFound = QuickDupsFound / LineCounter;

			stringstream fileHeader;
			fileHeader <<
				"O-File-" << x << "-" << y << endl
				<< "Average array size for this file was: " << ArraySize << endl
				<< "The (expected) proportion of duplicates for each array in this file: " << ProportionDups << "," << endl
				<< "which is equal to " << (ArraySize * ProportionDups)/2 << " duplicate pairs" << endl
				<< "The QuickSort Algorithm found: " << QuickDupsFound << " duplicate pairs." << endl
				<< "The BST Search Algorithm found: " << BSTDupsFound << " duplicate pairs." << endl				
				<< "####" << endl;

			ft.WriteToFile(fileHeader.str());

			// calculate the averages and write them to the current file
			QuickSortCounter = QuickSortCounter / LineCounter;
			ft.WriteToFileNewLine(to_string(QuickSortCounter) + " | <- QuickSort Algorithm");

			BSTreeCounter = BSTreeCounter / LineCounter;
			ft.WriteToFileNewLine(to_string(BSTreeCounter) + " | <- BSTree Algorithm");


			

			// finally, close the filetool and start over
			ft.Close();



		}
	}


}






// #include "CombinedQuickSort.hpp"
// #include "NaiveApproach.hpp"
// #include "AlteredNaive.hpp"
// #include "BSTSearch.hpp"

// void DoBenchMark(int _arraySize, float _fractionOfDuplicates, string _testTitle, int _amountOfTests, int _amountOfRepetitions)
// {
// 	cout << _testTitle << endl;
// 	FilePrinter timingFile (_testTitle);
// 	// create a blank container for the numbers
// 	vector<int> ArrayOfRandomNumbers;

// 	// The actual Benchmark Loop
// 	for (int i = 1; i <= _amountOfTests; i++)
// 	{
// 		// user feedback
// 		cout << "\r" << "Running Test #" << i << " Of " << _amountOfTests << ".";
// 		std::cout.flush();
		
// 		// populate the array with random numbers OUTSIDE of the timing wrap.
// 		ArrayOfRandomNumbers = GenerateRandomArray(_arraySize, _fractionOfDuplicates);
		
// 		// Select the type of algorithm to run this time
// 		//NaiveApproach CurrentAlgorithm = NaiveApproach(ArrayOfRandomNumbers);
// 		//AlteredNaive CurrentAlgorithm = AlteredNaive(ArrayOfRandomNumbers);
// 		//ImprovedQuickSort CurrentAlgorithm = ImprovedQuickSort(ArrayOfRandomNumbers);
// 		BSTSearch CurrentAlgorithm = BSTSearch(ArrayOfRandomNumbers);

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
// 		timingFile.WriteToFile(durationString.str());
// 	};
// 	// close the current file
// 	timingFile.CloseFile();
// }

// void DoArrayBench()
// {
// 	// The amount of times that the test is going to be run.
// 	int AmountOfTests = 5; // 10 Is the value that is to be used for the final run!
// 	// The amount of times each test is going to be repeated
// 	int AmountOfRepetitions = 10; // 1000 is the value to be used for the final run!


// 	for (int _ArraySize = 10; _ArraySize <= 1000000; _ArraySize *= 10)
// 	{
// 		float FractionOfDuplicates;

// 		// Variation #1 - No Duplicates
// 		FractionOfDuplicates = 0;
// 		stringstream TestTitleString1;
// 		TestTitleString1 << "BSTSearch-00-n=" << _ArraySize;
// 		DoBenchMark(_ArraySize, FractionOfDuplicates, TestTitleString1.str(), AmountOfTests, AmountOfRepetitions);
		
// 		//Variation #2 - 50% are duplicates
// 		FractionOfDuplicates = 0.5;
// 		stringstream TestTitleString2;
// 		TestTitleString2 << "BSTSearch-50-n=" << _ArraySize;
// 		DoBenchMark(_ArraySize, FractionOfDuplicates, TestTitleString2.str(), AmountOfTests, AmountOfRepetitions);

// 		//Variation #3 - 100% Are Duplicates
// 		FractionOfDuplicates = 1;
// 		stringstream TestTitleString3;
// 		TestTitleString3 << "BSTSearch-100-n=" << _ArraySize;
// 		DoBenchMark(_ArraySize, FractionOfDuplicates, TestTitleString3.str(), AmountOfTests, AmountOfRepetitions);

// 	} // main for
// }


















#endif
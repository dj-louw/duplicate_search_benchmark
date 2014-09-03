#ifndef BENCH
#define BENCH

#include <string>
#include <chrono>
#include <sstream>
#include <vector>









void DoBenchMark()
{

	DanLib::FileTool ft;

	for (int x = 1; x <= 11; x++) // x <= 11
	{
		for (int y = 1; y <= 5; y++) // x <= 5
		{
			// calculate the name of the file and open it
			stringstream iFileName, oFileName;
			if (TestMode)
			{
				iFileName << "../data/testarrays/I-File-" << x << "-" << y;
				oFileName << "../data/testarrays/output/O-File-" << x << "-" << y;							
			} else
			{
				iFileName << "../data/I-File-" << x << "-" << y;
				oFileName << "../data/output/O-File-" << x << "-" << y;				
			}


				
			cout << "Opening " << iFileName.str() << " and " << oFileName.str() << endl;

			bool success = ft.InitIFile(iFileName.str());
			if (success)
			{
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
					DanLib::TokenizeString(CurrentLine, "|", true, stringsFromLine);

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
					int BSTCurrentCount = MethodA.GetStepCounter();
					BSTreeCounter = BSTreeCounter + BSTCurrentCount;
					BSTDupsFound = BSTDupsFound + MethodA.GetDuplicateCounter();

					
					// The QuickSort based method
					vector<int> tempB(currentData); // we make a copy of the data just to be on the safe side.
					ImprovedQuickSort MethodB = ImprovedQuickSort(tempB);
					MethodB.Do();
					int QuickSortCurrentCounter = MethodB.GetStepCounter();
					QuickSortCounter = QuickSortCounter +  QuickSortCurrentCounter;
					QuickDupsFound = QuickDupsFound + MethodB.GetDuplicateCounter();

					cout << "Binary took: " << BSTCurrentCount << " steps to complete." << endl;
					cout << "Quick took:  " << QuickSortCurrentCounter << " steps to complete." << endl;

				};


				// File header (intended to be used as a sanity check)

				ArraySize = ArraySize / LineCounter; // this number should have no decimal
				float ProportionDups = ((x-1)/10.0); // calculate the proportion of duplicates that must be present
				// The actual duplicates found for each file
				
				BSTDupsFound = BSTDupsFound / LineCounter;
				QuickDupsFound = QuickDupsFound / LineCounter;

				stringstream fileHeader;
				fileHeader
					<< "# O-File-" << x << "-" << y << endl
					<< "# " << LineCounter << " arrays were found in this file," << endl
					<< "# with an average array size of: " << ArraySize << endl
					<< "# The (expected) proportion of duplicates for each array in this file: " << ProportionDups << "," << endl
					<< "# which is equal to " << (ArraySize * ProportionDups)/2 << " duplicate pairs" << endl
					<< "# The QuickSort Algorithm found: " << QuickDupsFound << " duplicate pairs." << endl
					<< "# The BST Search Algorithm found: " << BSTDupsFound << " duplicate pairs." << endl				
					<< "# " << endl;

				ft.WriteToFile(fileHeader.str());

				// calculate the averages and write them to the current file
				QuickSortCounter = QuickSortCounter / LineCounter;
				ft.WriteToFileNewLine(to_string(QuickSortCounter) + " | <- QuickSort Algorithm");

				BSTreeCounter = BSTreeCounter / LineCounter;
				ft.WriteToFileNewLine(to_string(BSTreeCounter) + " | <- BSTree Algorithm");

			}
			

			// finally, close the filetool and start over
			ft.Close();



		}
	}


}

void DoDifference()
{

	DanLib::FileTool ft;

	string oFileName;
	if (TestMode)
	{
		oFileName = "../data/testarrays/output/D-File.csv";				
	} else 
	{
		oFileName = "../data/output/D-File.csv";			
	}

	ft.InitOFile(oFileName);

	vector<string> currentLineToPrint = {"free parameters", "n=100", "n=300", "n=900", "n=2700", "n=8100"};
	ft.WriteStringVectorToFile(currentLineToPrint, ",");

	for (int x = 1; x <= 11; x++) // x <= 11
	{

		currentLineToPrint.clear();
		currentLineToPrint.push_back("p = " + to_string((x-1)/10.0));


		for (int y = 1; y <= 5; y++) // x <= 5
		{
			// calculate the name of the file and open it
			stringstream iFileName;			

			if (TestMode)
			{			
				iFileName << "../data/testarrays/output/O-File-" << x << "-" << y;				
			} else 
			{			
				iFileName << "../data/output/O-File-" << x << "-" << y;	
			}
			

			cout << "Opening " << iFileName.str() << endl;
			ft.InitIFile(iFileName.str());
			

			vector<string> lines, numbers;

			//read the lines from the file int a string vector
			string CurrentLine;			
			while (ft.ReadLineFromFile(CurrentLine))
			{
				lines.push_back(CurrentLine);
			};

			// go through the array and extract the lines containing the numbers
			for (auto elem : lines)
			{
				//cout << elem.at(0) << endl;
				if (elem.at(0) != '#')
				{
					//cout << "NUMBER" << endl;
					numbers.push_back(elem);					
				}
			}


			vector<string> QuickSortString, BSTreeSearchString;			

			DanLib::TokenizeString(numbers[0], "|", true, QuickSortString);
			DanLib::TokenizeString(numbers[1], "|", true, BSTreeSearchString);

			float QuickSortVal = atof(QuickSortString[0].c_str());
			float BSTreeSearchVal = atof(BSTreeSearchString[0].c_str());

			cout << numbers[0] << "    XX    " << float(QuickSortVal) << endl;
			cout << numbers[1] << "    XX    " << BSTreeSearchVal << endl;


			float Difference = QuickSortVal - BSTreeSearchVal;
			currentLineToPrint.push_back(to_string(Difference));

			

			// finally, close the filetool and start over
			ft.CloseIFile();



		}


		ft.WriteStringVectorToFile(currentLineToPrint, ",");
		// for (auto elem : currentLineToPrint)
		// {
		// 	cout << elem << ",";
		// }
		// cout << endl;


	}

	ft.Close();


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
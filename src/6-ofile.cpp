
// C++ includes
#include <iostream> // for io related stuff
#include <sstream> // for std::stringstream
#include <string> // for std::string

// External Library includs
#include "../danlib/danlib.h"

// Other file includes
#include "algorithms/algorithms.h"


using namespace std;


int main()
{

	cout << "QuickSort: reads IFiles, Performs at the duplicate searching and " << endl;


	DanLib::FileTool ftQuick, ftBST, ftOfile;	

	for (int x = 1; x <= 11; x++) // x <= 11
	{
		for (int y = 1; y <= 5; y++) // x <= 5
		{

			// calculate the names of the files
			stringstream QuickFileName, BSTFileName, OfileName;
			QuickFileName << "bin/output/quicksort/TempQuick_" << x << "_" << y;
			BSTFileName << "bin/output/bstree-nodelete/TempTreeNoDel_" << x << "_" << y;
			OfileName << "bin/output/ofile/O-File_" << x << "-" << y;							
			cout << "Opening " << QuickFileName.str() << " and " << BSTFileName.str() << " and " << OfileName.str() << endl;
			
			// open the input file (A-FILE)
			ftQuick.InitIFile(QuickFileName.str());
			ftBST.InitIFile(BSTFileName.str());
			ftOfile.InitOFile(OfileName.str());
			

			int QuickSortTime, BSTTime, QuickSortTimeCounter, BSTTimeCounter;
			QuickSortTime = BSTTime = 0;
			QuickSortTimeCounter = BSTTimeCounter = 0;

			// read the quick sort data in and tokenize
			string QuickSortLine; 				
			while (ftQuick.ReadLineFromFile(QuickSortLine))
			{

				QuickSortTimeCounter++;

				vector<string> stringsFromLine;
				DanLib::TokenizeString(QuickSortLine, "|", true, stringsFromLine);

				for (auto elem : stringsFromLine)
				{
					QuickSortTime += atoi(elem.c_str());
				}		

			}			

			// read the BST data in and tokenize
			string BSTLine; 				
			while (ftBST.ReadLineFromFile(BSTLine))
			{
				BSTTimeCounter++;

				vector<string> stringsFromLine;
				DanLib::TokenizeString(BSTLine, "|", true, stringsFromLine);

				for (auto elem : stringsFromLine)
				{
					BSTTime += atoi(elem.c_str());
				}					

			}
			

			float QuickSortAvgTime = QuickSortTime / QuickSortTimeCounter;
			ftOfile.WriteToFileNewLine(to_string(QuickSortAvgTime) + " | <- QuickSort Algorithm");

			float BSTAvgTime = BSTTime / BSTTimeCounter;
			ftOfile.WriteToFileNewLine(to_string(BSTAvgTime) + " | <- BSTree Algorithm");
			
			

			// finally, close the filetool and start over
			ftQuick.Close();
			ftBST.Close();
			ftOfile.Close();


		}
	}


	cout << "\nPress Return key to exit"; 
	cin.get();

	return 0;
}


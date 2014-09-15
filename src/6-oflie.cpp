
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


	DanLib::FileTool ft;

	for (int x = 1; x <= 11; x++) // x <= 11
	{
		for (int y = 1; y <= 5; y++) // x <= 5
		{

			// calculate the names of the files
			stringstream iFileName, oFileName;
			iFileName << "bin/output/ifile/I-File-" << x << "-" << y;
			oFileName << "bin/output/quicksort/TempQuick_" << x << "_" << y;							
			cout << "Opening " << iFileName.str() << " and " << oFileName.str() << endl;
			
			// open the input file (A-FILE)
			bool success = ft.InitIFile(iFileName.str());
			if (success)
			{

				// open the output file (I-FILE)
				ft.InitOFile(oFileName.str());

				// read each line into a placeholder string
				string CurrentLine; 				
				while (ft.ReadLineFromFile(CurrentLine))
				{


				}



			}

			// finally, close the filetool and start over
			ft.Close();			


		}
	}


	cout << "\nPress Return key to exit"; 
	cin.get();

	return 0;
}



// C++ includes
#include <iostream> // for io related stuff
#include <sstream> // for std::stringstream
#include <string> // for std::string

// External Library includs
#include "../danlib/danlib.h"

using namespace std;


int main()
{

	cout << "QuickSort: reads IFiles, Performs at the duplicate searching and " << endl;


	DanLib::FileTool ft;

	string oFileName;
	oFileName = "bin/output/dfile/D-File.csv";			


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
			iFileName << "bin/output/ofile//O-File_" << x << "-" << y;	

			

			cout << "Opening " << iFileName.str() << endl;
			bool initSuccess = ft.InitIFile(iFileName.str());
				
			if (!initSuccess)
				break;

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






	cout << "\nPress Return key to exit"; 
	cin.get();

	return 0;
}



// C++ includes
#include <iostream> // for io related stuff
#include <sstream> // for std::stringstream
#include <string> // for std::string
#include <thread> // std::this_thread::sleep_for()


// External Library includEs
#include "../danlib/danlib.h"


using namespace std;


int main()
{
	cout << "IFile: reads AFiles, shuffles them and prints to I-Files" << endl;


	DanLib::FileTool ft;

	for (int x = 1; x <= 11; x++) // x <= 11
	{
		for (int y = 1; y <= 5; y++) // x <= 5
		{

			// calculate the names of the files
			stringstream iFileName, oFileName;
			iFileName << "bin/output/afile/A-File-" << x << "-" << y;
			oFileName << "bin/output/ifile/I-File-" << x << "-" << y;							
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
					vector<string> stringsFromLine;

					// Break each string into a vector of tokens based on the delimeter
					DanLib::TokenizeString(CurrentLine, "|", true, stringsFromLine);

					vector<int> currentData;

					//cast the vector of strings to ints and copy to vector of ints.
					for (auto elem : stringsFromLine)
					{
						int temp = atoi(elem.c_str());
						currentData.push_back(temp);
					}

					// make sure the system sleeps for at least a second so that the rng gets seeded with a new seed every time.
					std::this_thread::sleep_for(std::chrono::seconds(1));
					// seed the rng
					srand(time(0));
					// shuffle the vector using the fisher-yates algorithm, conveniently built into C++ for us.	
					std::random_shuffle(currentData.begin(), currentData.end());

					ft.WriteVectorToFile(currentData, "|" );

				};
			}
			// finally, close the filetool and start over
			ft.Close();
		}
	}














































	cout << "\nPress Return key to exit"; 
	cin.get();

	return 0;
}


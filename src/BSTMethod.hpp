#ifndef BSTMETHOD
#define BSTMETHOD

void DoBSTMethod(bool _withDelete = false)
{
	DanLib::FileTool ft;

	for (int x = 1; x <= 11; x++) // x <= 11
	{
		for (int y = 1; y <= 5; y++) // x <= 5
		{

			// calculate the names of the files
			stringstream iFileName, oFileName;
			iFileName << "bin/output/ifile/I-File-" << x << "-" << y;

			if (_withDelete)
				oFileName << "bin/output/bstree-withdelete/TempTreeWithDel_" << x << "_" << y;							
			else
				oFileName << "bin/output/bstree-nodelete/TempTreeNoDel_" << x << "_" << y;							

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

					
					// The BST based method, without deletion
					vector<int> tempB(currentData); // we make a copy of the data just to be on the safe side.
					BSTSearch BSTSearchAlgorithm = BSTSearch(tempB, _withDelete);
					BSTSearchAlgorithm.Do();

					// Get the counters					
					int QuickSortCounter = BSTSearchAlgorithm.GetStepCounter();
					int QuickDupsFound = BSTSearchAlgorithm.GetDuplicateCounter();


					ft.WriteToFileNewLine(QuickSortCounter);

					

				}


			}

			// finally, close the filetool and start over
			ft.Close();		

		}
	}
}

#endif
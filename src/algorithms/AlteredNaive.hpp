#ifndef ALTEREDNAIVE
#define ALTEREDNAIVE

#include "FilePrinter.hpp"
#include <sstream>

class AlteredNaive
{
	private:
		vector<int> InputArray;
		int DuplicatesFound;	
	public:
		AlteredNaive(vector<int> & _inputArray)
		{
			Init(_inputArray);
		}		
		AlteredNaive(){}
		void Init(vector<int> _inputArray)
		{
			InputArray = _inputArray;
		}
		int GetDuplicateCounter()
		{
			return DuplicatesFound;
		}
		
		void Do()
		{
			DuplicatesFound = 0;

			vector<int>::iterator innerIt, outerIt;
			int outerCount = 0;
			
			vector<int> TempArray = InputArray;
			
			for (outerIt = TempArray.begin(); outerIt < TempArray.end(); outerIt++, outerCount++)
			{
				int innerCount = 0;
				for (innerIt = TempArray.begin(); innerIt < TempArray.end(); innerCount++ )
				{					
					if((*outerIt) == (*innerIt) && (outerCount != innerCount))
					{
						DuplicatesFound++;						
						innerIt = TempArray.erase(innerIt);
					}
					else
					{					
						innerIt++;
					}
				}				
			}
		}
};

#endif
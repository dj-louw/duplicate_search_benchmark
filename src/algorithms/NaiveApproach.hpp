#ifndef NAIVE
#define NAIVE

#include "FilePrinter.hpp"
#include <sstream>

class NaiveApproach
{
	private:
		vector<int> InputArray;	
		int DuplicatesFound;	
	public:
		NaiveApproach(vector<int> & _inputArray)
		{
			Init(_inputArray);
		}		
		NaiveApproach(){}
		
		void Init(vector<int> _inputArray)
		{
			InputArray = _inputArray;
		}

		int GetDuplicateCounter()
		{
			// this implementation counts every duplicate twice, hence the div by 2
			return DuplicatesFound/2;
		}

		void Do()
		{
			DuplicatesFound = 0;
			for (int i = 0; i <= InputArray.size()-1; i++)
			{
				for (int j = 0; j <= InputArray.size()-1; j++)
				{
					// if a duplicate has been found and they are not the same number send them off to the file
					if ((InputArray[i] == InputArray[j]) && (i != j))
					{
						DuplicatesFound++;
					}
				}		
			}	
		}
};

#endif
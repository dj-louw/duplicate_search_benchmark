#ifndef IMPROVEDQUICKSORT
#define IMPROVEDQUICKSORT

#include "../util/ArrayTools.hpp"

//temp
#include <iostream>

class ImprovedQuickSort
{
	private:
		unsigned long long int StepCounter;
		vector<int> InputArray;
		int DuplicatesFound;

	public:
		ImprovedQuickSort(vector<int> &_inputArray) : StepCounter(0), DuplicatesFound(0)
		{
			StepCounter = StepCounter + 1;
			Init(_inputArray);
		}		
		ImprovedQuickSort(){}
		void Init(vector<int> & _inputArray)
		{
			StepCounter = StepCounter + 1;
			InputArray = _inputArray;
		}
		int GetDuplicateCounter()
		{
			StepCounter = StepCounter + 1;
			return DuplicatesFound;
		}

		void Do()
		{
			StepCounter = StepCounter + 4;
			DuplicatesFound = 0;
			vector<int> TempArray = InputArray;
			//PrintArray(TempArray);
			QuickSort(TempArray);	
			//PrintArray(TempArray);
			FindDuplicates(TempArray);
		
		}
	private:

		void Swap(vector<int> & _inputArray, int _index1, int _index2)
		{
			StepCounter = StepCounter + 3;
			int temp = _inputArray[_index1];
			_inputArray[_index1] = _inputArray[_index2];
			_inputArray[_index2] = temp;
		}

		// Standard QuickSort implementation according to Data Structures and Algorithms 3rd ed by Adam Drozdek, pg 501
		void QuickSort(vector<int> & _inputArray, int _first, int _last)
		{
			StepCounter = StepCounter + 7;
			int lower = _first + 1;
			int upper = _last;

			Swap(_inputArray, _first, (_first+_last)/2);
			int bound = _inputArray[_first];

			while (lower <= upper)
			{
				StepCounter = StepCounter + 3;
				while (bound < _inputArray[lower])
				{
					StepCounter = StepCounter + 1;
					lower++;
				}
				while (bound > _inputArray[upper])
				{
					StepCounter = StepCounter + 1;
					upper--;
				}
				if (lower < upper)
				{
					StepCounter = StepCounter + 3;
					Swap(_inputArray, lower++, upper--);
				}
				else
				{
					StepCounter = StepCounter + 1;
					lower++;
				} 
			}
			Swap(_inputArray, upper, _first);
			StepCounter = StepCounter + 4;
			if(_first < upper-1)
			{
				StepCounter = StepCounter + 2;
				QuickSort(_inputArray, _first, upper-1);
			}
			if (upper+1 < _last)
			{
				StepCounter = StepCounter + 2;
				QuickSort(_inputArray, upper+1, _last);
			}
		}

		void QuickSort(vector<int> & _inputArray)
		{
			StepCounter = StepCounter + 1;
			if (_inputArray.size() < 2)
			{
				StepCounter = StepCounter + 1;
				return;
			}
			StepCounter = StepCounter + 8;
			int min = 0;
			// find the smallest element and put it at the end of _inputArray
			for (int i = 0; i < _inputArray.size(); i++)
			{
				StepCounter = StepCounter + 1;
				if (_inputArray[min] > _inputArray[i])
				{
					StepCounter = StepCounter + 1;
					min = i;				
				}
			}
			Swap(_inputArray, _inputArray.size()-1, min);			
			QuickSort(_inputArray, 0, _inputArray.size()-2);
		}


		void FindDuplicates(vector<int> & _inputArray)
		{
			StepCounter = StepCounter + 2;
			for (int i = 0; i < _inputArray.size(); )
			{
				StepCounter = StepCounter + 3;
				cout << "comparing: " << _inputArray[i] << " with: " << _inputArray[i+1] << endl;
				if (_inputArray[i] == _inputArray[i+1])
				{
					StepCounter = StepCounter + 1;
					DuplicatesFound++;
					cout << "BOOM!";					
				}
				else
				{
					StepCounter = StepCounter + 1;
					break;
				}
				i = i+2;
			}
		}





















		// void QuickSort(vector<int> & _inputArray)
		// {
		// 	if (_inputArray.size() > 1)
		// 	{
		// 		vector<int> less(0);
		// 		vector<int> greater(0);
		// 		int pivot;
				
		// 		// this can potentially be improved...
		// 		pivot = _inputArray.at(0);
					
		// 		for (int i = 1; i <= _inputArray.size() -1 ; i++)
		// 		{
		// 			int val = _inputArray.at(i);
		// 			if (val < pivot)
		// 			{
		// 				less.push_back(val);				
		// 			}
		// 			else if	(val > pivot)
		// 			{
		// 				greater.push_back(val);				
		// 			}
		// 			else
		// 				DuplicatesFound++; // neither < or >, therefor a duplicate!
		// 		}		

		// 		QuickSort(less);
		// 		QuickSort(greater);

		// 		vector<int> newvec(0);
		// 		newvec.insert(newvec.end(), less.begin(), less.end());
		// 		newvec.push_back(pivot);
		// 		newvec.insert(newvec.end(), greater.begin(), greater.end());
		// 		_inputArray = newvec;

		// 	}
		// }
};

#endif
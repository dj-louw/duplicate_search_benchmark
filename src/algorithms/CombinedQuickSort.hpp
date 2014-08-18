#ifndef IMPROVEDQUICKSORT
#define IMPROVEDQUICKSORT

#include "../util/ArrayTools.hpp"

//temp
#include <iostream>

class ImprovedQuickSort
{
	private:
		vector<int> InputArray;
		int DuplicatesFound;

	public:
		ImprovedQuickSort(vector<int> &_inputArray)
		{
			Init(_inputArray);
		}		
		ImprovedQuickSort(){}
		void Init(vector<int> & _inputArray)
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
			vector<int> TempArray = InputArray;
			PrintArray(TempArray);
			QuickSort(TempArray);	
			PrintArray(TempArray);
			FindDuplicates(TempArray);
		
		}
	private:

		void Swap(vector<int> & _inputArray, int _index1, int _index2)
		{
			int temp = _inputArray[_index1];
			_inputArray[_index1] = _inputArray[_index2];
			_inputArray[_index2] = temp;
		}

		// Standard QuickSort implementation according to Data Structures and Algorithms 3rd ed by Adam Drozdek, pg 501
		void QuickSort(vector<int> & _inputArray, int _first, int _last)
		{
			int lower = _first + 1;
			int upper = _last;

			Swap(_inputArray, _first, (_first+_last)/2);
			int bound = _inputArray[_first];

			while (lower <= upper)
			{
				while (bound < _inputArray[lower])
					lower++;
				while (bound > _inputArray[upper])
					upper--;
				if (lower < upper)
					Swap(_inputArray, lower++, upper--);
				else lower++;
			}
			Swap(_inputArray, upper, _first);
			if(_first < upper-1)
				QuickSort(_inputArray, _first, upper-1);
			if (upper+1 < _last)
				QuickSort(_inputArray, upper+1, _last);
		}

		void QuickSort(vector<int> & _inputArray)
		{
			if (_inputArray.size() < 2)
				return;
			int min = 0;
			// find the smallest element and put it at the end of _inputArray
			for (int i = 0; i < _inputArray.size(); i++)
			{
				if (_inputArray[min] > _inputArray[i])
					min = i;				
			}
			Swap(_inputArray, _inputArray.size()-1, min);			
			QuickSort(_inputArray, 0, _inputArray.size()-2);
		}


		void FindDuplicates(vector<int> & _inputArray)
		{
			for (int i = 0; i < _inputArray.size(); )
			{
				cout << "comparing: " << _inputArray[i] << " with: " << _inputArray[i+1] << endl;
				if (_inputArray[i] == _inputArray[i+1])
				{
					DuplicatesFound++;
					cout << "BOOM!";					
				}
				else
					break;
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
#ifndef IMPROVEDQUICKSORT
#define IMPROVEDQUICKSORT

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

		QuickSort(TempArray);	

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
			if (_inputArray[i] == _inputArray[i+1])
			{
				DuplicatesFound++;				
			}
			else
				break;
			i = i+2;
		}
	}
};

#endif
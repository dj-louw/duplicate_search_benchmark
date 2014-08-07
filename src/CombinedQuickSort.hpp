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
		}
	private:
		void QuickSort(vector<int> & _inputArray)
		{
			if (_inputArray.size() > 1)
			{
				vector<int> less(0);
				vector<int> greater(0);
				int pivot;
				
				// this can potentially be improved...
				pivot = _inputArray.at(0);
					
				for (int i = 1; i <= _inputArray.size() -1 ; i++)
				{
					int val = _inputArray.at(i);
					if (val < pivot)
					{
						less.push_back(val);				
					}
					else if	(val > pivot)
					{
						greater.push_back(val);				
					}
					else
						DuplicatesFound++; // neither < or >, therefor a duplicate!
				}		

				QuickSort(less);
				QuickSort(greater);

				vector<int> newvec(0);
				newvec.insert(newvec.end(), less.begin(), less.end());
				newvec.push_back(pivot);
				newvec.insert(newvec.end(), greater.begin(), greater.end());
				_inputArray = newvec;

			}
		}
};

#endif
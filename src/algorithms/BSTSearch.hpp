#ifndef BSTSEARCH
#define BSTSEARCH

unsigned long long int StepCounter;

class BSTree {
	private:
		struct BSTreeNode
		{
			int mData;
			BSTreeNode *mLeft, *mRight;
			BSTreeNode(int i)
			{
				StepCounter = StepCounter + 3;
				mData = i;
				mLeft = NULL;
				mRight = NULL;
			}
			~BSTreeNode()
			{
				StepCounter = StepCounter + 2;
				delete mLeft;
				delete mRight;
			}
		} * mRoot;
	public:
		int mDupCounter;
		// make sure the root doesn't get any value
		BSTree():mRoot(NULL),mDupCounter(0){}
		~BSTree()
		{
			StepCounter = StepCounter + 1;
			delete mRoot;
		}

		void InsertInto(BSTreeNode *& _node, int _valueToInsert)
		{	
			StepCounter = StepCounter + 5;
			if (!_node)
			{
				StepCounter = StepCounter + 2;
				_node = new BSTreeNode(_valueToInsert);
			}
			else if (_valueToInsert < _node->mData)
			{
				StepCounter = StepCounter + 2;
				InsertInto(_node->mLeft, _valueToInsert);			
			}
			else if (_valueToInsert > _node->mData)
			{
				StepCounter = StepCounter + 2;
				InsertInto(_node->mRight, _valueToInsert);
			}
			else
			{
				StepCounter = StepCounter + 1;
				mDupCounter++;
			}
		}

		void InsertIntoRoot(int _valueToInsert)
		{
			StepCounter = StepCounter + 1;
			InsertInto(mRoot, _valueToInsert);
		}
};

class BSTSearch
{
	private:
		vector<int> InputArray;
		BSTree * bstree;
		int TempDupsCounter;
	public:
		BSTSearch(vector<int> &_inputArray)
		{
			StepCounter = StepCounter + 1;
			Init(_inputArray);
		}		
		BSTSearch()
		{
			StepCounter = StepCounter + 3;
			bstree = new BSTree();
			TempDupsCounter = 0;
		}
		void Init(vector<int> & _inputArray)
		{
			StepCounter = StepCounter + 4;
			bstree = new BSTree();
			TempDupsCounter = 0;
			InputArray = _inputArray;
		}
		int GetDuplicateCounter()
		{
			StepCounter = StepCounter + 1;
			return TempDupsCounter;
		}
		int GetStepCounter()
		{
			StepCounter = StepCounter + 1;
			return StepCounter;
		}

		void Do()
		{
			StepCounter = StepCounter + 8;
			vector<int> TempArray = InputArray;
			do
			{				
				StepCounter = StepCounter + 7;
				bstree->InsertIntoRoot(TempArray[TempArray.size()-1]);
				TempArray.pop_back();				
			} while (!TempArray.empty());

			TempDupsCounter = bstree->mDupCounter;
			delete bstree;
			bstree = new BSTree();
		}

		void DoForAStream(int _newNumber)
		{
			StepCounter = StepCounter + 7;
			int currDups = bstree->mDupCounter;
			bstree->InsertIntoRoot(_newNumber);
			int newDups = bstree->mDupCounter;
			if (currDups != newDups)
				cout << "The value: '" << _newNumber << "' has been encountered before." << endl;
		}

};
#endif
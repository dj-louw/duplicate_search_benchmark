#ifndef BSTSEARCH
#define BSTSEARCH

class BSTree {
	private:
		struct BSTreeNode
		{
			int mData;
			BSTreeNode *mLeft, *mRight;
			BSTreeNode(int i)
			{
				mData = i;
				mLeft = NULL;
				mRight = NULL;
			}
			~BSTreeNode()
			{
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
			delete mRoot;
		}

		void InsertInto(BSTreeNode *& _node, int _valueToInsert)
		{	
			if (!_node)
				_node = new BSTreeNode(_valueToInsert);
			else if (_valueToInsert < _node->mData)
				InsertInto(_node->mLeft, _valueToInsert);			
			else if (_valueToInsert > _node->mData)
				InsertInto(_node->mRight, _valueToInsert);
			else
			{
				mDupCounter++;
			}
		}

		void InsertIntoRoot(int _valueToInsert)
		{
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
			Init(_inputArray);
		}		
		BSTSearch()
		{
			bstree = new BSTree();
			TempDupsCounter = 0;
		}
		void Init(vector<int> & _inputArray)
		{
			bstree = new BSTree();
			TempDupsCounter = 0;
			InputArray = _inputArray;
		}
		int GetDuplicateCounter()
		{
			return TempDupsCounter;
		}

		void Do()
		{
			vector<int> TempArray = InputArray;
			do
			{				
				bstree->InsertIntoRoot(TempArray[TempArray.size()-1]);
				TempArray.pop_back();				
			} while (!TempArray.empty());

			TempDupsCounter = bstree->mDupCounter;
			delete bstree;
			bstree = new BSTree();
		}

		void DoForAStream(int _newNumber)
		{
			int currDups = bstree->mDupCounter;
			bstree->InsertIntoRoot(_newNumber);
			int newDups = bstree->mDupCounter;
			if (currDups != newDups)
				cout << "The value: '" << _newNumber << "' has been encountered before." << endl;
		}

};







#endif
#ifndef BSTSEARCH
#define BSTSEARCH


using namespace std;

unsigned long long int StepCounter;

struct BSTreeNode
{
	int mData;
	BSTreeNode *mLeft, *mRight, *mParent;
	BSTreeNode(int i)
	{
		StepCounter = StepCounter + 3;
		mData = i;
		mLeft = NULL;
		mRight = NULL;
		mParent = NULL;
	}
	// ~BSTreeNode()
	// {
	// 	//StepCounter = StepCounter + 2;
	// 	// if (mLeft)
	// 	// 	delete mLeft;
	// 	// if (mRight)
	// 	// 	delete mRight;
	// 	// if (mParent)
	// 	// 	mParent = NULL;
	// }
};

class BSTree {
	private:
		BSTreeNode * mRoot;
		bool mWithDeletion;
	public:
		int mDupCounter;
		// make sure the root doesn't get any value
		BSTree():mRoot(NULL),mDupCounter(0),mWithDeletion(false){}
		BSTree(bool _withDelete):mRoot(NULL),mDupCounter(0),mWithDeletion(_withDelete){}
		~BSTree()
		{
			StepCounter = StepCounter + 1;
			delete mRoot;
		}


/******************************************************************************
******************* DELETION LOGIC
*
		BSTreeNode * FindSmallest(BSTreeNode *& _node)
		{
			if (!_node->mLeft)
				return _node;
			else
				return FindSmallest(_node->mLeft);		
		}

		void DeleteNode(BSTreeNode *& _node)
		{

			if (!_node->mLeft && !_node->mRight) // no subtrees
			{
				//delete _node;
				_node = NULL;
			}
			else if (_node->mLeft && !(_node->mRight)) // only left subtree
			{				
				if (_node->mParent)
				{
					if (_node->mParent->mLeft == _node)// i belong to my parent's mLeft
						_node->mParent->mLeft = _node->mLeft;
					else // I belong to my parent's mRight
						_node->mParent->mRight = _node->mLeft;					
				} else
					mRoot = _node->mLeft;
			}
			else if (_node->mRight && !(_node->mLeft)) // only right subtree
			{				
				if (_node->mParent)
								{
					if (_node->mParent->mLeft == _node)// i belong to my parent's mLeft
						_node->mParent->mLeft = _node->mRight;
					else // I belong to my parent's mRight
						_node->mParent->mRight = _node->mRight;
				} else
					mRoot = _node->mLeft;
			}
			else // both subtrees exist.
			{
				BSTreeNode * temp = FindSmallest(_node->mRight);
				_node->mData = temp->mData;	
				DeleteNode(temp);
			}

		}

/******************************************************************
****** DELETION LOGIC
*/




		void InsertInto(BSTreeNode *& _node, int _valueToInsert, BSTreeNode *& _parent)
		{	

			StepCounter = StepCounter + 5;
			if (!_node)
			{
				StepCounter = StepCounter + 2;
				_node = new BSTreeNode(_valueToInsert);
				_node->mParent = _parent;
			}
			else if (_valueToInsert < _node->mData)
			{
				StepCounter = StepCounter + 2;
				InsertInto(_node->mLeft, _valueToInsert, _node);			
			}
			else if (_valueToInsert > _node->mData)
			{
				StepCounter = StepCounter + 2;
				InsertInto(_node->mRight, _valueToInsert, _node);
			}
			else
			{
				StepCounter = StepCounter + 1;
				mDupCounter++;
				
				// delete the node already in the tree if we must
				if (mWithDeletion)
					DeleteNode(_node);
				
			}
		}

		void InsertIntoRoot(int _valueToInsert)
		{
			BSTreeNode * parent = NULL;
			StepCounter = StepCounter + 1;
			InsertInto(mRoot, _valueToInsert, parent);
		}
};

class BSTSearch
{
	private:
		vector<int> InputArray;
		BSTree * bstree;
		int TempDupsCounter;
	public:
		BSTSearch(vector<int> &_inputArray, bool _withDelete = false)
		{
			StepCounter = 0;
			StepCounter = StepCounter + 2;
			Init(_inputArray, _withDelete);
		}		
		// BSTSearch()
		// {
		// 	StepCounter = 0;
		// 	StepCounter = StepCounter + 3;
		// 	bstree = new BSTree();
		// 	TempDupsCounter = 0;
		// }
		~BSTSearch()
		{
			delete bstree;
		}
		void Init(vector<int> & _inputArray, bool _withDelete = false)
		{
			StepCounter = StepCounter + 4;
			bstree = new BSTree(_withDelete);
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

			// delete bstree;
			// bstree = NULL;
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
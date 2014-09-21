#ifndef BSTSEARCH
#define BSTSEARCH


using namespace std;

unsigned long long int StepCounter;



struct BSTreeNode
{
	int mData;
	BSTreeNode *mLeft, *mRight;
	BSTreeNode(): mLeft(NULL), mRight(NULL){}
	BSTreeNode(int _data): mData(_data), mLeft(NULL), mRight(NULL){};
	BSTreeNode(int _data, BSTreeNode * _leftChild, BSTreeNode * _rightChild)
		: mData(_data)
		, mLeft(_leftChild)
		, mRight(_rightChild)
	{}
};



class BSTree
{

private:
	BSTreeNode * mRoot;


public:

	int mDupCounter;

	BSTree(): mDupCounter(0){}


	void Insert(int _valueToInsert)
	{
		BSTreeNode *p = mRoot, *prev = NULL;
		while (p != NULL) // find a place to insert the new element.
		{
			prev = p;
			if (_valueToInsert < p->mData)
				p = p->mLeft;
			else if (_valueToInsert > p->mData)
				p = p->mRight;
			else // we have thus a duplicate, and we should delete p if the flag is set.
			{
				cout << "found\n";
				mDupCounter++;
				Delete(p);
				return; // there is no need to continue now.
			}
		}

		if (!mRoot) // tree is empty
			mRoot = new BSTreeNode(_valueToInsert);
		else if (_valueToInsert < prev->mData)
			prev->mLeft = new BSTreeNode(_valueToInsert);
		else prev->mRight = new BSTreeNode(_valueToInsert);
	}

	void Delete(BSTreeNode * _nodeToDelete)
	{

		cout << "deleting " << _nodeToDelete->mData << endl;

		BSTreeNode *node, *p = mRoot, *prev = NULL;

		prev = p;
		p = _nodeToDelete;
		node = p;

		if (p != NULL)
		{
			if (node->mRight == NULL) // node has no right child
				node = node->mRight;
			else if (node->mLeft == NULL) // node has no left child
				node = node->mLeft;
			else // node has both children
			{
				BSTreeNode *tmp = node->mLeft;
				BSTreeNode *previous = node;
				while (tmp->mRight != NULL)
				{
					previous = tmp;
					tmp = tmp->mRight;
				}

				node->mData = tmp->mData;

				if (previous == node)
					previous->mLeft = tmp->mLeft;
				else previous->mRight = tmp->mLeft;

			}

			if (p == mRoot)
				mRoot = node;
			else if (prev->mLeft == p)
				prev->mLeft = node;
			else prev->mRight = node;
		}

	}



};















	// void InsertInto(BSTreeNode *& _node, int _valueToInsert, BSTreeNode *& _parent)
	// {	

	// 	StepCounter = StepCounter + 5;
	// 	if (!_node)
	// 	{
	// 		StepCounter = StepCounter + 2;
	// 		_node = new BSTreeNode(_valueToInsert);
	// 		_node->mParent = _parent;
	// 	}
	// 	else if (_valueToInsert < _node->mData)
	// 	{
	// 		StepCounter = StepCounter + 2;
	// 		InsertInto(_node->mLeft, _valueToInsert, _node);			
	// 	}
	// 	else if (_valueToInsert > _node->mData)
	// 	{
	// 		StepCounter = StepCounter + 2;
	// 		InsertInto(_node->mRight, _valueToInsert, _node);
	// 	}
	// 	else
	// 	{
	// 		StepCounter = StepCounter + 1;
	// 		mDupCounter++;
			
	// 		// delete the node already in the tree if we must
	// 		if (mWithDeletion)
	// 			DeleteNode(_node);
			
	// 	}
	// }

	// void InsertIntoRoot(int _valueToInsert)
	// {
	// 	BSTreeNode * parent = NULL;
	// 	StepCounter = StepCounter + 1;
	// 	InsertInto(mRoot, _valueToInsert, parent);
	// }








// struct BSTreeNode
// {
// 	int mData;
// 	BSTreeNode *mLeft, *mRight, *mParent;
// 	BSTreeNode(int i)
// 	{
// 		StepCounter = StepCounter + 3;
// 		mData = i;
// 		mLeft = NULL;
// 		mRight = NULL;
// 		mParent = NULL;
// 	}
// 	// ~BSTreeNode()
// 	// {
// 	// 	//StepCounter = StepCounter + 2;
// 	// 	// if (mLeft)
// 	// 	// 	delete mLeft;
// 	// 	// if (mRight)
// 	// 	// 	delete mRight;
// 	// 	// if (mParent)
// 	// 	// 	mParent = NULL;
// 	// }
// };

// class BSTree {
// 	private:
// 		BSTreeNode * mRoot;
// 		bool mWithDeletion;
// 	public:
// 		int mDupCounter;
// 		// make sure the root doesn't get any value
// 		BSTree():mRoot(NULL),mDupCounter(0),mWithDeletion(false){}
// 		BSTree(bool _withDelete):mRoot(NULL),mDupCounter(0),mWithDeletion(_withDelete){}
// 		~BSTree()
// 		{
// 			StepCounter = StepCounter + 1;
// 			delete mRoot;
// 		}


// *****************************************************************************
// ******************* DELETION LOGIC
// *
// 		BSTreeNode * FindSmallest(BSTreeNode *& _node)
// 		{
// 			if (!_node->mLeft)
// 				return _node;
// 			else
// 				return FindSmallest(_node->mLeft);		
// 		}

// 		void DeleteNode(BSTreeNode *& _node)
// 		{

// 			if (!_node->mLeft && !_node->mRight) // no subtrees
// 			{
// 				//delete _node;
// 				_node = NULL;
// 			}
// 			else if (_node->mLeft && !(_node->mRight)) // only left subtree
// 			{				
// 				if (_node->mParent)
// 				{
// 					if (_node->mParent->mLeft == _node)// i belong to my parent's mLeft
// 						_node->mParent->mLeft = _node->mLeft;
// 					else // I belong to my parent's mRight
// 						_node->mParent->mRight = _node->mLeft;					
// 				} else
// 					mRoot = _node->mLeft;
// 			}
// 			else if (_node->mRight && !(_node->mLeft)) // only right subtree
// 			{				
// 				if (_node->mParent)
// 								{
// 					if (_node->mParent->mLeft == _node)// i belong to my parent's mLeft
// 						_node->mParent->mLeft = _node->mRight;
// 					else // I belong to my parent's mRight
// 						_node->mParent->mRight = _node->mRight;
// 				} else
// 					mRoot = _node->mLeft;
// 			}
// 			else // both subtrees exist.
// 			{
// 				BSTreeNode * temp = FindSmallest(_node->mRight);
// 				_node->mData = temp->mData;	
// 				DeleteNode(temp);
// 			}

// 		}

// /******************************************************************
// ****** DELETION LOGIC






// };

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
			
			// bstree = new BSTree(_withDelete);
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
				bstree->Insert(TempArray[TempArray.size()-1]);
				TempArray.pop_back();				
			} while (!TempArray.empty());




			TempDupsCounter = bstree->mDupCounter;			

			// delete bstree;
			// bstree = NULL;
		}

		// void DoForAStream(int _newNumber)
		// {
		// 	StepCounter = StepCounter + 7;
		// 	int currDups = bstree->mDupCounter;
		// 	bstree->InsertIntoRoot(_newNumber);
		// 	int newDups = bstree->mDupCounter;
		// 	if (currDups != newDups)
		// 		cout << "The value: '" << _newNumber << "' has been encountered before." << endl;
		// }

};
#endif
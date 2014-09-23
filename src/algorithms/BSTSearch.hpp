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
	~BSTreeNode()
	{
		delete mLeft;
		delete mRight;
	}
};



class BSTree
{

private:
	BSTreeNode * mRoot;
	bool mDeleteFlag;

public:

	int mDupCounter;

	BSTree(): mDupCounter(0), mRoot(NULL), mDeleteFlag(false) {}
	BSTree(bool _deleteFlag): mDupCounter(0), mRoot(NULL), mDeleteFlag(_deleteFlag) {}

	~BSTree()
	{
		delete mRoot;
	}

	void Insert(int _valueToInsert)
	{
		BSTreeNode *p = mRoot, *prev = NULL;
		while (p != NULL) // find a place to insert the new element.
		{
			prev = p;
			if (_valueToInsert < p->mData)
			{
				p = p->mLeft;
			}
			else if (_valueToInsert > p->mData)
			{
				p = p->mRight;
			}
			else // we have thus a duplicate, and we should delete p if the flag is set.
			{
				mDupCounter++;
				if (mDeleteFlag)
					Delete(_valueToInsert);
				return; // there is no need to continue now.
			}
		}

		if (!mRoot) // tree is empty
		{
			mRoot = new BSTreeNode(_valueToInsert);
		}
		else if (_valueToInsert < prev->mData)
		{
			prev->mLeft = new BSTreeNode(_valueToInsert);
		}
		else
		{
			prev->mRight = new BSTreeNode(_valueToInsert);	
		} 
	}

	void Delete(int _elemToDelete)
	{
		BSTreeNode *node, *p = mRoot, *prev = NULL;

		while (p != NULL && p->mData != _elemToDelete)
		{
			prev = p;
			if (_elemToDelete < p->mData)
			{
				p = p->mLeft;
			}
			else
			{
				p = p->mRight;	
			} 
		}

		node = p;		

		if (p != NULL && p->mData == _elemToDelete)
		{
			if (node->mRight == NULL) // node has no right child
			{
				node = node->mLeft;
			}
			else if (node->mLeft == NULL) // node has no left child
			{
				node = node->mRight;
			}
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
				{
					previous->mLeft = tmp->mLeft;
				}
				else
				{
					previous->mRight = tmp->mLeft;	
				} 

			}

			if (p == mRoot)
			{
				mRoot = node;
			}
			else if (prev->mLeft == p)
			{
				prev->mLeft = node;
			}
			else
			{
 				prev->mRight = node;
			}
		} 
		else if (mRoot != NULL)
		{
			cout << "Cannot find " << _elemToDelete << " in the tree :/ \n";
		}
		else
		{
			cout << "The tree is empty...\n";	
		} 

	}



};

class BSTSearch
{
	private:
		vector<int> InputArray;
		BSTree * bstree;
		int TempDupsCounter;
	public:
		BSTSearch(vector<int> &_inputArray, bool _withDelete = false): bstree(NULL)
		{
			StepCounter = 0;
			StepCounter = StepCounter + 2;
			Init(_inputArray, _withDelete);
		}		
		~BSTSearch()
		{
			delete bstree;
		}
		void Init(vector<int> & _inputArray, bool _withDelete = false)
		{
			StepCounter = StepCounter + 4;
			
			bstree = new BSTree(_withDelete);
			//bstree = new BSTree();

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
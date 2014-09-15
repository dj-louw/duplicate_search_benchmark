
// C++ includes
#include <iostream> // for io related stuff
#include <sstream> // for std::stringstream
#include <string> // for std::string

// External Library includs
#include "../danlib/danlib.h"

// Other file includes
#include "algorithms/algorithms.h"
#include "BSTMethod.hpp"


using namespace std;


int main()
{

	cout << "BST Algorithm - No Delete: reads IFiles, Performs at the duplicate searching and " << endl;


	DoBSTMethod(true);


	cout << "\nPress Return key to exit"; 
	cin.get();

	return 0;
}


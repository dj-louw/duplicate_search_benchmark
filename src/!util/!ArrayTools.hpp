#ifndef UTIL
#define UTIL

#include <random>
// #include <time.h>
#include <vector>
#include <algorithm>
#include <thread> // std::this_thread::sleep_for()

using namespace std;


// function that creates and populates an array of size @ArraySize with random numbers.
vector<int> GenerateRandomArray(int _arraySize, float _fractionDuplicates = 0.5)
{

	if(_fractionDuplicates >= 1)
		_fractionDuplicates = 1;

	// Create an empty vector
	std::vector<int> ArrayOfNumbers;

	int i = 1;

	// fill the first bit with the amount of duplicates specified.
	for ( ; ArrayOfNumbers.size() < int(_arraySize * (_fractionDuplicates)) ; i++)
	{
		ArrayOfNumbers.push_back(i);
		ArrayOfNumbers.push_back(i);
	}

	// using the same counter, fill the second bit with duplicates.
	for ( ; ArrayOfNumbers.size() <= _arraySize - 1; i++)
	{
		if (ArrayOfNumbers.size() < _arraySize)
			ArrayOfNumbers.push_back(i);
		// if (ArrayOfNumbers.size() < _arraySize)
		// 	ArrayOfNumbers.push_back(i*2);
	}
	// make sure the system sleeps for at least a second so that the rng gets seeded with a new seed every time.
	std::this_thread::sleep_for(std::chrono::seconds(1));
	// seed the rng
	srand(time(0));
	// shuffle the vector using the fisher-yates algorithm, conveniently built into C++ for us.	
	//std::random_shuffle(ArrayOfNumbers.begin(), ArrayOfNumbers.end());
	return ArrayOfNumbers;
}

void PrintArray(vector<int> _inputArray)
{
	for (int elem : _inputArray)
	{
		cout << elem << " | "; 
	}
	cout << endl;
}

#endif
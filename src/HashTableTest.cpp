// C++ includes
#include <iostream> // for io related stuff
#include <sstream> // for std::stringstream
#include <string> // for std::string
#include <thread> // std::this_thread::sleep_for()
#include <unordered_map> // for std::unordered_map
#include <chrono> // for high_resolution_clock

// External Library includs
#include "../danlib/danlib.h"

// Other file includes
using namespace std;

// function that creates and populates an array of size @ArraySize with random numbers.
vector<int> GenerateArray(int _arraySize, float _fractionDuplicates = 0.5)
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
	}

	// make sure the system sleeps for at least a second so that the rng gets seeded with a new seed every time.
	std::this_thread::sleep_for(std::chrono::seconds(1));
	// seed the rng
	srand(time(0));
	// shuffle the vector using the fisher-yates algorithm, conveniently built into C++ for us.	
	//std::random_shuffle(ArrayOfNumbers.begin(), ArrayOfNumbers.end());

	return ArrayOfNumbers;
}


int main()
{

	cout << "Hash Table Algorithm" << endl;

	DanLib::FileTool outtputFile;
	outtputFile.InitOFile("HashTable");
	stringstream OutputStream;

	for (int i=1;i<=100000;i=i*10)
	{
		auto ExpectedLoadFactor = 1000/(double)i;
		cout << "TEST: " << i << " buckets with 1000 elements, expected Load Factor of: " << ExpectedLoadFactor << endl;
		OutputStream << "TEST: " << i << " buckets with 1000 elements: " << ExpectedLoadFactor << endl;

		for (float f = 0.0; f <= 1.1; f = f+0.1)
		{
			cout << "    and duplicate factor of " << f << endl;
			OutputStream << "    and duplicate factor of " << f << endl;
			
			vector<int> ArrayOfNumbers  = GenerateArray(1000, f);

			int bucketcount, elementcount;
			double loadfactor;

   			long int RunningDuration = 0;
			// repeat each test iteration 100 times so that we get balanced results.
			for (int iteration = 0; iteration <=100; iteration++)
			{
    			
// Time critical section
//==============================================================================
    			chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//==============================================================================    

				std::unordered_map<int,int> HashTable;
				HashTable.max_load_factor(INFINITY);
				HashTable.rehash(i);

				for (auto elem : ArrayOfNumbers)
				{
					std::pair<int,int> kvpair (elem,elem);
					pair<typename std::unordered_map< int, int >::iterator,bool> retval = HashTable.insert(kvpair);
					
					if (retval.second == false) 
						HashTable.erase(retval.first);

				}

				loadfactor = HashTable.load_factor();
				bucketcount = HashTable.bucket_count();
				elementcount = HashTable.size();

// Time critical section
//==============================================================================
    			chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
//==============================================================================
				
				auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
				RunningDuration += duration;

			}


// Time critical section
//==============================================================================

			cout << "		Final Table Size: " << elementcount << endl;
			OutputStream << "		Final Table Size: " << elementcount << endl;

			cout << "		Achieved Bucket Count: " << bucketcount << endl;
			OutputStream << "		Achieved Bucket Count: " << bucketcount << endl;

			cout << "		Achieved Load Factor: " << loadfactor << endl;
			OutputStream << "		Achieved Load Factor: " << loadfactor << endl;

			cout << "		Duration: " << RunningDuration/100 << " Microseconds" << endl;
			OutputStream << "		Duration: " << RunningDuration/100 << " Microseconds" << endl;
		}
		cout << endl;
	}

	outtputFile.WriteToFile(OutputStream.str());

		//DanLib::PrintArray(ArrayOfNumbers);

	// for (auto& x: HashTable)
	// 	std::cout << x.first << ": " << x.second << std::endl;

	// cout << endl << endl;

	// // for (auto& elem : HashTable)
	// // {
	// // 	cout << elem.first << " | "; 
	// // }
	// cout << endl;

	// cout << "Array Size: " << ArrayOfNumbers.size() << endl;

	// cout << "bucket count: " << HashTable.bucket_count() << endl;
	// cout << "load factor: " << HashTable.load_factor() << endl;



 //  std::pair<std::string,double> myshopping ("baking powder",0.3);

 //  myrecipe.insert (myshopping);                        // copy insertion
 //  myrecipe.insert (std::make_pair<std::string,double>("eggs",6.0)); // move insertion
 //  myrecipe.insert (mypantry.begin(), mypantry.end());  // range insertion
 //  myrecipe.insert ( {{"sugar",0.8},{"salt",0.1}} );    // initializer list insertion

 //  std::cout << "myrecipe contains:" << std::endl;
 //  for (auto& x: myrecipe)
 //    std::cout << x.first << ": " << x.second << std::endl;

 //  std::cout << std::endl;
 //  return 0;


















	cout << "\nPress Return key to exit"; 
	cin.get();

	return 0;
}

